package spring.HH.repository;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Person;

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
        person.setAge(28);
        person.setBloodType("B");

        personRepository.save(person);

        System.out.println(personRepository.findAll());

        //When
        List<Person> people = personRepository.findAll();

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("junhyuk");
        assertThat(people.get(0).getAge()).isEqualTo(28);
    }
    
    @Test
    void hashCodeAndEquals() {
    
        Person person1 = new Person("junhyuk", 28, "A");
        Person person2 = new Person("junhyuk", 28, "A");

        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
        System.out.println(person2.hashCode());

        Map<Person, Integer> map = new HashMap<>();
        map.put(person1, person1.getAge());

        System.out.println(map);
        System.out.println(map.get(person2));
    }

    @Test
    void findByBloodType() {

        //Given
        givenPerson("junhyuk", 28, "B");
        givenPerson("Mary", 29, "A");
        givenPerson("jacop", 27, "O");
        givenPerson("sundae", 25, "AB");
        givenPerson("sohee", 22, "A");

        //When
        List<Person> result = personRepository.findByBloodType("A");

        //Then
        result.forEach(System.out::println);
    }

    @Test
    void findByBirthdayBetween() {

        //Given
        givenPerson("junhyuk", 28, "B", LocalDate.of(1994, 3, 3));
        givenPerson("Mary", 29, "A", LocalDate.of(1993, 8, 15));
        givenPerson("jacop", 27, "O", LocalDate.of(1995, 12, 31));
        givenPerson("sundae", 25, "AB", LocalDate.of(1997, 2, 11));
        givenPerson("sohee", 22, "A", LocalDate.of(2000, 8, 7));

        //When
        List<Person> result = personRepository.findByBirthdayBetween(LocalDate.of(1993, 1, 1), LocalDate.of(2000, 12, 31));

        //Then
        result.forEach(System.out::println);
    }

    private void givenPerson(String name, int age, String bloodType) {
        givenPerson(name, age, bloodType, null);
    }

    private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(birthday);

        personRepository.save(person);
    }
}