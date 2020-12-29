package spring.HH.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import spring.HH.exception.Person;

public interface PersonRepository extends JpaRepository<Person, Long> {
}
