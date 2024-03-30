DESC EMPLOYEE;
DESC DESIGNATION;
DESC DEPARTMENT;

SELECT * FROM EMPLOYEE WHERE DEPT_CODE IS NULL;

SELECT * FROM EMPLOYEE WHERE BASIC = 0;

SELECT * FROM EMPLOYEE WHERE BASIC IS NULL;

SELECT AVG(BASIC) FROM EMPLOYEE;

UPDATE EMPLOYEE
SET BASIC = 0
WHERE BASIC IS NULL;

DELETE FROM EMPLOYEE WHERE DEPT_CODE IS NULL;

SELECT EMP_NAME, (BASIC + BASIC * 50 / 100 + BASIC * 40 / 100) AS Net_Pay FROM EMPLOYEE;

SELECT UPPER(EMP_NAME), BASIC FROM EMPLOYEE ORDER BY DEPT_CODE;

SELECT * FROM employee WHERE JN_DT > '2010-01-01';

SELECT count(*) FROM employee WHERE monthname(JN_DT) = "january";

SELECT MAX(BASIC) AS MAX_BASIC, MIN(BASIC) AS MIN_BASIC FROM EMPLOYEE;

SELECT COUNT(*) AS Female_Employee_No FROM EMPLOYEE WHERE SEX = "F";

UPDATE employee
SET CITY = upper(CITY);
SELECT * FROM employee;

SELECT COUNT(DISTINCT CITY) AS NUM_CITIES_RESIDING FROM EMPLOYEE;

SELECT * FROM EMPLOYEE ORDER BY DEPT_CODE, BASIC DESC;


