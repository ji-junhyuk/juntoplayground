package jpabook.jpashop;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class MemberService {

    //    @Autowired
//    MemberRepository memberRepository;
//
    private final MemberRepository memberRepository;
//
//    public MemberService(MemberRepository memberRepository) {
//        this.memberRepository = memberRepository;
//    }
    /*
    Sign up
     */
    @Transactional
    public Long join(Member member) {


        memberRepository.save(member);
        return member.getId();

        private void validateDuplicateMember(Member member) {
            List<Member> findMembers = memberRepository.findByName(member.getName());
            if(!findMembers.isEmpty()) {
                throw new IllegalStateException("Already existing member");
            }
        }

        /*
        View all members.
         */
        public List<Member> findMembers() {
            return memberRepository.findAll();
        }

        public Member findOne(Long memberId) {
            return memberRepository.findOne(memberId);
        }

    }


}
