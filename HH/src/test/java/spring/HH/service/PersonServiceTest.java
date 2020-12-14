package spring.HH.service;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Block;
import spring.HH.domain.Person;
import spring.HH.repository.BlockRepository;
import spring.HH.repository.PersonRepository;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class PersonServiceTest {

    @Autowired
    private PersonService personService;

    @Autowired
    private PersonRepository personRepository;

    @Autowired
    private BlockRepository blockRepository;

    @Test
    public void getPeopleExcludeBlocks() {

        //given
        givenPeople();

        //when
        List<Person> result = personService.getPeopleExcludeBlocks();
        System.out.println(result);

        //then
        result.forEach(System.out::println);
    }

    @Test
    public void cascadeTest() {

        //given
        givenPeople();
        //when
        List<Person> result = personRepository.findAll();

        //then
        System.out.println("=====================");
        System.out.println(result);
        System.out.println("=====================");
        result.forEach(System.out::println);

        Person person = result.get(3);
        person.getBlock().setStartDate(LocalDate.now());
        person.getBlock().setEndDate(LocalDate.now());

        personRepository.save(person);
        personRepository.findAll().forEach(System.out::println);

/*
        personRepository.delete(person);
        personRepository.findAll().forEach(System.out::println);
        blockRepository.findAll().forEach(System.out::println);
*/
        person.setBlock(null);
        personRepository.save(person);
        personRepository.findAll().forEach(System.out::println);
        blockRepository.findAll().forEach(System.out::println);
    }

    @Test
    public void getPerson() {

        //given
        givenPeople();

        //when
        Person person = personService.getPerson(3L);

        //then
        System.out.println(person);
    }

    private void givenPeople() {
        givenPerson("martin", 10, "A");
        givenPerson("david", 9, "B");
        givenBlockPerson("dennis", 7, "O");
        givenBlockPerson("martin", 11, "AB");
    }

    private void givenPerson(String name, int age, String bloodType) {
        personRepository.save(new Person(name, age, bloodType));
    }

    private void givenBlockPerson(String name, int age, String bloodType) {
        Person blockPerson = new Person(name, age, bloodType);
        blockPerson.setBlock(new Block(name));

        personRepository.save(blockPerson);
    }

}