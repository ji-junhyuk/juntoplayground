package jpabook.jpashop.domain;

import lombok.Getter;
import lombok.Setter;

import javax.persistence.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "orders")
@Getter
@Setter
public class Order {

    @Id
    @GeneratedValue
    @Column(name = "order_id")
    private Long id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "member_id")
    private Member member;

    @OneToMany(mappedBy = "order", cascade = CascadeType.ALL)
    private List<OrderItem1> orderItem1s = new ArrayList<>();

    @OneToOne(cascade = CascadeType.ALL, fetch = FetchType.LAZY)
    @JoinColumn(name = "delivery_id")
    private Delivery delivery;

    private LocalDateTime orderDate;

    @Enumerated(EnumType.STRING)
    private OrderStatus status;

    //==Association Method==//
    public void setMember(Member member) {
        this.member = member;
        member.getOrders().add(this);
    }

    public void addOrderItem(OrderItem1 orderItem1) {
        orderItem1s.add(orderItem1);
        orderItem1.setOrder(this);
    }

    public void setDelivery(Delivery delivery) {
        this.delivery = delivery;
        delivery.setOrder(this);
    }

    //==Create Method==//
    public static Order createOrder(Member member, Delivery delivery, OrderItem1... orderItem1s) {
        Order order = new Order();
        order.setMember(member);
        order.setDelivery(delivery);
        for (OrderItem1 orderItem1 : orderItem1s) {
            order.addOrderItem(orderItem1);
        }
        order.setStatus(OrderStatus.ORDER);
        order.setOrderDate(LocalDateTime.now());
        return order;
    }

    //==Business Logic==//
    /*
    Cancel order
     */
    public void cancel() {
        if (delivery.getStatus() == DeliveryStatus.COMP) {
            throw new IllegalStateException("Products that have been delivered cannot be canceled.");
        }
        this.setStatus(OrderStatus.CANCEL);
        for (OrderItem1 orderItem1 : orderItem1s) {
            orderItem1.cancel();
        }
    }

    //==Lookup logic==//
    /*
    Display price for all orders
     */
    public int getTotalPrice() {
        int totalPrice = 0;
        for (OrderItem1 orderItem1 : orderItem1s) {
            totalPrice += orderItem1.getTotalPrice();
        }
        return totalPrice;
    }
}
