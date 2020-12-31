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

    @GetMapping(value = "{id}")
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













