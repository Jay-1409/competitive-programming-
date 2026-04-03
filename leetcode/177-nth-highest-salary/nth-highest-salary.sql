CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */    

    SELECT MAX(salary)
    INTO result
    FROM (
        SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) rnk
    FROM employee
    )
    WHERE rnk = N;

    RETURN result;
END;