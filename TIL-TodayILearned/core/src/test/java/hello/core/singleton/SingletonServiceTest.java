package hello.core.singleton;

import hello.core.AppConfig;
import hello.core.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import static org.assertj.core.api.Assertions.assertThat;


public class SingletonServiceTest {

    @Test
    @DisplayName("Using objects with singleton pattern applied")
    public void singletonServiceTest() {
        //The constructor was blocked with private. A compilation error occurs.
        //new SingletonService();

        //1. Lookup: Returns the same object each time it is called
        SingletonService singletonService1 = SingletonService.getInstance();
        //2. Lookup: Returns the same object each time it is called
        SingletonService singletonService2 = SingletonService.getInstance();

        //Check that the reference values are the same
        System.out.println("singletonService1 = " + singletonService1);
        System.out.println("singletonService2 = " + singletonService2);

        assertThat(singletonService1).isSameAs(singletonService2);
        singletonService1.logic();
    }

    @Test
    @DisplayName("Spring Containers and Singletons")
    void springContainer() {

        ApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

        //1. Lookup: Returns the same object each time it is called
        MemberService memberService1 = ac.getBean("memberService", MemberService.class);
        MemberService memberService2 = ac.getBean("memberService", MemberService.class);

        //
        System.out.println("memberService1 = " + memberService1);
        System.out.println("memberService2 = " + memberService2);

        assertThat(memberService1).isSameAs(memberService2);
    }


}
