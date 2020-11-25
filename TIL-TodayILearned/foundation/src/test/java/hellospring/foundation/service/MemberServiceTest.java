package hellospring.foundation.service;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.transaction.annotation.Transactional;

@SpringBootTest
@Transactional
class MemberServiceTest {
     
/*
    MemberService memberService = new MemberService();
    MemoryMemberRepository memberRepository;


    @BeforeEach
    public void beforeEach() {
//        SpringConfig springConfig = new SpringConfig();

    }

    @AfterEach
    public void afterEach() {
        memberRepository.clearStore();
    }

    @Test
    public void join() throws Exception {
        //given
        Member member = new Member(1L, "memberA", Grade.VIP);
        member.setName("hello");

        //when
        Long saveId = memberService.join(member);

        //then
        Member findMember = memberRepository.findById(saveId).get();
        assertEquals(member.getName(), findMember.getName());
    }

    @Test
    public void duplicateMemberException() throws Exception {
        //given
        Member member1 = new Member(1L, "memberA", Grade.VIP);
        member1.setName("spring");

        Member member2 = new Member(1L, "memberA", Grade.VIP);
        member2.setName("spring");

        //when
        memberService.join(member1);
        IllegalStateException e = assertThrows(IllegalStateException.class,
                () -> memberService.join(member2));

        Assertions.assertThat(e.getMessage()).isEqualTo("Already existing member.");

        //then
     }*/

     @Test
     public void join2() {
/*
         //given
         Member member = new Member(1L, "memberA", Grade.VIP);

         //when
         memberService.join(member);
         Optional<Member> findMember = memberService.findOne(1L);

         //then
         Assertions.assertThat(member).isEqualTo(findMember);
*/
     }

}