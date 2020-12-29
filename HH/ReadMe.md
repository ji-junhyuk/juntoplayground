### Controller 생성

```java
@RestController
public class HelloWorldController {

	@GetMapping(value = "/api/helloWorld")
	public String helloWorld() {
		return "HelloWorld";
	}
}
```

### Embedded WAS(Web Application Server)

```zsh
./gradlew bootRun
```

### Test by .http

test/../hello.http
```
GET http://localhost:8080/api/helloWorld
```

### HelloWorldController Test
```java
@SpringBootTest
class HelloWorldControllerTest {

    @Autowired
    private HelloWorldController helloWorldController;

    private MockMvc mockMvc;

    @Test
    public void helloWorld() {

        assertThat(helloWorldController.helloWorld()).isEqualTo("HelloWorld");
    }

    @Test
    void mockMvcTest() throws Exception {

        //Given
        mockMvc = MockMvcBuilders.standaloneSetup(helloWorldController).build();

        //then
        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloWorld"))
                .andDo(MockMvcResultHandlers.print())
                .andExpect(MockMvcResultMatchers.status().isOk())
                .andExpect(MockMvcResultMatchers.content().string("HelloWorld"));
    }
}
```
