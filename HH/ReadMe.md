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
```java
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
```

## 이론
* @OneToOne
  * Entity를 1:1 관계로 연결해주는 어노테이션
  * `optional=false`이면 `inner join`으로 쿼리가 생성됨
  * `optional=true`로 하면 `left outer join`으로 쿼리가 생성됨

* cascade
  * 관련된 entity의 영속성을 함께 관리할 수 있도록 해줌
  * CascadeType.PERSIST
    * insert할 경우 관련 entity도 함께 insert함
  * CascadeType.MERGE 
    * update할 경우 관련 entity도 함께 update함
  * CascadeType.REMOVE 
    * delete할 경우 관련 entity도 함께 delete함
  * CascadeType.ALL
    * 모든 케이스에 대해 영속성을 함께 관리함
* orphanRemoval (default = false)
  * 관련 entity의 relation이 사라질 때, entity를 함께 삭제해줌

* fetch (default = EAGER)
  * FetchType.EAGER 
    * 항상 relation이 있는 entity를 join하여 값을 함께 가져옴
  * FetchType.LAZY 
    * 해당 객체가 필요한 시점에 id를 통해 새로 select해서 값을 가져옴


##### PersonServiceTest 보완(JPA Relation) //junhyuk이름을 가진 아이 한명만 차단
```java
public class Person {

    private boolean block; //delete

    private boolean blockReason; //delete

    private boolean blockStartDate; //delete

    private boolean blockEndDate; //delete

    @OneToOne
    private Block block;
}

@Service
public class PersonService {

    @Autowired
    private PersonRepository personRepository;
    
    public List<Person> getPeopleExcludeBlocks() {
        List<Person> people = personRepository.findAll();

        return people.stream().filter(person -> person.getBlock() == null).collect(Collectors.toList());
    }
}

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
        givenBlockPerson("junhyuk", 11, "AB");
    }

    private void givenBlocks() {
        givenBlock("junhyuk");
    }

    private void givenPerson(String name, int age, String bloodType) {
        personRepository.save(new Person(name, age, bloodType));
    }

    private void givenBlockPerson(String name, int age, String bloodType) {
        Person blockPerson = new Person(name, age, bloodType);
        blockPerson.setBlock(givenBlock(name));

        personRepository.save(blockPerson);
    }

    private Block givenBlock(String name) {
        return blockRepository.save(new Block(name));
    }
}
```

##### PersonServiceTest 에서 givenblock을 new Block으로 수정하면 TransientPropertyValueException 발생 (new Block)코드
```java
    private void givenBlockPerson(String name, int age, String bloodType) {
        Person blockPerson = new Person(name, age, bloodType);
        blockPerson.setBlock(new Block(name));

        personRepository.save(blockPerson);
    }
//추가로 givenBlock 관련 메소드(2) 삭제하도록 한다.
```


```java
public class Person {
    @OneToOne(cascade = CascadeType.PERSIST) // TransientPropertyValueException 해결, Person엔티티에서 block엔티티까지 함께 관리하겠다!
    private Block block;
}
```
##### PersonServiceTest에 casecadeTest 추가(casecade 동작원리를 알아보기 위해서) 

```java
    @Test
    void casecadeTest() {

        givenPeoPle();
        
        List<Person> result = personRepository.findAll();
        result.forEach(System.out::println);
        
        Person person = result.get(3);
        person.getBlock().setStartDate(LocalDate.now());
        person.getBlock().setEndDate(LocalDate.now());

        personRepository.save(person);
        personRepository.findAll().forEach(System.out::println);
    }


    @OneToOne(cascade = {CascadeType.PERSIST, CascadeType.MERGE})
    private Block block;

//MERGE를 추가하면 LocalDate.now 정보가 db에 반영된다.

        personRepository.delete(person);
        personRepository.findAll().forEach(System.out::println);
        blockRepository.findAll().forEach(System.out::println);

    @OneToOne(cascade = {CascadeType.PERSIST, CascadeType.MERGE, CascadeType.REMOVE})
    private Block block;

//Remove를 추가하면 blockRepository에 Remove한 person(3)이 반영된다.
```

