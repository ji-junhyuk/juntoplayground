void draw(int i_x, int i_y);

void init_aiming_bullet_fp
(
	int i_mx, int i_my,    // 메인 캐릭터의 위치
	int i_ex, int i_ey,    // 적의 좌표
	int& i_x, int& i_y,    // 탄의 좌표
	int& i_vx, int& i_vy,  // 탄의 속도벡터
	int i_speed          // 탄의 속도
)
{
	// 탄의 좌표를 설정하기
	i_x = i_ex; 
	i_y = i_ey;

	// 목표에 대한 X방향과 Y방향의 차이의 절대값(i_dx, i_dy)를 구하기
	int i_dx = i_mx >= i_ex ? i_mx - i_ex : i_ex - i_mx;
	int i_dy = i_my >= i_ey ? i_my - i_ey : i_ey - i_my;

	// X방향과 Y방향의 차이중 보다 긴 쪽을 거리 d로 둠
	int i_d = i_dx >= i_dy ? i_dx : i_dy;

	// 속도벡터(i_vx,i_vy)를 구하기
	i_vx = (i_mx-i_ex) * i_speed / i_d;
	i_vy = (i_my-i_ey) * i_speed / i_d;
}

void move_aiming_bullet_fp
(
	int& i_x, int& i_y,  // 탄의 좌표
	int i_vx, int i_vy   // 탄의 속도
) 
{
	// 탄의 좌표(x, y)에 속도벡터(i_vx,i_vy)를 더하기
	i_x += i_vx;
	i_y += i_vy;
	// 탄을 그리기:
	// 화면에 탄을 그릴 때는 좌표를 (x>>8, y>>8)로 지정함
	// 탄을 그리는 구체적인 처리는 draw함수에서 수행하기로 가정함
	draw(i_x >> 8, i_y >> 8);
}
