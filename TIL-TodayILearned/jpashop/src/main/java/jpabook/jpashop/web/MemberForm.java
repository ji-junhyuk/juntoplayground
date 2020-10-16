package jpabook.jpashop.web;

import javax.validation.constraints.NotEmpty;

@Getter
@Setter
public class MemberForm {

    @NotEmpty(message = "Member name is necessary.")
    private String name;

    private String city;
    private String street;
    private String zipcode;
}
