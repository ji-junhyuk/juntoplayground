package jello.core.discount;

import jello.core.member.Member;

public interface DiscountPolicy {

    /*
   @return discout rate
     */
    int discount(Member member, int price);

}
