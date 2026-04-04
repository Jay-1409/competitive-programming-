/* Write your PL/SQL query statement below */
select max(m.num) as num from mynumbers m where (select count(*) from mynumbers where num = m.num) = 1;