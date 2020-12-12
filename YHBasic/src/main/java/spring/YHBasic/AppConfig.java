package spring.YHBasic;

import spring.YHBasic.discount.DiscountPolicy;
import spring.YHBasic.discount.FixDiscountPolicy;
import spring.YHBasic.discount.RateDiscountPolicy;
import spring.YHBasic.repository.MemberRepository;
import spring.YHBasic.repository.MemoryMemberRepository;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.MemberServiceImpl;
import spring.YHBasic.service.OrderService;
import spring.YHBasic.service.OrderServiceImpl;

public class AppConfig {

    public MemberService memberService() {
        return new MemberServiceImpl(memberRepository());
    }

    public MemberRepository memberRepository() {
        return new MemoryMemberRepository();
    }

    public OrderService orderService() {
        return new OrderServiceImpl(
                memberRepository(),
                discountPolicy());
    }

    public DiscountPolicy discountPolicy() {
//        return new FixDiscountPolicy();
        return new RateDiscountPolicy();
    }
}
