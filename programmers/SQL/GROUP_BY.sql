select ANIMAL_TYPE,count(ANIMAL_TYPE) as count from ANIMAL_INS where ANIMAL_TYPE = "Cat" or ANIMAL_TYPE = "Dog" group by ANIMAL_TYPE order by ANIMAL_TYPE asc;
select NAME,cnt as "COUNT" from(select NAME,count(NAME) as cnt from ANIMAL_INS group by NAME)tmp where cnt >= 2 order by NAME;
select HOUR(DATETIME) as time,count(HOUR(DATETIME)) as "COUNT" from ANIMAL_OUTS where HOUR(DATETIME) between 9 and 19 group by time order by time;

set @tmp = -1;
select HOUR,case when cnt is NULL then '0' else cnt end as COUNT from(
    (select HOUR(DATETIME) as HOUR,count(HOUR(DATETIME)) as cnt from ANIMAL_OUTS group by HOUR(DATETIME) order by HOUR(DATETIME))
union
    (select (@tmp := @tmp+1) as HOUR,NULL as cnt from ANIMAL_OUTS where @tmp < 23)
)tmp group by HOUR order by HOUR;