package hellospring.foundation.service;

import hellospring.foundation.domain.Grade;
import hellospring.foundation.domain.Member;
import hellospring.foundation.repository.MemberRepository;
import hellospring.foundation.repository.MemoryMemberRepository;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

class MemberServiceTest {

    MemberService memberService = new MemberService();
    MemoryMemberRepository memberRepository;


    @BeforeEach
    public void beforeEach() {
        memberRepository = new MemoryMemberRepository();
//        memberService = new MemberService(memberRepository);
    }

    @AfterEach
    public void afterEach() {
        memberRepository.clearStore();
    }

    @Test
    public void join() throws Exception {
        //given
        Member member = new Member(1L, "memberA", Grade.VIP);
        member.setName("hello");

        //when
        Long saveId = memberService.join(member);

        //then
        Member findMember = memberRepository.findById(saveId).get();
        assertEquals(member.getName(), findMember.getName());
    }

    @Test
    public void duplicateMemberException() throws Exception {
        //given
        Member member1 = new Member(1L, "memberA", Grade.VIP);
        member1.setName("spring");

        Member member2 = new Member(1L, "memberA", Grade.VIP);
        member2.setName("spring");

        //when
        memberService.join(member1);
        IllegalStateException e = assertThrows(IllegalStateException.class,
                () -> memberService.join(member2));

        Assertions.assertThat(e.getMessage()).isEqualTo("Already existing member.");

        //then
     }

     @Test
     public void join2() {
/*
         //given
         Member member = new Member(1L, "memberA", Grade.VIP);

         //when
         memberService.join(member);
         Optional<Member> findMember = memberService.findOne(1L);

         //then
         Assertions.assertThat(member).isEqualTo(findMember);
*/
     }

}