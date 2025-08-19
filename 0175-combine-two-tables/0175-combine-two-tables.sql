# Write your MySQL query statement below
-- col same-inner join
-- left join-left side and all rows
-- left+right=full join

SELECT  p.firstname,p.lastname,a.city,a.state
FROM Person p
LEFT JOIN Address a
ON p.personId=a.personId