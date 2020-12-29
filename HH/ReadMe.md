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

###이론 
* JPA사용을 위한 의존성 추가하기
  * spring-boot-starter-data-jpa : JPA사용을 위한 스프링부트 스타터
  * h2 : 간단하게 사용할 수 있는 초경량 메모리 DB
* JPA의 특징
  * DB의 종류에 상관없이 JPA문법에 따라서 로직을 생성할 수 있음
  * DB를 변경하더라도 JPA에서 해당 DB에 적합한 쿼리를 자동으로 변경생성해줌
* 주요 Annotation의 역할
  * @Entity : 해당 클래스가 Domain Entity로 사용할 것이라는 표식
  * @Id : 해당 컬럼이 Domain Entity의 Pk임을 명시함
  * @GeneratedValue : 해당 컬럼의 값은 자동으로 생성되는 값임을 명시함
    * GenerationType : TABLE, SEQUENCE, IDENTITY, AUTO (default)
* personRepository.save(person) 객체를 저장하고 System.out.println(personRepository.findAll(); 출력하게 되면 Person객체의 hashcode값이 출력된다. 이를 위해서 ToString을 사용함.

```java
@Entity
@Getter 
@Setter
@ToString
public class Person {

    @Id
    @GeneratedValue
    private Long id;

    private String name;

    private int age;
}

```java
@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    void crud() {

        //Given
        Person person = new Person();
        person.setName("junhyuk");
        person.setAge(28);

        personRepository.save(person);

//        System.out.println(personRepository.findAll());
        
        //When
        List<Person> people = personRepository.findAll();

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("junhyuk");
        assertThat(people.get(0).getAge()).isEqualTo(28);
    }
}
```

