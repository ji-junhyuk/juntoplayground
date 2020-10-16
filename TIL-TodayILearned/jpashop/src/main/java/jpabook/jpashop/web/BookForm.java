package jpabook.jpashop.web;

import com.fasterxml.jackson.annotation.JsonAnyGetter;
import com.fasterxml.jackson.annotation.JsonAnySetter;

@JsonAnyGetter
@JsonAnySetter
public class BookForm {

    private Long id;

    private String name;
    private int price;

    private int stockQuantity;

    private String author;
    private String isbn;
}
