## NULL by default =>
- mysql> insert into teacher values (3 , "akash2" , NULL );

## if salary is NULL ==> NOT SHOWN
mysql> SELECT * FROM teacher WHERE salary>1000;           

## cant use * for GROUP BY
mysql> SELECT s_branch , *  FROM student GROUP BY s_branch ;


## how to apply column alias in sql?


## marks_should_be>0&&<100
ALTER TABLE student 
ADD CONSTRAINT marks_should_be>0&&<100 CHECK (marks BETWEEN 0 AND 100),
ADD CONSTRAINT chk_age CHECK (age >= 18),
ADD CONSTRAINT chk_gender CHECK (gender IN ('M','F','O'));


## Replicate table