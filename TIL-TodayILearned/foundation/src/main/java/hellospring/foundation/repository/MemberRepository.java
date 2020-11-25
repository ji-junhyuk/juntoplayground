package hellospring.foundation.repository;

import hellospring.foundation.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberRepository {

    Member save(Member member);
//Basic : void save(Member) member

    Optional<Member> findById(Long id);
//Basic : Member findById(Long memberId)

    Optional<Member> findByName(String name);

    List<Member> findAll();
}
