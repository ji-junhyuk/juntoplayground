package jpabook.jpashop;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class OrderService {

    private final MemberRepository memberRepository;
    private final OrderRepository orderRepository;
    private final ItemService itemService;

    @Transactional
    public Long Order(Long memberId, Long itemId, int count) {
        //entity lookup
        Member member = memberRepository.findOne(memberId);
        Item item = itemService.findOne(itemId);

        //Create shipping information
        Delivery delivery = new Delivery();
        delivery.setAddress(member.getAddress());
        delivery.setStatus(DeliveryStatus.READY);

        //Create order item.
        OrderItem.createOrderItem(item, item.getPrice(), count);

        //Create order
        Order order = Order.createOrder(member, delivery, orderItem);

        //Store Order
        orderRepository.save(order);
        return order.getId();
    }

    /*
    Cancel order
     */
    @Transactional
    public void cancelOrder(Long orderId) {

        //Order entity lookup
        Order order = orderRepository.findOne(orderId);

        //Cancel order
        order.cancel();
    }
//    *Search order
//    public List<Order> findOrders(OrderSearch ordersearch) {
//        return orderRepository.findAll(OrderSearch);
//    }
}
