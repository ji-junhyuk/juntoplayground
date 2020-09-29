package jello.core;

import jello.core.member.Grade;
import jello.core.member.Member;
import jello.core.member.MemberService;
import jello.core.member.MemberServiceImpl;

public class MemberApp {
    public static void main(String[] args) { //pvsm
        MemberService memberService = new MemberServiceImpl();
        Member member = new Member(1L, "memberA", Grade.VIP);
        memberService.join(member);

        Member findMember = memberService.findMember(1L);
        System.out.println("new member = " + member.getName());
        System.out.println("find Member = " + findMember.getName());
    }
}
