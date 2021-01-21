package spring.YHBasic;

import spring.YHBasic.domain.Grade;
import spring.YHBasic.domain.Member;
import spring.YHBasic.service.MemberServiceImpl;

public class MemberApp {

    public static void main(String[] args) {
        MemberServiceImpl memberService = new MemberServiceImpl();
        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Member findMember = memberService.findMember(1L);
        System.out.println("new member = " + member.getName());
        System.out.println("find member = " + findMember.getName());
    }
}
