select DATETIME as "시간" from ANIMAL_INS order by DATETIME desc limit 0,1
select DATETIME as "시간" from ANIMAL_INS order by DATETIME asc limit 0,1
select count(ANIMAL_ID) from ANIMAL_INS;
select count(NAME) from (select NAME from ANIMAL_INS group by NAME)tmp;