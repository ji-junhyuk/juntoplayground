package spring.YHBasic.repository;

import spring.YHBasic.domain.Member;

public interface MemberRepository {

    void save(Member member);

    Member findById(Long id);
}
