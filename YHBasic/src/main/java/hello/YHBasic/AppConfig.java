package hello.YHBasic;

import hello.YHBasic.discount.DiscountPolicy;
import hello.YHBasic.discount.FixDiscountPolicy;
import hello.YHBasic.discount.RateDiscountPolicy;
import hello.YHBasic.repository.MemberRepository;
import hello.YHBasic.repository.MemoryMemberRepository;
import hello.YHBasic.service.MemberService;
import hello.YHBasic.service.MemberServiceImpl;
import hello.YHBasic.service.OrderService;
import hello.YHBasic.service.OrderServiceImpl;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Bean
    public MemberService memberService() {
        return new MemberServiceImpl(memberRepository());
    }

    @Bean
    public MemberRepository memberRepository() {
        return new MemoryMemberRepository();
    }

    @Bean
    public OrderService orderService() {
        return new OrderServiceImpl(
                memberRepository(),
                discountPolicy()
        );
    }

    @Bean
    public DiscountPolicy discountPolicy() {
//        return new FixDiscountPolicy();
        return new RateDiscountPolicy();
    }
}
