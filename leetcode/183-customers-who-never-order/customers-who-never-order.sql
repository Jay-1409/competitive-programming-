/* Write your PL/SQL query statement below */
select c.name as Customers from customers c where (select count(*) from orders o where o.customerId = c.id) = 0;