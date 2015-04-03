/*
* Procedure to get return the first and last names from the employees
* table with the provided last name
*/
DELIMITER //
CREATE PROCEDURE get_name
(IN last VARCHAR(30))
BEGIN
    SELECT first_name, last_name FROM employees
    WHERE last_name = last;
END //
DELIMITER ;

/*
* Procedure to return the average salary of all employees in a department
* given the department's ID
*/
DELIMITER //
CREATE PROCEDURE avg_salary
(IN dept CHAR(4))
BEGIN
    SELECT AVG(salary) FROM salaries as s
    JOIN
        dept_emp as de ON de.emp_no = s.emp_no
    WHERE de.dept_no = dept;
END //
DELIMITER ;

/*
* Procedure to return the count of employees of a given gender
*/
DELIMITER //
CREATE PROCEDURE count_gender
(IN gen CHAR(1))
BEGIN
    SELECT COUNT(gender) FROM employees WHERE gender = gen;
END //
DELIMITER ;
