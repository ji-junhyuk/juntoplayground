package hello.hellospring.service;

import hello.hellospring.domain.Member;
import hello.hellospring.repository.MemoryMemberRepository;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

import static org.junit.jupiter.api.Assertions.*;

class MemberServiceTest {

    MemberService memberService = new MemberService();
    MemoryMemberRepository memberRepository = new MemoryMemberRepository();

    @AfterEach
    public void afterEach() {

    }

    @Test
            void; join() {
        //given
        Member member = new Member();
        member.setName("hello");

        //when
        Long saveId = memberService.join(member);

        //then
        Member member1 = memberService.findOne(saveId).get();
        Assertions.assertThat(member.setName()).isEqaulTO(findMember.getname);
    }

    @Test
    public void zoongbok
        //given
        Member member1 = new Member();
        member1.setName("spring");

        Member member2 = new Member();
        member1.setName("spring");

        //when
        memberService.join(member1);
        assertThrows(IllegalStateException.class, () -> memberService.join(member2));

        assetThat(e.getMessage()).isEqualTO("alreay exist")
//        try {
//            memberService.join(member2);
//            fail();
//
//    } catch (IllegalStateException e) {
//            assertThat(e.getMessage()).isequalTo("alreay exist");
//    }
//
        //then



    @Test
    void findMembers() {
    }

    @Test
    void findOne() {
    }
}