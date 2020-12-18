package spring.HH.repository;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.domain.Person;
import spring.HH.domain.dto.Birthday;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@Transactional
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

/*    @Test
    void crud() {
        Person person = new Person();
        person.setName("martin");
        person.setAge(10);
fddf
        personRepository.save(person);
        System.out.println("++++++++++++++++++++++++++++++++++++");
        System.out.println(personRepository.findAll());
        System.out.println("++++++++++++++++++++++++++++++++++++");

        List<Person> people = personRepository.findAll();

        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("martin");
        assertThat(people.get(0).getAge()).isEqualTo(10);
    }

    @Test
    void constructorTest() {
        Person person = new Person("martin", 10);*/
//        Person person = new Person(1L, "martin", 10, "Soccer", LocalDate.of(1994, 03, 03));
//    }

    @Test
    void hashCodeAndEquals() {
        Person person1 = new Person("martin", 10, "A");
        Person person2 = new Person("martin", 10, "A");

        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
        System.out.println(person2.hashCode());

        Map<Person, Integer> map = new HashMap<>();
        map.put(person1, person1.getAge());
        System.out.println("**********");
        System.out.println(map);
        System.out.println(map.get(person2));
    }
    private void givenPeople() {
        givenPerson("martin", 10, "A");
        givenPerson("david", 9, "B");
    }

    @Test
    public void findByBloodType() {

        //given
        givenPerson("martin", 10, "A");
        givenPerson("david", 9, "B");
        givenPerson("dennis", 8, "O");
        givenPerson("saphio", 7, "AB");
        givenPerson("benny", 7, "A");
        givenPerson("bob", 7, "A");

        List<Person> result = personRepository.findByBloodType("A");

        result.forEach(System.out::println);

//        System.out.println(result);
        //when

        //then
    }
    @Test
    public void findByBirthdayBetween() {

        //given
        givenPerson("martin", 10, "A", LocalDate.of(1991, 8, 30));
        givenPerson("david", 9, "B", LocalDate.of(1992, 2, 10));
        givenPerson("dennis", 8, "O", LocalDate.of(1993, 5, 4));
        givenPerson("saphio", 7, "AB", LocalDate.of(1994, 3, 3));
        givenPerson("benny", 7, "A", LocalDate.of(1996, 3, 3));

        List<Person> result = personRepository.findByMonthOfBirthday(8);

        result.forEach(System.out::println);

        //when

        //then
    }

    private void givenPerson(String name, int age, String bloodType) {
        givenPerson(name, age, bloodType, null);
    }

    private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(new Birthday(birthday));
        personRepository.save(person);
    }
}