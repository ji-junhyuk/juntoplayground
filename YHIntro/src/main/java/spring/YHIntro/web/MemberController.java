package spring.YHIntro.web;

import org.springframework.stereotype.Controller;
import spring.YHIntro.service.MemberService;

@Controller
public class MemberController {

    private final MemberService memberService;

    public MemberController(MemberService memberService) {
        this.memberService = memberService;
    }
}
