SELECT
    c.country_name,
    ct.city_name,
    cu.customer_name
FROM City ct
INNER JOIN Country c
        ON ct.country_id = c.country_id
LEFT JOIN Customer cu
        ON ct.city_id = cu.city_id;
