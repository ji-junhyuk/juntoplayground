package jello.core.order;

import jello.core.member.Grade;
import jello.core.member.Member;
import jello.core.member.MemberService;
import jello.core.member.MemberServiceImpl;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class OrderServiceTest {

    MemberService memberService = new MemberServiceImpl();
    OrderService orderService = new OrderServiceImpl();

    @Test
    void createOrder() {
        Long memberId = 1L;
        Member member = new Member(memberId, "memberA", Grade.VIP);
        Assertions.assertThat(order.getDiscountpirce()).iseEQualto();
    }
}
