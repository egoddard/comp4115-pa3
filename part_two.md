#Part Two
#Area of a Circle

```SQL
MariaDB [(none)]> CREATE FUNCTION circle_area RETURNS REAL SONAME "circle_area.so";
Query OK, 0 rows affected (0.00 sec)

MariaDB [(none)]> select circle_area(1);
+----------------+
| circle_area(1) |
+----------------+
|           3.14 |
+----------------+
1 row in set (0.00 sec)

MariaDB [(none)]> select circle_area(2.93001);
+----------------------+
| circle_area(2.93001) |
+----------------------+
|                26.97 |
+----------------------+
1 row in set (0.00 sec)

MariaDB [(none)]> create database circles;
Query OK, 1 row affected (0.00 sec)

MariaDB [(none)]> use circles;
Database changed
MariaDB [circles]> create table radii(id int not null auto_increment primary key, radius double);
Query OK, 0 rows affected (0.00 sec)

MariaDB [circles]> insert into radii(radius) values (3), (4.2), (9.5), (23.12);
Query OK, 4 rows affected (0.00 sec)
Records: 4  Duplicates: 0  Warnings: 0

MariaDB [circles]> select id, radius, circle_area(radius) from radii;
+----+--------+---------------------+
| id | radius | circle_area(radius) |
+----+--------+---------------------+
|  1 |      3 |               28.27 |
|  2 |    4.2 |               55.42 |
|  3 |    9.5 |              283.53 |
|  4 |  23.12 |             1679.29 |
+----+--------+---------------------+
4 rows in set (0.00 sec)
```

## Seconds to Hours, Minutes, Seconds

```SQL
MariaDB [classicmodels]> CREATE FUNCTION convert_time RETURNS STRING SONAME "convert_time.so";
Query OK, 0 rows affected (0.00 sec)

MariaDB [classicmodels]> select convert_time(500);+--------------------------------+
| convert_time(500)              |
+--------------------------------+
| 0 Hours, 8 Minutes, 20 Seconds |
+--------------------------------+
1 row in set (0.00 sec)

MariaDB [classicmodels]> select convert_time(50000);
+----------------------------------+
| convert_time(50000)              |
+----------------------------------+
| 13 Hours, 53 Minutes, 20 Seconds |
+----------------------------------+
1 row in set (0.00 sec)

MariaDB [classicmodels]> select convert_time(300);
+-------------------------------+
| convert_time(300)             |
+-------------------------------+
| 0 Hours, 5 Minutes, 0 Seconds |
+-------------------------------+
1 row in set (0.00 sec)

MariaDB [classicmodels]> use circles;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
MariaDB [circles]> alter table radii ADD COLUMN seconds int;
Query OK, 4 rows affected (0.01 sec)               
Records: 4  Duplicates: 0  Warnings: 0

MariaDB [circles]> create table times(id int auto_increment primary key not null, time_seconds int);
Query OK, 0 rows affected (0.00 sec)

MariaDB [circles]> insert into times(time_seconds) values (150), (200), (80000), (320);
Query OK, 4 rows affected (0.00 sec)
Records: 4  Duplicates: 0  Warnings: 0

MariaDB [circles]> select id, time_seconds, convert_time(time_seconds) from times;
+----+--------------+----------------------------------+
| id | time_seconds | convert_time(time_seconds)       |
+----+--------------+----------------------------------+
|  1 |          150 | 0 Hours, 2 Minutes, 30 Seconds   |
|  2 |          200 | 0 Hours, 3 Minutes, 20 Seconds   |
|  3 |        80000 | 22 Hours, 13 Minutes, 20 Seconds |
|  4 |          320 | 0 Hours, 5 Minutes, 20 Seconds   |
+----+--------------+----------------------------------+
4 rows in set (0.00 sec)

```

