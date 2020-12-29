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

## 이론 
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

* Lombok의 필요성
  * 자바 코드에서 필요한 기본 메소드들을 자동으로 생성해줌
  * 특히, entity는 반복적인 생성자, Getter, Setter들을 많이 생성하게 되어 Lombok이 유용함
* @Getter
  * getter는 class의 field variable의 값에 접근할 수 있는 메소드임
  * @Getter를 선언하면 기본 getter를 생성해줌
  * @Getter는 각 field variable에 선언할 수도 있고, class 상단에 선언할 수도 있음
* @Setter
  * setter는 class의 field variable의 값을 저장할 수 있는 메소드임
  * @Setter를 선언하면 기본 setter을 생성ㅇ해줌
  * @Setter는 각 field variable에 선언할 수도 있고, class 상단에 선언할 수도 있음
* @ToString
  * toString()은 기본적으로 해당 객체를 출력할 수 있도록 최상위 Object 객체에 선언되어 있음
  * toString()을 override하여 자신이 원하는 값을 출력할 수 있도록 커스터마이징 할 수 있음
  * Object 객체의 toString()은 해당 객체의 해쉬값을 출력하기 때문에, 일반적으로 toString()은 override 해야만 함
  * @ToString을 사용하면, 일반적으로 사용하는 방식의 toString()을 자동으로 생성해줌
  
* @NoArgsConstructor
  * 아무런 파라미터를 가지지 않은 생성자를 생성해줌
* @AllArgsConstructor
  * 전체 field variable을 파라미터로 가지는 생성자를 생성해줌
* @RequiredArgsConstructor
  * 필요한 field variable을 @NonNull로 선언하고, 해당 파라미터를 가지는 생성자를 생성해줌
* @EqualsAndHashCode
  * HashCode : 해시코드가 동일하면, 같은 객체라는 것을 의미함
  * Equal : 해당 객체가 같은 값을 가지고 있다는 것을 의미함
* @Data
  * @Getter @Setter @RequiredArgsConstructor @ToString @EqualsAndHashCode를 한꺼번에 선언해줌  
  
```java
@Entity
@NoArgsConstructor
@AllArgsConstructor
@RequiredArgsConstructor
@Data //Getter, Setter, ToString, EqualsAndHashcode, RequiredArgsConstructor
public class Person {

    @Id
    @GeneratedValue
    private Long id;
    
    @NonNull
    private String name;
    
    @NonNull
    private int age;
    
    private String hobby;
    
    @NonNull
    private String bloodType;

    private String address;

    private LocalDate birthday;

    private String job;

    @ToString.Exclude
    private String phoneNumber;
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

        System.out.println(personRepository.findAll());
        
        //When
        List<Person> people = personRepository.findAll();

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("junhyuk");
        assertThat(people.get(0).getAge()).isEqualTo(28);
    }

    @Test
    void hashCodeAndEquals() {
    
        Person person1 = new Person("junhyuk", 28, "A");
        Person person2 = new Person("junhyuk", 28, "A");

        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
        System.out.println(person2.hashCode());

        Map<Person, Integer> map = new HashMap<>();
        map.put(person1, person1.getAge());

        System.out.println(map);
        System.out.println(map.get(person2));
    }
}
```

## 참고
##### bloodType에 @NonNull을 추가하고 person1, 2 혈액형 값을 다르게 주었을 때, 구현누락으로 해당 객체가 같다고 출력된다.
Person
```java
    @ToString.Exclude
    private String phoneNumber;

    public boolean equals(Object object) {
        if (object == null) {
            return false;
        }

        Person person = (Person) object;

        if (!person.getName().equals(this.getName())) {
            return false;
        }
        if (person.getAge() != this.getAge()) {
            return false;
        }
        return true;
    }

    public int hashCode() {
        return (name + age).hashCode();
    }

    @Test
    void hashCodeAndEquals() {
    
        Person person1 = new Person("junhyuk", 28, "A");
        Person person2 = new Person("junhyuk", 28, "B");

        System.out.println(person1.equals(person2));
        System.out.println(person1.hashCode());
        System.out.println(person2.hashCode());

        Map<Person, Integer> map = new HashMap<>();
        map.put(person1, person1.getAge());

        System.out.println(map);
        System.out.println(map.get(person2));
    }
```

##### Person 
```java
    private boolean block;

    private boolean blockReason;

    private boolean blockStartDate;

    private boolean blockEndDate;
```

##### Block
```java
@Entity
@Data

    @Id
    @GeneratedValue
    private Long id;

    private String name;

    private String reason;

    private LocalDate startDate;

    private LocalDate endDate;
```

##### BlockRepository
```java
public interface BlockRepository extends JpaRepository<Block, Long> {
}
```

##### BlockRepositoryTest
```java
@SpringBootTest
class BlockRepositoryTest {

    @Autowired
    private BlockRepository blockRepository;

    @Test
    void crud() {

        //Given
        Block block = new Block();
        block.setName("junhyuk");
        block.setReason("so awesome");
        block.setStartDate(LocalDate.now());
        block.setEndDate(LocalDate.now());

        blockRepository.save(block);

        //When
        List<Block> blocks = blockRepository.findAll();

        //Then
        assertThat(blocks.size()).isEqualTo(1);
        assertThat(blocks.get(0).getName()).isEqualTo("junhyuk");
    }
```

##### PersonService
```java
@Service
public class PersonService {

    @Autowired
    private PersonRepository personRepository;
    @Autowired
    private BlockRepository blockRepository;

    public List<Person> getPeopleExcludeBlocks() {
        List<Person> people = personRepository.findAll();
        List<Block> blocks = blockRepository.findAll();

        List<String> blockNames = blocks.stream().map(Block::getName).collect(Collectors.toList());

        return people.stream().filter(person -> !blockNames.contains(person.getName())).collect(Collectors.toList());
    }
}
```

##### PersonServiceTest
```java
@SpringBootTest
class PersonServiceTest {

    @Autowired
    private PersonService personService;
    @Autowired
    private PersonRepository personRepository;
    @Autowired
    private BlockRepository blockRepository;

    @Test
    void getPeopleExcludeBlocks() {

        //Given
        givenPeoPle();
        givenBlocks();

        //When
        List<Person> result = personService.getPeopleExcludeBlocks();

        //Then
//        System.out.println(result);
        result.forEach(System.out::println);
    }

    private void givenPeoPle() {
        givenPerson("junhyuk", 10, "B");
        givenPerson("david", 9, "B");
        givenPerson("dennis", 7, "O");
        givenPerson("junhyuk", 11, "AB");
    }

    private void givenBlocks() {
        givenBlock("junhyuk");
    }

    private void givenPerson(String name, int age, String bloodType) {
        personRepository.save(new Person(name, age, bloodType));
    }

    private void givenBlock(String name) {
        blockRepository.save(new Block(name));
    }
}
//해당 getPeolpleExcludeBlocks를 실행하면 junhyuk이름을 가진 아이 둘 다 차단된다.
```

##### Block
@Entity
@Data
@RequiredArgsConstructor // add (PersonRepositoryTest에서 name을 인자로 가지는 생성자가 있기 때문에, name에도 NonNull)
@NoArgsConstructor // add (전에 사용하던 NoArgsContructor가 있기때문에, BlockRespositoryTest 에서 new Block (기본생성자)
public class Block {

    @Id
    @GeneratedValue
    private Long id;

    @NonNull
    private String name;

    private String reason;

    private LocalDate startDate;

    private LocalDate endDate;
}
