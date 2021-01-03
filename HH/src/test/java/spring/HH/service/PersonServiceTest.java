package spring.HH.service;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.domain.Person;
import spring.HH.repository.PersonRepository;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

@SpringBootTest
@Transactional
class PersonServiceTest {

    @Autowired
    private PersonService personService;
    @Autowired
    private PersonRepository personRepository;

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
        givenPerson("junhyuk");
        givenPerson("david");
    }

    private void givenPerson(String name) {
        personRepository.save(new Person(name));
    }
}