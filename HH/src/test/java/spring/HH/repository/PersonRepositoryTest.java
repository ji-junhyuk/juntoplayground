package spring.HH.repository;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Person;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    public void crud() {

        //given
        Person person = new Person();
        person.setName("martin");
        person.setAge(10);
        person.setBloodType("A");

        personRepository.save(person);

        System.out.println("==========================");
        System.out.println(personRepository.findAll());
        System.out.println("==========================");

        //when
        List<Person> people = personRepository.findAll();

        //then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("martin");
        assertThat(people.get(0).getAge()).isEqualTo(10);
        assertThat(people.get(0).getBloodType()).isEqualTo("A");
    }

    @Test
    public void hashCodeAndEquals() {

        //given
        Person person1 = new Person("marin", 10, "A");
        Person person2 = new Person("marin", 10, "A");

        System.out.println("========================");
        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
        System.out.println(person2.hashCode());
        System.out.println("========================");

        //when
        Map<Person, Integer> map = new HashMap<>();
        map.put(person1, person1.getAge());

        System.out.println(map);
        System.out.println(map.get(person2));

        //then
    }
}