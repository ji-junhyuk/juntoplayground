package jpabook.jpashopPractice1.repository.order.query;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Repository;

import javax.persistence.EntityManager;
import java.util.List;

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

    }

}
