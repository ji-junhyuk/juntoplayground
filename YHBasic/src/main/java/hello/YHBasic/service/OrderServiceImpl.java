package hello.YHBasic.service;

import hello.YHBasic.discount.DiscountPolicy;
import hello.YHBasic.discount.FixDiscountPolicy;
import hello.YHBasic.domain.Member;
import hello.YHBasic.domain.Order;
import hello.YHBasic.repository.MemberRepository;
import hello.YHBasic.repository.MemoryMemberRepository;

public class OrderServiceImpl implements OrderService {

    private final MemberRepository memberRepository;
    private final DiscountPolicy discountPolicy;

    public OrderServiceImpl(MemberRepository memberRepository, DiscountPolicy discountPolicy) {
        this.memberRepository = memberRepository;
        this.discountPolicy = discountPolicy;
    }

    @Override
    public Order createOrder(Long memberId, String itemName, int itemPrice) {

        Member member = memberRepository.findById(memberId);
        int discountPrice = discountPolicy.discount(member, itemPrice);

        return new Order(memberId, itemName, itemPrice, discountPrice);
    }
}
