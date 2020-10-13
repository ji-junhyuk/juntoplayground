package jpabook.jpashop;

import org.junit.Test;

import static org.junit.Assert.*;

public class ItemTest {

    @Test
    public void orderCancel() {
        //given
        Member member = createMember();
        Item item = createBook("Country Jpa", 10000, 10);
        int orderCount = 2;

        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //when
        orderService.cancelOrder(orderId);

        //then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals("When canceling an order, the status is cancel.", OrderStatus.CANCEL, getOrder.getStatus());
        assertEquals("Products whose orders have been canceled must increase their inventory accordingly", 10, item.getStockQuantity());

    }
}