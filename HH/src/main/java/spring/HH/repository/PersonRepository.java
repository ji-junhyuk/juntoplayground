package spring.HH.repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import spring.HH.domain.Person;

public interface PersonRepository extends JpaRepository<Person, Long> {
}
