package hellospring.foundation.service;

import hellospring.foundation.discount.DiscountPolicy;
import hellospring.foundation.domain.*;
import hellospring.foundation.domain.item.Item;
import hellospring.foundation.repository.ItemRepository;
import hellospring.foundation.repository.MemberRepository;
import hellospring.foundation.repository.OrderRepository;
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

    @Transactional
    public Long order(Long memberId, Long itemId, int count) {

        //lookup entity
        Member member = memberRepository.findOne(memberId);
        Item item = itemRepository.findOne(itemId);

        //create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //create ordered item
        OrderItem orderItem = OrderItem.createOrderItem(item, item.getPrice(), count);

        //create order
        Order order = Order.createOrder(member, delivery, orderItem);

        //store order
        orderRepository.save(order);
        return order.getId();
    }

    /**
     * Cancel order
     */
    @Transactional
    public void cancelOrder(Long orderId) {
        Order order = orderRepository.findOne(orderId);
        order.cancel();
    }

//    private final MemberRepository memberRepository;
//    private final DiscountPolicy discountPolicy;
//
//
//    @Override
//    public Order createOrder(Long id, String itemName, int itemPrice) {
//        Member member = memberRepository.findById(id).get();
//        int discountPrice = discountPolicy.discount(member, itemPrice);
//
//        return new Order(Long id, itemName, itemPrice, discountPrice);
//    }
}
