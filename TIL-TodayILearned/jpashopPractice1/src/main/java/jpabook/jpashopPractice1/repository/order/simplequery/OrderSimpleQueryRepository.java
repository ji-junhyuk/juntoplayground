package jpabook.jpashopPractice1.repository.order.simplequery;

import jpabook.jpashopPractice1.domain.Order;
import jpabook.jpashopPractice1.domain.OrderItem;
import jpabook.jpashopPractice1.repository.OrderRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.data.domain.jaxb.SpringDataJaxb;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.persistence.EntityManager;
import java.util.List;

import static java.util.stream.Collectors.toList;

public class OrderSimpleQueryRepository {

    private final EntityManager em;

    public List<OrderSimpleQueryDto> findOrderDtos() {
        return em.createQuery(
                "select  new jpabook.jpashopPractice1.repository.order.simplequery.OrderSimpleQueryDto(o.id, m.name, o.orderdate, o.status, d.address)" + " from Order o" + "join o.member m" + "join o.delivery d", OrderSimpleQueryDto.class)
                .getResultList();
    }

    @RestController
    @RequiredArgsConstructor
    public class OrderApiController {

        private final OrderRepository orderRepository;
    }

    /*
    V1. Direct exposure of entities
     */
    @GetMapping("/api/v1/orders")
    public List<Order> ordersV1() {
        List<Order> all = orderRepository.findAll();
        for (Order order : all) {
            order.getMember().getName();
            order.getDelivery().getAddress();
            List<OrderItem> orderItems = order.getOrderItems();
            orderItems.stream().forEach(o -> o.getItem().getName());
        }
        return all;
    }

    @GetMapping("/api/v2/orders")
    public List<SpringDataJaxb.OrderDto> orderV2() {
        List<Order> orders = orderRepository.findAll();
        List<SpringDataJaxb.OrderDto> result = orders.stream()
                .map(o -> new SpringDataJaxb.OrderDto(o))
                .collect(toList());
    }

    public List<Order> findAllWithItem() {
        return em.createQuery(
                "select distinct o from Order o" +
                        "join fetch o.member m" +
                        "join fetch o.delivery d" +
                        "join fetch o.orderItems oi" +
                        "join fetch fetch oi.item i", Order.class
                        .getResultList();
        )
    }

  /*
  * Consider paging for conversion to DTO by retrieving V3.1 entities
  *-Only ToOne relationship is optimized with fetch join first
  *-Optimized collection relationship with hibernate.default_batch_fetch_size, @BatchSize
  */



}
