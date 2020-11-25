package hellospring.foundation;

import hellospring.foundation.repository.JdbcTemplateMemberRepository;
import hellospring.foundation.repository.JpaMemberRepository;
import hellospring.foundation.repository.MemberRepository;
import hellospring.foundation.repository.MemoryMemberRepository;
import hellospring.foundation.service.MemberService;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;

import javax.persistence.EntityManager;
import javax.sql.DataSource;

@Configuration
@RequiredArgsConstructor
public class SpringConfig {

    private final DataSource dataSource;
    private final EntityManager em;


/*
    @Bean
    public MemberService memberService() {
        return new MemberService(memberRepository());
    }
*/

    @Bean
    public MemberRepository memberRepository() {
//        return new MemoryMemberRepository();
//        return new JdbcTemplateMemberRepository(dataSource);
        return new JpaMemberRepository(em);
    }

}
