package hellospring.foundation.service;

import hellospring.foundation.discount.DiscountPolicy;
import hellospring.foundation.domain.Member;
import hellospring.foundation.domain.Order;
import hellospring.foundation.repository.MemberRepository;
import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor
public class OrderService {

//    private final MemberRepository memberRepository;
//    private final DiscountPolicy discountPolicy;
//
//
//    @Override
//    public Order createOrder(Long id, String itemName, int itemPrice) {
//        Member member = memberRepository.findById(id).get();
//        int discountPrice = discountPolicy.discount(member, itemPrice);
//
//        return new Order(Long id, itemName, itemPrice, discountPrice);
//    }
}
