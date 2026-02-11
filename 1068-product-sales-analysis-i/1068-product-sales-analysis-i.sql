# Write your MySQL query statement below
select b.product_name ,a.year, a.price from product b  join sales a on b.product_id = a.product_id