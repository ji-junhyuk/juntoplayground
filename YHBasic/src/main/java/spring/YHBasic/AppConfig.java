package spring.YHBasic;

import spring.YHBasic.repository.MemoryMemberRepository;
import spring.YHBasic.service.MemberService;
import spring.YHBasic.service.MemberServiceImpl;

public class AppConfig {

    public MemberService memberService() {
        return new MemberServiceImpl(new MemoryMemberRepository());
    }
}
