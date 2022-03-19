## 게임 서버와 클라이언트
- 지금부터 언급하는 서버란 온라인 게임에서 데디케이티드 서버를 말한다.

### 4.3 서버의 역할
- 입력받기, 게임 로직 처리하기, 렌더링 이 세과정을 반보가는 것을 게임 루프(game loop)라고 부르겠다.

### 4.4 게임 클라이언트와 서버의 상호작용
- 게임 클라이언트와 서버의 상호 작용은 크게 네가지로 구별된다
	- 연결
	- 요청 - 응답
	- 능동적 통보
	- 연결 해제

### 4.5 게임 서버가 하는 일
- 여러 사용자와 상호작용
- 클라이언트에게 해킹 당하면 안 되는 처리
- 플레이어의 상태 보관

### 4.6 게임 서버의 품질
- 안정성(stability)
	- 80:20 법칙(성능에 지대한 영향을 주는 일부분의 소스코드에서만 프로그램 구조가 복잡해지더라도 성능을 최적화해서 개발하고, 나머지는 성능보다 유지 보수하기 쉬운 단순한 구조로 개발하는 것
- 확장성(scalability)
- 성능(performance)
- 관리 편의성

### 4.7 플레이어의 정보의 저장
- 플레이어 정보를 클라이언트에 잘 저장하지 않는다.
	 - 해킹에 취약하다. 사용자가 건드릴 수 있기 때문이다.
	 - 같은 사용자가 다른 기기를 사용할 때 문제가 된다. 온라인 게임 사용자가 클라이언트 기기를 교체하거나 다른 기기에서 게임을 마저할 경우, 처음 저장된 플레이어 데이터를 가져올 방버빙 없다.
- 플레이어 데이터를 데이터 베이스 소프트웨어를 이용해서 저장할 때가 더 많다.
	- 데이터 관리와 분석을 빠르게할 수 있다.
	- 강력한 데이터 복원 기능이 있다.
	- '전부 아니면 전무', 데이터베이스는 트랜젝션(transaction)이라는 기능을 제공하는데, 어떤 경우에도 원상복구할 수 있다. 이를 원자성(atomicity)이라고 한다.
	- 데이터 일관성을 유지시켜 준다.
	- 데이터베이스 처리가 2개 이상 동시에 실행될 때 한 데이터가 여러 데이터를 액세스하면서 이상한 결과가 나오는 문제를 막아주는 기능이 있다. (lock)
	- 장애에 대한 내성이 강하다. 로그 버퍼(log buffer)라는 별도 파일에 할일을 미리 기록한 후 이를 실제 데이터베이스에 적용한다. 그런데 중간에 죽어버린다면 로그 버퍼에서 '아직 안한 일'을 찾아 복원한다.
### 서버 구동 환경
### 서버 개발 지침