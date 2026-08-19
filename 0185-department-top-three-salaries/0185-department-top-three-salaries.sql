SELECT Department, Employee, Salary
FROM (SELECT d.name as 'Department', e.name as 'Employee', e.salary as 'Salary',
 DENSE_RANK() OVER(
    PARTITION BY d.id
    ORDER BY e.salary DESC
 ) as rnk
FROM Employee e
JOIN Department d
ON e.departmentID = d.id) AS x
WHERE rnk < 4;
