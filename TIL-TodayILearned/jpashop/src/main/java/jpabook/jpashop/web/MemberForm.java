package jpabook.jpashop.web;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class MemberForm {

    @NotEmpty(message = "Member name is necessary.")
    private String name;

    private String city;
    private String street;
    private String zipcode;
}
