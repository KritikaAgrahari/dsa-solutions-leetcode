# Write your MySQL query statement below
select min(event_date) as first_login,player_id
from activity
group by player_id;
