SELECT DISTINCT City FROM STATION
WHERE City RLIKE '^[^AEIOU]' AND City RLIKE '[^AEIOU]$'
ORDER BY City;
