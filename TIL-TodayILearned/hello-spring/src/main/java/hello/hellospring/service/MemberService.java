package hello.hellospring.service;

import hello.hellospring.domain.Member;
<<<<<<< HEAD
import hello.hellospring.repository.MemberRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
=======
import hello.hellospring.repository.MemoryMemberRepository;
>>>>>>> 559c734f5df1fdadd63c1f7294c52a63481a3bcd

import java.util.List;
import java.util.Optional;

<<<<<<< HEAD
@Service
public class MemberService {

//    private final MemberRepository memberRepository = new MemoryMemberRepository();
=======
>>>>>>> 559c734f5df1fdadd63c1f7294c52a63481a3bcd

public class MemberService {
    private final MemoryMemberRepository memberRepository;

<<<<<<< HEAD
    @Autowired
    public MemberService(MemberRepository memberRepository) {
=======
    public MemberService(MemoryMemberRepository memberRepository) {
>>>>>>> 559c734f5df1fdadd63c1f7294c52a63481a3bcd
        this.memberRepository = memberRepository;
    }

    /*
<<<<<<< HEAD
        Sign up
         */
=======
    Sign up.
     */
>>>>>>> 559c734f5df1fdadd63c1f7294c52a63481a3bcd
    public Long join(Member member) {

        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
                .ifPresent(m -> {
                    throw new IllegalStateException("Already existing member.");
                });
    }

    /*
<<<<<<< HEAD
    View all members
=======
    View all members.
>>>>>>> 559c734f5df1fdadd63c1f7294c52a63481a3bcd
     */
    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }

}
