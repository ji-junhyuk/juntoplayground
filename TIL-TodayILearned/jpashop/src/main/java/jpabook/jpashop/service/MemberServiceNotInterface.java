package jpabook.jpashop.service;

import jpabook.jpashop.domain.Member;
import jpabook.jpashop.repository.MemberRepositoryImplXXX;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class MemberServiceNotInterface {

    private  final MemberRepositoryImplXXX memberRepositoryImplXXX;

    /*
    Sign up
     */
    @Transactional
    public Long join(Member member) {

        validateDuplicateMember(member);
        memberRepositoryImplXXX.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        List<Member> findMembers = memberRepositoryImplXXX.findByName(member.getName());
        if (!findMembers.isEmpty()) {
            throw new IllegalStateException("Already existing member.");
        }
    }

    /*
    View all member
     */
    public List<Member> findMembers() {
        return memberRepositoryImplXXX.findAll();
    }

    public Member findOne(Long memberID) {
        return memberRepositoryImplXXX.findOne(memberID);
    }
}
