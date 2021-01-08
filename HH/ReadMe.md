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
[참조 링크](https://docs.spring.io/spring-data/jpa/docs/1.4.3.RELEASE/reference/htmlsingle/#repository-query-keywords "spring")

![image](https://user-images.githubusercontent.com/67992469/103324875-7c868680-4a8c-11eb-9880-f447cc4cc804.png)

##### PersonServiceTest
```java
    @Test
    void getPeoPleByName() {
    
        //Given
        givenPeoPle();
        
        //When
        List<Person> result = personService.getPeopleByName("junhyuk");
        
        //Then
        result.forEach(System.out::println);
    }
```
##### PersonService
```java
    public List<Person> getPeopleByName(String name) {
        List<Person> people = personRepository.findAll();

        return people.stream().filter(person -> person.getName().equals(name)).collect(Collectors.toList());
    }
// personServiceTest에 getPeopleByName 테스트 실행하면 junhyuk이름을 가진 2명이 출력되는 걸 확인.
```

##### PersonRepository 사용
```java
public interface PersonRepository extends JpaRepository<Person, Long> {

    List<Person> findByName(String name); //find = select, By = where, Name = argument
}
```

##### PersonService 수정
```java
    public List<Person> getPeopleByName(String name) {

        return personRepository.findByName(name);
    }
```

### PersonServiceTest
```java
    void getPeopleExcludeBlocks() {

        //Given
        givenPeoPle();

        //When
        List<Person> result = personService.getPeopleExcludeBlocks();

        //Then
//        System.out.println(result);
        result.forEach(System.out::println);
    }
```

##### PersonRepository 사용
```java
List<Person> findByBlockIsNull();
```

### PersonService 수정
```java
    public List<Person> getPeopleExcludeBlocks() {
//        List<Person> people = personRepository.findAll();
//        return people.stream().filter(person -> person.getBlock() == null).collect(Collectors.toList());
        return personRepository.findByBlockIsNull();
    }
```

##### PersonRepository 사용
```java
    List<Person> findByBloodType(String bloodType);
```

##### PersonRepositoryTest 
```java
    @Test
    void findByBloodType() {

        //Given
        givenPerson("junhyuk", 28, "B");
        givenPerson("Mary", 29, "A");
        givenPerson("jacop", 27, "O");
        givenPerson("sundae", 25, "AB");
        givenPerson("sohee", 22, "A");

        //When
        List<Person> result = personRepository.findByBloodType("A");

        //Then
        result.forEach(System.out::println);
    }

    private void givenPerson(String name, int age, String bloodType) {
        personRepository.save(new Person(name, age, bloodType));
    }
}
```

##### PersonRepository 사용
```java
List<Person> findByBirthdayBetween(LocalDate startDate, LocalDate endDate);
```

##### PersonRepositoryTest
```java
    @Test
    void findByBirthdayBetween() {

        //Given
        givenPerson("junhyuk", 28, "B", LocalDate.of(1994, 3, 3));
        givenPerson("Mary", 29, "A", LocalDate.of(1993, 8, 15));
        givenPerson("jacop", 27, "O", LocalDate.of(1995, 12, 31));
        givenPerson("sundae", 25, "AB", LocalDate.of(1997, 2, 11));
        givenPerson("sohee", 22, "A", LocalDate.of(2000, 8, 7));

        //When
        List<Person> result = personRepository.findByBirthdayBetween(LocalDate.of(1993, 1, 1), LocalDate.of(2000, 12, 31));

        //Then
        result.forEach(System.out::println);
    }

//Method Overriding 

    private void givenPerson(String name, int age, String bloodType) {  
        givenPerson(name, age, bloodType, null);
    }

    private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(birthday);

        personRepository.save(person);
    }
}
```
## 8월 생일인 사람을 축하해주기 위해 8월생을 찾을려면 어떻게 테스트 로직을 만들어야할까? (LocalDate는 년/월/일 입력
## 이론
* @Embedded
  * 다른 객체를 Entity의 속성으로 가져옴
* @Embeddable
  * 자기 객체를 다른 Entity의 속성으로 사용할 수 있음
* @Query
  * Naming 컨벤션에 따라 생성되는 쿼리가 아니라, 커스터마이징된 쿼리를 직접 지정하여 생성함
  * ?1 (숫자)를 통해서 parameter를 순서대로 주입하여 사용할 수 있음
  * @Param("A")으로 parameter를 받게 되면, :A로 파라미터를 주입하여 사용할 수 있음
  * `nativeQuery=true`를 사용하게 되면, JPQL이 아니라 써준 그대로 네이티브 쿼리를 생성해줌
* @Valid
  * 해당 객체의 유효성을 검토하겠다는 것을 의미함
* @Min
  * 숫자관련 필드에서 최소값은 얼마인지 정의함
* @Max
  * 숫자관련 필드에서 최대값은 얼마인지 정의함

##### domain/dto Birthday
```java
@Embeddable
@AllArgsConstructor
@NoArgsConstructor
@Data
public class Birthday {
    
    private int yearOfBirthday;
    private int monthOfBirthday;
    private int dayOfBirthday;
}
```
##### Person
```java
@Embedded
private Birthday birthday;
```

##### PersonRepositoryTest
```java
    private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(new Birthday(birthday.getYear(), birthday.getMonthValue(), birthday.getDayOfMonth()));

        personRepository.save(person);
    }
```

##### PersonRepositoryTest  
```java
    @Test
    void findByBirthdayBetween() {
    ...
    List<Person> result = personRepository.findByMonthOfBirthday(8);
    ...
    }
```
```java
@Query(value = "select person from Person person where person.birthday.monthOfBirthday = ?1")
    List<Person> findByMonthOfBirthday(int monthOfBirthday);
// findByBirthdayBetween 테스트를 실행이 성공한다.
``` 

##### 8/7일생 추출하기
```java
@Query(value = "select person from Person person where person.birthday.monthOfBirthday = ?1 and person.birthday.dayOfBirthday = ?2")
    List<Person> findByMonthOfBirthday(int monthOfBirthday, int dayOfBirthday);

List<Person> result = personRepository.findByMonthOfBirthday(8, 7);
```

##### JPQL ?숫자 보다는 이름 매핑이 더 좋다
```java
@Query(value = "select person from Person person where person.birthday.monthOfBirthday = :monthOfBirthday and person.birthday.dayOfBirthday = :dayOfBirthday")
    List<Person> findByMonthOfBirthday(@Param("monthOfBirthday") int monthOfBirthday, @Param("dayOfBirthday") int dayOfBirthday);
```

##### native query 옵션을 사용하게 되면 JPQL이 아니라 네이티브 쿼리로 작성할 수 있다.
```java
@Query(value = "select * from person where month_of_birthday = :monthOfBirthday and day_of_birthday = :dayOfBirthday", nativeQuery = true)
    List<Person> findByMonthOfBirthday(@Param("monthOfBirthday") int monthOfBirthday, @Param("dayOfBirthday") int dayOfBirthday);
```

##### 8월 생일생 찾는 로직으로 원상복귀, 13월생을 찾는 것이 테스트코트에서 정상실행된다.
```java
  List<Person> result = personRepository.findByMonthOfBirthday(13);

  private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(new Birthday(birthday.getYear(), 13, birthday.getDayOfMonth()));
```

```java
Person
    @Embedded
    @Valid
    private Birthday birthday;

    private String job;

Birthday
    @Min(1)
    @Max(12)
    private int monthOfBirthday;

    @Min(1)
    @Max(31)
    private int dayOfBirthday;
// 13월생 찾는 것이 테스트코드에서 실패한다. 

List<Person> result = personRepository.findByMonthOfBirthday(2);

private void givenPerson(String name, int age, String bloodType, LocalDate birthday) {
        Person person = new Person(name, age, bloodType);
        person.setBirthday(new Birthday(birthday.getYear(), 2, 30));

// 2월 30일은 없지만, 문법적으로 문제가 없기에 정상실행된다.
``` 

##### 날짜 타입으로 매핑하기
```java
@Embeddable
@Data
public class Birthday {

    private int yearOfBirthday;

    @Min(1)
    @Max(12)
    private int monthOfBirthday;

    @Min(1)
    @Max(31)
    private int dayOfBirthday;

    public Birthday(LocalDate birthday) {
        this.yearOfBirthday = birthday.getYear();
        this.monthOfBirthday = birthday.getMonthValue();
        this.dayOfBirthday = birthday.getDayOfMonth();
    }
}
```
```java
givenPerson("junhyuk", 28, "B", LocalDate.of(1994, 2, 30));

List<Person> result = personRepository.findByMonthOfBirthday(2);

person.setBirthday(new Birthday(birthday));

// 2월 30일은 유효하지 않은 날짜타입이라고 출력된다.
// 3/3일로 바꾸고, 3월생 찾기로 하고 생성자 추가하고 마무리한다.
```

##### JPA data.sql 사용하기, 테스트케이스 정리 (test/resources/data.sql)
```java
insert into person(`id`, `name`, `age`, `blood_type`) values (1, 'junhyuk', 28, 'B');

// PersonRepositoryTest crud 실행, birthday(NotNull)이라 에러
// Birthday int 를 Integer로 바꾸고 테스트 실행
// Person, GeneratedValue = stategy.IDENTITY 로 변경
```
##### PersonRepository crud 테스트 수정
```java
    @Test
    void crud() {

        //Given
        Person person = new Person();
        person.setName("junhyuk");
        person.setAge(28);
        person.setBloodType("B");

        personRepository.save(person);

        //When
        List<Person> people = personRepository.findByName("junhyuk");

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("junhyuk");
        assertThat(people.get(0).getAge()).isEqualTo(28);
    }

// hashequals 삭제

insert into person(`id`, `name`, `age`, `blood_type`) values (1, 'junhyuk', 28, 'B');
insert into person(`id`, `name`, `age`, `blood_type`) values (2, 'mary', 31, 'A');
insert into person(`id`, `name`, `age`, `blood_type`) values (3, 'sun', 33, 'O');
insert into person(`id`, `name`, `age`, `blood_type`) values (4, 'proom', 21, 'A');
insert into person(`id`, `name`, `age`, `blood_type`) values (5, 'malgum', 24, 'B');

//given person 모두 삭제
//많이 찾아봤지만. data.sql 이 적용이 안된다. 그냥 일일히 테스트 케이스에 추가하도록 하자.
//테스트 케이스 나중에 정리하도록 하자.
```

## 이론
* @GetMapping
  * Get 메소드의 Http 요청을 받을 수 있는 메소드임을 명시하는 어노테이션
* @PathVariable
  * Rest의 Url의 값을 읽어서 메소드의 파라미터로 매핑시킬 수 있도록 도와줌
  * {id}로 표기하면, 해당 위치에 들어오는 문자열을 id 파라미터에 할당해줌

```java
@RestController
@RequestMapping(value = "/api/person")
public class PersonController {

    @Autowired
    private PersonService personService;

    @GetMapping
    public Person getPerson(Long id) {
        return personService.getPerson(id);
    }
}
```

```
GET http://localhost:8080/api/helloWorld

###

GET http://localhost:8080/api/person?id=1

###
```

```java
    @Transactional(readOnly = true)
    public Person getPerson(Long id) {
       
        Optional<Person> person = personRepository.findById(id);

        if (person.isPresent()) {
            return person.get();
        } else {
            return null;
        }
        
//        System.out.println("person = " + person);
//        log.info("person: {}", person);

//        return person;
    }
}
```

```java
@Transactional(readOnly = true)
    public Person getPerson(Long id) {

        Person person = personRepository.findById(id).orElse(null);

        log.info("person: {}", person);

        return person;
    }
}
```

```java
    @GetMapping
    @RequestMapping(value = "{id}")
    public Person getPerson(@PathVariable Long id) {
        return personService.getPerson(id);
    }
}
```
```
GET http://localhost:8080/api/person/1
```
```java
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
}
```
```java
@RestController
@RequestMapping(value = "/api/person")
public class PersonController {

    @Autowired
    private PersonService personService;

    @GetMapping("/{id}")
    public Person getPerson(@PathVariable Long id) {
        
        return personService.getPerson(id);
    }
}
```

## 이론
* @PostMapping
  * Post 메소드의 Http 요청을 받을 수 있는 메소드임을 명시하는 어노테이션
* @RequestBody
  * Request Body에 있는 데이터를 읽어서 파라미터로 매핑할 수 있도록 도와줌
* @ResponseStatus
  * http 응답에 대한 코드값을 지정한 값으로 변경할 수 있음

##### PersonService
```java
    @Transactional
    public void put(Person person) {

        personRepository.save(person);
    }
```
```java
    @PostMapping
    public void postPerson(Person person) {

        personService.put(person);

        log.info("person -> {}", personRepository.findAll());
    }
```

##### PersonServiceTest, Person
```java
    @Autowired
    private PersonController personController;

    private MockMvc mockMvc;

    @Test
    void postPerson() throws Exception {

        //Given
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person"))
                .andDo(print())
                .andExpect(status().isOk());
    }
//실행하면 Person에 NotNull들에 NULL값들이 채워져 있는 것을 알 수 있다.

    @NonNull
    @NotEmpty
    @Column(nullable = false)
    private String name;

    @NonNull
    @Min(1)
    private int age;

    private String hobby;

    @NonNull
    @NotEmpty
    @Column(nullable = false)
    private String bloodType;

    private String address;
```

```java
 mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person?name=junhyuk&age=28&bloodType=B"))
                .andDo(print())
                .andExpect(status().isOk());
//Parameters = {name=[junhyuk], age=[28], bloodType=[B]} 출력된다. 이것을 Body에 넣으려면...
```
```java
    @PostMapping
    //postPerson(Person person) no annotation, Use RequestParam
    public void postPerson(@RequestBody Person person) {

        personService.put(person);

        log.info("person -> {}", personRepository.findAll());
    }
```
```java
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
                .andExpect(status().isOk());
    }

// PostMapping (잘 생성되었는지 201번 테스트)
// 어노테이션 추가
    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)

// testcase 수정
.andExpect(status().isCreated());
```

## 이론
* @PutMapping
  * Put 메소드의 Http 요청을 받을 수 있는 메소드임을 명시하는 어노테이션
* @PatchMapping
  * Patch 메소드의 Http 요청을 받을 수 있는 메소드임을 명시하는 어노테이션
```java 
//personController
    @PutMapping("/{id}"}
    public void modifyPerson(@PathVariable Long id, @RequestBody PersonDto personDto) {
        personService.modify(id, personDto);

        log.info("person -> {}", personRepository.findAll());
    }
```
```java
//personService
     @Transactional
    public void modify(Long id, PersonDto personDto) {
        Person personAtDb = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));
        
	if (!personAtDb.getName().equals(personDto.getName())) {
            throw new RuntimeException("Name is different.");
        }

        personAtDb.setName(personDto.getName());
        personAtDb.setPhoneNumber(personDto.getPhoneNumber());
        personAtDb.setJob(personDto.getJob());
        
        if (personDto.getBirthday() != null) {
            personAtDb.setBirthday(new Birthday(personDto.getBirthday()));
        }
        
        personAtDb.setAddress(personDto.getAddress());
        personAtDb.setBloodType(personDto.getBloodType());
        personAtDb.setHobby(personDto.getHobby());
        personAtDb.setAge(personDto.getAge());

        personRepository.save(personAtDb);
    }
```
```java
@Data
public class PersonDto {

    private String name;
    private int age;
    private String hobby;
    private String bloodType;
    private String address;
    private LocalDate birthday; //Birthday birthday, return type (year, month, day)...
    private String job;
    private String phoneNumber;
}
```

##### Person 로직 수정
```java
    public void set(PersonDto personDto) {
        if (personDto.getAge() != 0) {
            this.setAge(personDto.getAge());
        }

        if (!ObjectUtils.isEmpty(personDto.getHobby())) {
            this.setHobby(personDto.getHobby());
        }

        if (!ObjectUtils.isEmpty(personDto.getBloodType())) {
            this.setBloodType(personDto.getBloodType());
        }

        if (!ObjectUtils.isEmpty(personDto.getAddress())) {
            this.setAddress(personDto.getAddress());
        }

        if (!ObjectUtils.isEmpty(personDto.getJob())) {
            this.setJob(personDto.getJob());
        }

        if (!ObjectUtils.isEmpty(personDto.getPhoneNumber())) {
            this.setPhoneNumber(personDto.getPhoneNumber());
        }
    }
```
##### PersonService
```java
    @Transactional
    public void modify(Long id, PersonDto personDto) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        if (!person.getName().equals(personDto.getName())) {
            throw new RuntimeException("Name is different.");
        }

        person.set(personDto);
        
        personRepository.save(person);
    }
}
```

##### Person의 이름만 수정하는 API
```java
    @PatchMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, String name) {
        personService.modify(id, name);

        log.info("person -> {}", personRepository.findAll());
    }
```
```java
    @Transactional
    public void modify(Long id, String name) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        person.setName(name);

        personRepository.save(person);
    }
```
```
    @Test
    void modifyName() throws Exception {

        //Given
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.patch("/api/person/1")
                        .param("name", "junhyuk"))
                .andDo(print())
                .andExpect(status().isOk());
    }
```    
## 이론
* @DeleteMapping
  * Delete 메소드의 Http 요청을 받을 수 있는 메소드임을 명시하는 어노테이션 

```java
    @DeleteMapping("/{id}")
    public void deletePerson(@PathVariable Long id) {
        personService.delete(id);

        log.info("person -> {}", personRepository.findAll());
    }
```
```java
    @Transactional
    public void delete(Long id) {
//        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));
//        personRepository.delete(person);

        personRepository.deleteById(id);
    }
```
```java
    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders.standaloneSetup(personController).build();
    }
    
    ...
    
    @Test
    void deletePerson() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.delete("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk());
    }
```

##### delete하는 방식을 소프트하게 수정 (현업에서 쓰는 방식)
```java
//Person
@Where(clause = "deleted = false")

    @ToString.Exclude
    private String phoneNumber;
    
    @ColumnDefault("0")
    private boolean deleted;
```

```java
    @Transactional
    public void delete(Long id) {
//        One way
//        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));
//        personRepository.delete(person);

//        Two way
//        personRepository.deleteById(id);

        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        person.setDeleted(true);

        personRepository.save(person);
    }
```  

##### Where 을 붙이게 되면 id가 삭제되어 쿼리문이 나간다. 삭제된 내용을 보고 싶다면
```java
//personRepository
    @Query(value = "select person from Person person where person.deleted = true", nativeQuery = true)
    List<Person> findPeopleDeleted();
}

//PersonControllerTest
    @Autowired
    private PersonRepository personRepository;
    
    deletePerson에 
          //log.info(people deleted: {}, personRepository.findPeopleDeleted()); 
	  하지만, log가 테스트케이스에선 적용이 안됨.
```

## 리팩토링 도메인 코드
## ControllerTest 수정
```java
    @Test
    void deletePerson() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.delete("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk());

        assertTrue(personRepository.findPeopleDeleted().stream().anyMatch(
                person -> person.getId().equals(1L)
        ));
    }
```    
```java
    @Test
    void modifyName() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.patch("/api/person/1")
                        .param("name", "junhyuk"))
                .andDo(print())
                .andExpect(status().isOk());

        assertThat(personRepository.findById(1L).get().getName()).isEqualTo("junhyuk");
    }
```
```java
    @Autowired
    private ObjectMapper objectMapper;
    
    ...
    
        @Test
    void checkJsonString() throws Exception {

        //Given
        PersonDto dto = new PersonDto();

        //When
        dto.setName("junhyuk");
        dto.setBirthday(LocalDate.now());
        dto.setAddress("Seoul");

        //Then
        System.out.println(">>> " + toJsonString(dto));
    }

    private String toJsonString(PersonDto personDto) throws JsonProcessingException {
        return objectMapper.writeValueAsString(personDto);
    }
```
```java
    @Test
    void modifyPerson() throws Exception {
        PersonDto dto = new PersonDto();
        dto.setName("jini");
        dto.setBirthday(LocalDate.now());
        dto.setAddress("Seoul");
        dto.setHobby("programming");
        dto.setJob("programmer");
        dto.setPhoneNumber("010-1111-2222");
```
```java
//PersonDto
@NoArgsConstructor
@AllArgsConstructor(staticName = "of")

//PersonControllerTest
    @Test
    void modifyPerson() throws Exception {
        PersonDto dto = PersonDto.of("junhyuk", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");


        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/1")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andDo(print())
                .andExpect(status().isOk());

        Person result = personRepository.findById(1L).get();

        assertAll(
                () -> assertThat(result.getName()).isEqualTo("junhyuk"),
                () -> assertThat(result.getHobby()).isEqualTo("programming"),
                () -> assertThat(result.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                () -> assertThat(result.getJob()).isEqualTo("programmer"),
                () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-1112")
        );
    }
```
## 이론
* Controller Test에서 사용하는 메소드
    * jsonPath
      * $ : 객체를 의미함
      * .name : 객체의 name attribute를 가져옴, getName()을 사용한다고 생각하면 됨
      * . 체이닝을 통해서 recursive하게 데이터 추출이 가능
    * value(A)
      * 값이 A와 동일한지 검증함
    * imEmpty()
      * 값이 빈 값인지 검증함
    * isNumber()
      * 값이 숫자값인지 검증함
    * isBoolean()
      * true/false 값인지 검증함
* JsonSerializer<T>
  * serialize()
* @Configuration
  * Spring의 Configuration Bean임을 표시하는 어노테이션
* MappingJackson2HttpMessageConverter
  * Spring의 Controller에서 반환하는 결과를 Json으로 만드는데, 해당 포맷을 커스터마이징할 수 있게 해줌
* SimpleModule
  * 커스텀으로 만든 Serializer를 Converter에 등록하기 위해서 모듈화해줌

##### ControllerTest
```java
    @Test
    void getPerson() throws Exception {

        //Then
        mockMvc.perform(MockMvcRequestBuilders.get("/api/person/1"))
                .andDo(print())
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("junhyuk"))
                .andExpect(jsonPath("$.hobby").isEmpty())
                .andExpect(jsonPath("address").isEmpty())
                .andExpect(jsonPath("$.birthday.yearOfBirthday").value(1991))
                .andExpect(jsonPath("$.birthday.monthOfBirthdaya").value(8))
                .andExpect(jsonPath("$.birthday.dayOfBirthday").value(15))
                .andExpect(jsonPath("$.job").isEmpty())
                .andExpect(jsonPath("$.phoneNumber").isEmpty())
                .andExpect(jsonPath("$.deleted").value(false))
                .andExpect(jsonPath("$.age").isNumber())
                .andExpect(jsonPath("$.birthdayToday").isBoolean());
    }
    /// 1991-08-15로 출력하기 위해 JsonConfig, BirthdaySerializer 만듬
    
//BirthdaySerializer
public class BirthdaySerializer extends JsonSerializer<Birthday> {

    @Override
    public void serialize(Birthday value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
        if (value != null) {
            gen.writeObject(LocalDate.of(value.getYearOfBirthday(), value.getMonthOfBirthday(), value.getDayOfBirthday()));
        }
    }
}

//JsonConfig
//만든 Serializer를 default module에 주입해주고 Birthday module은 objectmapper에 넣어주고 object mapper는 메시지 컨버터에 넣어주는 식
@Configuration
public class JsonConfig {

    @Bean
    public MappingJackson2HttpMessageConverter mappingJackson2HttpMessageConverter(ObjectMapper objectMapper) {
        MappingJackson2HttpMessageConverter converter = new MappingJackson2HttpMessageConverter();
        converter.setObjectMapper(objectMapper);

        return converter;
    }
    
    @Bean
    public ObjectMapper objectMapper() {
        ObjectMapper objectMapper = new ObjectMapper();
        objectMapper.registerModule(new BirthdayModule());

        return objectMapper;
    }

    static class BirthdayModule extends SimpleModule {

        BirthdayModule() {
            super();
            addSerializer(Birthday.class, new BirthdaySerializer());
        }
    }
}
```

```java
    @Autowired
    private MappingJackson2HttpMessageConverter messageConverter;
    
    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders.standaloneSetup(personController).setMessageConverters().build();
    }
// get Person 테스트, 우리가 원하는 식이 아니라 JSON 타입으로 변환되었음.

 @Bean
    public ObjectMapper objectMapper() {
        ObjectMapper objectMapper = new ObjectMapper();
        objectMapper.registerModule(new BirthdayModule());
        objectMapper.registerModule(new JavaTimeModule());

        objectMapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);

        return objectMapper;
    }
    
//getPerson test
.andExpect(jsonPath("$.birthday").value("1991-08-15"))

##### 24강 PersonControllerTest
    @Test
    void postPerson() throws Exception {
        PersonDto dto = PersonDto.of("junhyuk", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");
        
        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andDo(print())
                .andExpect(status().isCreated());
    }
// PersonController
    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    //postPerson(Person person) no annotation, Use RequestParam
    public void postPerson(@RequestBody PersonDto personDto) {

        personService.put(personDto);
    }
    
// Person Service
    @Transactional
    public void put(PersonDto personDto) {
        Person person = new Person();
        person.set(personDto);
        person.setName(personDto.getName());


        personRepository.save(person);
    }
    
        @Test
    void postPerson() throws Exception {
        PersonDto dto = PersonDto.of("junhyuk", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");
        
        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andDo(print())
                .andExpect(status().isCreated());

        Person result = personRepository.findAll(Sort.by(Sort.Direction.DESC, "id")).get(0);

        assertAll(
                () -> assertThat(result.getName()).isEqualTo("junhyuk"),
                () -> assertThat(result.getHobby()).isEqualTo("programming"),
                () -> assertThat(result.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                () -> assertThat(result.getJob()).isEqualTo("programmer"),
                () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-1112")
        );
    }
```

##### PersonRepositoryTest
```java
@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    void findByNmae() {
        List<Person> people = personRepository.findByName("tony");
        assertThat(people.size()).isEqualTo(1);

        Person person = people.get(0);
        assertAll(
                () -> assertThat(person.getName()).isEqualTo("tony"),
                () -> assertThat(person.getHobby()).isEqualTo("reading"),
                () -> assertThat(person.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(person.getBirthday()).isEqualTo(LocalDate.of(1994, 3, 3)),
                () -> assertThat(person.getJob()).isEqualTo("officer"),
                () -> assertThat(person.getPhoneNumber()).isEqualTo("010-1111-1234"),
                () -> assertThat(person.isDeleted()).isEqualTo(false)
        );
    }

    @Test
    void findByNameIfDeleted() {
    
        //When
        List<Person> people = personRepository.findByName("andrew");

        //Then
        assertThat(people.size()).isEqualTo(0);
    }
    
    @Test
    void findByMonthOfBirthday() {
    
        //Given
        List<Person> people = personRepository.findByMonthOfBirthday(8);
        
        //Then
        assertThat(people.size()).isEqualTo(2);
        assertAll(
                () -> assertThat(people.get(0).getName()).isEqualTo("david"),
                () -> assertThat(people.get(1).getName()).isEqualTo("tony")
        );
    }
    
    @Test
    void findPeopleDeleted() {
    
        //Given
        List<Person> people = personRepository.findPeopleDeleted();
        
        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("andrew");
    }
}
```
## 이론
* Mock 테스트의 장점
  * 테스트를 더 빠르게 실행할 수 있음
  * 테스트를 더 구체적이고 세밀하게 할 수 있음
* @ExtendWith
  * 테스트를 진행할 컨테이너를 별도로 지정해줌
  * Junit4에서 @RunWith를 대체하는 어노테이션
* MockitoExtension
  * Mockito를 사용할 수 있도록 처리해줌
* @InjectMocks
  * @Mock으로 지정된 객체들을 생성해서, 테스트의 주체가 되는 클래스에 주입(Autowired)까지 해줌
* @Mock
  * 실제 Bean이 아니라 가짜 객체(Mock)를 만들어서 실제 Bean을 대체함
* when...thenReturn
  * Mock의 어떤 메소드와 파라미터가 매핑되는 경우, 결과값에 대해서 지정해줄 수 있음

##### PersonServiceTest
```java
@ExtendWith(MockitoExtension.class)
@Transactional
class PersonServiceTest {

    @InjectMocks
    private PersonService personService;
    @Mock
    private PersonRepository personRepository;

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

        //Given
        PersonDto dto = PersonDto.of("junhyuk", "programming", "seoul", LocalDate.now(), "programmer", "010-1111-1119");

        //When
        personService.put(dto);

        //Then
        verify(personRepository, times(1)).save(any(Person.class));
    }
    
    //PersonService
    @Transactional(readOnly = true)
    public Person getPerson(Long id) {

        return personRepository.findById(id).orElse(null);
    }    
```    
```java
    @Test
    void modifyIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modifyIfNameIsDifferent() {

        //When
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("tony")));

        //Then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    void modify() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("junhyuk")));

        //When
        personService.modify(1L, mockPersonDto());

        //Then
        verify(personRepository, times(1)).save(any(Person.class));
    }

    private PersonDto mockPersonDto() {

        return PersonDto.of("junhyuk", "programming", "seoul", LocalDate.now(), "programmer", "010-1111-1119");
    }
``` 
##### PersonService에서 Person.set(personDto) 주석처리 했을 경우 ModifyTest는 이것을 잡아내지 못한다.
```java
@Transactional
    public void modify(Long id, PersonDto personDto) {
        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));

        if (!person.getName().equals(personDto.getName())) {
            throw new RuntimeException("Name is different.");
        }

        // person.set(personDto);

        personRepository.save(person);
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
```
```java
    @Test
    void modifyByNameIfPersonNotFound() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //Then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, "daniel"));
    }
```
```java
    private static class IsNameWillBeUpdated implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return person.getName().equals("daniel");
        }
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
        assertThrows(RuntimeException.class, () -> personService.delete(1L));
    }    
```
```java
    @Test
    void delete() {

        //Given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //When
        personService.delete(1L);

        //Then
        verify(personRepository, times(1)).save(any(Person.class));
    }
    
    private static class IsPersonWillBeDeleted implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return person.isDeleted();
        }
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
```
```java
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
    
    @Test
    void put() {

        //When
        personService.put(mockPersonDto());

        //Then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeInserted()));
    }    
```    
## 이론
* Parameter Validator란?
  * 내부 로직에서 처리할 수 없는 입력값을 사전에 검증하고, 필요한 오류 및 메시지로 매핑해서 응답하는 것
* @NotEmpty
  * 해당 값이 null이거나 empty string("")에 대해서 검증하는 어노테이션
  * 속성
    * message : 해당 validation을 통과하지 못할 경우 표시할 오류 메시지
* @NotBlank
  * 해당 값이 null이거나 empty string("") 및 공백 문자열(" ")까지 검증하는 어노테이션
* @Valid
  * 일반적으로 validator는 해당 인자에 대해서만 검증하므로, 검증 대상이 객체이면 recursive하게 검증할 수 있도록 표시해주는 어노테이션

* Pageable
  * JPA에서 정의한 Paging을 위한 인터페이스
  * 속성
    * content
    * totalPages
    * totalElements
    * numberOfElements
* PageRequest
  * Pageable 인터페이스를 구현한 구현체
* @PageableDefault
  * API에서 페이징을 위한 파라미터가 존재하지 않을 때, 페이징을 위한 기본값을 제공

## SpringBoot Project 학습정리

### SpringBoot 특성

* 스프링의 생산성
* Coding By Convention 활용 (CoC : Convention over Configuration)

### 학습했던 내용 정리

* 스프링부트 프로젝트 생성
* Gradle을 이용한 의존성 관리
* Iteration(반복주기) 개발로 2-cycle 개발 진행

#### 1-cycle 내용정리

* JPA
  * Entity 생성
  * @OneToOne Relation
    * CascadeType
    * FetchType
    * Optional, orphanRemoval
  * QueryMethod
  * @Embedded
  * @Valid
  * @Query
  * @Where (for soft-delete)
  * Data.sql

* SpringMvc
  * @GetMapping
  * @PostMapping
  * @PutMapping
  * @PatchMapping
  * @DeleteMapping
  * @PathVariable
  * @RequestBody

* Lombok
  * @Getter
  * @Setter
  * @ToString
  * @Constructor
  * @EqualsAndHashCode
  * @Data

* SpringTest

* Java8
  * Stream
  * Fileter
  * Map

#### 2-cycle 내용정리

* SpringMvc
  * CustomJsonSerializer

* SpringTest
  * MockMvc Test
  * Matcher
  * Junit5

* MockTest
  * Mockito
  * CustomArgumentMatcher

* Exception Handling
  * CustomException
  * ExceptionalHandler
  * GlobalExceptionHandler

* Parameter Validator
  * @NotEmpty
  * @NotBlank
  * @Valid

* Paging
  * Pageable
  * Page<T>

### 추가로 학습할 것

* FrontEnd 개발
  * Web
    * VueJs
    * ReactJs
  * App
    * Android App
    * IOS App

* DB 연동
  * MySQL
  * MongDB

* Spring(Boot)의 중급활용
  * 추가적인 설정
  * Customizing 설정

* JPA 중급활용
  * 다양한 Relation
  * QueryDSL
  * Jooq

* 로직의 확장
  * 추가적인 스펙

```java
@Entity
@NoArgsConstructor
@AllArgsConstructor
@RequiredArgsConstructor
@Data
public class Group {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;

	private String description;

	@OneToMany
	private List<Person> personList;
}
```

```java
@RequestMapping(value = "/api/group")
@RestController
public class GroupController {
	@GetMapping
	public List<Group getAll() {
		return null;	// Group 전체 정보 가져오기
	}

	@GetMapping("/{id}")
	public Group getGroup(@PathVariable Long id) {
		return null;	// 특정 Group 정보 가져오기
	}

	@PostMapping
	@ResponseStatus(HttpStatus.CREATED)
	public void postGroup(@RequestBody Object groupDto) {	// DTO 구현필요
		// Group 생성하기
	}

	@PatchMapping("/{id}")
	public void modifyGroup(@PathVariable Long id, String description) {
		// Group description 수정하기
	}

	@GetMapping("/{id}/people")
	public List<Person getPeopleInGroup(@PathVariable Long id) {
		return null;	// 특정 그룹의 Person 리스트 가져오기
	}

	@PutMapping("/{id}/person/{personId}")
	public void putPersonInGroup(@PathVariable Long id, @PathVariable Long personId) {
		// Person 정보를 Group 정보에 매핑하기
	}
}
```
## 
```java
//configuration/serializer
public class BirthdaySerializer extends JsonSerializer<Birthday> {

    @Override
    public void serialize(Birthday value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
        if (value != null) {
            gen.writeObject(LocalDate.of(value.getYearOfBirthday(), value.getMonthOfBirthday(), value.getDayOfBirthday()));
        }
    }
}
//configuration
@Configuration
public class JsonConfig {

    @Bean
    public MappingJackson2HttpMessageConverter mappingJackson2HttpMessageConverter(ObjectMapper objectMapper) {
        MappingJackson2HttpMessageConverter converter = new MappingJackson2HttpMessageConverter();
        converter.setObjectMapper(objectMapper);

        return converter;
    }

    @Bean
    public ObjectMapper objectMapper() {
        ObjectMapper objectMapper = new ObjectMapper();
        objectMapper.registerModule(new BirthdayModule());
        objectMapper.registerModule(new JavaTimeModule());

        objectMapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);

        return objectMapper;
    }

    static class BirthdayModule extends SimpleModule {

        BirthdayModule() {
            super();
            addSerializer(Birthday.class, new BirthdaySerializer());
        }
    }
}
```
```java
//controller/dto
@Data
@NoArgsConstructor
@AllArgsConstructor(staticName = "of")
public class PersonDto {

    @NotBlank(message = "Name is necessary.")
    private String name;
    private String hobby;
    private String address;
    private LocalDate birthday; //Birthday birthday, return type (year, month, day)...
    private String job;
    private String phoneNumber;
}

@RestController
public class HelloWorldController {

    @GetMapping(value = "/api/helloWorld")
    public String helloWorld() {
        return "HelloWorld";
    }

    @GetMapping(value = "/api/helloException")
    public String helloException() {
        throw new RuntimeException("Hello RuntimeException");
    }
}

@RestController
@RequestMapping(value = "/api/person")
@Slf4j
public class PersonController {

    @Autowired
    private PersonService personService;

    @GetMapping
    public Page<Person> getAll(@PageableDefault Pageable pageable) {
        return personService.getAll(pageable);
    }

    @GetMapping("/{id}")
    public Person getPerson(@PathVariable Long id) {

        return personService.getPerson(id);
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    //postPerson(Person person) no annotation, Use RequestParam
    public void postPerson(@RequestBody @Valid PersonDto personDto) {

        personService.put(personDto);
    }

    @PutMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, @RequestBody PersonDto personDto) {
        try {
            personService.modify(id, personDto);
        } catch (RuntimeException ex) {
            log.error(ex.getMessage(), ex);
        }
    }

    @PatchMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, String name) {
        personService.modify(id, name);
    }

    @DeleteMapping("/{id}")
    public void deletePerson(@PathVariable Long id) {
        personService.delete(id);
    }
}
```
```java
//domain/dto
@Embeddable
@Data
@NoArgsConstructor
public class Birthday {

    private Integer yearOfBirthday;
    private Integer monthOfBirthday;
    private Integer dayOfBirthday;

    private Birthday(LocalDate birthday) {
        this.yearOfBirthday = birthday.getYear();
        this.monthOfBirthday = birthday.getMonthValue();
        this.dayOfBirthday = birthday.getDayOfMonth();
    }

    public static Birthday of(LocalDate birthday) {
        return new Birthday(birthday);
    }
}

@Entity
@NoArgsConstructor
@AllArgsConstructor
@RequiredArgsConstructor
@Data
@Where(clause = "deleted = false")
public class Person {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @NonNull
    @NotEmpty
    @Column(nullable = false)
    private String name;

    private String hobby;

    private String address;

    @Embedded
    @Valid
    private Birthday birthday;

    private String job;

    private String phoneNumber;

    @ColumnDefault("0")
    private boolean deleted;

    public void set(PersonDto personDto) {

        if (!ObjectUtils.isEmpty(personDto.getHobby())) {
            this.setHobby(personDto.getHobby());
        }

        if (!ObjectUtils.isEmpty(personDto.getAddress())) {
            this.setAddress(personDto.getAddress());
        }

        if (!ObjectUtils.isEmpty(personDto.getJob())) {
            this.setJob(personDto.getJob());
        }

        if (!ObjectUtils.isEmpty(personDto.getPhoneNumber())) {
            this.setPhoneNumber(personDto.getPhoneNumber());
        }
    }

    public Integer getAge() {
        if (this.birthday != null) {
            return LocalDate.now().getYear() - this.birthday.getYearOfBirthday() + 1;
        } else {
            return null;
        }
    }

    public boolean isBirthdayToday() {
        return LocalDate.now().equals(LocalDate.of(this.birthday.getYearOfBirthday(), this.birthday.getMonthOfBirthday(), this.birthday.getDayOfBirthday()));
    }
}
```
```java
//exception/dto, handler
@Data
@AllArgsConstructor(access = AccessLevel.PRIVATE)
public class ErrorResponse {

    private int code;
    private String message;

    public static ErrorResponse of(HttpStatus httpStatus, String message) {
        return new ErrorResponse(httpStatus.value(), message);
    }

    public static ErrorResponse of(HttpStatus httpStatus, FieldError fieldError) {
        if (fieldError == null) {
            return new ErrorResponse(httpStatus.value(), "invalid params");
        } else {
            return new ErrorResponse(httpStatus.value(), fieldError.getDefaultMessage());
        }
    }
}

@Slf4j
@RestControllerAdvice
public class GlobalExceptionHandler {

    @ExceptionHandler(RenameIsNotPermittedException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handleRenameNoPermittedException(RenameIsNotPermittedException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

    @ExceptionHandler(PersonNotFoundException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handlePersonNotFoundException(PersonNotFoundException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

//    @ExceptionHandler(MethodArgumentNotValidException.class)
//    @ResponseBody(HttpStatus.BAD_REQUEST)
//    public ErrorResponse handleMethodArgumentNotValidException(MethodArgumentNotValidException ex) {
//        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getBindingResult().getFieldError().getDefaultMessage());
//    }

    @ExceptionHandler(RuntimeException.class)
    @ResponseStatus(HttpStatus.INTERNAL_SERVER_ERROR)
    public ErrorResponse handleRuntimeException(RuntimeException ex) {
        log.error("server error: {}", ex.getMessage(), ex);
        return ErrorResponse.of(HttpStatus.INTERNAL_SERVER_ERROR, "Unknown server error is occurred.");
    }
}

@Slf4j
public class PersonNotFoundException extends RuntimeException {

    private static final String MESSAGE = "Person Entity not exist.";
    public PersonNotFoundException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}

@Slf4j
public class RenameIsNotPermittedException extends RuntimeException {

    private static final String MESSAGE = "Do not allow name changes.";
    public RenameIsNotPermittedException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}
```
```java
//repository
public interface PersonRepository extends JpaRepository<Person, Long> {

    List<Person> findByName(String name); //find = select, By = where, Name = argument

    @Query(value = "select person from Person person where person.birthday.monthOfBirthday = :monthOfBirthday")
    List<Person> findByMonthOfBirthday(@Param("monthOfBirthday") int monthOfBirthday);

    @Query(value = "select * from Person person where person.deleted = true", nativeQuery = true)
    List<Person> findPeopleDeleted();
}
```
```java
//service
@Service
@Slf4j
public class PersonService {

    @Autowired
    private PersonRepository personRepository;

    public Page<Person> getAll(Pageable pageable) {
        return personRepository.findAll(pageable);
    }

    public List<Person> getPeopleByName(String name) {

        return personRepository.findByName(name);
    }

    @Transactional(readOnly = true)
    public Person getPerson(Long id) {

        return personRepository.findById(id).orElse(null);
    }

    @Transactional
    public void put(PersonDto personDto) {
        Person person = new Person();
        person.set(personDto);
        person.setName(personDto.getName());

        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, PersonDto personDto) {
        Person person = personRepository.findById(id).orElseThrow(PersonNotFoundException::new);

        if (!person.getName().equals(personDto.getName())) {
            throw new RenameIsNotPermittedException();
        }

        person.set(personDto);

        personRepository.save(person);
    }

    @Transactional
    public void modify(Long id, String name) {
        Person person = personRepository.findById(id).orElseThrow(RuntimeException::new);

        person.setName(name);

        personRepository.save(person);
    }

    @Transactional
    public void delete(Long id) {
//        One way
//        Person person = personRepository.findById(id).orElseThrow(() -> new RuntimeException("Not exist id."));
//        personRepository.delete(person);

//        Two way
//        personRepository.deleteById(id);

        Person person = personRepository.findById(id).orElseThrow(PersonNotFoundException::new);

        person.setDeleted(true);

        personRepository.save(person);
    }
}
```

## Test
@SpringBootTest
class HelloWorldControllerTest {

//    @Autowired
//    private HelloWorldController helloWorldController;

    @Autowired
    private WebApplicationContext wac;

    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders
                .webAppContextSetup(wac)
//                .standaloneSetup(helloWorldController)
                .alwaysDo(print())
                .build();
    }
    @Test
    void helloWorld() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloWorld"))
                .andExpect(status().isOk())
                .andExpect(MockMvcResultMatchers.content().string("HelloWorld"));
    }

    @Test
    void helloException() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloException"))
                .andExpect(status().isInternalServerError())
                .andExpect(jsonPath("$.code").value(500))
                .andExpect(jsonPath("$.message").value("Unknown server error is occurred."));
    }
}

