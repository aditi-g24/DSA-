SELECT DISTINCT ConsecutiveNums
FROM (SELECT num as ConsecutiveNums, LAG(num) over (ORDER BY id) as prev, 
LEAD(num) over (ORDER BY id) as next 
FROM Logs) as x
where prev = next AND next = ConsecutiveNums AND prev = ConsecutiveNums;
