package spring.HH.controller;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.client.RequestMatcher;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.result.MockMvcResultHandlers;
import org.springframework.test.web.servlet.result.MockMvcResultMatchers;
import org.springframework.test.web.servlet.result.ModelResultMatchers;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import spring.HH.repository.PersonRepository;

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

    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();
    }

    @Test
    public void getPerson() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("martin"));
     }

     @Test
     public void postPerson() throws Exception {

         mockMvc.perform(
                 MockMvcRequestBuilders.post("/api/person")
                         .contentType(MediaType.APPLICATION_JSON_UTF8)
                         .content("{\n"
                                 + "  \"name\": \"martin2\",\n"
                                 + "  \"age\": 20,\n"
                                 + "  \"bloodType\": \"A\"\n"
                                 + "}"))
                 .andDo(print())
                 .andExpect(status().isCreated());
      }

      @Test
      public void modifyPerson() throws Exception {

          mockMvc.perform(
                  MockMvcRequestBuilders.put("/api/person/1")
                          .contentType(MediaType.APPLICATION_JSON)
                          .content("{\n"
                                  + "  \"name\": \"martin\",\n"
                                  + "  \"age\": 20,\n"
                                  + "  \"bloodType\": \"A\"\n"
                                  + "}"))
                  .andDo(print())
                  .andExpect(status().isOk());
       }

       @Test
       public void modifyName() throws Exception {

           mockMvc.perform(
                   MockMvcRequestBuilders.patch("/api/person/1")
                           .param("name", "martin22"))
                   .andDo(print())
                   .andExpect(status().isOk());
        }

        @Test
        public void deletePerson() throws Exception {

            //given
            mockMvc.perform(
                    MockMvcRequestBuilders.delete("/api/person/1"))
                    .andDo(print())
                    .andExpect(status().isOk());

//            log.info("people deleted : {}", personRepository.findPeopleDeleted());
         }
}