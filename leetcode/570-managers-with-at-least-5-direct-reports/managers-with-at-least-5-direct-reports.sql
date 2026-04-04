/* Write your PL/SQL query statement below */
select e1.name as name from employee e1 where (select count(*) from employee e2 where e2.ManagerId = e1.id) >= 5;