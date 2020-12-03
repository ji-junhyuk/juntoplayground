package spring.YHBasic.service;

import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;
import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;

import static org.junit.jupiter.api.Assertions.*;

class MemberServiceTest {

    MemberService memberService = new MemberServiceImpl();

    @Test
    public void join() {

        //given
        Member member = new Member(1L, "memberA", Grade.VIP);

        //when
        memberService.join(member);
        Member findMember = memberService.findMember(1L);

        //then
        Assertions.assertThat(member).isEqualTo(findMember);
    }

}