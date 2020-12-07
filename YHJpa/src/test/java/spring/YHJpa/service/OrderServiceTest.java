package spring.YHJpa.service;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.Address;
import spring.YHJpa.domain.Member;
import spring.YHJpa.domain.Order;
import spring.YHJpa.domain.OrderStatus;
import spring.YHJpa.domain.item.Book;
import spring.YHJpa.domain.item.Item;
import spring.YHJpa.exception.NotEnoughStockException;
import spring.YHJpa.repository.OrderRepository;

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
    public void orderProduct() throws Exception {

        //given
        Member member = createMember();
        Item item = createBook("JPA", 10000, 10);

        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals("When ordering the product, the status is ORDER.", OrderStatus.ORDER,
                getOrder.getStatus());
        assertEquals("The number of items ordered must be correct.", 1,
                getOrder.getOrderItems().size());
        assertEquals("Order price is price * quantity.", 10000 * 2,
                getOrder.getTotalPrice());
        assertEquals("The stock must be reduced by the order quantity.", 8,
                item.getStockQuantity());
    }

    @Test(expected = NotEnoughStockException.class)
    public void orderInventoryQuantityExceeded() throws Exception {

        //given
        Member member = createMember();
        Item item = createBook("JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("There should be an out of stock exception.");
     }

     @Test
     public void cancelOrder() throws Exception {

         //given
         Member member = createMember();
         Item item = createBook("JPA", 10000, 10);

         int orderCount = 2;

         Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

         //when
         orderService.cancelOrder(orderId);

         //then
         Order getOrder = orderRepository.findOne(orderId);

         assertEquals("When canceling an order, the status is CANCEL", OrderStatus.CANCEL,
                 getOrder.getStatus());
         assertEquals("Products with cancecled orders must increase inventory accordingly",
                 10, item.getStockQuantity());
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