configuration

&nbsp;&nbsp;  JsonConfig
&nbsp;&nbsp; - serializer
  
&nbsp;&nbsp;&nbsp;BirthdaySerializer


controller

 &nbsp;&nbsp; HelloWorldController(test)
  
&nbsp;&nbsp;  PersonController(test)
  
  GroupController
  
 
domain

 &nbsp;&nbsp; Person
  
 &nbsp;&nbsp; Group
  
 &nbsp;&nbsp; - dto
  
  &nbsp;&nbsp;&nbsp;  Birthday
    
    
exception

  &nbsp;&nbsp;GlobalExceptionHandler
  
  &nbsp;&nbsp;PersonNotFoundException
  
 &nbsp;&nbsp;RenameIsnotPermitted
  
  &nbsp;&nbsp;- dto
  
  &nbsp;&nbsp;&nbsp;  ErrorResponse
   
   
repository

  &nbsp;&nbsp; PersonRepository(test)
  
  
service

  &nbsp;&nbsp; PersonService(test)
  
  
etc. (data.sql, hello.http)
