package hello.YHBasic;

import hello.YHBasic.domain.Grade;
import hello.YHBasic.domain.Member;
import hello.YHBasic.domain.Order;
import hello.YHBasic.service.MemberService;
import hello.YHBasic.service.MemberServiceImpl;
import hello.YHBasic.service.OrderService;
import hello.YHBasic.service.OrderServiceImpl;

public class OrderApp {

    public static void main(String[] args) {
        MemberService memberService = new MemberServiceImpl();
        OrderService orderService = new OrderServiceImpl();

        long memberId = 1L;
        Member member = new Member(memberId, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(memberId, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
