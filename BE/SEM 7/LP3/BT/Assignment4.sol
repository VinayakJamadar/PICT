// SPDX-License-Identifier: MIT
pragma solidity >= 0.8.0;

contract StudentData{
    struct Student{
        uint256 rollNumber;
        string name;
        string department;
    }

    Student[] student;

    function addStudent(uint256 _rollNumber, string memory _name, string memory _department) public {
        Student memory newStudent = Student({
            rollNumber : _rollNumber,
            name : _name,
            department : _department
        });
        student.push(newStudent);
    }
    function getStudent(uint256 _rollNumber) public view returns(string memory, string memory){
        for(uint256 i=0;i < student.length;i++){
            Student memory stud = student[i];
            if(stud.rollNumber == _rollNumber){
                return (stud.name,stud.department);
            }
        }
        return ("Name not Found","Department Not Found");
    }

    function getStudentCount() public view returns (uint256){
        return student.length;
    }

    //Fallback Function
    receive() external payable{
        student.push(Student(7,"MSD","IT"));
    }

}