/* Write your PL/SQL query statement below */
select distinct p.email from person p where (select count(*) from person p1 where p1.email = p.email) > 1;