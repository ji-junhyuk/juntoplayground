package jpabook.jpashop.service;

import jpabook.jpashop.domain.*;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.ItemRepository1;
import jpabook.jpashop.repository.MemberRepositoryImplXXX;
import jpabook.jpashop.repository.OrderRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService1 {

    private final MemberRepositoryImplXXX memberRepositoryImplXXX;
    private final OrderRepository orderRepository;
    private final ItemRepository1 itemRepository1;

    /*
    Order
     */
    @Transactional
    public Long order(Long memberId, Long itemId, int count) {

        //Lookup entity
        Member member = memberRepositoryImplXXX.findOne(memberId);
        Item item = itemRepository1.findOne(itemId);

        //Create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //Create ordered product
        OrderItem1 orderItem = OrderItem1.createOrderItem(item, item.getPrice(), count);

        //Create order
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

        Order order = orderRepository.findOne(orderId);

        order.cancel();
    }
}
