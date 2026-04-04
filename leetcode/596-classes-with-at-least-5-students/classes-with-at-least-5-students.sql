/* Write your PL/SQL query statement below */
select distinct a.class from courses a where (select count(*) from courses c where c.class = a.class) >= 5;