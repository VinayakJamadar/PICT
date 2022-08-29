-- Creating table Borrower
CREATE TABLE Borrower(RollNo INT NOT NULL, Name VARCHAR(20) NOT NULL, DateOfIssue DATE NOT NULL, NameOfBook VARCHAR(40) NOT NULL, Status CHAR(1) DEFAULT 'I', PRIMARY KEY(RollNo));

-- Inserting record in Borrower table
INSERT INTO Borrower(RollNo, Name, DateOfIssue, NameOfBook) VALUES (1, 'Vinayak Jamadar', '2022-07-30', 'Wings of Fire');

-- Creating table Fine
CREATE TABLE Fine(RollNo INT NOT NULL, DateOfIssue Date NOT NULL, Amount INT, FOREIGN KEY(RollNo) REFERENCES Borrower(RollNo), UNIQUE(RollNo));

-- Changing Delimiter from ';' to '//'
DELIMITER //

-- Error Code or Symbol -> Reason of Error
-- 1146 -> Calling Procedure before Creating Either Borrower or Fine Table will throw Error 1146
-- 1062 -> Calling Procedure for Duplicate Roll No in Fine Table will throw Error 1062
-- NOT FOUND --> Calling Procedure for Not Existing Roll No in Borrower Table will throw Error 'NOT FOUND'

-- * CURDATE() -> Returns the Current Date
-- * DATEDIFF(date1, date2) -> returns the number(INT) of days between two date values i.e (date1-date2)

-- Creating Procedure calculateFine
CREATE PROCEDURE calculateFine(IN rollNo INT)
BEGIN 
	DECLARE amount INT DEFAULT 0;
	DECLARE currentDate DATE;
	DECLARE issuedDate DATE;
	DECLARE dateDifference INT DEFAULT 0;

    DECLARE EXIT HANDLER FOR 1146 
	BEGIN
        SELECT 'Non Existing Table is used in Procedure' AS Message; 
	END;

    DECLARE CONTINUE HANDLER FOR 1062
    BEGIN
        SELECT CONCAT('Error due to inserting Duplicate Roll No ', rollNO, ' in Fine Table and Updating the Amount to ', amount) AS message;
        UPDATE Fine SET Fine.Amount = amount WHERE Fine.RollNo = rollNo;
    END;

    DECLARE EXIT HANDLER FOR NOT FOUND
	BEGIN
        SELECT CONCAT('Roll No ', rollNo, ' is not Present in Borrower Table') AS MESSAGE;
	END;

    SET currentDate = CURDATE();

    SELECT DateOfIssue into issuedDate FROM Borrower WHERE Borrower.RollNo = rollNo;

	SET dateDifference = DATEDIFF(currentDate, issuedDate);

    IF (dateDifference > 15) THEN
        IF (dateDifference > 30) THEN
            SET amount = (dateDifference-30)*50;
            SET dateDifference = 30;
        END IF;
        SET amount = (dateDifference-15)*5;
        
        UPDATE Borrower SET Status = "R" WHERE Borrower.RollNo = rollNo;
        INSERT INTO Fine VALUES (rollNo, issuedDate, amount);
        SELECT CONCAT('Fine for Roll No ', rollNo, ' is Amount ', amount, ' Rs.') AS message;
    ELSE
        SELECT CONCAT('No Fine for Roll No ', rollNo) AS message;
    END IF;
    
END;
//

-- Changing Delimiter from '//' to ';'
DELIMITER ;

-- Calling procedure
CALL calculateFine(1);

SELECT * FROM Borrower;

SELECT * FROM Fine;

-- Drop the Procedure
DROP PROCEDURE calculateFine;