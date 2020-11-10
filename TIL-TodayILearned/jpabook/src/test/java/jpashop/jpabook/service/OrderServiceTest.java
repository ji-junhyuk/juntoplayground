package jpashop.jpabook.service;

import jpashop.jpabook.domain.Member;
import jpashop.jpabook.domain.Order;
import jpashop.jpabook.domain.OrderStatus;
import jpashop.jpabook.domain.item.Book;
import jpashop.jpabook.domain.item.Item;
import jpashop.jpabook.repository.OrderRepository;
import org.apache.tomcat.jni.Address;
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
    public void orderItem() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);
        int orderCount = 2;

        //when
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals("When ordering the product, the status is ORDER", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("The number of product types ordered must be correct.", 1, getOrder.getOrderItems().size());
        assertEquals("Order price is price * quantity", 10000 * 2, getOrder.getTotalPrice());
        assertEquals("The stock should be reduced by the order quantity", 8, item.getStockQuantity());
    }

    @Test
    public void productOrder_StockqQantityExceeded() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("There should be a shortage of stock exception");
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