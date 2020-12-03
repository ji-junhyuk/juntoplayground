package spring.YHBasic.service;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;
import spring.YHBasic.domain.Order;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

class OrderServiceTest {

    MemberService memberService = new MemberServiceImpl();
    OrderService orderService = new OrderServiceImpl();

    @Test
    public void createOrder() {

        //given
        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        //when
        Order order = orderService.createOrder(1L, "memberA", 10000);

        //then
        assertThat(order.getDiscountPrice()).isEqualTo(1000);
    }

}