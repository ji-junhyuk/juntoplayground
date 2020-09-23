package hello.hellospring.service;

import hello.hellospring.domain.Member;
import hello.hellospring.repository.MemberRepository;
import hello.hellospring.repository.MemoryMemberRepository;

import java.util.List;
import java.util.Optional;

public class MemberService {
//ctrl shift t

    private final MemberRepository memberRepository = new MemoryMemberRepository();

    /** //ctrl shift enter
     *
     * */
    public Long join(Member member) {
        // zoongbok X
        vaildateDuplicateMember(member); //zungbok examine
        memberRepository.save(member);
        return member.getId();

    }

    private void vaildateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                .ifPresent(m -> {
                     throw new IllegalStateException("alreay exist member");
                });
    }

    /**
     *
     * @return
     */

    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }
}
