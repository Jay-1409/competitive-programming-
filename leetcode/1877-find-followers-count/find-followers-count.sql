/* Write your PL/SQL query statement below */
select distinct f1.user_id,
       (
           select count(*)
           from followers f2
           where f2.user_id = f1.user_id
       ) as followers_count
from followers f1 order by user_id asc;