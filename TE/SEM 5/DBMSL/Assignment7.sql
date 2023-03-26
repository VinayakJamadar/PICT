-- Create table Library
CREATE TABLE Library(BookId INT NOT NULL, BookName VARCHAR(30) NOT NULL, BookEdition INT NOT NULL, BookQuantity INT NOT NULL, PRIMARY KEY(BookId));

-- Insert record in Library table
INSERT INTO Library VALUES (1, "Wings of Fire", 2, 15);
INSERT INTO Library VALUES (2, "Three Men in a Boat", 3, 10);

-- Create table Library_Audit
CREATE TABLE Library_Audit(BookId INT NOT NULL, BookName VARCHAR(30) NOT NULL, BookEdition INT NOT NULL, BookQuantity INT NOT NULL, TypeOfOperation VARCHAR(10), ModifiedBy VARCHAR(30), ModifiedDateTime DATETIME);

-- Change Delimiter from ';' to '//'
DELIMITER //

-- Trigger for Before Insert
CREATE TRIGGER BeforeInsertTrigger
BEFORE INSERT
ON Library FOR EACH ROW
BEGIN
    IF (NEW.BookId < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Id Cannot be Negative';
    ELSEIF (NEW.BookName = NULL) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Name Cannot be NULL';
    ELSEIF (NEW.BookEdition < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Edition Cannot be Negative';
    ELSEIF (NEW.BookQuantity < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Quantity Cannot be Negative';
    END IF;
END //

-- Trigger for After Insert
CREATE TRIGGER AfterInsertTrigger
AFTER INSERT
ON Library FOR EACH ROW
BEGIN
    INSERT INTO Library_Audit VALUES (NEW.BookId, NEW.BookName, NEW.BookEdition, NEW.BookQuantity, "Insert", CURRENT_USER(), CURRENT_TIMESTAMP());
END //


-- Trigger for Before Update
CREATE TRIGGER BeforeUpdateTrigger
BEFORE UPDATE 
ON Library FOR EACH ROW  
BEGIN
    -- * Error Handling using SIGNAL If BookId or BookEdition or BookQuantity is Negative while Updating Record
    IF (NEW.BookId < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Id Cannot be Negative';
    ELSEIF (NEW.BookName = NULL) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Name Cannot be NULL';
    ELSEIF (NEW.BookEdition < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Edition Cannot be Negative';
    ELSEIF (NEW.BookQuantity < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Quantity Cannot be Negative';
    -- * Else Inserting Record in Library_Audit
    ELSE
        INSERT INTO Library_Audit VALUES (OLD.BookId, OLD.BookName, OLD.BookEdition, OLD.BookQuantity, "Update", CURRENT_USER(), CURRENT_TIMESTAMP());
    END IF;
END //


-- Trigger for After Update
CREATE TRIGGER AfterUpdateTrigger
AFTER UPDATE 
ON Library FOR EACH ROW  
BEGIN
    IF (OLD.BookId != NEW.BookId OR OLD.BookName != NEW.BookName OR OLD.BookEdition != NEW.BookEdition) THEN
	UPDATE Library_Audit SET BookId = NEW.BookId, BookName = NEW.BookName,  BookEdition = NEW.BookEdition WHERE (BookId = NEW.BookId and BookName = OLD.BookName and BookEdition = OLD.BookEdition);
    END IF;
END //


-- Trigger for Before Delete
CREATE TRIGGER BeforeDeleteTrigger
BEFORE DELETE 
ON Library FOR EACH ROW  
BEGIN
    -- * Inserting Record in Library_Audit
    INSERT INTO Library_Audit VALUES (OLD.BookId, OLD.BookName, OLD.BookEdition, OLD.BookQuantity, "Delete", CURRENT_USER(), CURRENT_TIMESTAMP());
END //

-- Change Delimiter from '//' to ';'
DELIMITER ;

-- Display Table Library and Library_Audit
SELECT * FROM Library;
SELECT * FROM Library_Audit;

-- Updating the BookQuantity of BookId = 1
UPDATE Library SET BookQuantity = 10 WHERE BookId = 1;

-- Display Table Library and Library_Audit
SELECT * FROM Library;
SELECT * FROM Library_Audit;

-- Deleting Book having BookId = 1
DELETE FROM Library WHERE BookId = 1;

-- Display Table Library and Library_Audit
SELECT * FROM Library;
SELECT * FROM Library_Audit;

-- Inserting New Book with BookId = 3
INSERT INTO Library VALUES (3, "Bhagavad Gita", 1, 50);
UPDATE Library SET BookQuantity = -1 WHERE BookId = 3;

-- Display Table Library and Library_Audit
SELECT * FROM Library;
SELECT * FROM Library_Audit;

-- Drop Triggers
DROP TRIGGER BeforeInsertTrigger;
DROP TRIGGER AfterInsertTrigger;
DROP TRIGGER BeforeUpdateTrigger;
DROP TRIGGER AfterUpdateTrigger;
DROP TRIGGER BeforeDeleteTrigger;

-- Drop Table Library and Library_Audit
DROP TABLE Library, Library_Audit;
