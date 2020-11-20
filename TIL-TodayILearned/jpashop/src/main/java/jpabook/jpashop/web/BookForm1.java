package jpabook.jpashop.web;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class BookForm1 {

    private Long id;

    private String name;
    private int price;
    private int stockQuantity;

    private String author;
    private String isbn;
}
