package hellospring.JPA1.service;

import hellospring.JPA1.domain.Member;
import hellospring.JPA1.repository.MemberRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class MemberService {

    private final MemberRepository memberRepository;

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
            throw new IllegalStateException("Already existing member");
        }
    }

    /*
    View all member
     */
<<<<<<< HEAD:TIL-TodayILearned/JPA1/src/main/java/hellospring/JPA1/service/MemberService.java
    public List<Member> findMembers() {
        return memberRepository.findAll();
=======
    public List<Member> findMember() {
        return memberRepositoryImplXXX.findAll();
>>>>>>> parent of cd55527... Jpa1, (63) 93/93 (60m):TIL-TodayILearned/jpashop/src/main/java/jpabook/jpashop/service/MemberServiceNotInterface.java
    }

    public Member findOne(Long memberId) {
        return memberRepository.findOne(memberId);
    }

}
