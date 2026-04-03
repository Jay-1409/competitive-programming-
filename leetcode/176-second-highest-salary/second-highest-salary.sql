# Write your MySQL query statement below
select max(e.salary) as SecondHighestSalary from employee e where e.salary < (select max(e1.salary) from employee e1);
