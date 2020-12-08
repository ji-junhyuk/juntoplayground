package spring.YHJpa.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
public class Member {

    private String id;

    @Id
    @GeneratedValue
    @Column(name = "number")
    private Long number;

    private String pwd;

    private String pwd2;

    private String name;

    @Embedded
    private Address address;

    @OneToMany(mappedBy = "member")
    private List<Order> orders = new ArrayList<>();
}