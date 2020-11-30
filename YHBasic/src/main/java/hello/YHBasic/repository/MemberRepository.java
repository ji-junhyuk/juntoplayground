package hello.YHBasic.repository;

import hello.YHBasic.domain.Member;

public interface MemberRepository {

    void save(Member member);

    void findById(Long memberId);
}
