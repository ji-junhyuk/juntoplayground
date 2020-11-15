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
class OrderServiceTest {

    @PersistenceContext
    EntityManager em;

    @Autowired OrderService orderService;
    @Autowired OrderRepository orderRepository;

    @Test
    public void orderProduct() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);

/*
        assertEquals("When ordering the product, the status is ORDER", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct.", 1, getOrder.getStatus());
        assertEquals("Order price is price * quantity", 10000 * 2, getOrder.getTotalPrice());
        assertEquals("Stock should be reduced by the order quantity.",8,item.getStockQuantity());
*/
    }

    @Test
    public void productOrder_inventoryExceeded() throws Exception {
/*
        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("Out of stock exception should be raised.");
*/
     }
     @Test
     public void cancellationOrder() {
/*
         //given
         Member member = createMember();
         Item item = createMember("country JPA", 10000, 10);
         int orderCount = 2;

         Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

         //when
         orderService.cancelOrder(orderId);

         //then
         Order getOrder = orderRepository.findOne(orderId);
*/
/*
         assertEquals("When canceling an order, the status is CANCEL", OrderStatus.CANCEL, getOrder.getStatus());
         assertEquals("Products whose orders have been canceled should increase their inventory accordingly.", 10, item.getStockQuantity());
*/
     }
    private Member createMember() {
        Member member = new Member();
        member.setName("member1");
        member.setAddress(new Address("seoul", "river", "123 - 123"));
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