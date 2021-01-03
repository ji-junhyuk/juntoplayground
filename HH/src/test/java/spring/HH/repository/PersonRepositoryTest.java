package spring.HH.repository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.jdbc.AutoConfigureTestDatabase;
import org.springframework.boot.test.autoconfigure.orm.jpa.DataJpaTest;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Person;
import spring.HH.domain.dto.Birthday;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.assertThat;

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    void crud() {

        //Given
        Person person = new Person();
        person.setName("junhyuk");

        personRepository.save(person);

        //When
        List<Person> result = personRepository.findByName("junhyuk");

        //Then
        assertThat(result.size()).isEqualTo(1);
        assertThat(result.get(0).getName()).isEqualTo("junhyuk");
//        assertThat(result.get(0).getAge()).isEqualTo(28);
    }

    @Test
    void findByBirthdayBetween() {

        //Given
        givenPerson("junhyuk", LocalDate.of(1994, 3, 3));
        givenPerson("Mary",  LocalDate.of(1993, 8, 15));
        givenPerson("jacop",  LocalDate.of(1995, 12, 31));
        givenPerson("sundae",  LocalDate.of(1997, 2, 11));
        givenPerson("sohee",  LocalDate.of(2000, 8, 7));

        //When
        List<Person> result = personRepository.findByMonthOfBirthday(3);

        //Then
        assertThat(result.size()).isEqualTo(1);
        assertThat(result.get(0).getAge()).isEqualTo(28);
    }

    private void givenPerson(String name, LocalDate birthday) {
        Person person = new Person(name);
        person.setBirthday(new Birthday(birthday));

        personRepository.save(person);
    }
}