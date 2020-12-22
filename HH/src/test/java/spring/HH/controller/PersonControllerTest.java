package spring.HH.controller;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.data.domain.Sort;
import org.springframework.http.MediaType;
import org.springframework.http.converter.json.MappingJackson2HttpMessageConverter;
import org.springframework.test.web.client.RequestMatcher;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.result.MockMvcResultHandlers;
import org.springframework.test.web.servlet.result.MockMvcResultMatchers;
import org.springframework.test.web.servlet.result.ModelResultMatchers;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import org.springframework.web.util.NestedServletException;
import spring.HH.domain.Birthday;
import spring.HH.domain.Person;
import spring.HH.domain.dto.PersonDto;
import spring.HH.repository.PersonRepository;

import java.time.LocalDate;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.log;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;
import static org.springframework.test.web.servlet.result.ModelResultMatchers.*;

@SpringBootTest
class PersonControllerTest {

    @Autowired
    private PersonController personController;

    @Autowired
    private PersonRepository personRepository;

    @Autowired
    private ObjectMapper objectMapper;

    @Autowired
    private MappingJackson2HttpMessageConverter messageConverter;

    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders
                .standaloneSetup(personController)
                .setMessageConverters(messageConverter)
                .alwaysDo(print())
                .build();
    }

    @Test
    public void getPerson() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("martin"))
                .andExpect(jsonPath("hobby").isEmpty())
                .andExpect(jsonPath("address").isEmpty())
                .andExpect(jsonPath("$.birthday").value("1991-08-15"))
                .andExpect(jsonPath("$.phoneNumber").isEmpty())
                .andExpect(jsonPath("$.deleted").value(false))
                .andExpect(jsonPath("$.age").isNumber())
                .andExpect(jsonPath("$.birthdayToday").isBoolean());
     }

     @Test
     public void postPerson() throws Exception {

         PersonDto dto = PersonDto.of("martin", "programming", "pangyo", LocalDate.now(), "programmer", "010-1111-2222");

         mockMvc.perform(
                 MockMvcRequestBuilders.post("/api/person")
                         .contentType(MediaType.APPLICATION_JSON)
                         .content(toJsonString(dto)))
                 .andExpect(status().isCreated());

         Person result = personRepository.findAll(Sort.by(Sort.Direction.DESC, "id")).get(0);

         assertAll(
                 () -> assertThat(result.getName()).isEqualTo("martin"),
                 () -> assertThat(result.getHobby()).isEqualTo("programming"),
                 () -> assertThat(result.getAddress()).isEqualTo("pangyo"),
                 () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                 () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-2222")
         );
     }

     @Test
     public void postPersonIfNameIsNull() throws Exception {

         //given
         PersonDto dto = new PersonDto();

         //when

         //then
         mockMvc.perform(
                 MockMvcRequestBuilders.post("/api/person")
                         .contentType(MediaType.APPLICATION_JSON)
                         .content(toJsonString(dto)))
                 .andExpect(jsonPath("$.code").value(500))
                 .andExpect(jsonPath("$.message").value("Cant be aware of server exception."));

      }
      @Test
      public void modifyPerson() throws Exception {

          PersonDto dto = PersonDto.of("martin", "programming", "pangyo", LocalDate.now(), "programmer", "010-1111-2222");

          mockMvc.perform(
                  MockMvcRequestBuilders.put("/api/person/1")
                          .contentType(MediaType.APPLICATION_JSON)
                          .content(toJsonString(dto)))
                  .andDo(print())
                  .andExpect(status().isOk());

          Person result = personRepository.findById(1L).get();

          assertAll(
                  () -> assertThat(result.getName()).isEqualTo("martin"),
                  () -> assertThat(result.getHobby()).isEqualTo("programming"),
                  () -> assertThat(result.getAddress()).isEqualTo("pangyo"),
                  () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                  () -> assertThat(result.getJob()).isEqualTo("programmer"),
                  () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-2222")
          );
      }

    @Test
    public void modifyPersonIfNameIsDifferent() throws Exception {

        PersonDto dto = PersonDto.of("james", "programming", "pangyo", LocalDate.now(), "programmer", "010-1111-2222");

        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/1")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Name change is not accepted."));
    }

    @Test
    public void modifyPersonIfPersonNotFound() throws Exception {

        //given
        PersonDto dto = PersonDto.of("martin", "programming", "판교", LocalDate.now(), "programmer", "010-1111-2222");

        //then
        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/10")
                        .contentType(MediaType.APPLICATION_JSON)
                        .contentType(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Person Entity is not exist."));
     }

       @Test
       public void modifyName() throws Exception {

           mockMvc.perform(
                   MockMvcRequestBuilders.patch("/api/person/1")
                           .param("name", "martinModified"))
                   .andDo(print())
                   .andExpect(status().isOk());

           assertThat(personRepository.findById(1L).get().getName()).isEqualTo("martinModified");
        }

        @Test
        public void deletePerson() throws Exception {

            mockMvc.perform(
                    MockMvcRequestBuilders.delete("/api/person/1"))
                    .andDo(print())
                    .andExpect(status().isOk());

            assertTrue(personRepository.findPeopleDeleted().stream().anyMatch(person -> person.getId().equals(1L)));
         }

    private String toJsonString(PersonDto personDto) throws JsonProcessingException {
        return objectMapper.writeValueAsString(personDto);
    }
}
