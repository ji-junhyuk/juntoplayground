package hello.hellospring.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.Entity;

@Entity
@Getter @Setter
public class Member {

    private Long id;
    private String name;
}
