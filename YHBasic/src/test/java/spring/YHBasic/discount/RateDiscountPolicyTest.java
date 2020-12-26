package spring.YHBasic.discount;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import spring.YHBasic.AppConfig;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.OrderService;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

class RateDiscountPolicyTest {

    DiscountPolicy rateDiscountPolicy;

    @BeforeEach
    public void beforeEach() {
        AppConfig appConfig = new AppConfig();
        rateDiscountPolicy = appConfig.discountPolicy();
    }

    @Test
    public void vip_o() {

        //Given
        Member member = new Member(1L, "memberVIP", Grade.VIP);

        //When
        int discount = rateDiscountPolicy.discount(member, 30000);

        //Then
        assertThat(discount).isEqualTo(3000);
    }

    @Test
    public void vip_x() {

        //Given
        Member member = new Member(2L, "memberBASIC", Grade.BASIC);

        //When
        int discount = rateDiscountPolicy.discount(member, 30000);

        //Then
        assertThat(discount).isEqualTo(0);
    }
}