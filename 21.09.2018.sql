select rootid,name,max(price) as maxprice
from warecards2
group by rootid,name
order by maxprice desc
======================
insert into warecards4 
select rootid,name,dimid,price/1000 ,groupid,weight,postname,prodcountryid
from warecards2
where prodcountryid in('РБ')
======================
update warecards4 
set weight=1
where weight is null and dimid='кг'
======================
insert into warecards4 
select rootid,name,dimid,price/1000 ,groupid,weight,postname,prodcountryid
from warecards2
where prodcountryid in('РБ')

truncate table warecards4

select * from warecards4


update warecards4 
set weight=1
where weight is null and dimid='кг'


begin tran 

select * from warecards4
where weight is null and dimid='кг'


rollback tran

commit
=============================================
insert into warecards4 
select rootid,name,dimid,price/1000 ,groupid,weight,postname,prodcountryid
from warecards2
where prodcountryid in('РБ')

truncate table warecards4

select * from warecards4


update warecards4 
set weight=1
where weight is null and dimid='кг'


begin tran 

select * from warecards4
where weight is null and dimid='кг'


rollback tran

commit

select * from warecards2

select * from step_l2.dbo.warecards2

select * from warecards



insert into warecards (name,price,remark)
select name,price,postname
from step_l2.dbo.warecards2

use step_l1
