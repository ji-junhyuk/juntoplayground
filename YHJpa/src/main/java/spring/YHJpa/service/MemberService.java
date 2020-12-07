package spring.YHJpa.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.Member;
import spring.YHJpa.repository.MemberRepository;

import java.util.List;

@Service
@Transactional(readOnly = true)
public class MemberService {

    @Autowired
    MemberRepository memberRepository;

    /*
    Sign up
     */
    @Transactional
    public Long join(Member member) {

        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        List<Member> findMembers = memberRepository.findByName(member.getName());
        if (!findMembers.isEmpty()) {
            throw new IllegalStateException("Already existing member.");
        }
    }

    /*
    View all member
     */
    public Member findOne(Long memberId) {
        return memberRepository.findOne(memberId);
    }

    public List<Member> findMember() {
        return memberRepository.findAll();
    }
}
