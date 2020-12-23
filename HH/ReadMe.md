configuration

&nbsp;&nbsp;JsonConfig
&nbsp;&nbsp;- serializer
  
&nbsp;&nbsp;&nbsp;BirthdaySerializer


controller

 &nbsp;&nbsp; HelloWorldController(test)
  
&nbsp;&nbsp;  PersonController(test)
  
  GroupController
  
 
domain

 &nbsp;&nbsp; Person
  
 &nbsp;&nbsp; Group
  
 &nbsp;&nbsp; - dto
  
  &nbsp;&nbsp;&nbsp;  Birthday
    
    
exception

  &nbsp;&nbsp;GlobalExceptionHandler
  
  &nbsp;&nbsp;PersonNotFoundException
  
 &nbsp;&nbsp;RenameIsnotPermitted
  
  &nbsp;&nbsp;- dto
  
  &nbsp;&nbsp;&nbsp;  ErrorResponse
   
   
repository

  &nbsp;&nbsp; PersonRepository(test)
  
  
service

  &nbsp;&nbsp; PersonService(test)
  
  
etc. (data.sql, hello.http)

public class BirthdaySerializer extends JsonSerializer<Birthday> {

    @Override
    public void serialize(Birthday value, JsonGenerator gen, SerializerProvider serializers) throws IOException {
        if (value != null) {
            gen.writeObject(LocalDate.of(value.getYearOfBirthday(), value.getMonthOfBirthday(), value.getDayOfBirthday()));
        }
    }
}
==================
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

====================
@Data
@NoArgsConstructor
@AllArgsConstructor(staticName = "of")
public class PersonDto {
    @NotBlank(message = "name is necessary.")
    private String name;

    private String hobby;
    private String address;
    private LocalDate birthday;
    private String job;
    private String phoneNumber;
}
===========================

@RequestMapping(value = "/api/group")
@RestController
public class GroupController {

    @GetMapping
    public List<Group> getAll() {
        return null;
    }

    @GetMapping("{id}")
    public Group getGroup(@PathVariable Long id) {
        return null;
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public void postGroup(@RequestBody Object groupDto) {
    }

    @PatchMapping("/{id}")
    public void modifyGroup(@PathVariable Long id, String description) {
    }

    @GetMapping("/{id}/people")
    public List<Person> getPeopleInGroup(@PathVariable Long id) {
        return null;
    }

    @PutMapping("/{id}/person/{personId}")
    public void putPersonInGroup(@PathVariable Long id, @PathVariable Long personId) {
    }
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

@RequestMapping(value = "/api/person")
@RestController
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
    public void postPerson(@RequestBody @Valid PersonDto personDto) {
        personService.put(personDto);
    }

    @PutMapping("/{id}")
    public void modifyPerson(@PathVariable Long id, @RequestBody PersonDto personDto) {
        personService.modify(id, personDto);
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


@Embeddable
@Data
@NoArgsConstructor
public class Birthday {

    private Integer yearOfBirthday;
    private Integer monthOfBirthday;
    private Integer dayOfBirthday;

    public Birthday(LocalDate birthday) {
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
public class Group {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String description;

    @OneToMany
    private List<Person> personList;
}


@Entity
@AllArgsConstructor
@NoArgsConstructor
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

    @Valid
    @Embedded
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
        if (personDto.getBirthday() != null) {
            this.setBirthday(Birthday.of(personDto.getBirthday()));
        }
    }

    public Integer getAge() {
        if (this.birthday != null) {
            return LocalDate.now().getYear() - this.birthday.getYearOfBirthday() +1;
        } else {
            return null;
        }
    }

    public boolean isBirthdayToday() {
        return LocalDate.now().equals(LocalDate.of(this.birthday.getYearOfBirthday(), this.birthday.getMonthOfBirthday(), this.birthday.getDayOfBirthday()));
    }
}


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
    public ErrorResponse handleRenameNoPermittedExcecption(RenameIsNotPermittedException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

    @ExceptionHandler(PersonNotFoundException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handlePersonNotFoundException(PersonNotFoundException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getMessage());
    }

    @ExceptionHandler(MethodArgumentNotValidException.class)
    @ResponseStatus(HttpStatus.BAD_REQUEST)
    public ErrorResponse handleMethodArgumentNotValidException(MethodArgumentNotValidException ex) {
        return ErrorResponse.of(HttpStatus.BAD_REQUEST, ex.getBindingResult().getFieldError().getDefaultMessage());
    }

    @ExceptionHandler(RuntimeException.class)
    @ResponseStatus(HttpStatus.INTERNAL_SERVER_ERROR)
    public ErrorResponse handleRuntimeException(RuntimeException ex) {
        log.error("server error: {}", ex.getMessage(), ex);
        return ErrorResponse.of(HttpStatus.INTERNAL_SERVER_ERROR, "An unknown server error has occurred.");
    }
}

@Slf4j
public class PersonNotFoundException extends RuntimeException {

    private static final String MESSAGE = "Person entity is not exist.";

    public PersonNotFoundException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}

@Slf4j
public class RenameIsNotPermittedException extends RuntimeException {

    private static final String MESSAGE = "Change name is not accepted.";

    public RenameIsNotPermittedException() {
        super(MESSAGE);
        log.error(MESSAGE);
    }
}

public interface PersonRepository extends JpaRepository<Person, Long> {

    List<Person> findByName(String name);

    @Query(value = "select person from Person person where person.birthday.monthOfBirthday = :monthOfBirthday")
    List<Person> findByMonthOfBirthday(@Param("monthOfBirthday") int monthOfBirthday);

    @Query(value = "select * from Person person where person.deleted = true", nativeQuery = true)
    List<Person> findPeopleDeleted();
}

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
        Person person = personRepository.findById(id).orElseThrow(PersonNotFoundException::new);

        person.setName(name);

        personRepository.save(person);
    }

    public void delete(Long id) {
        Person person = personRepository.findById(id).orElseThrow(PersonNotFoundException::new);

        person.setDeleted(true);

        personRepository.save(person);
    }
}

@SpringBootTest
class HelloWorldControllerTest {

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
    void helloWorld() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloWorld"))
                .andExpect(status().isOk())
                .andExpect(MockMvcResultMatchers.content().string("HelloWorld"));
    }