@SpringBootTest
@Transactional
class PersonControllerTest {

//    @Autowired
//    private PersonController personController;

    @Autowired
    private PersonRepository personRepository;

    @Autowired
    private ObjectMapper objectMapper;

//    @Autowired
//    private MappingJackson2HttpMessageConverter messageConverter;

//    @Autowired
//    private GlobalExceptionHandler globalExceptionHandler;

    @Autowired
    private WebApplicationContext wac;

    private MockMvc mockMvc;

    @BeforeEach
    void beforeEach() {
        mockMvc = MockMvcBuilders
                .webAppContextSetup(wac)
//                .standaloneSetup(personController)
//                .setMessageConverters()
//                .setControllerAdvice(globalExceptionHandler)
                .alwaysDo(print())
                .build();
    }

    @Test
    void getAll() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/person")
                        .param("page", "1")
                        .param("size", "2"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.totalPages").value(3))
                .andExpect(jsonPath("$.totalElement").value(6))
                .andExpect(jsonPath("$.numberOfElements").value(2))
                .andExpect(jsonPath("$.content.[0].name").value("dennis"))
                .andExpect(jsonPath("$.content.[1].name").value("sophia"));
    }

    @Test
    void getPerson() throws Exception {

        //Then
        mockMvc.perform(MockMvcRequestBuilders.get("/api/person/1"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("junhyuk"))
                .andExpect(jsonPath("$.hobby").isEmpty())
                .andExpect(jsonPath("address").isEmpty())
                .andExpect(jsonPath("$.birthday").value("1991-08-15"))
                .andExpect(jsonPath("$.job").isEmpty())
                .andExpect(jsonPath("$.phoneNumber").isEmpty())
                .andExpect(jsonPath("$.deleted").value(false))
                .andExpect(jsonPath("$.age").isNumber())
                .andExpect(jsonPath("$.birthdayToday").isBoolean());
    }

    @Test
    void postPerson() throws Exception {
        PersonDto dto = PersonDto.of("junhyuk", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andExpect(status().isCreated());

        Person result = personRepository.findAll(Sort.by(Sort.Direction.DESC, "id")).get(0);

        assertAll(
                () -> assertThat(result.getName()).isEqualTo("junhyuk"),
                () -> assertThat(result.getHobby()).isEqualTo("programming"),
                () -> assertThat(result.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                () -> assertThat(result.getJob()).isEqualTo("programmer"),
                () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-1112")
        );
    }

    @Test
    void postPersonIfNameIsNull() throws Exception {

        //Given
        PersonDto dto = new PersonDto();

        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Name is necessary."));
    }

    @Test
    void postPersonIfNameIsEmptyString() throws Exception {
        PersonDto dto = new PersonDto();
        dto.setName("");

        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Name is necessary"));
    }

    @Test
    void postPersonIfNameIsBlankString() throws Exception {

        //Given
        PersonDto dto = new PersonDto();
        dto.setName(" ");

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.post("/api/person")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Name is necessary"));
}

    @Test
    void modifyPerson() throws Exception {
        PersonDto dto = PersonDto.of("junhyuk", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");


        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/1")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andExpect(status().isOk());

        Person result = personRepository.findById(1L).get();

        assertAll(
                () -> assertThat(result.getName()).isEqualTo("junhyuk"),
                () -> assertThat(result.getHobby()).isEqualTo("programming"),
                () -> assertThat(result.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(result.getBirthday()).isEqualTo(Birthday.of(LocalDate.now())),
                () -> assertThat(result.getJob()).isEqualTo("programmer"),
                () -> assertThat(result.getPhoneNumber()).isEqualTo("010-1111-1112")
        );
    }

    @Test
    void modifyPersonIfNameIsDifferent() throws Exception {
        PersonDto dto = PersonDto.of("jini", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");


        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/1")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Do not allow name changes."));
    }
    @Test
    void modifyPersonIfPersonNotFound() throws Exception {
        PersonDto dto = PersonDto.of("martin", "programming", "Seoul", LocalDate.now(), "programmer", "010-1111-1112");

        mockMvc.perform(
                MockMvcRequestBuilders.put("/api/person/10")
                        .contentType(MediaType.APPLICATION_JSON)
                        .characterEncoding("utf-8")
                        .content(toJsonString(dto)))
                .andExpect(status().isBadRequest())
                .andExpect(jsonPath("$.code").value(400))
                .andExpect(jsonPath("$.message").value("Person Entitiy Not exist"));
    }

    @Test
    void modifyName() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.patch("/api/person/1")
                        .param("name", "junhyuk"))
                .andExpect(status().isOk());

        assertThat(personRepository.findById(1L).get().getName()).isEqualTo("junhyuk");
    }

    @Test
    void deletePerson() throws Exception {

        //Then
        mockMvc.perform(
                MockMvcRequestBuilders.delete("/api/person/1"))
                .andExpect(status().isOk());

        assertTrue(personRepository.findPeopleDeleted().stream().anyMatch(
                person -> person.getId().equals(1L)
        ));
    }

    @Test
    void checkJsonString() throws Exception {

        //Given
        PersonDto dto = new PersonDto();

        //When
        dto.setName("junhyuk");
        dto.setBirthday(LocalDate.now());
        dto.setAddress("Seoul");

        //Then
        System.out.println(">>> " + toJsonString(dto));
    }

    private String toJsonString(PersonDto personDto) throws JsonProcessingException {
        return objectMapper.writeValueAsString(personDto);
    }
}

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    void findByNmae() {
        List<Person> people = personRepository.findByName("tony");
        assertThat(people.size()).isEqualTo(1);

        Person person = people.get(0);
        assertAll(
                () -> assertThat(person.getName()).isEqualTo("tony"),
                () -> assertThat(person.getHobby()).isEqualTo("reading"),
                () -> assertThat(person.getAddress()).isEqualTo("Seoul"),
                () -> assertThat(person.getBirthday()).isEqualTo(LocalDate.of(1994, 3, 3)),
                () -> assertThat(person.getJob()).isEqualTo("officer"),
                () -> assertThat(person.getPhoneNumber()).isEqualTo("010-1111-1234"),
                () -> assertThat(person.isDeleted()).isEqualTo(false)
        );
    }

    @Test
    void findByNameIfDeleted() {

        //When
        List<Person> people = personRepository.findByName("andrew");

        //Then
        assertThat(people.size()).isEqualTo(0);
    }

    @Test
    void findByMonthOfBirthday() {

        //Given
        List<Person> people = personRepository.findByMonthOfBirthday(8);

        //Then
        assertThat(people.size()).isEqualTo(2);
        assertAll(
                () -> assertThat(people.get(0).getName()).isEqualTo("david"),
                () -> assertThat(people.get(1).getName()).isEqualTo("tony")
        );
    }

    @Test
    void findPeopleDeleted() {

        //Given
        List<Person> people = personRepository.findPeopleDeleted();

        //Then
        assertThat(people.size()).isEqualTo(1);
        assertThat(people.get(0).getName()).isEqualTo("andrew");
    }
}

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
```
