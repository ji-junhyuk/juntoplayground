package spring.YHJpa.web;

import lombok.Getter;
import lombok.Setter;

import javax.validation.constraints.NotEmpty;

@Getter
@Setter
public class MemberForm {

    @NotEmpty(message = "Mamber name is necessary")
    private String name;

    private String city;
    private String street;
    private String zipcode;
}
