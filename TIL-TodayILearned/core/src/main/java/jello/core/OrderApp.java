package jello.core;

import jello.core.member.Grade;
import jello.core.member.Member;
import jello.core.member.MemberService;
import jello.core.member.MemberServiceImpl;
import jello.core.order.OrderService;
import jello.core.order.OrderServiceImpl;

public class OrderApp {

    public static void main(String[] args) {
        MemberService memberService = new MemberServiceImpl();
        OrderService orderService = new OrderServiceImpl();

        Long memberId = 1L;
        Member member = new Member(memberId, "memberA", Grade.VIP);

    }
}
