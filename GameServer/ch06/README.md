## 6장. 게임 네트워크 엔진 프라우드넷
- 게임 서버와 멀티 플레이 처리를 개발할 때 게임 네트워킹 처리를 위해 보통 소켓 API를 이용한다. 그러나 소켓 API만을 이용해서 개발할 때는 다음과 같은 번거로움이 발생한다.
	1. 운영체제마다 소켓 API를 사용하는 방식이나 작동하는 방식에 조금씩 차이가 있다.
	2. 소켓 API에서 제공 되지 않는 기능을 직접 만들어써야 할 때가 있다.
- 게임 서버 엔진의 종류
	- 프라우드넷
	- 프톤 서버 
	- 게임 스파크
	- 플레이팹
	- 락넷
### 6.2 개발 환경과 기본 모듈
- 프라우드넷의 네트워크 모듈은 크게 클래스 2개로 나뉜다.
	- NetServer 클래스: 게임 서버의 메인 모듈. 클라이언틔 연결을 받으며, 클라이언트와 메시지를 주고 받는 역할, 각 클라이언트의 네트워크 상황 열람 가능
	- NetClient 클래스: 게임 클라이언트에서 네트워크 모듈이다. 서버로 연결을 맺은 후 메시지 주고 받기를 수행할 수 있다. 또 다른 클라이언트와 P2P통신도 가능하다.

### 6.3 게임 클라이언트-서버 간 통신
- NetServer 인스턴스를 생성하고 NetServer가 클라이언트 접속을 받으려면 다음 작업이 필요하다
	1. CNetServer.Create()로 CNetServer 인스턴스를 생성합니다.
	2. CNetServer.Start()로 서버가 클라이언트 접속을 받을 수 있게 합니다.
- start()에 들어가는 필수 매개변수는 프로토콜 버전과 리스팅 포트 번호이다.
- 클라이언트는 다음과 같이 서버에 접속한다.
	1. CNetClient.Create()로 클라이언트 인스턴스를 생성
	2. CNetClient.Connect()로 서버에 접속
- Connect() 함수를 호출할 때 입력값으로 서버 주소와 포트 값, 프로토콜 버전값을 넣으면 된다.
- 서버에서 클라이언트 접속이 들어오면 서버가 갖고 있는 스레드 풀에서 OnClientJoin()이벤트 함수를 호출한다. 이는 함수 콜백(callback)형태이다. 즉, 여러분은 이 이벤트를 처리하는 함수를 만들어야 하고, 프라우드넷은 그 함수를 호출해준다.
- 서버간 연결 해제
	- 클라이언트에서 DisConnet()함수 호출, 서버에선 OnClientLeave()이벤트 함수 호출 - 우리가 구현.
	- 중간에 연결 해제되면 클라이언트에서 OnLeaveServer()이벤트 함수 호출(서버-OnClientLeave() 함수 호출)
#### 서버를 구동하는 코드
```c++
CNetServer* s = CNetServer::Create(); // 서버 생성
param.m_tcpPorts.Add(44444); // 서버가 네트워크 연결 받기 위해 사용하는 TCP 리슨 포트
param.m_udpPort.Add(44444);
param.m_protocolVersion = Guiod(
{ 0x5sdss, 0x9221, 0x22a0, {0xb5, 0x8b,
0x85, 0x92 ,0x83, 0x25, 0x2e}}); // 서버와 클라이언트가 모두 맞추어야 하는 프로토콜 버전값이다. 이값은 클라이언트와 서버가 같아야 한다.
s->Start(param);
```

#### 서버 접속 코드
```c++
CNetClient* c = CNetClient::Create();
param.m_serverAddr = _PNT("my.game.com");
param.m_serverPort = 44444;
param.m_protocol = Guid(...);
c->Connect(param);
```

#### 서버 접속 게임
```c++
NetClient c = new NetClient(); 
param.m_serverAddr = "my.game.com";
param.m_serverPort = 44444;
param.m_protocol = Guid.From({...});
c.Connect(param);
```

#### 이벤트 처리 코드
```c++
c->OnJoinServerComplete = [](ErrorInfo* result) 
{
	if (result->m_errorType == ErrorType_Ok)
	{
		... // 성공처리
	}
	else
	{
		print(result->ToString());
	}
}
```

