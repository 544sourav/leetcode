# Write your MySQL query statement below
-- select * from customer c left join product p on  c.product_key=p.product_key  

select customer_id from customer group by customer_id having count(distinct  product_key) = (select count(product_key)from product)