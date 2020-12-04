package spring.YHJpa.web;

import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotEmpty;

@Getter
@Setter
public class MemberForm {

    @NotEmpty(message = "Member name is necessary")
    private String id;
    private String pwd;
    private String pwd2;

    private String name;

    private String city;
    private String street;
    private String zipcode;
}
