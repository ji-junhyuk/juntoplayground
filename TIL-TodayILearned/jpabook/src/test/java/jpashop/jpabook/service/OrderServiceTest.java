package jpashop.jpabook.service;

import jpashop.jpabook.domain.Address;
import jpashop.jpabook.domain.Member;
import jpashop.jpabook.domain.Order;
import jpashop.jpabook.domain.OrderStatus;
import jpashop.jpabook.domain.item.Book;
import jpashop.jpabook.domain.item.Item;
import jpashop.jpabook.repository.OrderRepository;
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
    @Autowired
    OrderRepository orderRepository;

    @Test
    public void itemOrder() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);
        int orderCount = 2;

        // when
        Order getOrder = orderRepository.findOne(orderId);

        //then
        orderRepository.findOne(orderId);
        assertEquals("OrderItem status is ORDER", OrderStatus.ORDER, getOrder.getStatus());
        assertEquals("orderItem is accurate", 1, getOrder.getOrderItem().size());
        assertEquals("OrderPrice is Price * quantity", 10000 * 2, getOrder.getTotalPrice());
        assertEquals("inventory is dreacred according to orderItem", 8, item.getStockQuantity());
    }

    @Test
    public void orderItem_InvetoryExceed() throws Exception {
        //given
        Member member = createMember();
        Item item = createBook("Country JPA", 10000, 10);

        int orderCount = 11;

        //when
        orderService.order(member.getId(), item.getId(), orderCount);

        //then
        fail("Inventory lack error occurred.");
     }

     @Test
     public void orderCancel() throws Exception {
         //given
         Member member = createMember();
         Item item = createBook("Country JPA", 10000, 10);
         int orderCount = 2;

         Long orderId = orderService.order(member.getId(), item.getId(), orderCount);
         //when
         orderService.cancelOrder(orderId);

         //then
         Order getOrder = orderRepository.findOne(orderId);

         assertEquals("OrderCancel status Cancel", OrderStatus.CANCEL, getOrder
                 .getStatus());
         assertEquals("Canceld items must be increase as well", 10, item.getStockQuantity());

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