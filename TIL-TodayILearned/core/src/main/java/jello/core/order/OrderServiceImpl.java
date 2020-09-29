package jello.core.order;

import jello.core.discount.DiscountPolicy;
import jello.core.discount.FixDiscountPolicy;
import jello.core.member.Member;
import jello.core.member.MemberRepository;
import jello.core.member.MemoryMemberRepository;

public class OrderServiceImpl implements OrderService {

    private final MemberRepository memberRepository = new MemoryMemberRepository();
    private final DiscountPolicy discountPolicy = new FixDiscountPolicy()

    @Override
    public Order createOrder(Long memberId, String name, int itemPrice) {
        Member member = memberRepository.findById(memberId);
        int d = discountPolicy.discount(member, itemPrice);

        return new Order(memberId, itemPrice, itemPrice, discountPolicy);
    }
}
