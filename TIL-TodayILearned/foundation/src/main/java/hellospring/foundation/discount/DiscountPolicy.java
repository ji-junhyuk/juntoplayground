package hellospring.foundation.discount;

import hellospring.foundation.domain.Member;

public interface DiscountPolicy {

    int discount(Member member, int price);
}
