#include <cmath>

// 메인 캐릭터의 위치를 저장하는 테이블
int m_pos[360][2];

// 테이블을 작성하기:
// M_PI는 원주율
void make_table() 
{
	for (int idx = 0; idx < 360; idx++) 
	{
		m_pos[idx][0] = cos(M_PI / 180 * idx) * 1000;
		m_pos[idx][1] = sin(M_PI / 180 * idx) * 1000;
	}
}

void init_directed_bullet_dda2
(
	int i_theta,         // 발사각도
	int i_ex, int i_ey,    // 적의 좌표
	int& i_x, int& i_y,    // 탄의 좌료
	int& i_vx, int& i_vy,  // 탄의 이동방향
	int& i_dx, int& i_dy,  // X방향과 Y방향의 차이
	int& i_diff          // 오차
) 
{
	// 가상적인 메인 캐릭터의 위치를 테이블에서 읽어옴
	int dir = (i_theta % 360 + 360) % 360;
	int mx = m_pos[dir][0];
	int my = m_pos[dir][1];

	// 이후는 DDA를 사용하여 메인 캐릭터 방향으로 탄을 보내는 처리와 같음
	// 탄의 좌표를 설정하기
	i_x = i_ex; 
	i_y=i_ey;

	// 탄의 이동방향(i_vx,i_vy)을 구하기: 값은 1 혹은 -1
	i_vx = mx > i_ex ? 1 : -1;
	i_vy = my > i_ey ? 1 : -1;

	// 목표에 대한 X방향과 Y방향의 차이의 절대치(i_dx, i_dy)를 구하기
	i_dx = mx >= i_ex ? mx-i_ex : i_ex-mx;
	i_dy = my >= i_ey ? my-i_ey : i_ey-my;

	// 오차i_diff : i_dx>=i_dy일 때는 i_dx/2, i_dx<i_dy일 때는 i_dy/2로 설정함
	i_diff = i_dx >= i_dy ? i_dx/2 : i_dy/2;
}
