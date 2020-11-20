package jpabook.jpashop.service;

import jpabook.jpashop.domain.Member;
import jpabook.jpashop.repository.MemberRepositoryImplXXX;
import jpabook.jpashop.repository.MemberRepositoryNotInterface;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

import static org.junit.jupiter.api.Assertions.*;

@Transactional
@SpringBootTest
class MemberServiceNotInterfaceTest {

    @Autowired
    MemberServiceNotInterface memberServiceNotInterface;

    @Autowired
    MemberRepositoryImplXXX memberRepositoryImplXXX;


    @Test
    public void join() throws Exception {
        //given
        Member member = new Member();
        member.setName("kim");

        //when
        Long saveId = memberServiceNotInterface.join(member);

        //then
        assertEquals(member, memberRepositoryImplXXX.findOne(saveId));
     }

     @Test
     public void duplicateMemberException() throws Exception {
/*
         //given
         Member member1 = new Member();
         member1.setName("kim");

         Member member2 = new Member();
         member2.setName("kim");

         //when
         memberServiceNotInterface.join(member1);
         memberServiceNotInterface.join(member2);

         //then
         fail("Error must be occur.");
*/
      }

}