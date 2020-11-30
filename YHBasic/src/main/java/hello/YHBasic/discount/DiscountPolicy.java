package hello.YHBasic.discount;

import hello.YHBasic.domain.Member;

public interface DiscountPolicy {

    int discount(Member member , int price);
}
