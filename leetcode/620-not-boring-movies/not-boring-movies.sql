/* Write your PL/SQL query statement below */
select * from Cinema m where mod(m.id, 2) = 1 and m.description != 'boring' order by m.rating desc;