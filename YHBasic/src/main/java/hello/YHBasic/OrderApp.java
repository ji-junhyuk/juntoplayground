package hello.YHBasic;

import hello.YHBasic.domain.Grade;
import hello.YHBasic.domain.Member;
import hello.YHBasic.domain.Order;
import hello.YHBasic.service.MemberService;
import hello.YHBasic.service.MemberServiceImpl;
import hello.YHBasic.service.OrderService;
import hello.YHBasic.service.OrderServiceImpl;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class OrderApp {

    public static void main(String[] args) {
        ApplicationContext applicationContext = new AnnotationConfigApplicationContext(AppConfig.class);
        MemberService memberService = applicationContext.getBean("memberService", MemberService.class);
        OrderService orderService = applicationContext.getBean("orderService", OrderService.class);

        long memberId = 1L;
        Member member = new Member(memberId, "memberA", Grade.VIP);
        memberService.join(member);

        Order order = orderService.createOrder(memberId, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
