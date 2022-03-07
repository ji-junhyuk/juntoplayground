#include <cmath>

void init_directed_bullet
(
	float f_ex, float f_ey,    // 적의 좌표
	float& x, float& y,    // 탄의 좌표
	float& f_vx, float& f_vy,  // 탄의 속도벡터
	float f_speed,           // 탄의 속도
	float f_theta            // 발사각도
) 
{
	// 탄의 좌표를 설정하기
	x = f_ex; 
	y = f_ey;
	// f_speed의 속도로 각도 f_theta 방향으로 날아가는 탄의 속도벡터(f_vx,f_vy)를 구하기:
	// M_PI는 원주율
	f_vx = cos(M_PI/180*f_theta) * f_speed;
	f_vy = sin(M_PI/180*f_theta) * f_speed;
}

void move_directed_bullet
(
	float& f_x, float& f_y,  // 탄의 좌표
	float f_vx, float f_vy   // 탄의 속도벡터
) 
{
	// 탄의 좌표(f_x,f_y)에 속도벡터(f_vx,f_vy)를 더하기
	f_x += f_vx;
	f_y += f_vy;
}
