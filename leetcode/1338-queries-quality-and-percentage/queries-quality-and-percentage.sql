/* Write your PL/SQL query statement below */
select 
    q.query_name,
    round(avg(nvl(q.rating/nullif(q.position, 0),0)), 2) as quality,
    round(
        nvl(
            (select count(*) from queries q2 where q2.query_name = q.query_name and rating < 3) 
            / 
            nullif (
                 (select count(*) from queries q2 where q2.query_name = q.query_name) , 0
            ) ,
            0
        ) 
        * 
        100 ,
        2
    ) as poor_query_percentage
    from queries q group by q.query_name;