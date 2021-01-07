package spring.HH.controller;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import spring.HH.controller.dto.PersonDto;
import spring.HH.domain.Person;
import spring.HH.exception.PersonNotFoundException;
import spring.HH.exception.RenameIsNotPermittedException;
import spring.HH.exception.dto.ErrorResponse;
import spring.HH.repository.PersonRepository;
import spring.HH.service.PersonService;

@RestController
@RequestMapping(value = "/api/person")
@Slf4j
public class PersonController {

    @Autowired
    private PersonService personService;

    @GetMapping("/{id}")
    public Person getPerson(@PathVariable Long id) {

        return personService.getPerson(id);
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    //postPerson(Person person) no annotation, Use RequestParam
    public void postPerson(@RequestBody PersonDto personDto) {

        personService.put(personDto);
    }

    @PutMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, @RequestBody PersonDto personDto) {
        try {
            personService.modify(id, personDto);
        } catch (RuntimeException ex) {
            log.error(ex.getMessage(), ex);
        }
    }

    @PatchMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, String name) {
        personService.modify(id, name);
    }

    @DeleteMapping("/{id}")
    public void deletePerson(@PathVariable Long id) {
        personService.delete(id);
    }
}
