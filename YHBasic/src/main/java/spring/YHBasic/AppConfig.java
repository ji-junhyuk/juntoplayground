package spring.YHBasic;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import spring.YHBasic.discount.DiscountPolicy;
import spring.YHBasic.discount.FixDiscountPolicy;
import spring.YHBasic.discount.RateDiscountPolicy;
import spring.YHBasic.repository.MemberRepository;
import spring.YHBasic.repository.MemoryMemberRepository;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.MemberServiceImpl;
import spring.YHBasic.service.OrderService;
import spring.YHBasic.service.OrderServiceImpl;

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
