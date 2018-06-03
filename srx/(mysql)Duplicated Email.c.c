/////////////////////////////////////////第一种分组计数的方式，group by的位置一定要在having 前面，否则报错
select Email from Person group by Email having count(*) >1
///////////////////////////////////////第二种两对象对比的方式，distinct用来去除重复的值
select distinct p1.Email from Person p1, Person p2 where p1.Email=p2.Email and p1.Id<>p2.Id
