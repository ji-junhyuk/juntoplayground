package hello.YHBasic.service;

import hello.YHBasic.domain.Member;

public interface MemberService {

    void join(Member member);

    Member findMember(Long memberId);
}