#### 서버에서 클라이언트 접속을 받는 코드
```c++
s->OnClientJoin = [](CNetClientInfo* info)
{
// info에는 새 클라이언트 정보가 있다.
}
```
- 일반적으로 게임 클라이언트는 메인 루프를 가진다. 메인 루프에서는 게임 로직 처리와 렌더링을 한다. 서버나 다른 클라이언트에서 온 메시지를 처리하거나 이벤트 함수를 호출하는 것도 이 메인루프 어딘가에서 여러분이 원하는 시점에 하기 마련이다.
- 요약하자면
	1. NetServer 를 생성해서 Start()함수를 호출
	2. NetClient 를 생성해서 Connect()함수를 호출
	3. NetServer.OnClientJoin(), OnClineLeave()에서 클라이언트의 들어감 / 나감을 처리
	4. NetClient.OnJoinServerComplete(), OnLeaveServer()에서 서버와 접속의 성공/실패/중도연결 해제를 처리
	5. NetClient.FrameMove()를 게속해서 호출한다.
#### 6.4 메시지 주고 받기
```c++
unsigned char data[100];

c->SendUserMessage(HostID_Server,
	RmiContext::ReliableSend, data, 100);
s->SendUserMessage(ClientHostID,
	RmiContext::UnreliableSend, data, 50);
HostID sendTo[10];
s->SendUserMessage(sendTo, 10,
	RmiContext::UnreliableSend, data, 30);
```
- 메시지 받는 코드
```c++
c->OnReceiveUserMessage = [...]
	(HostID sender, cosnt RmiContext& rmiContext,
		uint8_t* payload, int payloadLength)
	{
	};
```
#### 6.5 와이파이 셀룰러 연결 핸드오버 기능
- 와이파이 지역에서 게임을 플레이하던 모바일 게임 클라이언트가 와이파이 지역을 벗어나면? -> 인터넷 연결이 끊어진다
- 와이파이 지역 바깥에서 게임을 하던 모바일 게임 클라이언트가 와이파이 지역 안으로 들어오면? -> 인터넷 연결이 끊어진다
- 프라우드넷은 연결 유지 기능(auto connection recovery)이 있다
```c++
param.m_autoConnectionRecovery = true;
...
c->Connect(param);
```
- 네트워크가 일시 정지를 했을 때 우리는 게임 클라이언트 화면에 무언가를 보여주고 싶다. 반대로 네트워크가 완전히 회복되었을 때도.
```c++
c->OnServerOffline = [...](CRemoteOfflineEventArgs &args)
{}
// ====

c->OnServeOnline = [](CRemoteOfflineEventArgs &args)
{}
```
- 만약 p2p 연결을 사용하고 있다면 OnP2PMemberOffline, OnP2pMemberOnline 호출될 것.

### 6.6 원격 메서드 호출
- SendUserMessage를 이용해서 이진 데이터를 보내고, 받는 쪽에서는 OnReceiveUserMessage를 주고 받는 것은 송수신 루틴을 직접 만들어야 하는 번거로움이 있다.
- 프라우드넷의 RMI를 이용하면 이것이 편리해진다. RMI는 원격 메서드 호출(Remote Method Invocation)로 "상대방 컴퓨터 안에 있는 프로그램의 특정 함수를 멀리서 실행하라"라는 의미이다.
```c++
class SenderCode
{
	// 자동으로 생성되는 코드
	Knight_Move(SendTo, position, motion)
	{
		Message msg;
		msg.Write(ID_Knight_Move);
		msg.Write(position);
		msg.Write(motion0;
		Send(SendTo, msg);
	}
}
// 송신을 담당하는 코드는 "함수 호출을 대신 해준다"라는 의미로 proxy라고 한다.
반대로 수신하는 쪽에서는 받은 메시지를 분석하여 여러분이 만든 함수를 호출해준다.

class ReceiverCode
{
	// 자동으로 생성되는 코드
	ProcessReceivedMessage(Message msg)
	{
		ID = msg.Read();
		switch (ID)
		{
		case ID_Knight_Move:
			position = msg.Read();
			motion = msg.Read();
			Knight_Move(position, motion);
			break;
		}
	}
	Knight_Move(position, motion)
	{
		// 여기에 코드를 작성한다.
	}
}
```

