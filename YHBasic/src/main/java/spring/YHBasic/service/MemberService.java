package spring.YHBasic.service;

import spring.YHBasic.domain.Member;

public interface MemberService {

    void join(Member member);

    Member findMember(Long memberId);
}
