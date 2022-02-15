#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU
{
	MM_NODE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NODE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD
};

# define NAME_SIZE	32
struct _tagPlayer
{
	char	strName[NAME_SIZE];
	char	strJobName[NAME_SIZE];
	JOB		eJob;
	int 	iAttckMin;
	int		iAttckMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iExp;
	int		iLevel;
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int 	iAttckMin;
	int		iAttckMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHP;
	int		iHPMax;
	int		iMP;
	int		iMPMax;
	int		iLevel;
	int		iExp;
	int		iGoldMin;
	int		iGoldMax;
};

int main(void)
{
	srand((unsigned int)time(0));

	while (1)
	{
		system("cls");
		cout << "******************** 로비 ********************" << '\n';
		cout << "1. 맵" << '\n';
		cout << "2. 상점" << '\n';
		cout << "3. 가방" << '\n';
		cout << "4. 종료" << '\n';
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MM_EXIT)
			break ;
		switch (iMenu)
		{
			case MM_MAP:
				while (1)
				{
					system("cls");
					cout << "******************** 맵 ********************" << '\n';
					cout << "1. 쉬움" << '\n';
					cout << "2. 보통" << '\n';
					cout << "3. 어려움" << '\n';
					cout << "4. 뒤로가기" << '\n';
					cout << "맵을 선택하세요 : ";

					cin >> iMenu;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					if (iMenu == MT_BACK)
						break ;
				}
				break ;
			case MM_STORE:
				break ;
			case MM_INVENTORY:
				break ;
			default:
				cout << "잘못 선택하였습니다." << '\n';
				break;
		}
	}
	return (0);
}
