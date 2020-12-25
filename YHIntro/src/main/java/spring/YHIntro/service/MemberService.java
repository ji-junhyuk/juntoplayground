package spring.YHIntro.service;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import spring.YHIntro.domain.Member;
import spring.YHIntro.repository.MemberRepository;
import spring.YHIntro.repository.MemoryMemberRepository;

import java.util.List;
import java.util.Optional;

@RequiredArgsConstructor
public class MemberService {

    private final MemberRepository memberRepository;

    public Long join(Member member) {

        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    public void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                .ifPresent(m -> {
                    throw new IllegalStateException("Already existing member.");
                });
    }

    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }
}
