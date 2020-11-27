package spring.YHBasic.service;

import spring.YHBasic.domain.Member;
import spring.YHBasic.repository.MemberRepository;
import spring.YHBasic.repository.MemoryMemberRepository;

public class MemberServiceImpl implements MemberService {

    private final MemberRepository memberRepository = new MemoryMemberRepository();

    @Override
    public void join(Member member) {
        memberRepository.save(member);
    }

    @Override
    public Member findMember(Long memberId) {
        return memberRepository.findById(memberId);
    }
}
