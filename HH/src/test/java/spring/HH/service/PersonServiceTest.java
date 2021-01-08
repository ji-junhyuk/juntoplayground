package spring.HH.service;

import org.assertj.core.util.Lists;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentMatcher;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageImpl;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;
import org.springframework.transaction.annotation.Transactional;
import spring.HH.controller.dto.PersonDto;
import spring.HH.domain.Person;
import spring.HH.domain.dto.Birthday;
import spring.HH.exception.PersonNotFoundException;
import spring.HH.exception.RenameIsNotPermittedException;
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
    void getAll() {

        //Given
        when(personRepository.findAll(any(Pageable.class)))
                .thenReturn(new PageImpl<>(Lists.newArrayList(new Person("martin"), new Person("je"), new Person("nunu"))));

        //When
        Page<Person> result = personService.getAll(PageRequest.of(0, 3));

        //Then
        assertThat(result.getNumberOfElements()).isEqualTo(3);
        assertThat(result.getContent().get(0).getName()).isEqualTo("martin");
        assertThat(result.getContent().get(1).getName()).isEqualTo("je");
        assertThat(result.getContent().get(2).getName()).isEqualTo("nunu");
    }

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
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeInserted()));
    }

    @Test
    void modifyIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(PersonNotFoundException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modifyIfNameIsDifferent() {

        //When
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("tony")));

        //Then
        assertThrows(RenameIsNotPermittedException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modify() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("junhyuk")));

        //When
        personService.modify(1L, mockPersonDto());

        //Then
//        verify(personRepository, times(1)).save(any(Person.class));
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeUpdated()));
    }

    @Test
    void modifyByNameIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(PersonNotFoundException.class, () -> personService.modify(1L, "daniel"));
    }

    @Test
    void modifyByName() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //When
        personService.modify(1L, "daniel");

        //then
        verify(personRepository, times(1)).save(argThat(new IsNameWillBeUpdated()));
    }

    @Test
    void deleteIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(PersonNotFoundException.class, () -> personService.delete(1L));
    }

    @Test
    void delete() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //When
        personService.delete(1L);

        //Then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeDeleted()));
    }

    private PersonDto mockPersonDto() {

        return PersonDto.of("junhyuk", "programming", "seoul", LocalDate.now(), "programmer", "010-1111-1119");
    }

    private static class IsPersonWillBeInserted implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return equals(person.getName(), "junhyuk")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "seoul")
                    && equals(person.getBirthday(), Birthday.of(LocalDate.now()))
                    && equals(person.getJob(), "programmer")
                    && equals(person.getPhoneNumber(), "010-1111-2222");
        }

        private boolean equals(Object actual, Object expected) {
            return expected.equals(actual);
        }
    }

    private static class IsPersonWillBeUpdated implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return equals(person.getName(), "junhyuk")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "seoul")
                    && equals(person.getBirthday(), Birthday.of(LocalDate.now()))
                    && equals(person.getJob(), "programmer")
                    && equals(person.getPhoneNumber(), "010-1111-2222");
        }

        // NullpointerException
        private boolean equals(Object actual, Object expected) {
            return expected.equals(actual);
        }
    }

    private static class IsNameWillBeUpdated implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return person.getName().equals("daniel");
        }
    }

    private static class IsPersonWillBeDeleted implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return person.isDeleted();
        }
    }
}