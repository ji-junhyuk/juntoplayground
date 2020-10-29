package jpabook.jpashopPractice1.api;

import jpabook.jpashopPractice1.domain.Member;
import jpabook.jpashopPractice1.service.MemberService;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import javax.xml.transform.Result;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

@RestController
@RequiredArgsConstructor
public class MemberApiController {

    private final MemberService memberService;

    /* *
     * Registration V1: Receive a Member entity directly as a request value
     * problem
     * -The logic for the presentation layer is added to the entity.
     *      -The entity enters the logic for API verification. (@NotEmpty etc.)
     *      -In practice, various APIs for member entities are made,
            but it is difficult to include all request requirements for each API in one entity.
     * -API specification changes when entity changes.

     * conclusion
     * -Receive a separate DTO as a parameter according to the API request specification.
     */

    @PostMapping("/api/v1/members")
    public CreateMemberResponse saveMemberV1(@RequestBody @Valid Member member) {
        Long id = memberService.join(member);
        return new CreateMemberResponse(id);
    }

    @Data
    static class CreateMemberRequest {
        private String name;
    }

    @Data
    class CreateMemberResponse {
        private Long id;

        public CreateMemberResponse(Long id) {
            this.id = id;
        }

        /*
         *Registration V2: Receive a separate DTO instead of the Member entity as a request value.
         */
        @PostMapping("/api/v2/members")
        public CreateMemberResponse saveMemberV2(@RequestBody @Valid CreateMemberRequest request) {

            Member member = new Member();
            member.setName(request.getName());

            Long id = memberService.join(member);
            return new CreateMemberResponse(id);
        }

        @PutMapping("/api/v2/members/{id}")
        public UpdateMemberResponse updateMemberV2(@PathVariable("id") Long id, @RequestBody @Valid UpdateMemberRequest request) {
            memberService.update(id, request.getName());
            Member findMember = memberService.findOne(id);
            return new UpdateMemberResponse(findMember.getId(), findMember.getName());
        }

        @Data
        static class UpdateMemberRequest {
            private String name;
        }

        @Data
        @AllArgsConstructor
        class UpdateMemberResponse {
            private Long id;
            private String name;
        }


    }
    //Lookup V1: bad version, all entities exposed, @JsonIgnore -> this is really the worst, api is not one!
    // Don't be subordinate to the screen!

    @GetMapping("/api/v1/members")
    public List<Member> membersV1() {
        return memberService.findMembers();
    }

    //Inquiry V2 : A separate Dto other than an entity is returned as a response value.
    @GetMapping("/api/v2/members")
    public Result memberV2() {

        List<Member> findMembers = memberService.findMembers();
        List<MemberDto> collect = findMembers.stream().map(m -> new MemberDto(m.getName())).collect(Collectors.toList());
        return new Result(collect);
    }

    @Data
    @AllArgsConstructor
    class Result<T> {
        private T data;
    }

    class MemberDto {
        private String name;
    }


