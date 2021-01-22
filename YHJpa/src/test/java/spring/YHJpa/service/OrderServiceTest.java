package spring.YHJpa.service;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.Address;
import spring.YHJpa.domain.Member;
import spring.YHJpa.domain.Order;
import spring.YHJpa.domain.OrderStatus;
import spring.YHJpa.domain.item.Book;
import spring.YHJpa.domain.item.Item;
import spring.YHJpa.exception.NotEnoughtStockException;
import spring.YHJpa.repository.OrderRepository;

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
    void orderProduct() throws Exception {

        //Given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);
        int orderCount = 2;

        //When
        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //Then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals(OrderStatus.ORDER, getOrder.getStatus(),
                "When ordering the product, the status is ORDER.");
        assertEquals(1, getOrder.getOrderItems().size(),
                "The number of Product types ordered must be correct.");
        assertEquals(10000 * 2, getOrder.getTotalPrice(),
                "Order price is price * quantity.");
        assertEquals(8, item.getStockQuantity(),
                "Stock should be reduced by the order quantity.");
    }

    @Test
    void orderProduct_inventoryQuantityExceeded() throws Exception {

        //Given
        Member member = createMember();
        Item item = createBook("country JPA", 10000, 10);
        int orderCount = 11;

        //When
        NotEnoughtStockException e = assertThrows(NotEnoughtStockException.class, () -> orderService.order(member.getId(), item.getId(), orderCount));

        //Then
        assertEquals(e.getMessage(), "need more stock.");
    }

    @Test
    void cancelOrder() {

        //Given
        Member member = createMember();
        Item item = createBook("country JPA", 20000, 20);
        int orderCount = 10;

        Long orderId = orderService.order(member.getId(), item.getId(), orderCount);

        //When
        orderService.cancelOrder(orderId);

        //Then
        Order getOrder = orderRepository.findOne(orderId);

        assertEquals(OrderStatus.CANCEL, getOrder.getStatus(),
                "When canceling an order, the status is CANCEL.");
        assertEquals(20, item.getStockQuantity(),
                "Products whose orders have been canceled should increase inventory accordingly.");

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