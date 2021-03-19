#include <stdio.h>
void main()
{
	int arr1[2] = {1, 2}, arr2[2] = {3, 4}, arr3[2] = {5, 6};

	int *array[3]; // int형 주소를 3개까지 저장할 수 있는 배열
	//int (*array)[2] - 포인터 변수로 열의 개수가 2개인 int형 배열의 시작주소 저장
	
	array[0] = arr1;
	array[1] = arr2;
	array[2] = arr3;

	printf("%d %d\n", array[0][0], array[0][1]);
	printf("%d %d\n", array[1][0], array[1][1]);
	printf("%d %d\n", array[2][0], array[2][1]);
}
