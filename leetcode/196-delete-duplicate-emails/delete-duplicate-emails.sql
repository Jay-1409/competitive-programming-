/* Write your PL/SQL query statement below */
DELETE FROM person p1
WHERE p1.id IN (
    SELECT p1.id
    FROM person p1
    JOIN person p2
      ON p1.email = p2.email
     AND p1.id > p2.id
);