package jpashop.jpabook.domain;

import lombok.Getter;
import lombok.Setter;
import org.apache.tomcat.jni.Address;
import org.hibernate.criterion.Order;

import javax.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
public class Member {

    @Id
    @GeneratedValue
    @Column(name = "member_id")
    private Long id;

    private String name;

    @Embedded
    private Address address;

    @OneToMany(mappedBy = "orders")
    private List<Order> orders = new ArrayList<>();
}
