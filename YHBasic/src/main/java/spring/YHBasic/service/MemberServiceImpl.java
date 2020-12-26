package spring.YHBasic.service;

import lombok.RequiredArgsConstructor;
import spring.YHBasic.domain.Member;
import spring.YHBasic.repository.MemberRepository;

@RequiredArgsConstructor
public class MemberServiceImpl implements MemberService {

    private final MemberRepository memberRepository;

    @Override
    public void join(Member member) {
        memberRepository.save(member);
    }

    @Override
    public Member findMember(Long id) {
        return memberRepository.findById(id);
    }
}
