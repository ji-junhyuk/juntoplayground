package spring.YHBasic;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
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
        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);
        MemberService memberService = ac.getBean("memberService", MemberService.class);
        OrderService orderService = ac.getBean("orderService", OrderService.class);

        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(1L, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
