4강
V1
Member Entity
name을 username으로 변경하는 순간
Entitiy의 스펙이 변한다.
Api스펙 자체가 바뀐다. (Entitiy와 Api와 스펙 자체가 매핑)
Api스펙을 위한 Data 클래스가 필요하다. (별도의 Dto가 필요) -> 나중에 별도의 큰 장애가 생길 수 있음
Api를 만들때는 절대 Entity를 파라미터로 받지 마라.
엔티티를 외부에 노출해서는 안된다.

5강
V2
- 유지보수할 때 큰 장점(CretaeMemberRequest request)
- 엔티티를 변경해도 Api스펙이 바뀌지 않는다.
- 외부 Api 스펙이랑 엔티티랑 무관하게 별도의 객체를 만들어준다. (Dto 정석)

// 영한님 Entitiy에는 롬복 어노테이션 자제함 Getter 정도만
// dto에는 그냥 막써요 (성향) 대충 데이터만 왔다갔다 하기 때문에 (실용적인 관점)
// 영한님 개발 원칙: 커맨드랑 쿼리를 철저히 분리 (public void update -> public Member update (member를 쿼리를 하는 꼴))
// @PutMapping member findMember = memberService.findOne(id) 별도로 만듬
// 단순히 pk 하나 찍어서 개발하는 거에는 분리를 시킴. 유지보수성 증가. 특별히 트래픽 많은 api가 아니라면...
 
6강

