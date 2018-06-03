select Customers.Name 
as customers 
from Customers 
where Customers.Id 
not in 
(select Customers.Id 
from Customers, Orders 
where Customers.Id = Orders.CustomerId)
