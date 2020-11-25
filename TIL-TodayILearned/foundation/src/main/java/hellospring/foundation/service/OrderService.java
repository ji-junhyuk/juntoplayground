package hellospring.foundation.service;

import hellospring.foundation.discount.DiscountPolicy;
import hellospring.foundation.discount.FixDiscountPolicy;
import hellospring.foundation.domain.Member;
import hellospring.foundation.domain.Order;
import hellospring.foundation.repository.MemberRepository;
import hellospring.foundation.repository.MemoryMemberRepository;

import java.util.Optional;

public class OrderService implements OrderServiceInterface {

    private final MemberRepository memberRepository = new MemoryMemberRepository();
    private final DiscountPolicy discountPolicy = new FixDiscountPolicy();

    @Override
    public Order createOrder(Long id, String itemName, int itemPrice) {
        Member member = memberRepository.findById(id).get();
        int discountPrice = discountPolicy.discount(member, itemPrice);

        return new Order(id, itemName, itemPrice, discountPrice);
    }
}
