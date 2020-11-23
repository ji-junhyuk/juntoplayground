package hellospring.JPA1.service;

import hellospring.JPA1.domain.*;
import hellospring.JPA1.domain.item.Item;
import hellospring.JPA1.repository.ItemRepository;
import hellospring.JPA1.repository.MemberRepository;
import hellospring.JPA1.repository.OrderRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final MemberRepository memberRepository;
    private final OrderRepository orderRepository;
    private final ItemRepository itemRepository;

    /*
    Order
     */
    public Long order(Long memberId, Long itemId, int count) {

        //Lookup entity
        Member member = memberRepository.findOne(memberId);
        Item item = itemRepository.findOne(itemId);

        //Create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //Create Ordered item
        OrderItem orderItem = OrderItem.createOrderItem(item, item.getPrice(), count);

        //create order
        Order order = Order.createOrder(member, delivery, orderItem);

        //Store order
        orderRepository.save(order);
        return order.getId();
    }

    /*
    Cancel order
     */

    @Transactional
    public void cancelOrder(Long orderId) {

        //lookup order entity
        Order order = orderRepository.findOne(orderId);

        //cancel order
        order.cancel();
    }
}
