package spring.HH.domain;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;

@Entity
@Getter
@Setter
@ToString

public class Person {

    @Id
    @GeneratedValue
    @ToString.Exclude
    private Long id;

    private String name;

    private int age;
}
