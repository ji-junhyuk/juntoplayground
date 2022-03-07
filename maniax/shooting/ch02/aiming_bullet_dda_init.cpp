void init_aiming_bullet_dda
(
	int i_mx, int i_my,    // 메인 캐릭터의 위치
	int i_ex, int i_ey,    // 적의 좌표
	int& i_x, int& i_y,    // 탄의 좌표
	int& i_vx, int& i_vy,  // 탄의 이동방향
	int& i_dx, int& i_dy,  // X방향과 Y방향의 차이
	int& i_diff          // 오차
) 
{
	// 탄의 좌표를 설정하기
	i_x = i_ex; 
	i_y = i_ey;

	// 탄의 이동방향(i_vx,i_vy)을 구하기: 값은 1 혹은 -1
	i_vx = i_mx > i_ex ? 1 : -1;
	i_vy = i_my > i_ey ? 1 : -1;

	// 목표에 대한 X방향과 Y방향의 차이의 절대치(i_dx, i_dy)를 구하기
	i_dx = i_mx >= i_ex ? i_mx - i_ex : i_ex - i_mx;
	i_dy = i_my >= i_ey ? i_my - i_ey : i_ey - i_my;

	// 오차i_diff : i_dx>=i_dy일 때는 i_dx/2, i_dx<i_dy일 때는 i_dy/2로 설정함
	i_diff = i_dx >= i_dy ? i_dx / 2 : i_dy / 2;
}

void MoveAimingBulletDDA
(
	int& i_x, int& i_y,  // 탄의 좌표
	int i_vx, int i_vy,  // 탄의 이동방향
	int i_dx, int i_dy,  // X방향과 Y방향의 차이
	int& i_diff,       // 오차
	int i_speed        // 탄의 속도
) 
{
	// X방향으로의 이동거리가 길 때
	if (i_dx>=i_dy) 
	{
		for (int idx = 0; idx < i_speed; ++idx) 
		{
			// X방향으로는 매번 이동시킴
			i_x += i_vx;
			// Y방향으로는 오차가 누적되었을 경우에만 이동시킴
			i_diff += i_dy;
			if (i_diff >= i_dx) 
			{
				i_diff -= i_dx;
				i_y += i_vy;
			}
		}
	} 
	// Y방향으로의 이동거리가 길 때
	else {
		for (int idx = 0; idx < i_speed; ++idx) 
		{
			// Y방향으로는 매번 이동시킴
			i_y += i_vy;
			// X방향으로는 오차가 누적되었을 경우에만 이동시킴
			i_diff += i_dx;
			if (i_diff >= i_dy) 
			{
				i_diff -= i_dy;
				i_x += i_vx;
			}
		}
	}
}
