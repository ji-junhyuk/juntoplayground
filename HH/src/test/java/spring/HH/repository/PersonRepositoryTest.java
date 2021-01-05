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
import static org.junit.jupiter.api.Assertions.assertAll;

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    void findByNmae() {
        List<Person> people = personRepository.findByName("tony");
        assertThat(people.size()).isEqualTo(1);

        Person person = people.get(0);
        assertAll(
                () -> assertThat(person.getName()).isEqualTo("tony"),
                () -> assertThat(person.getHobby()).isEqualTo("reading"),
                () -> assertThat(person.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(person.getBirthday()).isEqualTo(LocalDate.of(1994, 3, 3)),
                () -> assertThat(person.getJob()).isEqualTo("officer"),
                () -> assertThat(person.getPhoneNumber()).isEqualTo("010-1111-1234"),
                () -> assertThat(person.isDeleted()).isEqualTo(false)
        );
    }

    @Test
    void findByNameIfDeleted() {

        //When
        List<Person> people = personRepository.findByName("andrew");

        //Then
        assertThat(people.size()).isEqualTo(0);
    }

    @Test
    void findByMonthOfBirthday() {

        //Given
        List<Person> people = personRepository.findByMonthOfBirthday(8);

        //Then
        assertThat(people.size()).isEqualTo(2);
        assertAll(
                () -> assertThat(people.get(0).getName()).isEqualTo("david"),
                () -> assertThat(people.get(1).getName()).isEqualTo("tony")
        );
    }

    @Test
    void findPeopleDeleted() {

        //Given
        List<Person> people = personRepository.findPeopleDeleted();

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("andrew");
    }
}