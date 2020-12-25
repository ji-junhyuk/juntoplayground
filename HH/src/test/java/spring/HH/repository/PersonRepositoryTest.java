package spring.HH.repository;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Person;
import spring.HH.domain.dto.Birthday;

import java.time.LocalDate;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertAll;

@SpringBootTest
public class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    public void findByName() {

        //given
        List<Person> people = personRepository.findByName("tony");
        assertThat(people.size()).isEqualTo(1);

        //when
        Person person = people.get(0);

        //then
        assertAll(
                () -> assertThat(person.getName()).isEqualTo("tony"),
                () -> assertThat(person.getHobby()).isEqualTo("reading"),
                () -> assertThat(person.getAddress()).isEqualTo("seoul"),
                () -> assertThat(person.getBirthday()).isEqualTo(Birthday.of(LocalDate.of(1991, 7, 10))),
                () -> assertThat(person.getJob()).isEqualTo("officer"),
                () -> assertThat(person.getPhoneNumber()).isEqualTo("010-1111-2222")
        );
    }

    @Test
    public void findByNameIfDeleted() {

        //given
        List<Person> people = personRepository.findByName("andrew");

        //then
        assertThat(people.size()).isEqualTo(0);
    }

    @Test
    public void findByMonthOfBirthday() {

        //given
        List<Person> people = personRepository.findByMonthOfBirthday(7);

        //when
        assertThat(people.size()).isEqualTo(2);

        //then
        assertAll(
                () -> assertThat(people.get(0).getName()).isEqualTo("david"),
                () -> assertThat(people.get(1).getName()).isEqualTo("tony")
        );
    }

    @Test
    public void findPeopleDeleted() {

        //given
        List<Person> people = personRepository.findPeoPleDeleted();

        //when
        assertThat(people.size()).isEqualTo(1);

        //then
        assertThat(people.get(0).getName()).isEqualTo("andrew");
    }
}
