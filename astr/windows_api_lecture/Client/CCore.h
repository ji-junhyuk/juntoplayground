#pragma once

//cf.
// 지역
// 전역
// 정적 (데이터 영역)
// 1. 함수 안에
// 2. 파일 
// 3. 클래스 안에 
// 정적멤버는 클래스 밖에서 반드시 초기화해주어야 한다.
// 외부

// 싱글톤 패턴
// 객체의 생성을 1개로 제한
// 어디서든 쉽게 접근 가능

/*
class CCore
{
private:
	static CCore* g_pInst;
public:
	// 정적 멤버함수, 객체 없이 호출 가능 즉, 멤버에 접근 불가능(this 키워드가 없음), 정적 멤버는 접근 가능.
	static CCore* GetInstance()
	{
		if (g_pInst == nullptr)
		{
			g_pInst = new CCore;
		}
		return g_pInst;
	}
	static void Release()
	{
		if (g_pInst != nullptr)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}
private:
	CCore();
	~CCore();
};
*/

class CCore
{
	SINGLE(CCore);
	//static CCore* GetInst()
	//{
	//	static CCore core;

	//	return &core;
	//}
private:
	HWND	m_hWnd;			// 메인 윈도우 핸들
	POINT	m_ptResolution;	// 메인 윈도우 해상도
	HDC		m_hDc;			// 메인 윈도우에 Draw 함수
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
private:
	void update();
	void render();
private:
	CCore();
	~CCore();
};