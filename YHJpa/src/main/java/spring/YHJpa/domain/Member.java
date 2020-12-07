package spring.YHJpa.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.Embedded;
import javax.persistence.Entity;
import javax.persistence.OneToOne;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
public class Member {

    private Long id;
    private String name;

    @Embedded
    private Address address;

    @OneToOne
    private List<Order> orders = new ArrayList<>();
}