##### cascadeTest에 OrphanRemoval 테스트
```java
    @Test
    void casecadeTest() {

        givenPeoPle();

        List<Person> result = personRepository.findAll();
        result.forEach(System.out::println);

        Person person = result.get(3);
        person.getBlock().setStartDate(LocalDate.now());
        person.getBlock().setEndDate(LocalDate.now());

        personRepository.save(person);
        personRepository.findAll().forEach(System.out::println);

//        personRepository.delete(person);
//        personRepository.findAll().forEach(System.out::println);
//        blockRepository.findAll().forEach(System.out::println);
 
        person.setBlock(null);
        personRepository.save(person);
        personRepository.findAll().forEach(System.out::println);
        blockRepository.findAll().forEach(System.out::println);
    }


    @OneToOne(cascade = CascadeType.ALL, orphanRemoval = true)
    private Block block;


//block이 해제되는 순간 blockRepository에도 반영된다. 불필요한 엔티티를 관리할 수 있게 된다.
```

##### fetch Test
```java
@Service
@Slf4j
public class PersonService {

    @Autowired
    private PersonRepository personRepository;

    public List<Person> getPeopleExcludeBlocks() {
        List<Person> people = personRepository.findAll();

        return people.stream().filter(person -> person.getBlock() == null).collect(Collectors.toList());
    }

    public Person getPerson(Long id) {
        Person person = personRepository.findById(id).get();

//        System.out.println("person = " + person);
        log.info("person: {}", person);
        
        return person;
    }
}
```

##### PersonServiceTest 에 getPerson Test 추가
```java
    @Test
    void getPerson() {

        //Given
        givenPeoPle();

        //When
        Person person = personService.getPerson(3L);

        //Then
        System.out.println(person);

    }
// PersonService에 추가한 log 형식에 맞춰 log가 출력되는 걸 확인할 수 있음.
// Eager 타입이기 때문에 left outer join으로 block문이 하나의 쿼리문으로 실행된 걸 확인할 수 있음.

public class Person {
    @OneToOne(cascade = CascadeType.ALL, orphanRemoval = true, fetch = FetchType.LAZY)
    private Block block;
}

public class PersonService {

    @Transactional(readOnly = true)
    public Person getPerson(Long id) {
        Person person = personRepository.findById(id).get();
    }
}
// Eager 타입을 LAZY타입으로 바꾸고, @Transactional 옵션을 추가하고 다시 getPerson Test를 실행시킴.
// select 문이 2개로 나누어서 동작한다. 하나는 from person으로 동작하고, 다른 하나는 from block 으로 동작함.
// Lazy를 하는 경우 실제로 Person객체를 호출할 때 block을 select를 하지 않고 block객체가 필요한 시점에 block id를 통해 select를 함.
// 여기서는 person과 block이 한번에 찍힌 이유는 log를 찍었기 때문에 person과 block이 한번에 호출된 것이다.
```

```java
    @OneToOne(cascade = CascadeType.ALL, orphanRemoval = true, fetch = FetchType.LAZY)
    @ToString.Exclude
    private Block block;
// person 쿼리 하나만 실행됨. block 쿼리는 실행되지 않음. 불필요한 쿼리 호출 줄이는 데 도움이 된다.
```

```java
    @OneToOne(cascade = CascadeType.ALL, orphanRemoval = true, fetch = FetchType.EAGER, optional = false)
    @ToString.Exclude
    private Block block;

// Eager로 변경하게 되면 left outer join으로 쿼리문이 실행됨
// optional 기본값은 true, false로 주게되면 block의 값이 항상 필요하다는 의미가 된다.

PersonServiceTest

    private void givenPeoPle() {
        givenBlockPerson("junhyuk", 10, "B");
        givenBlockPerson("david", 9, "B");
        givenBlockPerson("dennis", 7, "O");
        givenBlockPerson("junhyuk", 11, "AB");
    }
// Eager 타입으로 변경 시 left Outer join, 하지만 Optional=false 이기때문에 쿼리 문이 inner join으로 실행됨.
// Jpa는 몇 가지 옵션을 통해 자동적으로 쿼리가 생성됨. 옵션을 잘 사용하도록 하는 것이 중요.
// BlockPerson 2개 해제, fetch와 optional 삭제하여 원상복구함.
```

##### JPA Query Method (find = select, By = where ...)
[참조 링크](https://docs.spring.io/spring-data/jpa/docs/1.4.3.RELEASE/reference/htmlsingle/#repository-query-keywords "spring"으로 이동합니다.)

![image](https://user-images.githubusercontent.com/67992469/103324875-7c868680-4a8c-11eb-9880-f447cc4cc804.png)


