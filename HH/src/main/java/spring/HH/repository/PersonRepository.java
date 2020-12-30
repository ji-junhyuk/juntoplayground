package spring.HH.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import spring.HH.domain.Person;

import java.time.LocalDate;
import java.util.List;

public interface PersonRepository extends JpaRepository<Person, Long> {

    List<Person> findByName(String name); //find = select, By = where, Name = argument

    List<Person> findByBlockIsNull();

    List<Person> findByBloodType(String bloodType);

    List<Person> findByBirthdayBetween(LocalDate startDate, LocalDate endDate);
}
