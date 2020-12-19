package spring.YHBasic;

import org.springframework.beans.factory.annotation.Autowired;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;
import spring.YHBasic.domain.Order;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.OrderService;

public class OrderApp {

    @Autowired
    MemberService memberService;

    @Autowired
    OrderService orderService;

    public static void main(String[] args) {
        AppConfig appConfig = new AppConfig();
        MemberService memberService = appConfig.memberService();
        OrderService orderService = appConfig.orderService();

        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(1L, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
