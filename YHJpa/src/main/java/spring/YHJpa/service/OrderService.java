package spring.YHJpa.service;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.*;
import spring.YHJpa.domain.item.Item;
import spring.YHJpa.repository.ItemRepository;
import spring.YHJpa.repository.MemberRepository;
import spring.YHJpa.repository.OrderRepository;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final MemberRepository memberRepository;
    private final OrderRepository orderRepository;
    private final ItemRepository itemRepository;

    @Transactional
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

        //Create Order
        Order order = Order.createOrder(member, delivery, orderItem);

        //Store Order
        orderRepository.save(order);
        return order.getId();
    }

    /**
     * cancellation order
     */
    @Transactional
    public void cancelOrder(Long orderId) {
        //lookup order entity
        Order order = orderRepository.findOne(orderId);

        //cancel order
        order.cancel();
    }

    /**
     * search order
     */
    public List<Order> findOrders(OrderSearch orderSearch) {
        return orderRepository.findAllByString(orderSearch);
    }
}
