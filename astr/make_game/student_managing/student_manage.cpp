/*
   구조체 연습
*/

#include <iostream>
# define NAME_SIZE 32
# define ADDRESS_SIZE 128
# define PHONE_SIZE 14
# define STUDENT_MAX 10

using namespace std;

struct _tagStudent
{
	char	strName[NAME_SIZE];
	char	strAddress[ADDRESS_SIZE];
	char	strPhoneNumber[PHONE_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

enum MENU
{
	MENU_NODE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main(void)
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	int		iStudentCount = 0;
	int 	iStdNumber = 1;
	char 	strName[NAME_SIZE] = {};

	while (1)
	{
		system("cls");
		cout << "1. 학생등록" << '\n';
		cout << "2. 학생삭제" << '\n';
		cout << "3. 학생탐색" << '\n';
		cout << "4. 학생출력" << '\n';
		cout << "5. 종료" << '\n';
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;
		// (실수로) 문자열을 입력 받은 경우
		if (cin.fail())
		{
			cin.clear();

			//입력버퍼에 \n이 남아있다.
			//버퍼크기, 찾고자 하는 문자, 지우기.
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MENU_EXIT)
			break ;
		switch (iMenu)
		{
			case MENU_INSERT:
				system("cls");
				cout << "================== 학생 추가 =================" << '\n'; 
				// 학생 정보는 학번, 이름, 주소
				// 국어, 영어, 수학 점수는 입력받고, 학번, 총점, 평균은 연산을 통해 계산해준다.
				if (iStudentCount == STUDENT_MAX)
					break ;
				cout << "이름 : ";
				cin >> tStudentArr[iStudentCount].strName;

				cin.ignore(1024, '\n');

				cout << "주소 : ";
				cin.getline(tStudentArr[iStudentCount].strAddress, ADDRESS_SIZE);

				cout << "전화번호 : ";
				cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

				cout << "국어 : ";
				cin >> tStudentArr[iStudentCount].iKor;

				cout << "영어 : ";
				cin >> tStudentArr[iStudentCount].iEng;

				cout << "수학 : ";
				cin >> tStudentArr[iStudentCount].iMath;
				tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor + tStudentArr[iStudentCount].iEng
					+ tStudentArr[iStudentCount].iMath;
				tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;
				tStudentArr[iStudentCount].iNumber = iStdNumber;
				++iStdNumber;
				++iStudentCount;
				cout << "학생 추가 완료" << '\n';
					break ;
			case MENU_DELETE:
				system("cls");
				cout << "================== 학생 삭제 =================" << '\n'; 
				cin.ignore(1024, '\n');
				cout << "삭제할 이름을 입력하세요 : ";
				cin.getline(strName, NAME_SIZE);
				for (int idx = 0; idx < iStudentCount; ++idx)
				{
					if (strcmp(tStudentArr[idx].strName, strName) == 0)
					{
						for (int jdx = idx; jdx < iStudentCount - 1; ++jdx)
							tStudentArr[idx] = tStudentArr[idx + 1];
						--iStudentCount;
						cout << "학생을 삭제하였습니다." << '\n';
						break ;
					}
				}
				break ;
			case MENU_SEARCH:
				system("cls");
				cout << "================== 학생 탐색 =================" << '\n'; 
				cin.ignore(1024, '\n');
				cout << "탐색할 이름을 입력하세요 : ";
				cin.getline(strName, NAME_SIZE);
				for (int idx = 0; idx < iStudentCount; ++idx)
				{
					if (strcmp(tStudentArr[idx].strName, strName) == 0)
					{
						cout << "이름 : " << tStudentArr[idx].strName << '\n';
						cout << "전화번호 : " << tStudentArr[idx].strPhoneNumber << '\n';
						cout << "주소 : " << tStudentArr[idx].strAddress << '\n';
						cout << "학번 : " << tStudentArr[idx].iNumber << '\n';
						cout << "국어 : " << tStudentArr[idx].iKor << '\n';
						cout << "영어 : " << tStudentArr[idx].iEng << '\n';
						cout << "수학 : " << tStudentArr[idx].iMath << '\n';
						cout << "총점 : " << tStudentArr[idx].iTotal << '\n';
						cout << "평균 : " << tStudentArr[idx].fAvg << '\n' << '\n';
						break ;
					}
				}
				break ;
			case MENU_OUTPUT:
				system("cls");
				cout << "================== 학생 출력  =================" << '\n'; 
				for (int idx = 0; idx < iStudentCount; ++idx)
				{
					cout << "이름 : " << tStudentArr[idx].strName << '\n';
					cout << "전화번호 : " << tStudentArr[idx].strPhoneNumber << '\n';
					cout << "주소 : " << tStudentArr[idx].strAddress << '\n';
					cout << "학번 : " << tStudentArr[idx].iNumber << '\n';
					cout << "국어 : " << tStudentArr[idx].iKor << '\n';
					cout << "영어 : " << tStudentArr[idx].iEng << '\n';
					cout << "수학 : " << tStudentArr[idx].iMath << '\n';
					cout << "총점 : " << tStudentArr[idx].iTotal << '\n';
					cout << "평균 : " << tStudentArr[idx].fAvg << '\n' << '\n';
				}

				break ;
			default:
				cout << "메뉴를 잘못 선택했습니다." << '\n';
				break ;
		}
		system("pause");
	}
	return (0);
}
