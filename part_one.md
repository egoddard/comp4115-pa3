#Part One
```SQL
MariaDB [classicmodels]> create function multip(a INT, b INT) returns INT
    -> return a * b;
Query OK, 0 rows affected (0.00 sec)

MariaDB [classicmodels]> select multip(2, 3);
+--------------+
| multip(2, 3) |
+--------------+
|            6 |
+--------------+
1 row in set (0.00 sec)
```
