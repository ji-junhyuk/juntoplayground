package jpabook.jpashop.service;

import jpabook.jpashop.domain.Address;
import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.Order;
import jpabook.jpashop.domain.OrderStatus;
import jpabook.jpashop.domain.item.Book;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.repository.OrderRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@Transactional
class OrderService1Test {
    
    @PersistenceContext
    EntityManager em;

    @Autowired
    OrderService1 orderService1;
    @Autowired
    OrderRepository orderRepository;
    
    @Test
    public void orderProduct() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService1.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);

/*
        assertEquals("When ordering a product, the status is ORDER", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct", 1, getOrder.getOrderItem1s().size());
        assertEquals("Order price is price * quantity", 10000 * 2, getOrder.getTotalPrice());
        assertEquals("Stock should be reduced by the quantity ordered.", 8, item.getStockQuantity());
*/
    }
    @Test
    public void productOrder_stockQuantityExceeded() throws Exception {
/*
        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService1.order(member.getId(), item.getId(), orderCount);

        //then
        fail("There should be an out of stock exception.");
*/
     }

     @Test
     public void orderCancel() throws Exception {
         //given
         Member member = createMember();
         Item item = createBook("country JPA", 10000, 10);
         int orderCount = 2;

         Long orderId = orderService1.order(member.getId(), item.getId(), orderCount);

         //when
         orderService1.cancelOrder(orderId);

         //then
         Order getOrder = orderRepository.findOne(orderId);

/*
         assertEquals("When canceling an order, the status is cancel", OrderStatus.CANCEL, getOrder.getStatus());
         assertEquals("Products whose orders have been canceled should increase inventory accordingly.", 10, item.getStockQuantity());
*/

     }

    private Member createMember() {
        Member member = new Member();
        member.setName("member1");
        member.setAddress(new Address("Seoul", "River", "123-123"));
        em.persist(member);
        return member;
    }

    private Book createBook(String name, int price, int stockQuantity) {
        Book book = new Book();
        book.setName(name);
        book.setStockQuantity(stockQuantity);
        book.setPrice(price);
        em.persist(book);
        return book;
    }
}