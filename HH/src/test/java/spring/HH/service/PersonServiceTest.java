package spring.HH.service;

import org.assertj.core.util.Lists;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.ArgumentMatcher;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;
import org.springframework.boot.test.context.SpringBootTest;
import spring.HH.domain.Birthday;
import spring.HH.domain.Person;
import spring.HH.domain.dto.PersonDto;
import spring.HH.repository.PersonRepository;

import java.time.LocalDate;
import java.util.List;
import java.util.Optional;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

@SpringBootTest
@ExtendWith(MockitoExtension.class)
class PersonServiceTest {

    @InjectMocks
    private PersonService personService;

    @Mock
    private PersonRepository personRepository;


    @Test
    public void getPeopleByName() {
        when(personRepository.findByName("martin"))
                .thenReturn(Lists.newArrayList(new Person("martin")));

        List<Person> result = personService.getPeopleByName("martin");

        assertThat(result.size()).isEqualTo(1);
        assertThat(result.get(0).getName()).isEqualTo("martin");
    }

    @Test
    public void getPerson() {
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        Person person = personService.getPerson(1L);

        assertThat(person.getName()).isEqualTo("martin");
    }

    @Test
    public void getPersonIfNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when
        Person person = personService.getPerson(1L);

        //then
        assertThat(person).isNull();
    }

    @Test
    public void put() {

        //when
        personService.put(mockPersonDto());

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeInserted()));

    }

    @Test
    public void modifyIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    public void modifyIfNameIsDifferent() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("tony")));

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    public void modify() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.modify(1L, mockPersonDto());

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeUpdated()));
    }

    @Test
    public void modifyByNameIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, "daniel"));
    }

    @Test
    public void modifyByName() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.modify(1L, "daniel");

        //then
        verify(personRepository, times(1)).save(argThat(new IsNameWillBeUpdated()));
    }

    @Test
    public void deleteIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //then
        assertThrows(RuntimeException.class, () -> personService.delete(1L));
    }

    @Test
    public void delete() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.delete(1L);

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeDeleted()));
    }

    private PersonDto mockPersonDto() {

        return PersonDto.of("martin", "programming", "pangyo", LocalDate.now(), "programmer", "010-1111-2222");
    }

    private static class IsPersonWillBeInserted implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return equals(person.getName(), "martin")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "pangyo")
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
            return equals(person.getName(), "martin")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "pangyo")
                    && equals(person.getBirthday(), Birthday.of(LocalDate.now()))
                    && equals(person.getJob(), "programmer")
                    && equals(person.getPhoneNumber(), "010-1111-2222");
        }

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