    @Test
    void mockMvcTest() throws Exception {

        mockMvc.perform(
                MockMvcRequestBuilders.get("/api/helloException"))
                .andExpect(status().isInternalServerError())
                .andExpect(jsonPath("$.code").value(500))
                .andExpect(jsonPath("$.message").value("An unknown server error occurred."));
    }
}

SpringBootTest
@Transactional
class PersonControllerTest {

    @Autowired
    private PersonRepository personRepository;

    @Autowired
    private ObjectMapper objectMapper;

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
    public void getAll() throws Exception {

        mockMvc.perform(MockMvcRequestBuilders.get("/api/person")
                .param("page", "1")
                .param("size ","2"))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.totalPage").value(3))
                .andExpect(jsonPath("$.totalElements").value(6))
                .andExpect(jsonPath("$.numberOfElements").value(2))
                .andExpect(jsonPath("$.content.[0].name").value("dennis"))
                .andExpect(jsonPath("$.content.[1].name").value("sophia"));
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

         //then
         mockMvc.perform(
                 MockMvcRequestBuilders.post("/api/person")
                         .contentType(MediaType.APPLICATION_JSON)
                         .content(toJsonString(dto)))
                 .andExpect(status().isBadRequest())
                 .andExpect(jsonPath("$.code").value(500))
                 .andExpect(jsonPath("$.message").value("Name is necessary."));
      }

      @Test
      public void postPersonIfNameIsEmptyString() throws Exception {

          //given
          PersonDto dto = new PersonDto();
          dto.setName("");

          //when
          mockMvc.perform(
                  MockMvcRequestBuilders.post("/api/person")
                          .contentType(MediaType.APPLICATION_JSON)
                          .contentType(toJsonString(dto)))
                  .andExpect(status().isBadRequest())
                  .andExpect(jsonPath("$.code").value(400))
                  .andExpect(jsonPath("$.message").value("Name is necessary."));
       }

