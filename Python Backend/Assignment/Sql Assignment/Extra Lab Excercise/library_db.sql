-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 26, 2025 at 08:18 AM
-- Server version: 10.4.32-MariaDB
-- PHP Version: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `library_db`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `checkBookPrice` (IN `bid` INT)   BEGIN
    DECLARE book_price DECIMAL(10,2);

    SELECT price INTO book_price FROM books WHERE book_id = bid;

    IF book_price > 100 THEN
        SELECT CONCAT('Book ID ', bid, ' has a price above $100') AS message;
    ELSE
        SELECT CONCAT('Book ID ', bid, ' has a price $100 or below') AS message;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `displayBooksForLoop` ()   BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_book_id INT;
    DECLARE v_title VARCHAR(255);
    DECLARE v_author VARCHAR(100);
    DECLARE v_publisher VARCHAR(100);
    DECLARE v_year INT;
    DECLARE v_price DECIMAL(10,2);
    DECLARE v_genre VARCHAR(50);

    DECLARE cur_books CURSOR FOR 
        SELECT book_id, title, author, publisher, year_of_publication, price, genre FROM books;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur_books;

    read_loop: LOOP
        FETCH cur_books INTO v_book_id, v_title, v_author, v_publisher, v_year, v_price, v_genre;
        IF done THEN
            LEAVE read_loop;
        END IF;
        SELECT v_book_id AS book_id, v_title AS title, v_author AS author, v_publisher AS publisher, v_year AS year_of_publication, v_price AS price, v_genre AS genre;
    END LOOP;

    CLOSE cur_books;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `displayMembers` ()   BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_member_id INT;
    DECLARE v_member_name VARCHAR(100);
    DECLARE v_date_of_membership DATE;
    DECLARE v_email VARCHAR(100);

    DECLARE cur_members CURSOR FOR 
        SELECT member_id, member_name, date_of_membership, email FROM members;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur_members;

    read_loop: LOOP
        FETCH cur_members INTO v_member_id, v_member_name, v_date_of_membership, v_email;
        IF done THEN
            LEAVE read_loop;
        END IF;
        SELECT v_member_id AS member_id, v_member_name AS member_name, v_date_of_membership AS date_of_membership, v_email AS email;
    END LOOP;

    CLOSE cur_members;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getBookPrice` (IN `bid` INT)   BEGIN
SELECT price FROM books WHERE book_id=bid;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getBooksByAuthor` (IN `authorName` VARCHAR(100))   BEGIN
SELECT * FROM books WHERE author=authorName;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getBooksByAuthorCursor` (IN `authorName` VARCHAR(100))   BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_title VARCHAR(255);

    DECLARE cur_books CURSOR FOR 
        SELECT title FROM books WHERE author = authorName;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;

    OPEN cur_books;

    read_loop: LOOP
        FETCH cur_books INTO v_title;
        IF done THEN
            LEAVE read_loop;
        END IF;
        SELECT v_title AS title;
    END LOOP;

    CLOSE cur_books;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `getTotalBooks` ()   BEGIN
    SELECT COUNT(*) AS total_books FROM books;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `insertBook` ()   BEGIN
    INSERT INTO books (book_id, title, author, publisher, year_of_publication, price, genre)
    VALUES (15,'Python Programming','Mark Lutz','OReilly',2023,800.00,'Programming');
    SELECT 'Book inserted successfully.' AS message;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `priceOperations` ()   BEGIN
    DECLARE CONST_DISCOUNT DECIMAL(5,2) DEFAULT 50.00;
    DECLARE total_price DECIMAL(10,2);

    -- Calculate total price of all books
    SELECT SUM(price) INTO total_price FROM books;

    -- Display original total, discount, and discounted total
    SELECT total_price AS original_total,
           CONST_DISCOUNT AS discount,
           (total_price - CONST_DISCOUNT) AS discounted_total;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `showBookInfo` ()   BEGIN
    DECLARE v_book_id INT;
    DECLARE v_price DECIMAL(10,2);

    SET v_book_id = 101;
    SET v_price = 499.99;

    SELECT v_book_id AS book_id, v_price AS price;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `author` varchar(100) DEFAULT NULL,
  `publisher` varchar(100) DEFAULT NULL,
  `year_of_publication` int(11) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL,
  `genre` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`book_id`, `title`, `author`, `publisher`, `year_of_publication`, `price`, `genre`) VALUES
(1, 'Mathematics Basics', 'John Doe', 'EduPub', 2015, 150.00, 'Education'),
(2, 'Physics Fundamentals', 'Jane Smith', 'SciencePub', 2018, 200.00, 'Science'),
(3, 'Chemistry 101', 'Alice Brown', 'ChemBooks', 2017, 120.00, 'Science'),
(4, 'Programming in C', 'Robert Martin', 'TechPress', 2020, 300.00, 'Programming'),
(5, 'English Grammar', 'Emily White', 'LangPub', 2016, 100.00, 'Language'),
(11, 'Data Structures', 'Alice Brown', 'TechPub', 2021, 250.00, 'Programming'),
(12, 'Algorithms', 'Bob Smith', 'TechPub', 2020, 300.00, 'Programming'),
(13, 'Database Systems', 'Carol White', 'EduPub', 2019, 200.00, 'Education'),
(14, 'Data Structures', 'Alice Brown', 'TechPub', 2021, 250.00, 'Programming'),
(15, 'Algorithms', 'Bob Smith', 'TechPub', 2020, 300.00, 'Programming'),
(16, 'Database Systems', 'Carol White', 'EduPub', 2019, 200.00, 'Education'),
(17, 'Data Structures', 'Alice Brown', 'TechPub', 2021, 250.00, 'Programming'),
(18, 'Algorithms', 'Bob Smith', 'TechPub', 2020, 300.00, 'Programming'),
(19, 'Database Systems', 'Carol White', 'EduPub', 2019, 200.00, 'Education'),
(20, 'Machine Learning', 'John Smith', 'TechPress', 2022, 400.00, 'Programming'),
(21, 'Artificial Intelligence', 'Jane Doe', 'AI Pub', 2021, 350.00, 'Programming'),
(22, 'Big Data Analytics', 'Alice Brown', 'DataPub', 2020, 300.00, 'Data Science');

-- --------------------------------------------------------

--
-- Stand-in structure for view `books_view`
-- (See below for the actual view)
--
CREATE TABLE `books_view` (
`title` varchar(255)
,`author` varchar(100)
,`price` decimal(10,2)
);

-- --------------------------------------------------------

--
-- Table structure for table `log_changes`
--

CREATE TABLE `log_changes` (
  `log_id` int(11) NOT NULL,
  `book_id` int(11) DEFAULT NULL,
  `title` varchar(255) DEFAULT NULL,
  `deleted_at` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `member_name` varchar(100) DEFAULT NULL,
  `date_of_membership` date DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`member_id`, `member_name`, `date_of_membership`, `email`) VALUES
(1, 'Rahul S.', '2022-01-15', 'rahul.sharma@example.com'),
(2, 'Priya Patel', '2021-12-20', 'new.priya@example.com'),
(3, 'Amit Kumar', '2023-03-05', 'amit.kumar@example.com'),
(4, 'Sneha Mehta', '2022-07-10', 'sneha.mehta@example.com'),
(5, 'Karan Joshi', '2023-01-25', 'karan.joshi@example.com'),
(6, 'Amit Sharma', '2023-05-10', 'amit.sharma@example.com');

-- --------------------------------------------------------

--
-- Stand-in structure for view `members_before_2020`
-- (See below for the actual view)
--
CREATE TABLE `members_before_2020` (
`member_id` int(11)
,`member_name` varchar(100)
,`date_of_membership` date
,`email` varchar(100)
);

-- --------------------------------------------------------

--
-- Structure for view `books_view`
--
DROP TABLE IF EXISTS `books_view`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `books_view`  AS SELECT `books`.`title` AS `title`, `books`.`author` AS `author`, `books`.`price` AS `price` FROM `books` ;

-- --------------------------------------------------------

--
-- Structure for view `members_before_2020`
--
DROP TABLE IF EXISTS `members_before_2020`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `members_before_2020`  AS SELECT `members`.`member_id` AS `member_id`, `members`.`member_name` AS `member_name`, `members`.`date_of_membership` AS `date_of_membership`, `members`.`email` AS `email` FROM `members` WHERE `members`.`date_of_membership` < '2020-01-01' ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`);

--
-- Indexes for table `log_changes`
--
ALTER TABLE `log_changes`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`member_id`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `log_changes`
--
ALTER TABLE `log_changes`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
