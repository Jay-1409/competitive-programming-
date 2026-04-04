/* Write your PL/SQL query statement below */
select 
distinct 
round (
    nvl(
        (select count(*) from delivery d where d.order_date = (select min(d2.order_date) from delivery d2 where d.customer_id = d2.customer_id) and d.order_date = d.customer_pref_delivery_date)
        , 0
    ) / 
    nvl(
        nullif (
            (select count(*) from delivery d where d.order_date = (select min(d2.order_date) from delivery d2 where d.customer_id = d2.customer_id))
            , 0
        ), 0
    ) * 100, 2
) as immediate_percentage from dual;