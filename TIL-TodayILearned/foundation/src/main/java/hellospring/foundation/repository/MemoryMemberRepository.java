package hellospring.foundation.repository;

import hellospring.foundation.domain.Member;

import java.util.*;

/*
    Concurrency issues are not considered.
    In practice, consider using concurrentHashmap and AtomicLong
*/

public class MemoryMemberRepository {

}

/*    private static Map<Long, Member> store = new HashMap<>();
    private static long sequence = 0L;
//BASIC : private static Map<Long, Member> store = new HashMap<>();

    @Override
    public Member save(Member member) {
        member.setId(++sequence);
        store.put(member.getId(), member);
        return member;
    }

    @Override
    public Optional<Member> findById(Long id) {
        return Optional.ofNullable(store.get(id));
    }

    @Override
    public Optional<Member> findByName(String name) {
        return store.values().stream()
                .filter(member -> member.getName().equals(name))
                .findAny();
    }

    @Override
    public List<Member> findAll() {
        return new ArrayList<>(store.values());
    }

    public void clearStore() {
        store.clear();
    }
}*/
