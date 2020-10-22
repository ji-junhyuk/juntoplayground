package jpabook.jpashop.service;

import jpabook.jpashop.domain.Address;
import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.Order;
import jpabook.jpashop.domain.OrderStatus;
import jpabook.jpashop.domain.item.Book;
import jpabook.jpashop.domain.item.Item;
import jpabook.jpashop.exception.NotEnoughStockException;
import jpabook.jpashop.repository.OrderRepository;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;

import static org.junit.Assert.*;

@RunWith(SpringRunner.class)
@SpringBootTest
@Transactional
public class OrderServiceTest {

    @PersistenceContext
    EntityManager em;

    @Autowired
    OrderService orderService;

    @Autowired
    OrderRepository orderRepository;

    @Test
    public void orderItem() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Countury JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals("When ordering products, the status is order.", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct.", 1, getOrder.getOrderItems().size());
        assertEquals("Order price is PRICE * QUANTITY", 10000, 2, getOrder.getTotalPrice());
        assertEquals("The stock should be reduced by the order quantity", 8, item.getStockQuantity());
    }

    @Test(expected = NotEnoughStockException.class)
    public void orderItemInventoryQuantityExceeded() throws Exception {

        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("Out of stock exception should be thrown.");
    }

    @Test
    public void cancelOrder() {
        //given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);
        int orderCount = 2;

        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //when
        orderService.cancelOrder(orderId);

        //then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals("When canceling an order, the status is CANCEL", OrderStatus.CANCEL, getOrder.getStatus());
        assertEquals("Products with canceled orders should increase inventory accordingly.", 10, item.getStockQuantity());

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