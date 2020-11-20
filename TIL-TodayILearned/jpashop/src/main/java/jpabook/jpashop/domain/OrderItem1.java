package jpabook.jpashop.domain;

import jpabook.jpashop.domain.item.Item;
import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;

@Entity
@Table(name = "order_item")
@Getter
@Setter
public class OrderItem1 {

    @Id
    @GeneratedValue
    @Column(name = "order_item_id")
    private Long id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "item_id")
    private Item item;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "order_id")
    private Order order;

    private int orderPrice;
    private int count;

    //==Create Method==//
    public static OrderItem1 createOrderItem(Item item, int orderPrice, int count) {
        OrderItem1 orderItem1 = new OrderItem1();
        orderItem1.setItem(item);
        orderItem1.setOrderPrice(orderPrice);
        orderItem1.setCount(count);

        item.removeStock(count);
        return orderItem1;
    }

    //==Business Logic==//
    /*
    Cancel order
     */
    public void cancel() {
        getItem().addStock(count);
    }

    //==Lookup logic==//
    /*
    Display price of all orders
     */
    public int getTotalPrice() {
        return getOrderPrice() * getCount();
    }
}
