-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: May 12, 2022 at 12:39 AM
-- Server version: 10.4.17-MariaDB
-- PHP Version: 8.0.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cpp_food_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `foodinfo`
--

CREATE TABLE `foodinfo` (
  `f_id` int(11) NOT NULL,
  `f_category` varchar(100) DEFAULT '0',
  `f_type` varchar(100) DEFAULT '0',
  `f_name` varchar(100) NOT NULL DEFAULT '0',
  `f_manufacturer` varchar(100) NOT NULL DEFAULT '0',
  `f_price` varchar(100) NOT NULL DEFAULT '0',
  `f_quantity` varchar(100) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `foodinfo`
--

INSERT INTO `foodinfo` (`f_id`, `f_category`, `f_type`, `f_name`, `f_manufacturer`, `f_price`, `f_quantity`) VALUES
(1, 'Drinks', 'Juice', 'Tropicana Twister 250ml', 'Tropicana Food SDN BHD', '3.20', '16'),
(2, 'Drinks', 'Juice', 'Frooto 250ml', 'Pran', '4.00', '16'),
(3, 'Snacks', 'Chips', 'Doritos 180g', 'Pepsico', '2.80', '14');

-- --------------------------------------------------------

--
-- Table structure for table `solditem`
--

CREATE TABLE `solditem` (
  `f_id` int(11) NOT NULL,
  `f_category` varchar(100) DEFAULT '0',
  `f_type` varchar(100) DEFAULT '0',
  `f_name` varchar(100) NOT NULL DEFAULT '0',
  `f_manufacturer` varchar(100) NOT NULL DEFAULT '0',
  `f_price` varchar(100) NOT NULL DEFAULT '0',
  `f_quantity` varchar(100) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1 ROW_FORMAT=COMPACT;

--
-- Dumping data for table `solditem`
--

INSERT INTO `solditem` (`f_id`, `f_category`, `f_type`, `f_name`, `f_manufacturer`, `f_price`, `f_quantity`) VALUES
(1, 'Popular ', 'Jazz', 'WU-TANG CLAN – ‘DON’T STOP’', 'WU-TANG CLAN', '10', '1'),
(2, 'Old', 'Pop', 'O Bondhu Lal Golapi', 'Shahabuddin', '100', '1'),
(3, 'Popular ', 'Jazz', 'WU-TANG CLAN – ‘DON’T STOP’', 'WU-TANG CLAN', '10', '1'),
(4, 'Old', 'Pop', 'O Bondhu Lal Golapi', 'Shahabuddin', '100', '1');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `foodinfo`
--
ALTER TABLE `foodinfo`
  ADD PRIMARY KEY (`f_id`);

--
-- Indexes for table `solditem`
--
ALTER TABLE `solditem`
  ADD PRIMARY KEY (`f_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `foodinfo`
--
ALTER TABLE `foodinfo`
  MODIFY `f_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT for table `solditem`
--
ALTER TABLE `solditem`
  MODIFY `f_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
