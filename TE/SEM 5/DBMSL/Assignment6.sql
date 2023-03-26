-- Create table O_EmpId
CREATE TABLE O_EmpId(EmpId INT NOT NULL, EmpName VARCHAR(30) NOT NULL, EmpDesignation VARCHAR(30) NOT NULL, PRIMARY KEY(EmpId));

-- Insert record in O_EmpId table
INSERT INTO O_EmpId VALUES (1, "Vinayak Jamadar", "MERN Full Stack Developer");
INSERT INTO O_EmpId VALUES (2, "Akash Jamadar", "Competitve Programmer");

-- Create table N_EmpId
CREATE TABLE N_EmpId(EmpId INT NOT NULL, EmpName VARCHAR(30) NOT NULL, EmpDesignation VARCHAR(30) NOT NULL, PRIMARY KEY(EmpId));

-- Change Delimiter from ';' to '//'
DELIMITER //

CREATE PROCEDURE MergeTable()
BEGIN
    DECLARE eId INT;
    DECLARE flag BOOLEAN;
    -- Declaring Cursor 'cur' with Parameters EmpId from O_EmpId table
    DECLARE cur CURSOR FOR SELECT EmpId FROM O_EmpId;
    -- Continue Handler used to check if All the records of O_EmpId are Iterated by Setting flag True
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET flag = TRUE;

    OPEN cur;

    label: LOOP
        -- Fetch a record into Cursor 'cur'
        FETCH cur INTO eId;
        -- Check if record in already existing in N_EmpId table
        IF NOT EXISTS (SELECT * FROM N_EmpId WHERE EmpId=eId) THEN
            -- Insert record if not existing in N_EmpId table
            INSERT INTO N_EmpId SELECT * FROM O_EmpId WHERE EmpId=eId;
            -- Display the Message of Inserted record
            SELECT CONCAT("Empolyee having EmpId: ", eId, " is Inserted in N_EmpId Table") AS MESSAGE;
        END IF;
        
        -- Check if flag is True(i.e If all the records are Iterated)
        IF flag THEN
            -- Close the Cursor 'cur'
            CLOSE cur;
            -- Terminate the LOOP label
            LEAVE label;
        END IF;
    END LOOP;
END;
//

-- Change Delimiter from '//' to ';'
DELIMITER ;

-- Display Table O_EmpId and N_EmpId Before Calling Procedure MergeTable;
SELECT * FROM O_EmpId;

SELECT * FROM N_EmpId;

-- Call Procedure MergeTable
CALL MergeTable();

-- Display Table O_EmpId and N_EmpId After Calling Procedure MergeTable;
SELECT * FROM O_EmpId;

SELECT * FROM N_EmpId;

-- Insert One more Record in O_EmpId
INSERT INTO O_EmpId VALUES (3, "Deepak Jamadar", "Database Management");

-- Display Table O_EmpId and N_EmpId Before Calling Procedure MergeTable;
SELECT * FROM O_EmpId;

SELECT * FROM N_EmpId;

-- Call Procedure MergeTable
CALL MergeTable();

-- Display Table O_EmpId and N_EmpId After Calling Procedure MergeTable;
SELECT * FROM O_EmpId;

SELECT * FROM N_EmpId;

-- Drop MergeTable Procedure
DROP PROCEDURE MergeTable;

-- Drop O_EmpId and N_EmpId Tables
DROP TABLES O_EmpId, N_EmpId;