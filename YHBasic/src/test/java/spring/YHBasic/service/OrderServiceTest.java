package spring.YHBasic.service;

import org.junit.jupiter.api.Test;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;
import spring.YHBasic.domain.Order;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class OrderServiceTest {

    MemberService memberService = new MemberServiceImpl();
    OrderService orderService = new OrderServiceImpl();

    @Test
    void createOrder() {

        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(1L, "memberA", 10000);
        assertThat(order.getDiscountPrice()).isEqualTo(1000);
    }

}