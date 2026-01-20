
## Display patient's full name,
height in the units feet rounded to 1 decimal,
weight in the unit pounds rounded to 0 decimals,
birth_date,
gender non abbreviated.
---
Convert CM to feet by dividing by 30.48.
Convert KG to pounds by multiplying by 2.205.
SELECT concat(first_name," " , last_name) , 
ROUND(height/30.48 , 1) , ROUND(weight*2.205,0) , birth_date ,
CASE 
WHEN gender='M' THEN 'MALE' 
WHEN gender='F' THEN 'FEMALE' 
ELSE 'Other'
END as gender
FROM patients;

## Show all of the patients grouped into weight groups.
Show the total amount of patients in each weight group.
Order the list by the weight group decending.

For example, if they weight 100 to 109 they are placed in the 100 weight group, 110-119 = 110 weight group, etc.

SELECT 
floor(weight/10)*10 as weight_group,
COUNT(*)
FROM patients
GROUP BY 
weight_group
order by weight_group desc;

## BMI Index
SELECT
    patient_id,
    weight,
    height,
    CASE
        WHEN weight / POWER(height / 100.0, 2) >= 30 THEN 1
        ELSE 0
    END AS isObese
FROM patients;

