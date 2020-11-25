package hellospring.foundation;

import hellospring.foundation.discount.FixDiscountPolicy;
import hellospring.foundation.repository.JdbcTemplateMemberRepository;
import hellospring.foundation.repository.JpaMemberRepository;
import hellospring.foundation.repository.MemberRepository;
import hellospring.foundation.repository.MemoryMemberRepository;
import hellospring.foundation.service.MemberService;
import hellospring.foundation.service.MemberServiceInterface;
import hellospring.foundation.service.OrderService;
import hellospring.foundation.service.OrderServiceInterface;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.persistence.EntityManager;
import javax.sql.DataSource;

@Configuration
//@RequiredArgsConstructor
public class SpringConfig {

/*    private final DataSource dataSource;
    private final EntityManager em;


    @Bean
    public MemberServiceInterface memberServiceInterface() {
        return new MemberService(new MemoryMemberRepository());
    }

    @Bean
    public OrderServiceInterface orderServiceInterface() {
        return new OrderService(
                new MemoryMemberRepository(),
                new FixDiscountPolicy());
    }

    @Bean
    public MemberRepository memberRepository() {
//        return new MemoryMemberRepository();
//        return new JdbcTemplateMemberRepository(dataSource);
        return new JpaMemberRepository(em);
    }*/

}
