package jpabook.jpashopPractice1.repository.order.query;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Repository;
import org.springframework.web.bind.annotation.GetMapping;

import javax.persistence.EntityManager;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.toList;

@Repository
@RequiredArgsConstructor
public class OrderQueryRepository {

    private final EntityManager em;

    /*
    * - Collections are viewed separately
    * - Query : root 1, collection N
    * - The method that is often used in single item inquiry
     */

    public List<OrderQueryDto> findOrderQueryDtos() {
        //Root search (search all toONe codes at once)
        List<OrderQueryDto> result = findOrders();

        //Add collection while looping (execute additional query)
        result.forEach(o -> {
            List<OrderItemQueryDto> orderItems = findOrderItems(o.getOrderId());
            o.setOrderItems(orderItems);
        });
        return result;
    }

    /*
    Searches all at once except for 1:N relationship.(collection)
     */
    private List<OrderQueryDto> findOrders() {
        return em.createQuery(
                "select new jpabook.jpashopPractice1.repository.order.query.OrderQueryDto(o.id, m.name, o.orderDate. o.status, d.address" +
                        "from Order o" +
                        "join o.member m" +
                        "join o.delivery d", OrderQueryDto.class)
                .getResultList();
        )

         /*
         * Lookup orderItems, which is a 1:N relationship.
         */

        private List<OrderItemQueryDto> findOrderItems(Long orderId) {
            return em.createQuery(
                    "select new jpabook.jpashopPractice1.repository.order.query.OrderItemQueryDto(oi.order.id, i.name, oi.orderPrice, oi.count)" +
                            " from OrderItem oi" +
                            " join oi.item i" +
                            " where oi.order.id = : orderId",
                    OrderItemQueryDto.class)
                    .setParameter("orderId", orderId)
                    .getResultList();
            )
        }

        /*
        optimization
        Query : root 1, collection 1
        A method that is used a lot when processing data at once
         */
        public List<OrderQueryDto> findAllByDto_Optimization() {

            //Root search(search all toOne codes at once)
            List<OrderQueryDto> result = findOrders();

            //Search the orderItem collection in one map
            Map<Long, List<OrderItemQueryDto>> orderItemMap = findOrderItemMap(toOrderIds(result));

            //Add collection while looping(execute additional query x)
            result.forEach(o -> o.setOrderItems(orderItemMap.get(o.getOrderId())));

            return result;
        }

        private List<Long> toOrderIds (List < OrderQueryDto > result) {
            return result.stream()
                    .map(o -> o.getOrderId())
                    .collect(Collectors.toList());
        }

        private Map<Long, List<OrderItemQueryDto>> findOrderItemMap(List<Long> orderIds) {
            List<OrderItemQueryDto> orderItems = em.createQuery("select new jpabook.jpashopPractice1.repository.order.query.OrderItemQueryDto(oi.order.id, i.name, oi.orderPrice, oi.count)" +
                    " from OrderItem oi" +
                    " join oi.item i" +
                    " where oi.order.id in :orders", OrderItemQueryDto.class)
                    .setParameter("orderIds", orderIds)
                    .getResultList();

            return orderItems.stream()
                    .collect(groupingBy(OrderItemQueryDto::getOrderId));
        }

        @GetMapping("/api/v6/orders")
        public List<OrderQueryDto> ordersV6(){
            List<OrderFlatDto> flats = orderQueryRepository.findAllByDto_flat();

            return flats.stream()
                    .collect(groupingBy(o -> new OrderQueryDto(o.getOrderId(),
                    o.getName(), o.getOrderDate(), o.getOrderStatus, o.getAddress()),
                    mapping(o -> new OrderItemQueryDto(o.getOrderId(),
                            o.getItemName(), o.getOrderPrice(), o.getCount()), toList())
                    )).entrySet()stream()
                    .map(e -> new OrderQueryDto(e.getKey().getOrderId(), e.getKey().getName(), e.getKey().getOrderDate(),
                            e.getKey().getOrderStatus, e.getKey().getAddress, e.getValue()))
                            .collect(toList());
        }


    }

}
