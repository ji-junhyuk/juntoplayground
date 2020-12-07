package spring.YHJpa.domain.item;

import lombok.Getter;
import lombok.Setter;
import spring.YHJpa.domain.Address;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
public class Category {

    @Id
    @GeneratedValue
    @Column(name = "category_id")
    private Long id;

    private String name;

    @ManyToMany
    private List<Item> items = new ArrayList<>();

    private Address parent;

    private Address child;
}
