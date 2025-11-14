SELECT
    c.country_name,
    ct.city_name,
    cu.customer_name
FROM Country c
LEFT JOIN City ct
        ON c.country_id = ct.country_id
LEFT JOIN Customer cu
        ON ct.city_id = cu.city_id;
