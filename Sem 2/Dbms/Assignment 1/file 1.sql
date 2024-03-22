CREATE TABLE `EMPLOYEE` (
  `EMP_CODE` VARCHAR(16) NOT NULL,
  `EMP_NAME` VARCHAR(20) NOT NULL,
  `DEPT_CODE` VARCHAR(16) NULL,
  `DESIG_CODE` VARCHAR(16) NULL,
  `SEX` VARCHAR(1) NULL,
  `ADDRESS` VARCHAR(25) NULL,
  `CITY` VARCHAR(20) NULL,
  `STATE` VARCHAR(20) NULL,
  `PIN` VARCHAR(6) NULL,
  `BASIC` INT NULL,
  `JN_DT` DATE NULL,
  PRIMARY KEY (`EMP_CODE`));
  
CREATE TABLE `DESIGNATION` (
  `DESIG_CODE` VARCHAR(16) NOT NULL,
  `DESIG_DESC` VARCHAR(20) NULL,
  PRIMARY KEY (`DESIG_CODE`));
  
CREATE TABLE `DEPARTMENT` (
  `DEPT_CODE` VARCHAR(16) NOT NULL,
  `DEPT_NAME` VARCHAR(20) NULL,
  PRIMARY KEY (`DEPT_CODE`));
  
INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DEPT_CODE, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, BASIC, JN_DT) 
VALUES 
('3', 'David Brown', '3', '1', 'M', '789 Oak St', 'Smalltown', 'TX', '67890', 60000, '2022-12-20'),
('4', 'Emily Lee', '2', '3', 'F', '101 Pine St', 'Bigcity', 'IL', '45678', 52000, '2024-01-08'),
('5', 'Michael Chen', '1', '2', 'M', '202 Cedar St', 'Midtown', 'GA', '23456', 58000, '2023-08-12'),
('6', 'Sarah Johnson', '2', '2', 'F', '303 Maple St', 'Hilltown', 'MA', '34567', 59000, '2024-02-18'),
('9', 'Kevin Taylor', '2', '2', 'M', '606 Oakwood St', 'Mountain', 'CO', '67890', 58000, '2023-09-10'),
('10', 'Amanda Martinez', '1', '1', 'F', '707 Elmwood St', 'Lakeside', 'WA', '78901', 60000, '2024-01-30'),
('21', 'Kimberly White', '4', '4', 'F', '909 Pineapple St', 'Beachside', 'CA', '01234', 54000, '2023-10-05'),
('22', 'Daniel Thompson', '5', '5', 'M', '1010 Cherry St', 'Riverside', 'TX', '12345', 0, '2024-02-29'),
('23', 'Olivia Garcia', '4', '5', 'F', '1111 Apple St', 'Orchard', 'NY', '23456', 56000, '2023-06-15'),
('24', 'Ethan Rodriguez', '5', '4', 'M', '1212 Banana St', 'Tropicana', 'FL', '34567', 60000, '2024-01-18'),
('25', 'Sophia Martinez', '4', '5', 'F', '1313 Mango St', 'Palmside', 'CA', '45678', 0, '2023-08-20');

INSERT INTO EMPLOYEE (EMP_CODE, EMP_NAME, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, JN_DT) 
VALUES
('7', 'Robert Miller', '1', 'M', '404 Walnut St', 'Riverside', 'FL', '45678', '2023-11-25'),
('8', 'Jessica Wong', '3', 'F', '505 Birch St', 'Bayville', 'NJ', '56789', '2024-03-02');
  
INSERT INTO `DEPARTMENT` (`DEPT_CODE`, `DEPT_NAME`) VALUES ('1', 'Personnel');
INSERT INTO `DEPARTMENT` (`DEPT_CODE`, `DEPT_NAME`) VALUES ('2', 'Production');
INSERT INTO `DEPARTMENT` (`DEPT_CODE`, `DEPT_NAME`) VALUES ('3', 'Purchase');
INSERT INTO `DEPARTMENT` (`DEPT_CODE`, `DEPT_NAME`) VALUES ('4', 'Finance');
INSERT INTO `DEPARTMENT` (`DEPT_CODE`, `DEPT_NAME`) VALUES ('5', 'Research');

INSERT INTO `DESIGNATION` (`DESIG_CODE`, `DESIG_DESC`) VALUES ('1', 'Manager');
INSERT INTO `DESIGNATION` (`DESIG_CODE`, `DESIG_DESC`) VALUES ('2', 'Executive');
INSERT INTO `DESIGNATION` (`DESIG_CODE`, `DESIG_DESC`) VALUES ('3', 'officer');
INSERT INTO `DESIGNATION` (`DESIG_CODE`, `DESIG_DESC`) VALUES ('4', 'clerk');
INSERT INTO `DESIGNATION` (`DESIG_CODE`, `DESIG_DESC`) VALUES ('5', 'helper');
