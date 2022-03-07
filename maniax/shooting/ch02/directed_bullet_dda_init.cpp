#include <cmath>

void init_directed_bullet_dda
(
	int i_theta,         // 발사 각도
	int i_ex, int i_ey,    // 적의 좌표
	int& i_x, int& i_y,    // 탄의 좌표
	int& i_vx, int& i_vy,  // 탄의 이동방향
	int& i_dx, int& i_dy,  // X방향과 Y방향의 차이
	int& i_diff          // 오차
) 
{
	// 가상적인 메인 캐릭터를 멀리 배치하기:
	// M_PI는 원주율
	int i_mx = cos(M_PI / 180 * i_theta) * 1000;
	int i_my = sin(M_PI / 180 * i_theta) * 1000;
	// 이후는 DDA를 사용한 조준탄 처리와 동일함
	
	// 탄의 좌표를 설정하기
	i_x = i_ex; 
	i_y = i_ey;

	// 탄의 이동방향(i_vx,i_vy)을 구하기: 값은 1 혹은 -1
	i_vx = i_mx > i_ex ? 1:-1;
	i_vy = i_my > i_ey ? 1:-1;

	// 목표에 대한 X방향과 Y방향의 차이의 절대치(i_dx, i_dy)를 구하기
	i_dx = i_mx >= i_ex ? i_mx - i_ex : i_ex - i_mx;
	i_dy = i_my >= i_ey ? i_my - i_ey : i_ey - i_my;

	// 오차i_diff : i_dx>=i_dy일 때는 i_dx/2, i_dx<i_dy일 때는 i_dy/2로 설정함
	i_diff = i_dx >= i_dy ? i_dx / 2 : i_dy / 2;
}
