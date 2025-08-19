# Write your MySQL query statement below
-- here self join is used
SELECT a.name AS Employee
FROM Employee a
JOIN Employee b
  ON a.managerId = b.id
WHERE a.salary > b.salary;

