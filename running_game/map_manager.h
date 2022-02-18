#pragma once
#include "value.h"

// 클래스 전방 선언 : 이곳에서 전방선언한 클래스가 있다 라고 인식하게 만든다. 전방선언 한 부분에서는 가정만 하는 것이기 때문에 전방선언한 클래스의 객체를 생성하던가 끌어다 사용할 수 없다. 단순히 포인터 변수를 선언할 목적으로 주로 사용하고 전방선언을 사용함으로써 헤더에서 헤더를 #include 하는 상황을 막아주고 cpp에서 실제 사용할 때 include를 해주어서 헤더간에 서로 include 하는 상황을 막아줄 수 있다.
class CStage;
class CMapManager
{
	private:
		CMapManager();
		~CMapManager();
	private:
		static CMapManager *m_p_inst;
	public:
		static CMapManager *get_inst();
		static void destroy_inst();
	private:
		CStage *m_p_stage[STAGE_MAX_COUNT];
	public:
		bool init();
};
