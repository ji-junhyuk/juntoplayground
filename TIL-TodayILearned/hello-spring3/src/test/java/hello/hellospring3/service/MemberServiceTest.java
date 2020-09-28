package hello.hellospring3.service;

import hello.hellospring3.domain.Member;
import hello.hellospring3.repository.MemoryMemberRepository;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.*;

class MemberServiceTest {

    MemberService memberService; //1
    MemoryMemberRepository memberRepository; //after Test DME, before AfterEach

    @BeforeEach
    public void beforeEach() {
        memberRepository = new MemoryMemberRepository();
        memberService = new MemberService(memberRepository);
    }

    @AfterEach
    public void afterEach() {
        memberRepository.clearStore();
    }

    @Test
    void join() {
        //given
        Member member = new Member(); //1
        member.setName("hello");//2

        //when
        Long saveId = memberService.join(member); //3

        //then
        Member findMember = memberService.findOne(saveId).get();//5
        assertThat(member.getName()).isEqualTo(findMember.getName());//4 Assertions.assertThat() //6 () fill //7 static import
    }

    @Test
    public void duplicateMemberException() {
        //given
        Member member1 = new Member();
        member1.setName("spring");

        Member member2 = new Member();
        member2.setName("spring");

        //when
        memberService.join(member1);
        IllegalStateException e = assertThrows(IllegalStateException.class, () -> memberService.join(member2));

        assertThat(e.getMessage()).isEqualTo("alreay existing member.");
/*
        try {
            memberService.join(member2);
            fail();
        } catch (IllegalStateException e) {
            assertThat(e.getMessage()).isEqualTo("alreay existing member.");
        }
*/

        //then
    }

    @Test
    void findMembers() {
        //given

        //when

        //then
    }

    @Test
    void findOne() {
        //given

        //when

        //then
    }
}