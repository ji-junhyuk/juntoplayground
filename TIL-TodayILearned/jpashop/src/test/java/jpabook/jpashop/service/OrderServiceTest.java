package jpabook.jpashop.service;

import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.Order;
import jpabook.jpashop.domain.OrderStatus;
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
        //Given
        Member member = createMember();
        Item item = createBook("Countury JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(OrderId);

        assertEquals("When ordering products, the status is ORDER.", OrderStatus.ORDER,
                getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct.", 1,
                getOrder.getOrderItems().size());
        assertEquals("Order Price is price * quantity.", 10000 * 2,
                getOrder.getTotalPrice());
        assertEquals("The stock should be reduced by the order quantity", 8,
                item.getStockQuantity());
    }

    @Test(expected = NotEnoughStockException.class)
    public void orderItemInventoryExceeded() throws Exception {

    }

    @Test
    public void orderCancel() {
    }

    private Member createMember() {
        Member member = new Member();
        member.setName(name);
        book.setStockQuantity(stockQuantity);
        book.setPrice(price);
        em.persist(book);
        return book;
    }

    @Test(expected = NotEnoughStockException.class)
    public void orderItemInventoryExceeded() throws Exception {
        //given
        Member member = new Member();
        Item item = createBook(Country JPA, 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("Out of stock exception should be thrown.");
    }

}