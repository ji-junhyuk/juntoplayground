package hellospring.foundation;

import hellospring.foundation.domain.Grade;
import hellospring.foundation.domain.Member;
import hellospring.foundation.domain.Order;
import hellospring.foundation.service.MemberService;
import hellospring.foundation.service.MemberServiceInterface;
import hellospring.foundation.service.OrderService;
import hellospring.foundation.service.OrderServiceInterface;

public class OrderApp {

    public static void main(String[] args) {
        MemberServiceInterface memberServiceInterface = new MemberService();
        OrderServiceInterface orderServiceInterface = new OrderService();

        long id = 1L;
        Member member = new Member(id, "memberA", Grade.VIP);
        memberServiceInterface.join(member);

        Order order = orderServiceInterface.createOrder(id, "itemA", 10000);

        System.out.println("order = " + order);
    }
}
