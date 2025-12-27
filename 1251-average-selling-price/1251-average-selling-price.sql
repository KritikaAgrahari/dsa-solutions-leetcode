# Write your MySQL query statement below
SELECT DISTINCT
    p.product_id,
    COALESCE(
        ROUND(
            SUM(u.units * p.price) OVER (PARTITION BY p.product_id) /
            SUM(u.units) OVER (PARTITION BY p.product_id),
            2
        ),
        0
    ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date BETWEEN p.start_date AND p.end_date;
