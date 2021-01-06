package spring.HH.service;

import org.assertj.core.util.Lists;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.controller.dto.PersonDto;
import spring.HH.domain.Person;
import spring.HH.repository.PersonRepository;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
@Transactional
class PersonServiceTest {

    @InjectMocks
    private PersonService personService;
    @Mock
    private PersonRepository personRepository;

    @Test
    void getPeoPleByName() {

        when(personRepository.findByName("junhyuk"))
                .thenReturn(Lists.newArrayList(new Person("junhyuk")));

        List<Person> result = personService.getPeopleByName("junhyuk");

        assertThat(result.size()).isEqualTo(1);
        assertThat(result.get(0).getName()).isEqualTo("junhyuk");
    }

    @Test
    void getPerson() {
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("junhyuk")));

        Person person = personService.getPerson(1L);

        assertThat(person.getName()).isEqualTo("junhyuk");
    }

    @Test
    void getPersonIfNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //When
        Person person = personService.getPerson(1L);

        //Then
        assertThat(person).isNull();
    }

    @Test
    void put() {

        //When
        personService.put(mockPersonDto());

        //Then
        verify(personRepository, times(1)).save(any(Person.class));
    }

    @Test
    void modifyIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modifyIfNameIsDifferent() {

        //When
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("tony")));

        //Then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modify() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("junhyuk")));

        //When
        personService.modify(1L, mockPersonDto());

        //Then
        verify(personRepository, times(1)).save(any(Person.class));
    }

    private PersonDto mockPersonDto() {

        return PersonDto.of("junhyuk", "programming", "seoul", LocalDate.now(), "programmer", "010-1111-1119");
    }
}