package spring.YHJpa.service;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.*;
import spring.YHJpa.domain.item.Item;
import spring.YHJpa.repository.ItemRepository;
import spring.YHJpa.repository.MemberRepository;
import spring.YHJpa.repository.OrderRepository;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final MemberRepository memberRepository;
    private final ItemRepository itemRepository;
    private final OrderRepository orderRepository;

    /*
    Order
     */
    @Transactional
    public Long order(Long memberId, Long itemId, int count) {

        //lookup entity
        Member member = memberRepository.findOne(memberId);
        Item item = itemRepository.findOne(itemId);

        //Create delivery information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //Create ordered item
        OrderItem orderItem = OrderItem.createOrderItem(item, item.getPrice(), count);

        //create Order
        Order order = Order.createOrder(member, delivery, orderItem);

        //store Order
        orderRepository.save(order);
        return order.getId();
    }

    /*
    cancel order
     */
    @Transactional
    public void cancelOrder(Long orderId) {
        //Lookup order entity
        Order order = orderRepository.findOne(orderId);
        //cancel order
        order.cancel();
    }
}
