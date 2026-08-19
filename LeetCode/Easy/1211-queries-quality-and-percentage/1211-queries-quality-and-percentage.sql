# Write your MySQL query statement below
select query_name , round(avg(q.rating/q.position),2) as quality , 
    round(sum(q.rating < 3) / count(q.rating) * 100,2) as poor_query_percentage
from queries q
group by q.query_name