- 세상에서 제일 비효율적인 계산기 만들기 (클라이언트가 서버에 두 값을 보내면, 서버는 그 결과를 더해 클라이언트에 응답)
```c++
global CalcC2S 1000
{
	RequestAdd([in] int a, [in] int b);
}
global CalcC2S 2000 // 1000, 2000은 RMI ID의 시작값이다.
{
	ResponseAdd([in] int sum);
}

이 PIDL 파일을 컴파일 할 때 PIDL컴파일러가 생성하는 클래스는 다음과 같다.
CalcC2s::Proxy // 클라 -> 서버
CalcC2s::Stub
CalcC2s::StubFunctional
CalcS2C::Proxy // 서버 -> 클라
CalcS2C::Stub
CalcS2C::StubFunctional
}
```
- 클라이언트와 서버에 송신 코드(proxy)와 수신 코드(stub) 붙이기
- 서버는 클라의 Proxy를 가지고 클라는 서버의 Stub를 가져야한다.
```c++
CalcC2s::Proxy CalcC2SProxy;
c->AttatchProxy(&CalcC2SProxy);
CalcS2C::StubFunctional CalcS2CStub;
c->AttatchStub(&CalcS2CStub);
```
- 클라에서 서버로 RMI호출
```c++
CalcC2SProxy.RequestAdd(HostID_Server,
	RmiContext::ReliableSend, 3, 4);
```
- 서버에서 RMI 호출받기. 함수를 호출 받을 것이므로 호출 받는 함수 만들기!
```c++
CalcC2SStub.RequestAdd_Function =
	[]PARAM_CalcC2SStub_RequestAdd
	{ // 클라에서 보낸 즉 원격으로 호출한 RequestAdd함수가 실행할 루틴을 람다식으로 넣어주는 부분이다
		int sum = a + b;
		CalcS2CProxy.ResponseAdd(remote,
			RmiContext::ReliableSend,
			sum); // 서버에서 클라이언트에 원격으로 함수를 호출한다.
	};
};
```
- 클라이언트에서도 수신하는 곳 만들기!
```c++
CalcS2CStub.ResponseAdd_Function = 
	[]PARAM_CalcS2CStub_ResponseADD
	{
		print(sum);
	};
```
- 지금까지 절차 요약해보자.
	1. PIDL 파일에 RMI 함수 정의
	2. 이를 컴파일(빌드설정에 넣기)
	3. 생성된 Proxy, Stub를 NetClient와 NetServerdp qnckr
	4. 생성된 Proxy의 함수를 호출하면 메시지가 전송
	5. 생성된 Stub에 함수를 부착하면 그 함수들이 호출
### 6.8 클라이언트끼리 P2P 통신
- 프라우드넷 P2P 네트워킹 기능 중 하나는 "P2P 연결을 생성하는데 시간이 걸리지 않는다"라는 점
	1. 서버에서 클라1과 클라2가 P2P 연결을 하라고 지시
	2. 클라1, 클라2는 자기가 P2P연결 되었음을 즉시 알 수 있다.
	3. 직후에 바로 클라 1과 클라2는 메시지를 주고 받는다.
- P2P 그룹의 특징
	1. P2P 그룹에는 클라이언트를 0개 이상 넣을 수 있다.
	2. 클라이언트 하나가 여러 P2P 그룹에 들어가도 된다. 즉 겹쳐도 된다.
	3. 서버도 P2P 그룹에 들어가는 것이 허락된다.
```c++
HostId list[2];
list[0] = C1;
list[1] = C2;
G = s->CreateP2PGroup(list, 2);
```
```c++
c->OnP2PMemberJoin = [...]
	(HostID memberHostID, //1
	HostID groupHostID, //2
	int	memberCount, //3
	const ByteArray &customField)
{
	G = groupHostID; //4
	Peers.Add(memberHostID);
};
```
- 1 memberHostID가 가리키는 다른 호스트와 로컬 자기 자신과 P2P연결이 맺어졌는지 의미
- 2 memberHostID와 로컬 자기 자신이 어느 P2P 그룹에 들어가 있는지 의미
- 3 P2P그룹에 호스트가 몇개 있는지 의미한다.
- 4 여러분 코드. 지금 필요한 것은 "내가 어느 P2P그룹에 있고 나와 통신 가능한 다른 호스트들이 누구인지"를 보관
```c++
// p2p메시지 보내기
C->SendUserMessage(G, RmiContext::ReliableSend, data, length0;
```
- P2P 홀펀칭 상태 변화 감지하기 : P@P 홀펀칭이란 인터넷 공유기 뒤에 있는 클라끼리는 서로 P2P 통신을 할 수 있는 기법이다.
- 홀펀칭이 되어 있지 않으면 P2P 네트워킹은 서버를 통해 간접적으로 이루어진다. 이를 P2P 릴레이라고 한다. 
- P2P 네트워킹이 홀펀칭되어서 직접 이루어지는지, 아직 홀펀칭이 되어 있지 않아 P2P 네트워킹이 릴레이 되어서 이루어지는지 궁금하다면 OnChangeP2PRelayState() 함수 콜백하자.
```c++
global MyGameP2P // 1
{
	Player_Move([in] Vector3 position);
}

MyGameP2P::Proxy P2PProxy; //2
MyGameP2P::StubFunctional P2PStub;

P2PStub.Player_Move_Function = [...]PARAM_MyGameP2P_Player_Move {}; // 3
c->AttachProxy(&P2PProxy); // 4
C->AttachStub(&P2PStub);

P2PProxy.Player_Move(G, RmiContext::UnreliableSend, myPosition); // 5
```
- 1 P2P 통신용 RMI 정의
- 2 P2P RMI의 Proxy와 Stub의 클래스 인스턴스
- 3 P2P로 RMI를 받으면 그것을 처리하는 함수 정의
- 4 2의 인스턴스들을 NetClient에 부착
- 5 P2P 클라이언트에 원격 함수 호출, 즉 송신

