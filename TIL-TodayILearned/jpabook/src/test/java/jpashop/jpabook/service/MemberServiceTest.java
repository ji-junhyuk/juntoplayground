package jpashop.jpabook.service;

import jpashop.jpabook.domain.Member;
import jpashop.jpabook.repository.MemberRepository;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
@Transactional
class MemberServiceTest {

    @Autowired
    MemberService memberService;

    @Autowired
    MemberRepository memberRepository;

    @Test
    public void join() throws Exception {
        //given
        Member member = new Member();
        member.setName("Kim");

        //when
        Long saveId = memberService.join(member);

        //then
        assertEquals(member, memberRepository.findOne(saveId));
     }

     @Test
     public void duplicateMemberException() throws Exception {
         //given
         Member member1 = new Member();
         member1.setName("Kim");

         Member member2 = new Member();
         member2.setName("Kim");

         //when
         memberService.join(member1);
         memberService.join(member2);

         //then
         fail("An exception must occur.");
      }
}