       @Test
       public void postPersonIfNameIsBlankString() throws Exception {

           //given
           PersonDto dto = new PersonDto();
           dto.setName(" ");

           //then
           mockMvc.perform(
                   MockMvcRequestBuilders.post("/api/person")
                           .contentType(MediaType.APPLICATION_JSON)
                           .content(toJsonString(dto)))
                   .andExpect(status().isBadRequest())
                   .andExpect(jsonPath("$.code").value(400))
                   .andExpect(jsonPath("$.message").value("Name is Necessary"));

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

@SpringBootTest
class PersonRepositoryTest {

    @Autowired
    private PersonRepository personRepository;

    @Test
    public void findByName() {

        //given
        List<Person> people = personRepository.findByName("tony");
        assertThat(people.size()).isEqualTo(1);

        //when
        Person person = people.get(0);

        //then
        assertAll(
                () -> assertThat(person.getName()).isEqualTo("tony"),
                () -> assertThat(person.getHobby()).isEqualTo("reading"),
                () -> assertThat(person.getAddress()).isEqualTo("seoul"),
                () -> assertThat(person.getBirthday()).isEqualTo(Birthday.of(LocalDate.of(1991, 7, 10))),
                () -> assertThat(person.getJob()).isEqualTo("officer"),
                () -> assertThat(person.getPhoneNumber()).isEqualTo("010-1111-2222"),
                () -> assertThat(person.isDeleted()).isEqualTo(false)
        );
    }

    @Test
    public void findByNameIfDeleted() {

        //given
        List<Person> people = personRepository.findByName("andrew");

        //then
        assertThat(people.size()).isEqualTo(0);
    }

    @Test
    public void findByMonthOfBirthday() {

        //given
        List<Person> people = personRepository.findByMonthOfBirthday(7);

        //when
        assertThat(people.size()).isEqualTo(2);

        //then
        assertAll(
                () -> assertThat(people.get(0).getName()).isEqualTo("david"),
                () -> assertThat(people.get(1).getName()).isEqualTo("tony")
        );
    }

    @Test
    public void findPeopleDeleted() {

        //given
        List<Person> people = personRepository.findPeopleDeleted();

        //when
        assertThat(people.size()).isEqualTo(1);

        //then
        assertThat(people.get(0).getName()).isEqualTo("andrew");
    }
}

@ExtendWith(MockitoExtension.class)
class PersonServiceTest {

    @InjectMocks
    private PersonService personService;

    @Mock
    private PersonRepository personRepository;

    @Test
    public void getAll() {

        //when
        when(personRepository.findAll(any(Pageable.class)))
                .thenReturn(new PageImpl<>(Lists.newArrayList(
                        new Person("martin"),
                        new Person("dennis"),
                        new Person("tony"))));

        Page<Person> result = personService.getAll(PageRequest.of(0, 3));

        //then
        assertThat(result.getNumberOfElements()).isEqualTo(3);
        assertThat(result.getContent().get(0).getName()).isEqualTo("martin");
        assertThat(result.getContent().get(1).getName()).isEqualTo("dennis");
        assertThat(result.getContent().get(2).getName()).isEqualTo("tony");
    }

    @Test
    public void getPeopleByName() {
        when(personRepository.findByName("martin"))
                .thenReturn(Lists.newArrayList(new Person("martin")));

        List<Person> result = personService.getPeopleByName("martin");

        assertThat(result.size()).isEqualTo(1);
        assertThat(result.get(0).getName()).isEqualTo("martin");
    }

    @Test
    public void getPerson() {
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        Person person = personService.getPerson(1L);

        assertThat(person.getName()).isEqualTo("martin");
    }

    @Test
    public void getPersonIfNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when
        Person person = personService.getPerson(1L);

        //then
        assertThat(person).isNull();
    }

    @Test
    public void put() {

        //when
        personService.put(mockPersonDto());

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeInserted()));

    }

    @Test
    public void modifyIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    public void modifyIfNameIsDifferent() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("tony")));

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, mockPersonDto()));
    }

    @Test
    public void modify() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.modify(1L, mockPersonDto());

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeUpdated()));
    }

    @Test
    public void modifyByNameIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //when

        //then
        assertThrows(RuntimeException.class, () -> personService.modify(1L, "daniel"));
    }

    @Test
    public void modifyByName() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.modify(1L, "daniel");

        //then
        verify(personRepository, times(1)).save(argThat(new IsNameWillBeUpdated()));
    }

    @Test
    public void deleteIfPersonNotFound() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.empty());

        //then
        assertThrows(RuntimeException.class, () -> personService.delete(1L));
    }

    @Test
    public void delete() {

        //given
        when(personRepository.findById(1L))
                .thenReturn(Optional.of(new Person("martin")));

        //when
        personService.delete(1L);

        //then
        verify(personRepository, times(1)).save(argThat(new IsPersonWillBeDeleted()));
    }

    private PersonDto mockPersonDto() {

        return PersonDto.of("martin", "programming", "pangyo", LocalDate.now(), "programmer", "010-1111-2222");
    }

    private static class IsPersonWillBeInserted implements ArgumentMatcher<Person> {

        @Override
        public boolean matches(Person person) {
            return equals(person.getName(), "martin")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "pangyo")
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
            return equals(person.getName(), "martin")
                    && equals(person.getHobby(), "programming")
                    && equals(person.getAddress(), "pangyo")
                    && equals(person.getBirthday(), Birthday.of(LocalDate.now()))
                    && equals(person.getJob(), "programmer")
                    && equals(person.getPhoneNumber(), "010-1111-2222");
        }

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
