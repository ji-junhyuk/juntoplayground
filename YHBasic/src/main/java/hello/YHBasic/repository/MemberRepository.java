package hello.YHBasic.repository;

import hello.YHBasic.domain.Member;

public interface MemberRepository {

    void save(Member member);

    Member findById(Long memberId);
}
