-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Nov 22, 2025 at 04:45 AM
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
-- Database: `school_db`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `CheckEmployeeDept` (IN `emp_id` INT)   BEGIN
    DECLARE v_dept VARCHAR(100);
    SELECT d.department_name INTO v_dept
    FROM employees e
    JOIN departments d ON e.department_id = d.department_id
    WHERE e.employee_id = emp_id;

    IF v_dept = 'HR' THEN
        SELECT 'Employee works in Human Resources' AS message;
    ELSE
        SELECT 'Employee works in another department' AS message;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `display_books` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE b_id INT;
    DECLARE b_title VARCHAR(100);
    DECLARE b_author VARCHAR(100);
    DECLARE b_price DECIMAL(10,2);

    DECLARE book_cursor CURSOR FOR
        SELECT book_id, title, author, price FROM books;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN book_cursor;

    read_loop: LOOP
        FETCH book_cursor INTO b_id, b_title, b_author, b_price;

        IF done THEN
            LEAVE read_loop;
        END IF;

        INSERT INTO book_output VALUES (
            CONCAT(
                'ID: ', b_id,
                ' | Title: ', b_title,
                ' | Author: ', b_author,
                ' | Price: ', b_price
            )
        );

    END LOOP;

    CLOSE book_cursor;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `display_members` ()   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE m_id INT;
    DECLARE m_name VARCHAR(100);
    DECLARE m_email VARCHAR(100);

    DECLARE member_cursor CURSOR FOR
        SELECT member_id, member_name, email FROM members;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN member_cursor;

    read_loop: LOOP
        FETCH member_cursor INTO m_id, m_name, m_email;

        IF done THEN
            LEAVE read_loop;
        END IF;

        INSERT INTO member_output VALUES (
            CONCAT(
                'ID: ', m_id,
                ' | Name: ', m_name,
                ' | Email: ', m_email
            )
        );
    END LOOP;

    CLOSE member_cursor;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `GetCourseDetails` (IN `c_id` INT)   BEGIN
    SELECT course_id, course_name, course_duration
    FROM courses
    WHERE course_id = c_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `GetEmployeesByDepartment` (IN `dept_id` INT)   BEGIN
    SELECT employee_id, employee_name, salary
    FROM employees
    WHERE department_id = dept_id;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `get_books_by_author` (IN `p_author` VARCHAR(100))   BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE b_title VARCHAR(200);

    DECLARE book_cursor CURSOR FOR
        SELECT title FROM books WHERE author = p_author;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

    OPEN book_cursor;

    read_loop: LOOP
        FETCH book_cursor INTO b_title;

        IF done THEN
            LEAVE read_loop;
        END IF;

        INSERT INTO books_output VALUES (b_title);
    END LOOP;

    CLOSE book_cursor;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `title` varchar(100) DEFAULT NULL,
  `author` varchar(100) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books`
--

INSERT INTO `books` (`book_id`, `title`, `author`, `price`) VALUES
(1, 'Book A', 'Author A', 250.00),
(2, 'Book B', 'Author B', 300.00),
(3, 'Book C', 'Author C', 450.00),
(101, 'Book One', 'Author A', 250.00),
(102, 'Book Two', 'Author B', 300.00),
(103, 'Book Three', 'Author A', 400.00);

-- --------------------------------------------------------

--
-- Table structure for table `books_output`
--

CREATE TABLE `books_output` (
  `title` varchar(200) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `books_output`
--

INSERT INTO `books_output` (`title`) VALUES
('Book A');

-- --------------------------------------------------------

--
-- Table structure for table `book_output`
--

CREATE TABLE `book_output` (
  `details` varchar(300) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `book_output`
--

INSERT INTO `book_output` (`details`) VALUES
('ID: 1 | Title: Book A | Author: Author A | Price: 250.00'),
('ID: 2 | Title: Book B | Author: Author B | Price: 300.00'),
('ID: 3 | Title: Book C | Author: Author C | Price: 450.00');

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `course_id` int(11) NOT NULL,
  `course_name` varchar(100) DEFAULT NULL,
  `course_duration` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`course_id`, `course_name`, `course_duration`) VALUES
(1, 'Mathematics', '10 months'),
(3, 'English', '6 months'),
(4, 'History', '5 months'),
(5, 'Geography', '4 months');

-- --------------------------------------------------------

--
-- Table structure for table `departments`
--

CREATE TABLE `departments` (
  `department_id` int(11) NOT NULL,
  `department_name` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `departments`
--

INSERT INTO `departments` (`department_id`, `department_name`) VALUES
(1, 'HR'),
(2, 'Finance'),
(3, 'IT');

-- --------------------------------------------------------

--
-- Stand-in structure for view `employeedepartmentview`
-- (See below for the actual view)
--
CREATE TABLE `employeedepartmentview` (
`employee_id` int(11)
,`employee_name` varchar(100)
,`salary` decimal(10,2)
,`department_name` varchar(100)
);

-- --------------------------------------------------------

--
-- Table structure for table `employees`
--

CREATE TABLE `employees` (
  `employee_id` int(11) NOT NULL,
  `employee_name` varchar(100) DEFAULT NULL,
  `department_id` int(11) DEFAULT NULL,
  `salary` decimal(10,2) DEFAULT NULL,
  `last_modified` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `employees`
--

INSERT INTO `employees` (`employee_id`, `employee_name`, `department_id`, `salary`, `last_modified`) VALUES
(101, 'Alice', 1, 50000.00, '2025-11-15 12:50:38'),
(102, 'Bob', 2, 60000.00, '2025-11-15 12:50:38'),
(103, 'Charlie', 3, 85000.00, '2025-11-15 12:50:38'),
(104, 'David', 2, 62000.00, '2025-11-15 12:50:38');

--
-- Triggers `employees`
--
DELIMITER $$
CREATE TRIGGER `log_new_employee` AFTER INSERT ON `employees` FOR EACH ROW INSERT INTO employee_logs (employee_id, action_type)
VALUES (NEW.employee_id, 'New Employee Added')
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `update_employee_timestamp` BEFORE UPDATE ON `employees` FOR EACH ROW SET NEW.last_modified = CURRENT_TIMESTAMP
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `employee_logs`
--

CREATE TABLE `employee_logs` (
  `log_id` int(11) NOT NULL,
  `employee_id` int(11) DEFAULT NULL,
  `action_type` varchar(50) DEFAULT NULL,
  `action_time` timestamp NOT NULL DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `members`
--

CREATE TABLE `members` (
  `member_id` int(11) NOT NULL,
  `member_name` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `members`
--

INSERT INTO `members` (`member_id`, `member_name`, `email`) VALUES
(1, 'John', 'john@gmail.com'),
(2, 'Mira', 'mira@gmail.com'),
(3, 'Ravi', 'ravi@gmail.com'),
(10, 'Rahul', 'rahul@example.com');

-- --------------------------------------------------------

--
-- Table structure for table `member_output`
--

CREATE TABLE `member_output` (
  `details` varchar(300) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `member_output`
--

INSERT INTO `member_output` (`details`) VALUES
('ID: 1 | Name: John | Email: john@gmail.com'),
('ID: 2 | Name: Mira | Email: mira@gmail.com'),
('ID: 3 | Name: Ravi | Email: ravi@gmail.com');

-- --------------------------------------------------------

--
-- Table structure for table `orders`
--

CREATE TABLE `orders` (
  `order_id` int(11) NOT NULL,
  `product_name` varchar(100) DEFAULT NULL,
  `quantity` int(11) DEFAULT NULL,
  `total_amount` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `orders`
--

INSERT INTO `orders` (`order_id`, `product_name`, `quantity`, `total_amount`) VALUES
(1, 'Laptop', 2, 80000.00),
(2, 'Mouse', 5, 1500.00),
(3, 'Keyboard', 3, 4500.00);

-- --------------------------------------------------------

--
-- Structure for view `employeedepartmentview`
--
DROP TABLE IF EXISTS `employeedepartmentview`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `employeedepartmentview`  AS SELECT `e`.`employee_id` AS `employee_id`, `e`.`employee_name` AS `employee_name`, `e`.`salary` AS `salary`, `d`.`department_name` AS `department_name` FROM (`employees` `e` join `departments` `d` on(`e`.`department_id` = `d`.`department_id`)) WHERE `e`.`salary` >= 50000 ;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`);

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`course_id`);

--
-- Indexes for table `departments`
--
ALTER TABLE `departments`
  ADD PRIMARY KEY (`department_id`);

--
-- Indexes for table `employees`
--
ALTER TABLE `employees`
  ADD PRIMARY KEY (`employee_id`),
  ADD KEY `department_id` (`department_id`);

--
-- Indexes for table `employee_logs`
--
ALTER TABLE `employee_logs`
  ADD PRIMARY KEY (`log_id`);

--
-- Indexes for table `members`
--
ALTER TABLE `members`
  ADD PRIMARY KEY (`member_id`);

--
-- Indexes for table `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`order_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `employee_logs`
--
ALTER TABLE `employee_logs`
  MODIFY `log_id` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `employees`
--
ALTER TABLE `employees`
  ADD CONSTRAINT `employees_ibfk_1` FOREIGN KEY (`department_id`) REFERENCES `departments` (`department_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
