package spring.YHBasic.service;

import lombok.RequiredArgsConstructor;
import spring.YHBasic.discount.DiscountPolicy;
import spring.YHBasic.discount.FixDiscountPolicy;
import spring.YHBasic.domain.Member;
import spring.YHBasic.domain.Order;
import spring.YHBasic.repository.MemberRepository;
import spring.YHBasic.repository.MemoryMemberRepository;

public class OrderServiceImpl implements OrderService {

    private final MemberRepository memberRepository = new MemoryMemberRepository();
    private final DiscountPolicy discountPolicy = new FixDiscountPolicy();

    @Override
    public Order createOrder(Long memberId, String itemName, int itemPrice) {

        Member member = memberRepository.findById(memberId);
        int discountPrice = discountPolicy.discount(member, itemPrice);

        return new Order(memberId, itemName, itemPrice, discountPrice);
    }
}
