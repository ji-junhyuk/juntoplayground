#include <iostream>
#include <time.h>

#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
	JOB_NODE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

enum ITEM_TYPE
{
	IT_NODE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NODE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

# define NAME_SIZE	32
# define ITEM_DESC_LENGTH 512
# define INVENTORY_MAX 20
# define STORE_WEAPON_MAX 3
# define STORE_ARMOR_MAX 3

struct _tagItem
{
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int		iMin;
	int 	iMax;
	int		iPrice;
	int		iSell;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem	tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
};

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
	_tagInventory tInventory;
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
	_tagPlayer tPlayer = {};
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NODE;
	while (iJob == JOB_NODE)
	{
		system("cls");
		cout << "1. 기사" << '\n';
		cout << "2. 궁수" << '\n';
		cout << "3. 마법사" << '\n';
		cout << "직업을 선택하세요 : " << '\n';
		cin >> iJob;
		
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue ;
		}
		else if (iJob <= JOB_NODE || iJob > 3)
		{
			cout << "hello";
			iJob = JOB_NODE;
		}
	}
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;
	switch (tPlayer.eJob)
	{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttckMin = 5;
			tPlayer.iAttckMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMax = 20;
			tPlayer.iHPMax = 500;
			tPlayer.iHP = 500;
			tPlayer.iMP = 100;
			tPlayer.iMPMax = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobName, "궁수");
			tPlayer.iAttckMin = 10;
			tPlayer.iAttckMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMax = 25;
			tPlayer.iHPMax = 400;
			tPlayer.iHP = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMax = 200;
		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobName, "마법사");
			tPlayer.iAttckMin = 15;
			tPlayer.iAttckMax = 20;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMax = 10;
			tPlayer.iHPMax = 300;
			tPlayer.iHP = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMax = 300;
	}
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttckMin = 20;
	tMonsterArr[0].iAttckMax = 30;
	tMonsterArr[0].iArmorMin = 20;
	tMonsterArr[0].iArmorMax = 20;
	tMonsterArr[0].iHP = 500;
	tMonsterArr[0].iHPMax = 500;
	tMonsterArr[0].iMP = 100;
	tMonsterArr[0].iMPMax = 100;
	tMonsterArr[0].iLevel= 5;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttckMin = 80;
	tMonsterArr[1].iAttckMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP= 2000;
	tMonsterArr[1].iHPMax= 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 20;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttckMin = 250;
	tMonsterArr[2].iAttckMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP= 30000;
	tMonsterArr[2].iHPMax= 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 50;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	_tagItem	tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem	tStoreArmor[STORE_ARMOR_MAX] = {};



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
					// 선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 된다. 그렇게 해서 해당 맵의 몬스터를 생성해준다.
					_tagMonster tMonster = tMonsterArr[iMenu - 1];
					while (1)
					{
						system("cls");
						switch (iMenu)
						{
							case MT_EASY:
								cout << "******************** 쉬움 ********************" << '\n';
								break ;
							case MT_NORMAL:
								cout << "******************** 보통 ********************" << '\n';
								break ;
							case MT_HARD:
								cout << "******************** 어려움 ********************" << '\n';
								break ;
						}
						cout << "================= Player =================" << '\n';
						cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << '\n';
						cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << '\n';
						cout << "공격력 : " << tPlayer.iAttckMin << " ~ " << tPlayer.iAttckMax << "\t방어력 : " << tPlayer.iArmorMin << " ~ " << tPlayer.iArmorMax << '\n';
						cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';

						cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << '\n' << '\n';

						cout << "================= Monster =================" << '\n';
						cout << "이름 : " << tMonster.strName << "\t레벨 : " << tMonster.iLevel << '\n';
						cout << "공격력 : " << tMonster.iAttckMin << " ~ " << tMonster.iAttckMax << "\t방어력 : " << tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << '\n';
						cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax << "\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << '\n';

						cout << "획득경험치 : " << tMonster.iExp << "\t획득골드 : " << tMonster.iGoldMin << " ~ " << tMonster.iGoldMax << '\n' << '\n';
						cout << "1. 공격" << '\n';
						cout << "2. 도망가기" << '\n';
						cout << "메뉴를 선택하세요 : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						if (iMenu == BATTLE_BACK)
							break ;
						switch (iMenu)
						{
							case BATTLE_ATTACK:
								int iAttack = rand() % (tPlayer.iAttckMax - tPlayer.iAttckMin + 1) + (tPlayer.iAttckMin);
								int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + (tMonster.iArmorMin);
								int iDamage = iAttack - iArmor;
								iDamage = iDamage < 1 ? 1 : iDamage;

								tMonster.iHP -= iDamage;

								cout << tPlayer.strName << " 가 " << tMonster.strName << "에게 " << iDamage << " 피해를 입혔습니다." << '\n';
								if (tMonster.iHP <= 0)
								{
									cout << tMonster.strName << " 몬스터가 사망하였습니다." << '\n';
									tPlayer.iExp += tMonster.iExp;
									int iGold = rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + (tMonster.iGoldMin);
									tPlayer.tInventory.iGold += iGold;
									cout << tMonster.iExp << " 경험치를 획득하였습니다." << '\n';
									cout << iGold << " Gold를 획득하였습니다." << '\n';
									tMonster.iHP = tMonster.iHPMax;
									tMonster.iMP = tMonster.iMPMax;
									system("pause");
									break ;
								}

								iAttack = rand() % (tMonster.iAttckMax - tMonster.iAttckMin + 1) + (tMonster.iAttckMin);
								iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + (tPlayer.iArmorMin);
								iDamage = iAttack - iArmor;
								iDamage = iDamage < 1 ? 1 : iDamage;
								tPlayer.iHP -= iDamage;

								cout << tMonster.strName << " 가 " << tPlayer.strName << "에게 " << iDamage << " 피해를 입혔습니다." << '\n';
								if (tPlayer.iHP <= 0)
								{
									cout << tPlayer.strName << " 플레이어가 사망하였습니다." << '\n';

									int iExp = tPlayer.iExp + 0.1f;
									int iGold = tPlayer.tInventory.iGold * 0.1f;

									tPlayer.iExp -= iExp;
									tPlayer.tInventory.iGold -= iGold;
									cout << iExp << " 경험치를 잃었습니다." << '\n';
									cout << iGold << " Gold를 잃었습니다." << '\n';
									tPlayer.iHP = tPlayer.iHPMax;
									tPlayer.iMP = tPlayer.iMPMax;
								}
								system("pause");
						}
					}
					break ;
				}
			case MM_STORE:
				while (1)
				{
					system("cls");
					cout << "******************** 상점 ********************" << '\n';
					cout << "1. 무기상점" << '\n';
					cout << "2. 방어구상점" << '\n';
					cout << "3. 뒤로가기" << '\n';
					cout << "상점을 선택하세요 : ";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (iMenu == SM_BACK)
						break ;
					
					switch (iMenu)
					{
						case SM_WEAPON:
						system("cls");
						cout << "******************** 무기상점 ********************" << '\n';
						for (int idx = 0; idx < STORE_WEAPON_MAX; ++idx)
						{
							cout << idx + 1 << " 이름 : " << tStoreWeapon[idx].strName << "\t종류 : " << tStoreWeapon[idx].strTypeName << '\n';
							cout << "공격력 : " << tStoreWeapon[idx].iMin << " ~ " << tStoreWeapon[idx].iMax << '\n';
							cout << "판매가격 : " << tStoreWeapon[idx].iPrice << "\t구매가격 : " << tStoreWeapon[idx].iSell << '\n';
							cout << "설명 : " << tStoreWeapon[idx].strDesc << '\n' << '\n';
						}
						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << '\n';
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << '\n';
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << '\n';
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> iMenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break ;
						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << '\n';
							system("pause");
							continue;
						}
						
						int iWeaponindex = iMenu - 1;

						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "가방이 꽉 찼습니다." << '\n';
							system("pause");
							continue;
						}
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponindex].iPrice)
						{
							cout << "보유금액이 부족합니다." << '\n';
							system("pause");
							continue;
						}
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponindex];
						++tPlayer.tInventory.iItemCount;

						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponindex].iPrice;
						cout << tStoreWeapon[iWeaponindex].strName << " 아이템을 구매하였습니다." << '\n';
						system("pause");
					}
					break ;
				}
				break ;
			case MM_INVENTORY:
					system("cls");
					cout << "******************** 가방 ********************" << '\n';
					cout << "================= Player =================" << '\n';
					cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << '\n';
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << '\n';
					cout << "공격력 : " << tPlayer.iAttckMin << " ~ " << tPlayer.iAttckMax << "\t방어력 : " << tPlayer.iArmorMin << " ~ " << tPlayer.iArmorMax << '\n';
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << '\n' << '\n';
					for (int idx = 0; tPlayer.tInventory.iItemCount; ++idx)
					{
						cout << idx + 1 << " 이름 : " << tPlayer.tInventory.tItem[idx].strName << "\t종류 : " << tPlayer.tInventory.tItem[idx].strTypeName << '\n';
						cout << "공격력 : " << tPlayer.tInventory.tItem[idx].iMin << " ~ " << tPlayer.tInventory.tItem[idx].iMax << '\n';
						cout << "판매가격 : " << tPlayer.tInventory.tItem[idx].iPrice << "\t구매가격 : " << tPlayer.tInventory.tItem[idx].iSell << '\n';
						cout << "설명 : " << tPlayer.tInventory.tItem[idx].strDesc << '\n' << '\n';
					}
					system("pause"); 
					break ;
			default:
				cout << "잘못 선택하였습니다." << '\n';
				break;
		}
	}
	return (0);
}
