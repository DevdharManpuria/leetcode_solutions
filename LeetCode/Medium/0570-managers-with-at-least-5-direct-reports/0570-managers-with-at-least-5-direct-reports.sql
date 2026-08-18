# Write your MySQL query statement below
select b.name
from Employee e
join Employee b on e.managerId = b.id
group by e.managerId
having count(e.managerId)>=5

