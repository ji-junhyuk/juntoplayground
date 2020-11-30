package hello.YHBasic;

import hello.YHBasic.domain.Grade;
import hello.YHBasic.domain.Member;
import hello.YHBasic.service.MemberService;
import hello.YHBasic.service.MemberServiceImpl;

public class MemberApp {

    public static void main(String[] args) {
        MemberService memberService = new MemberServiceImpl();
        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Member findMember = memberService.findMember(1L);
        System.out.println("new member = " + member.getName());
        System.out.println("find member = " + findMember.getName());
    }
}
