package hello.core.singleton;

import hello.core.AppConfig;
import hello.core.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class SingletonTest {

    @Test
    @DisplayName("Pure DI container without spring")
    void pureContainer() {

        AppConfig appConfig = new AppConfig();
        //1. Lookup: Create an object every time it is called
        MemberService memberService1 = appConfig.memberService();

        //2. Lookup: Create an object every time it is called
        MemberService memberService2 = appConfig.memberService();

        //Check that the reference value is different
        System.out.println("memberService1 = " + memberService1);
        System.out.println("memberService2 = " + memberService2);

        //memberService != memberService 2
        Assertions.assertThat(memberService1).isNotSameAs(memberService2);

    }


}
