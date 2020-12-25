package spring.HH.controller;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import org.springframework.web.context.WebApplicationContext;

import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@SpringBootTest
public class HelloWorldControllerTest {

    @Autowired
    private WebApplicationContext wac;

    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders
                .webAppContextSetup(wac)
                .alwaysDo(print())
                .build();
    }

    @Test
    public void helloWorld() throws Exception {

        //then
        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloWorld"))
                .andExpect(status().isOk())
                .andExpect(content().string("HelloWorld"));
     }

     @Test
     public void mockMvcTest() throws Exception {

         //then
         mockMvc.perform(MockMvcRequestBuilders.get("/api/helloException"))
                 .andExpect(status().isInternalServerError())
                 .andExpect(jsonPath("$.code").value(500))
                 .andExpect(jsonPath("$.message").value("An unknown server error occurred."));
      }
}