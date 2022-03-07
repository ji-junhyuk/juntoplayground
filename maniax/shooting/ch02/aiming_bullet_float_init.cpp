#include <cmath>

void init_aiming_bullet
(
	float f_mx, float f_my, // 메인케릭터의 위치
	float f_ex, float f_ey, // 적기의 좌표
	float f_speed, // 탄환의 속도
	float &f_x, float &f_y, // 탄환의 좌표
	float &f_vx, float &f_vy // 탄환의 속도 벡터
)
{
	f_x = f_ex; f_y = f_ey; //탄환의 좌표 설정
	
	float f_d = sqrt((f_mx - f_ex) * (f_mx - f_ex) + (f_my - f_ey) * (f_my - f_ey)); // 목표까지의 거리 f_d 구하기.
	if (f_d) // 속도가 일정한 값이 되도록 속도 벡터 구하기.
	{
		f_vx = (f_mx - f_ex) / f_d * f_speed;
		f_vy = (f_my - f_ey) / f_d * f_speed;
	}
	else // f_d가 0일 때는 아래쪽으로 발사함.
	{
		f_vx = 0;
		f_vy = f_speed;
	}
}
	
void move_aiming_bullet
(
	float& f_x, float& f_y, //탄환의 좌표
	float f_vx, float f_vy // 탄환의 속도
)
{
	f_x += vx;
	f_y += vy;
}
