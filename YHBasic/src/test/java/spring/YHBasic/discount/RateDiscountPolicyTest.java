package spring.YHBasic.discount;

import org.junit.jupiter.api.Test;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

class RateDiscountPolicyTest {

    RateDiscountPolicy discountPolicy = new RateDiscountPolicy();

    @Test
    void vip_o() {

        //Given
        Member member = new Member(1L, "MemberVIP", Grade.VIP);

        //When
        int discount = discountPolicy.discount(member, 10000);

        //Then
        assertThat(discount).isEqualTo(1000);
    }
    
    @Test
    void vip_x() {
    
        //Given
        Member member = new Member(2L, "memberBasic", Grade.BASIC);

        //When
        int discount = discountPolicy.discount(member, 10000);

        //Then
        assertThat(discount).isEqualTo(0);
    }

}