package spring.YHIntro.web;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import spring.YHIntro.service.MemberService;

@Controller
@RequiredArgsConstructor
public class MemberController {

    private final MemberService memberService;
}
