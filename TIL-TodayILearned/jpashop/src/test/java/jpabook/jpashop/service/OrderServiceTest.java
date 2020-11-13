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

    @Autowired
    OrderService orderService;

    @Autowired
    OrderRepository orderRepository;

    @Test
    public void orderProduct() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);
/*
        assertEquals("When ordering the product, the status is ORDER.", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct", 1, getOrder.getOrderItems().size());
        assertEquals("Order price is price * quantity", 10000 * 2, getOrder.getTotalPrice());
        assertEquals("Stock should be reduced by the order quantity", 8, item.getStockQuantity());
*/
    }

    @Test
    public void productOrder_stockQuantityExceeded() throws Exception {
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);

        int orderCount = 11;

        orderService.order(member.getId(), item.getId(), orderCount);

        fail("An out of stock exception should be made.");
    }

    @Test
    public void orderCancel() {
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);
        int orderCount = 2;

        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

//        orderService.cancelOrder(orderId);

        orderRepository.findOne(orderId);

/*
        assertEquals("When canceling an order, the status is CANCEL.", OrderStatus.CANCEL, getOrder.getStatus);
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