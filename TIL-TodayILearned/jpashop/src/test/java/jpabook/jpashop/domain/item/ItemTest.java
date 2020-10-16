package jpabook.jpashop.domain.item;

import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.OrderStatus;
import org.junit.Test;

import static org.junit.Assert.*;

public class ItemTest {

    @Test
    public void orderCancel() {
        //given
        Member member = new Member();
        Item item = createBook("Country JPA", 10000, 10);
        int orderCount = 2;

        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);
        //when
        orderService.cancelOrder(orderId);

        //then
        order getOrder = orderRepository.findOne(orderId);

        assertEquals("When canceling an order, the status is CANCEL.", OrderStatus.CANCEL,
                getOrder.getStatus());
        assertEquals("Products with canceled orders should increase inventory accordingly.", 10,
                item.getStockQuantity());
    }

}