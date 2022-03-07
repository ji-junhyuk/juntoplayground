#include <cmath>
void init_directed_bullet_16_3
(
	float& f_vx, float& f_vy,  // 적의 속도
	float f_theta            // 발사 속도
) 
{
	// 속도 3에 대한 속도 테이블
	static int v3[][2] =
	{
		{ 3, 0}, { 3, 1}, { 2, 2}, { 1, 3},
		{ 0, 3}, {-1, 3}, {-2, 2}, {-3, 1},
		{-3, 0}, {-3,-1}, {-2,-2}, {-1,-3},
		{ 0,-3}, { 1,-3}, { 2,-2}, { 3,-1}
	};

	// 각도 f_theta(0°〜360°)를 16방향(0〜15)으로 변환하기
	int dir = (int) (f_theta * 16/360);

	// 탄의 속도벡터(f_vx, f_vy)를 테이블로부터 구하기
	f_vx = v3[dir][0];
	f_vy = v3[dir][1];
}
