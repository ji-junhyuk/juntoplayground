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

    private final MemberRepository memberRepository;

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

    private void validateDuplicateMember(Member member) {
        List<Member> findMembers = memberRepository.findByName(member.getName());
        if (!findMembers.isEmpty()) {
            throw new IllegalStateException("Already existing member.");
        }
    }

    private void validateDuplicateName(Member member) {
        List<Member> findMembers = memberRepository.findByName(member.getName());
        if (!findMembers.isEmpty()) {
            throw new IllegalStateException("the name is already in use.");
        }
    }

    private void validatePwdMember(Member member) {
        String pwdCheck = member.getPwd();

        if (!pwdCheck.equals(member.getPwd2())) {
            throw new IllegalStateException("Passwords do not match");
        }
    }
      
     /*
    Check member existence
     */
    public boolean logingo(Member member) {

        boolean check = false;

        List<Member> sql = memberRepository.Login(member.getId(), member.getPwd());

        if (!sql.isEmpty()) {
            System.out.println("exist");
            check = true;
        } else {
            System.out.println("fail");
        }
        return check;
      

    /*
    View all member
     */
    public Member findOne(Long memberId) {
        return memberRepository.findOne(memberId);
    }

    public List<Member> findMembers() {
        return memberRepository.findAll();
    }
}