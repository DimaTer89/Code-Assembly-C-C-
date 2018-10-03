14.	Сделать выборку содержащую: id линии, id сотрудника, чаще других отвечавших на звонки линии, количество звонков этого сотрудника на этой линии.

--Создаю таблицу для данных
create table temp
(
id  int  NOT NULL,
id_Сотрудника int NOT NULL,
Количество_Звонков int NOT NULL,
);
--Заполняю таблицу 
insert into temp (id,id_Сотрудника,Количество_Звонков)
select л.id, сл.Сотрудник, count(з.Сотрудник) Количество_Звонков
from Линии л, Сотрудники_Линии сл, Звонки з,Сотрудники с
where с.id=сл.Сотрудник and л.id=сл.Линия and з.Сотрудник=с.id and л.id=з.Линия
group by л.id,сл.Сотрудник
  
--Делаю выборку из новой таблицы
select t.id,t.id_Сотрудника,t.Количество_Звонков
from temp t
inner join
(
select id,max(Количество_Звонков) Количество_Звонков
from temp 
group by id
)tt on t.id=tt.id and t.Количество_Звонков=tt.Количество_Звонков
group by t.id,t.id_Сотрудника,t.Количество_Звонков

15.	Сделать выборку содержащую: Название должности, Среднее время ответа, Среднее время Разговора, Среднее время удержания.


select д.Имя,
cast(cast(avg(cast(CAST(з.Время_ответа as datetime) as float)) as datetime) as time) Среднее_Время_Ответа,
cast(cast(avg(cast(CAST(з.Время_разговора as datetime) as float)) as datetime) as time) Среднее_Время_Разговора,
cast(cast(avg(cast(CAST(з.Время_удержания as datetime) as float)) as datetime) as time) Среднее_Время_Удержания
from Должности д,Звонки з
where д.id=з.Сотрудник
group by д.Имя
order by д.Имя
