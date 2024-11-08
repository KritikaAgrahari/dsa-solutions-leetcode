# Write your MySQL query statement below
SELECT * FROM cinema
WHERE 
 description <> 'boring' AND 
id % 2 <> 0
 order by RATING DESC;