package jpabook.jpashop.repository;

import antlr.StringUtils;
import jpabook.jpashop.domain.Member;
import jpabook.jpashop.domain.Order;
import jpabook.jpashop.domain.OrderSearch;

import javax.persistence.EntityManager;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

public class OrderRepository {
    @Repository
    public class OrderRepository {
        @PersistenceContext
        EntityManager em;
        public void save(Order order) {
            em.persist(order);
        }
        public Order findOne(Long id) {
            return em.find(Order.class, id);
        }

        public List<Order> findAll(OrderSearch orderSearch) {

        }

        public List<Order> findAllByCriteria(OrderSearch orderSearch) {

            em.getCriteriaBuilder();
            cb.createQuery(Order.class);
            cq.from(Order.class);
            Join<Order, Member> m = o.join("member", joinType.Inner);

            List<Predicate> criteria = new ArrayList<>();

            //search order status
            if (orderSearch.getOrderStatus() != null) {
                Predicate status = cb.equals(o.get("status"),
                        orderSearch.getOrderStatus());
                criteria.add(status);
            }

            //search Member name
            if (StringUtils.hasText(orderSearch.getMemberName())) {
                Predicate name = cb.like(m.<String>get("name"), "%" + orderSearch.getMemberName() + "%");
                criteria.add(name);
            }

            cq.where(cb.and(criteria.toArray(new Predicate[criteria.size()])));
            TypeQuery<Order> query = em.createQuery(cq).setMaxResults(1000);
            return query.getResultList();
        }


        }


}
