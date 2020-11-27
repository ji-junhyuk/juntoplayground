package spring.YHBasic;

import spring.YHBasic.discount.FixDiscountPolicy;
import spring.YHBasic.repository.MemoryMemberRepository;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.MemberServiceImpl;
import spring.YHBasic.service.OrderService;
import spring.YHBasic.service.OrderServiceImpl;

public class AppConfig {

    public MemberService memberService() {
        return new MemberServiceImpl(new MemoryMemberRepository());
    }

    public OrderService orderService() {
        return new OrderServiceImpl(
                new MemoryMemberRepository(),
                new FixDiscountPolicy());
    }
}
