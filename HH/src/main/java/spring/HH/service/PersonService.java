package spring.HH.service;

import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.controller.dto.PersonDto;
import spring.HH.domain.Person;
import spring.HH.repository.PersonRepository;

import java.util.List;

@Service
@Slf4j
public class PersonService {

    @Autowired
    private PersonRepository personRepository;

    public List<Person> getPeopleByName(String name) {

        return personRepository.findByName(name);
    }

    @Transactional(readOnly = true)
    public Person getPerson(Long id) {

        Person person = personRepository.findById(id).orElse(null);

        log.info("person: {}", person);

        return person;
    }

    @Transactional
    public void put(PersonDto personDto) {
        Person person = new Person();
        person.set(personDto);
        person.setName(personDto.getName());

        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, PersonDto personDto) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        if (!person.getName().equals(personDto.getName())) {
            throw new RuntimeException("Name is different.");
        }

        person.set(personDto);

        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, String name) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        person.setName(name);

        personRepository.save(person);
    }

    @Transactional
    public void delete(Long id) {
//        One way
//        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));
//        personRepository.delete(person);

//        Two way
//        personRepository.deleteById(id);

        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        person.setDeleted(true);

        personRepository.save(person);
    }
}
