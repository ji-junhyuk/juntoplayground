package hello.YHBasic;

import hello.YHBasic.discount.DiscountPolicy;
import hello.YHBasic.discount.FixDiscountPolicy;
import hello.YHBasic.repository.MemberRepository;
import hello.YHBasic.repository.MemoryMemberRepository;
import hello.YHBasic.service.MemberService;
import hello.YHBasic.service.MemberServiceImpl;
import hello.YHBasic.service.OrderService;
import hello.YHBasic.service.OrderServiceImpl;

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
                discountPolicy()
        );
    }

    public DiscountPolicy discountPolicy() {
        return new FixDiscountPolicy();
    }
}
