package spring.HH.repository;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Person;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

/*    @Test
    void crud() {
        Person person = new Person();
        person.setName("martin");
        person.setAge(10);

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
}