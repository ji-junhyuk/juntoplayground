package spring.YHIntro.controller;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import spring.YHIntro.domain.MemberService;

@Controller
@RequiredArgsConstructor
public class MemberController {

    private final MemberService memberService;
}
