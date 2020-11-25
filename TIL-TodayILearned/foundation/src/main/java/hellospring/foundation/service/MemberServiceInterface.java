package hellospring.foundation.service;

import hellospring.foundation.domain.Member;

import java.util.List;
import java.util.Optional;

public interface MemberServiceInterface {

    Long join(Member member);

    List<Member> findMembers();

    Optional<Member> findOne(Long id);
}
