package spring.HH.controller;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.*;
import spring.HH.domain.Person;
import spring.HH.repository.PersonRepository;
import spring.HH.service.PersonService;

@RestController
@RequestMapping(value = "/api/person")
@Slf4j
public class PersonController {

    @Autowired
    private PersonService personService;

    @Autowired
    private PersonRepository personRepository;

    @GetMapping(value = "{id}")
    public Person getPerson(@PathVariable Long id) {

        return personService.getPerson(id);
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    //postPerson(Person person) no annotation, Use RequestParam
    public void postPerson(@RequestBody Person person) {

        personService.put(person);

        log.info("person -> {}", personRepository.findAll());
    }
}
