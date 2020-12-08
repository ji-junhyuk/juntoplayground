package spring.YHBasic.discount;

import spring.YHBasic.domain.Member;

public interface DiscountPolicy {

    int discount(Member member, int price);
}
