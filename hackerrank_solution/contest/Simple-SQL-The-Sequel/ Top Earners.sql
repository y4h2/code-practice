/*
Enter your query here.
*/
SELECT MAX(months*salary),COUNT(*)
FROM employee
WHERE salary*months = (SELECT MAX(salary * months) FROM employee);
