# Write your MySQL query statement below
select P.FirstName, P.LastName, A.city, A.State from  Person P left outer join Address A on A.PersonId=P.PersonId 
