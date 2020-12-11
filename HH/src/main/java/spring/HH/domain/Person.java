package spring.HH.domain;

import lombok.*;
import org.springframework.web.bind.annotation.RestController;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import java.time.LocalDate;
import java.util.Objects;

@Entity
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
@RequiredArgsConstructor
@EqualsAndHashCode
@Data
public class Person {

    @Id
    @GeneratedValue
    @ToString.Exclude
    private Long id;

    @NonNull
    private String name;

    @NonNull
    private int age;

    private String hobby;

    private LocalDate birthday;
}
