package spring.YHIntro;

import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import spring.YHIntro.repository.JdbcTemplateMemberRepository;
import spring.YHIntro.repository.JpaMemberRepository;
import spring.YHIntro.repository.MemberRepository;
import spring.YHIntro.repository.MemoryMemberRepository;
import spring.YHIntro.service.MemberService;

import javax.persistence.EntityManager;
import javax.sql.DataSource;

@Configuration
@RequiredArgsConstructor
public class SpringConfig {

    private final DataSource dataSource;
    private final EntityManager em;

    @Bean
    public MemberService memberService() {
        return new MemberService(memberRepository());
    }

    @Bean
    public MemberRepository memberRepository() {
//        return new MemoryMemberRepository();
//        return new JdbcTemplateMemberRepository(dataSource);
        return new JpaMemberRepository(em);
    }
}
