package jpabook.jpashopPractice1.api;

import com.fasterxml.jackson.datatype.hibernate5.Hibernate5Module;
import jpabook.jpashopPractice1.domain.Address;
import jpabook.jpashopPractice1.domain.Order;
import jpabook.jpashopPractice1.domain.OrderItem;
import jpabook.jpashopPractice1.domain.OrderStatus;
import jpabook.jpashopPractice1.repository.OrderRepository;
import jpabook.jpashopPractice1.repository.order.simplequery.OrderSimpleQueryDto;
import lombok.Data;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.data.domain.jaxb.SpringDataJaxb;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.time.LocalDateTime;
import java.util.List;

import static java.util.stream.Collectors.toList;

public class OrderSimpleApiController {

    /*
    xToOne Relation Optimization
    Order
    Order -> Member
    Order -> delivery
     */
    @RestController
    @RequiredArgsConstructor
    public class OrderSimpleApiController {

        private final OrderRepository orderRepository;
    }

    /*
     * V1. Direct exposure of entities
     * - Hibernate5Module module registration.
     * - Two-way relationship problem occurred. -> @JsonIgnore
     */

    @GetMapping("api/v1/simple-orders")
    public List<Order> ordersV1() {
        List<Order> all = orderRepository.findAll();
        for (Order order : all) {
            order.getMember().getName(); // Lazy forced initialization.
            order.getDelivery().getAddress(); // Lazy forced initialization.
        }
        return all;
    }

    @Bean
    Hibernate5Module hibernate5Module() {
        return new Hibernate5Module();
    }

    /*
     * V2. Query entities and convert them to DTO (using fetch join X)
     * - Disadvantage: Queries N times with delayed loading
     */

    @GetMapping("/api/v2/simple-orders")
    public List<SimpleOrderDto> ordersV2() {
        List<Order> orders = orderRepository.findAll();
        List<SimpleOrderDto> result = orders.stream()
                .map(o -> new SimpleOrderDto(o))
                .collect(toList());

        return result;
    }

    @Data
    static class SimpleOrderDto {

        private Long orderId;
        private String name;
        private LocalDateTime orderDate;
        private OrderStatus orderStatus;
        private Address address;

        public SimpleOrderDto(Order order) {
            orderId = order.getId();
            name = order.getMember().getName();
            orderDate = order.getOrderDate();
            orderStatus = order.getStatus();
            address = order.getDelivery().getAddress();
        }

        @Data
        static class OrderItemDto {

            private String itemName;
            private int orderPrice;
            private int count;

            public OrderItemDto(OrderItem orderItem) {
                itemName = orderItem.getItem().getName();
                orderPrice = orderItem.getOrderPrice();
                count = orderItem.getCount();
            }

            @GetMapping("/api/v3/orders")
            public List<SpringDataJaxb.OrderDto> ordersV3() {
                List<Order> orders = orderRepository.findAllWithItem();
                List<SpringDataJaxb.OrderDto> result = orders.stream()
                        .map(o -> new SpringDataJaxb.OrderDto())
                        .collect(toList());

                return result;
            }


        }


        /*
         * V3. Query entities and convert them to DTO(using fetch join O)
         * Query 1 call with fetch join
         */

        @GetMapping("/api/v3/simple-orders")
        public List<SimpleOrderDto> overV3() {
            List<Order> orders = orderRepository.findAllWithMemberDelivery;
            List<SimpleOrderDto> result = orders.stream()
                    .map(o -> new SimpleOrderDto(o))
                    .collect(toList());
            return result;
        }

        public List<Order> findAllWithMemberDelivery() {
            return em.createQuery(
                    "select o from o" +
                            "join fetch o.member m" +
                            "join fetch o.delivery d", Order.class)
                    .getResultList();
        }

        /*
         * V4. Direct lookup form JPA to DTO.
         * - Query 1 call.
         * - Search by selecting only the desired data in the select clause.
         */

        @GetMapping("/api/v4/simple-orders")
        public List<OrderSimpleQueryDto> ordersV4() {
            return orderSimpleQueryRepository.findOrderDtos();
        }

        @GetMapping("/api/v.3.1/orders")
        public List<SpringDataJaxb.OrderDto> ordersV3_page(@RequestParam(value = "offset"),
                                                           defaultValue ="0") {
        }

        int offset,

        @RequestParam(value = "limit", defaultValue = "100"int limit) {
            List<Order> orders = orderRepository.findAllWithMemberDelivery(offset, limit);
            List<SpringDataJaxb.OrderDto> result = orders.stream()
                    .map(o -> new OrderDto(o))
                    .collect(toList());

            return result;
        }

        @GetMapping("/api/v4/orders")
        public List<OrderQueryDto> ordersV4() {
            return orderQueryRepository.findOrderQueryDtos();
        }



    }

}
