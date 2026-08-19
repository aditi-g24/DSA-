SELECT d.name as 'Department', x.name as 'Employee', x.salary as 'Salary'
FROM (
    SELECT name, salary, departmentId,
           DENSE_RANK() OVER (
               PARTITION BY departmentId
               ORDER BY salary DESC
           ) AS rnk
    FROM Employee
) AS x
JOIN Department AS d
    ON x.departmentId = d.id
WHERE rnk = 1;