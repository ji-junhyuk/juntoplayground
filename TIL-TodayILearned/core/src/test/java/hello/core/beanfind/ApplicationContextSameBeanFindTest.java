package hello.core.beanfind;

import hello.core.member.MemberRepository;
import hello.core.member.MemoryMemberRepository;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.NoUniqueBeanDefinitionException;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.Map;

public class ApplicationContextSameBeanFindTest {

    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext();

    @Test
    @DisplayName("When searching by type, if there is more than one of the same type, a duplicate error occurs.")
    void findBeanByTypeDuplicate() {
        Assertions.assertThrows(NoUniqueBeanDefinitionException.class, () ->
                ac.getBean(MemberRepository.class));
    }

    @Test
    @DisplayName("When searching by type, if there is more than one type of the same type, you can specify the name been.")
    void findBeanByName() {
        MemberRepository memberRepository = ac.getBean("memberRepository1", MemberRepository.class);
        org.assertj.core.api.Assertions.assertThat(memberRepository).isInstanceOf(MemberRepository.class);
    }

    @Test
    @DisplayName("Retrieve all by specific type.")
    void findAllBeenByType() {
        Map<String, MemberRepository> beanOfType = ac.getBeansOfType(MemberRepository.class);
        for (String key : beanOfType.keySet()) {
            System.out.println("key = " + key + " value = " + beanOfType.get(key));
        }
            System.out.println("beanOfType = " + beanOfType);
            org.assertj.core.api.Assertions.assertThat(beanOfType.size()).isEqualTo(2);
    }

    @Configuration
    static class SameBeanConfig {

        @Bean
        public MemberRepository memberRepository1() {
            return new MemoryMemberRepository();
        }

        @Bean
        public MemberRepository memberRepository2() {
            return new MemoryMemberRepository();
        }
    }
}
