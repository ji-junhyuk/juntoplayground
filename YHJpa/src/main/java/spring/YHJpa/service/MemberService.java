package spring.YHJpa.service;

import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import spring.YHJpa.domain.Member;
import spring.YHJpa.repository.MemberRepository;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class MemberService {

    private  final MemberRepository memberRepository;

    /*
    Sign up
     */
    @Transactional
    public Long join(Member member) {

        validateDuplicateMember(member);
        validateDuplicateName(member);
        validatePwdMember(member);
        memberRepository.save(member);
        return member.getNumber();
    }

    private void validatePwdMember(Member member) {
        String pwdCheck = member.getPwd();

        if (!pwdCheck.equals(member.getPwd2())) {
            throw new IllegalStateException("Passwords do not match.");
        }
    }

    private void validateDuplicateName(Member member) {
        List<Member> findMembers = memberRepository.findByName(member.getName());
        if (!findMembers.isEmpty()) {
            throw new IllegalStateException("The name is already in use.");
        }
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
    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    public Member findOne(Long memberId) {
        return memberRepository.findOne(memberId);
    }

}
