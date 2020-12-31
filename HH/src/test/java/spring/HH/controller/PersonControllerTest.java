package spring.HH.controller;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;

import static org.junit.jupiter.api.Assertions.*;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@SpringBootTest
class PersonControllerTest {

    @Autowired
    private PersonController personController;

    private MockMvc mockMvc;

    @Test
    void getPerson() throws Exception {

        //Given
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();

        //Then
        mockMvc.perform(MockMvcRequestBuilders.get("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk());
    }

    @Test
    void postPerson() throws Exception {

        //Given
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
        .content("{\n" +
                "    \"name\": \"junhyuk\",\n" +
                "    \"age\": 20,\n" +
                "    \"bloodType\": \"B\"\n" +
                "}"))
                .andDo(print())
                .andExpect(status().isCreated());
    }
}