1. friend 함수가 가지는 특권은 무엇인가?
- friend 함수는 접근 제어 지시자에 영향을 받지 않는다. 따라서 private, protected로 지정되어 보호 받는 클래스 멤버 변수에도 직접 접근할 수 있다.
2. A클래스의 멤버로 B클래스(포인터나 참조 제외)가 사용됐다면 이 두 클래스는 어떤 관계라 할 수 있나요?
 - Composition 관계이다. A클래스 선언 시 B클래스도 같이 선언되고 A클래스가 해제되면 B클래스도 같이 해제된다.