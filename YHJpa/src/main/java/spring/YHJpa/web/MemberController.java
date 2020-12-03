package spring.YHJpa.web;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import spring.YHJpa.domain.Address;
import spring.YHJpa.domain.Member;
import spring.YHJpa.service.MemberService;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import javax.validation.Valid;
import java.util.List;

@Controller
@RequiredArgsConstructor
public class MemberController {

    private final MemberService memberService;

    //login
    @GetMapping("/members/log")
    public String loginForm(Model model) {
        model.addAttribute("loginForm", new LoginForm());
        return "members/loginMemberForm";
    }

    @PostMapping("/members/login")
    public String login(Model model, HttpServletRequest req, HttpSession session) {
        String id = req.getParameter("id");
        String pwd = req.getParameter("pwd");

        Member member = new Member();
        member.setId(id);
        member.setPwd(pwd);
        boolean logo = memberService.logingo(member);

        if (logo == true) {
            System.out.println("login Success!");
            session.setAttribute("id", id);
        } else {
            System.out.println("login fail!");
            session.setAttribute("id", null);
        }

        return "redirect:/";
    }

    //logout
    @GetMapping("members/logout")
    public String logout(HttpSession session) {
        session.removeAttribute("id");
        System.out.println("@@@ logout success @@@");
        return "redirect:/";
    }

    @GetMapping(value = "/members/new")
    public String createForm(Model model) {

        model.addAttribute("memberForm", new MemberForm());
        return "members/createMemberForm";
    }

    @PostMapping(value = "/members/new")
    public String create(@Valid MemberForm form, BindingResult result) {

        if (result.hasErrors()) {
            return "members/createMemberForm";
        }

        Address address = new Address(form.getCity(), form.getStreet(), form.getZipcode());

        Member member = new Member();

        member.setId(form.getId());
        member.setPwd(form.getPwd());
        member.setPwd2(form.getPwd2());
        member.setName(form.getName());
        member.setAddress(address);

        memberService.join(member);
        return "redirect:/";
    }

    @GetMapping(value = "/members")
    public String list(Model model) {
        List<Member> members = memberService.findMembers();
        model.addAttribute("members", members);
        return "members/memberList";
    }
}
