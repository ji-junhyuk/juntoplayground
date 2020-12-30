package spring.HH.service;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.domain.Block;
import spring.HH.domain.Person;
import spring.HH.repository.BlockRepository;
import spring.HH.repository.PersonRepository;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@Transactional
class PersonServiceTest {

    @Autowired
    private PersonService personService;
    @Autowired
    private PersonRepository personRepository;
    @Autowired
    private BlockRepository blockRepository;

    @Test
    void getPeopleExcludeBlocks() {

        //Given
        givenPeoPle();

        Block block = new Block();
        block.setName("junhyuk");
        blockRepository.save(block);


        //When
        List<Person> result = personService.getPeopleExcludeBlocks();

        //Then
        assertThat(result.size()).isEqualTo(2);
        assertThat(result.get(0).getName()).isEqualTo("junhyuk");
        assertThat(result.get(1).getName()).isEqualTo("david");
    }

    @Test
    void getPeoPleByName() {

        //Given
        givenPeoPle();

        //When
        List<Person> result = personService.getPeopleByName("dennis");

        //Then
        assertThat(result.size()).isEqualTo(1);
    }

    @Test
    void getPerson() {

        //Given
        givenPeoPle();

        //WhenExcludeBlock
        Person result = personService.getPerson(1L);

        //Then
        assertThat(result.getName()).isEqualTo("junhyuk");
    }

    private void givenPeoPle() {
        givenPerson("junhyuk", 10, "B");
        givenPerson("david", 9, "B");
        givenBlockPerson("dennis", 7, "O");
        givenBlockPerson("junhyuk", 11, "AB");
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