### 6.8 예시: 채팅처리
- 클라에서 서버로 보내는 Chat RMI 함수를 선언합시다. 클라이언트에서는 이 함수를 호출하여 서버에 채팅을 보낸다.
- 서버에서 이를 수신하면 다른 모든 클라이언트에 ShowChat RMI를 멀티캐스트 한다.
- 클라이언트는 ShowChat RMI를 받으면 이를 화면에 표시.
```c++
class MyGameServer // 일부 의사코드
{
	CNetServer* m_netServer;
	CriticalSection m_critSec;
	map<HostID, shared_ptr<RemoteClient>> m_remoteClients;
	
	OnClientJoin(cleintInfo)
	{
		CriticalSectionLock lock(m_critSec, true);
		shared_ptr<RemoteClient> new Remote = shared_ptr<RemoteClient>(new RemoteClient);
		fill_somthing(newRemote);
		m_remoteClients.Add(clientInfo->m_hostID, newRemote);
	}
	
	OnClientLeave(clientinfo)
	{
		CriticalSectionLock lock(m_critSec, true);
		m_remoteClients.Remove(clientInfo->m_hostID)
	}
	
	Init()
	{
		m_netServer->OnclientJoin = OnClientJoin;
		m_netServer->OnClientLeave = OnClientLeave;
	}
}
```
- NetServer는 기본적으로 멀티 스레드로 작동한다.
- 클라이언트 목록 변수와 기타 데이터를 보호하는 mutex 혹은 크리티컬 섹션 객체를 갖고 있어야 한다.
##### 클라이언트에서 서버와 연결 및 수신처리를 알아보자
```c++ 
class MyGameClient
{
	CNetClient* m_netClinet;
	
	OnJoinServerComplete(info, replyFromServer)
	{
		if (info.type == OK)
		{
			do_success();
		}
		else
		{
			do_failure();
		}
	}
	
	OnLearveServer(info)
	{
		do_leave();
	}
	
	Init()
	{
		m_netClient->OnJoinServerComplete = OnJoinServerComplete;
		m_netClient->OnLearveServer = OnLeaveServer;
	}
	
	MainLoop()
	{
		while (true)
		{
			m_netClient->FrameMove();
			update_scene();
			render_scene();
		}
	}
}
```
- 서버에서 메시지를 수신하면 일을 처리하는 코드
```c++
class RemoteClient
{
	string m_name;
};

MyGameServer:public MyGame2CS::Stub
{
	MyGameS2C::Proxy m_s2cProxy;
	
	MyGameS2C::Stub::Chat(senderHostId, rmiContext, text)
	{
		CriticalSectionLock lock(m_critSec, true);
		
		shared_ptr<RemoteClient> sender = m_remoteClients.find(senderHostId).second;
		
		// 수신자 목록 만들기
		vector<HostID> sendTo;
		for (auto r : m_remoteClients)
		{
			if (r.first != senderHostID)
				sendTo.push_back(r.first);
		}
		
		// 멀티캐스트!
		m_s2cProxy.ShowChat(&r[0], r.size(),
			sender->m_name, text);
	}
}
```

### 6.9 스레드 모델
- 프라우드넷은 서버 프로세스 하나가 스레드를 여럿 가지는 형태와 여러 서버 프로세스가 각각 스레드 하나를 가지는 형태 모두 지원한다.
- 기본값으로 NetServer의 워커 스레드(work thread)는 CPU 개수만큼 공급된다. 그러나 다음 상황일 때 이를 권장하지 않는다.
	1. 서버 내부 데이터가 뮤텍스 1개로 보호되는 경우
	2. 서버 내부 로직에서 DB나 파일 액세스 등 디바이스 타임(device time)이 없는 경우
	3. 서버 프로세스를 여러 개 띄울 수 있게 분산 서버로 개발하는 경우
```c++
// 싱글 스레드 구동
void main()
{
	...
	CThreadPool* p = CThreadPool::Create(... , 0); // 스레드가 전혀 없는 스레드 풀 객체 생성
	
	CStartServerparameter param;
	param.m_externalNetWorkerThreadPool = p; // NetServer가 이 스레드 풀 객체를 사용하도록 설정
	param.m_externalUserWorkerThreadPool = p;
	netServer->Start(param);
	
	while (true)
	{
		p->Process(10); // 최대 10 밀리초까지 기다리면서 thread pool에 쌓인 이벤트를 처리한다.
	}
}
```
