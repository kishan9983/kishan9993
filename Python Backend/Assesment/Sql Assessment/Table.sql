CREATE TABLE Country (
    country_id INT PRIMARY KEY,
    country_name VARCHAR(50)
);

CREATE TABLE City (
    city_id INT PRIMARY KEY,
    city_name VARCHAR(50),
    country_id INT,
    FOREIGN KEY (country_id) REFERENCES Country(country_id)
);

CREATE TABLE Customer (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(50),
    city_id INT,
    FOREIGN KEY (city_id) REFERENCES City(city_id)
);
