-- TODO: Error Handling
-- Error Code or Symbol -> Reason of Error
-- 1146 -> Calling Function before Creating Either Student or Result Table will throw Error 1146
-- 1062 -> Calling Function for Duplicate Roll No in Result Table will throw Error 1062
-- NOT FOUND --> Calling Function for Not Existing Roll No in Student Table will throw Error 'NOT FOUND'

-- DECLARE EXIT HANDLER FOR 1146 
-- BEGIN
--     SELECT 'Non Existing Table is used in Function' AS Message; 
-- END;

-- DECLARE CONTINUE HANDLER FOR 1062
-- BEGIN
--     SELECT CONCAT('Error due to inserting Duplicate Roll No ', rollNo, ' in Result Table and Updating the Class if TotalMarks of Student are Changed.') AS message;
--     UPDATE Result SET Result.class = category WHERE Result.RollNo = rollNo;
-- END;

-- DECLARE EXIT HANDLER FOR NOT FOUND
-- BEGIN
--     SELECT CONCAT('Roll No ', rollNo, ' is not Present in Student Table') AS MESSAGE;
-- END;


-- Create table Student
CREATE TABLE Student(RollNo INT NOT NULL, StudentName VARCHAR(20) NOT NULL, TotalMarks INT NOT NULL, PRIMARY KEY(RollNo));

-- Insert record in Student table
INSERT INTO Student VALUES (1, 'Vinayak Jamadar', 995);

-- Create table Result
CREATE TABLE Result(RollNo INT NOT NULL, Name VARCHAR(20), Class VARCHAR(20), FOREIGN KEY(RollNo) REFERENCES Student(RollNo), UNIQUE(RollNo));

-- Change Delimiter from ';' to '//'
DELIMITER //

-- Create Function findCategory
CREATE FUNCTION findCategory(rollNo INT)
RETURNS VARCHAR(20) DETERMINISTIC
BEGIN 
	DECLARE category VARCHAR(20);
	DECLARE marks INT;
	DECLARE studName VARCHAR(20);
	
	SELECT StudentName, TotalMarks INTO studName, marks FROM Student WHERE Student.RollNo = rollNo;

	IF (marks >= 990 and marks <= 1500) THEN
		SET category = 'Distinction';
	ELSEIF (marks >= 900 and marks <= 989) THEN
		SET category = 'First Class';
	ELSEIF (marks >= 825 and marks <= 899) THEN
		SET category = 'Higher Second Class';
	ELSE 
		SET category = 'Fail';
	END IF;
	
	INSERT INTO Result VALUES (rollNo, studName, category);

	RETURN category;
END;
//

-- Change Delimiter from '//' to ';'
DELIMITER ;

-- Call Function
SELECT findCategory(1);

-- Display Student and Result Table
SELECT * FROM Student;

SELECT * FROM Result;

-- Drop the Function
DROP FUNCTION calculateFine;
