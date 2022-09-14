-- Create table Library
CREATE TABLE Library(BookId INT NOT NULL, BookName VARCHAR(30) NOT NULL, BookEdition INT NOT NULL, BookQuantity INT NOT NULL, PRIMARY KEY(BookId));

-- Insert record in Library table
INSERT INTO Library VALUES (1, "Wings of Fire", 2, 15);
INSERT INTO Library VALUES (2, "Three Men in a Boat", 3, 10);

-- Create table Library_Audit
CREATE TABLE Library_Audit(BookId INT NOT NULL, BookName VARCHAR(30) NOT NULL, BookEdition INT NOT NULL, BookQuantity INT NOT NULL, TypeOfOperation VARCHAR(10), ModifiedBy VARCHAR(30), ModifiedDateTime DATETIME);

-- Change Delimiter from ';' to '//'
DELIMITER //


-- Trigger for Before Update
CREATE TRIGGER UpdateTrigger
BEFORE UPDATE 
ON Library FOR EACH ROW  
BEGIN
    -- * Error Handling using SIGNAL If BookId or BookEdition or BookQuantity is Negative while Updating Record
    IF (NEW.BookId < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Id Cannot be Negative';
    ELSEIF (NEW.BookEdition < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Edition Cannot be Negative';
    ELSEIF (NEW.BookQuantity < 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Book Quantity Cannot be Negative';
    -- * Else Inserting Record in Library_Audit
    ELSE
        INSERT INTO Library_Audit VALUES (OLD.BookId, OLD.BookName, OLD.BookEdition, OLD.BookQuantity, "Update", CURRENT_USER(), CURRENT_TIMESTAMP());
    END IF;
END //

-- Trigger for After Delete
CREATE TRIGGER DeleteTrigger
AFTER DELETE 
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

-- Drop Trigger UpdateTrigger and DeleteTrigger
DROP TRIGGER UpdateTrigger;
DROP TRIGGER DeleteTrigger;

-- Drop Table Library and Library_Audit
DROP TABLE Library, Library_Audit;