SELECT id, movie, description, rating
FROM Cinema
WHERE id % 2 <> 0
  AND description NOT IN ('boring')

  ORDER BY rating DESC;

