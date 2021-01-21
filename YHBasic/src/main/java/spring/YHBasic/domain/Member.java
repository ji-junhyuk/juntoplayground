package spring.YHBasic.domain;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;
import spring.YHBasic.domain.Grade;

@Getter
@Setter
@AllArgsConstructor
public class Member {

    private Long id;
    private String name;
    private Grade grade;
}
