package jpabook.jpashop.service;

import jpabook.jpashop.domain.*;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.MemberRepository;
import jpabook.jpashop.repository.OrderRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final MemberRepository memberRepository;
    private final OrderRepository orderRepository;
    private final ItemService itemService;

    @Transactional
    public Long order(Long memberId, Long itemId, int count) {

        //Lookup entity
        Member member = memberRepository.findOne(memberId);
        Item item = itemService.findOne(itemId);

        //Create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //Create orderItem
        OrderItem orderItem = OrderItem.createOrderItem(item, item.getPrice(), count);

        //Create order
        Order order = Order.createOrder(member, delivery, orderItem);//Order order

        //Store order
        orderRepository.save(order);
        return order.getId();
    }

    @Transactional
    public void cancelOrder(Long orderId) {

        //Lookup entity
        Order order = orderRepository.findOne(orderId);
        order.cancel();
    }
}
