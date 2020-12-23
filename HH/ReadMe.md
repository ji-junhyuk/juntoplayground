configuration

  JsonConfig
  - serializer
  
    BirthdaySerializer

controller
  HelloWorldController(test)
  PersonController(test)
  GroupController
  -dto
    PersonDto
    
domain
  Person
  Group
  -dto
    Birthday
    
exception
  GlobalExceptionHandler
  PersonNotFoundException
  RenameIsnotPermitted
  -dto
    ErrorResponse
   
repository
  PersonRepository(test)
  
service
  PersonService(test)
  
etc. (data.sql, hello.http)
