#include <iostream>
#include <time.h>
# define NAME_SIZE			32
# define ITEM_DESC_LENGTH	512
# define INVENTORY_MAX		20
# define STORE_WEAPON_MAX	3
# define STORE_ARMOR_MAX	3
# define LEVEL_MAX			10

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

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
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


struct _tagItem
{
	char		strName[NAME_SIZE];
	char		strTypeName[NAME_SIZE];
	ITEM_TYPE 	eType;
	int			iMin;
	int 		iMax;
	int			iPrice;
	int			iSell;
	char		strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem	tItem[INVENTORY_MAX];
	int			iItemCount;
	int			iGold;
};

struct _tagPlayer
{
	char			strName[NAME_SIZE];
	char			strJobName[NAME_SIZE];
	JOB				eJob;
	int 			iAttackMin;
	int				iAttackMax;
	int				iArmorMin;
	int				iArmorMax;
	int				iHP;
	int				iHPMax;
	int				iMP;
	int				iMPMax;
	int				iExp;
	int				iLevel;
	_tagInventory 	tInventory;
	_tagItem		tEquip[EQ_MAX];
	bool			bEquip[EQ_MAX];
};

struct _tagMonster
{
	char	strName[NAME_SIZE];
	int 	iAttackMin;
	int		iAttackMax;
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

struct _tagLevelUpStatus
{
	int 	iAttackMin;
	int		iAttackMax;
	int		iArmorMin;
	int		iArmorMax;
	int		iHPMin;
	int		iHPMax;
	int		iMPMin;
	int		iMPMax;
};

int main(void)
{
	srand((unsigned int)time(0));

	const int iLevelUpExp[LEVEL_MAX] = {4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 50000};
	_tagLevelUpStatus tLvUpTable[JOB_END - 1] = {};

	tLvUpTable[JOB_KNIGHT - 1].iAttackMin = 4;
	tLvUpTable[JOB_KNIGHT - 1].iAttackMax = 10;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMin = 8;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMax = 16;
	tLvUpTable[JOB_KNIGHT - 1].iHPMin = 50;
	tLvUpTable[JOB_KNIGHT - 1].iHPMax = 100;
	tLvUpTable[JOB_KNIGHT - 1].iMPMin = 10;
	tLvUpTable[JOB_KNIGHT - 1].iMPMax = 20;

	tLvUpTable[JOB_ARCHER - 1].iAttackMin = 4;
	tLvUpTable[JOB_ARCHER - 1].iAttackMax = 10;
	tLvUpTable[JOB_ARCHER - 1].iArmorMin = 8;
	tLvUpTable[JOB_ARCHER - 1].iArmorMax = 16;
	tLvUpTable[JOB_ARCHER - 1].iHPMin = 50;
	tLvUpTable[JOB_ARCHER - 1].iHPMax = 100;
	tLvUpTable[JOB_ARCHER - 1].iMPMin = 10;
	tLvUpTable[JOB_ARCHER - 1].iMPMax = 20;

	tLvUpTable[JOB_WIZARD - 1].iAttackMin = 4;
	tLvUpTable[JOB_WIZARD - 1].iAttackMax = 10;
	tLvUpTable[JOB_WIZARD - 1].iArmorMin = 8;
	tLvUpTable[JOB_WIZARD - 1].iArmorMax = 16;
	tLvUpTable[JOB_WIZARD - 1].iHPMin = 50;
	tLvUpTable[JOB_WIZARD - 1].iHPMax = 100;
	tLvUpTable[JOB_WIZARD - 1].iMPMin = 10;
	tLvUpTable[JOB_WIZARD - 1].iMPMax = 20;

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
		else if (iJob <= JOB_NODE || iJob >= JOB_END)
			iJob = JOB_NODE;
	}
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;
	switch (tPlayer.eJob)
	{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobName, "기사");
			tPlayer.iAttackMin = 5;
			tPlayer.iAttackMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMax = 20;
			tPlayer.iHPMax = 500;
			tPlayer.iHP = 500;
			tPlayer.iMP = 100;
			tPlayer.iMPMax = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobName, "궁수");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMax = 25;
			tPlayer.iHPMax = 400;
			tPlayer.iHP = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMax = 200;
		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobName, "마법사");
			tPlayer.iAttackMin = 15;
			tPlayer.iAttackMax = 20;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMax = 10;
			tPlayer.iHPMax = 300;
			tPlayer.iHP = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMax = 300;
	}
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
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
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
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
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
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

	strcpy_s(tStoreWeapon[0].strName, "나무검");
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	strcpy_s(tStoreWeapon[0].strDesc, "나무로 만든 칼");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 500000;
	tStoreWeapon[0].iMax = 1000000;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	strcpy_s(tStoreWeapon[1].strName, "장궁");
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	strcpy_s(tStoreWeapon[1].strDesc, "짱장한 활");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;

	strcpy_s(tStoreWeapon[2].strName, "지팡이");
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	strcpy_s(tStoreWeapon[2].strDesc, "나무로 만든 지팡이");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;

	strcpy_s(tStoreArmor[0].strName, "천갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strDesc, "천으로 만든 허접한 갑옷");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	strcpy_s(tStoreArmor[1].strName, "가죽갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strDesc, "동물 가죽으로 만든 질긴 갑옷");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;

	strcpy_s(tStoreArmor[2].strName, "풀플레이트아머");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strDesc, "강철로 만든 판금갑옷");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;

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
						cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << '\n';
						if (tPlayer.bEquip[EQ_WEAPON] == true)
						{
							cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " ~ " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
						}
						else
							cout << "공격력 : " << tPlayer.iAttackMin << " ~ " << tPlayer.iAttackMax;

						if (tPlayer.bEquip[EQ_ARMOR] == true)
						{
							cout << "방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " ~ " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << '\n';
						}
						else 
							cout << "방어력 : " << tPlayer.iArmorMin << " ~ " << tPlayer.iArmorMax << '\n';

						cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << '\n';

						if (tPlayer.bEquip[EQ_WEAPON])
							cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
						else
							cout << "장착무기 : 없음";
						
						if (tPlayer.bEquip[EQ_ARMOR])
							cout << "장착 방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << '\n';
						else
							cout << "장착 방어구 : 없음" << '\n';

						cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << '\n' << '\n';

						cout << "================= Monster =================" << '\n';
						cout << "이름 : " << tMonster.strName << "\t레벨 : " << tMonster.iLevel << '\n';
						cout << "공격력 : " << tMonster.iAttackMin << " ~ " << tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin << " ~ " << tMonster.iArmorMax << '\n';
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
						else if (iMenu == BATTLE_BACK)
							break ;

						switch (iMenu)
						{
							case BATTLE_ATTACK:
								int iAttackMin = tPlayer.iAttackMin;
								int iAttackMax = tPlayer.iAttackMax;
								if (tPlayer.bEquip[EQ_WEAPON])
								{
									iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
									iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
								}
								int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
								int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

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

									if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
									{
										++tPlayer.iLevel;
										cout << "레벨업 하였습니다." << '\n';

										int iJobIndex = tPlayer.eJob - 1;
										int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) + tLvUpTable[iJobIndex].iHPMin;
										int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) + tLvUpTable[iJobIndex].iMPMin;
										tPlayer.iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
										tPlayer.iAttackMax += tLvUpTable[iJobIndex].iAttackMax;
										tPlayer.iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
										tPlayer.iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

										tPlayer.iHP += tPlayer.iHPMax;
										tPlayer.iMP += tPlayer.iMPMax;
									}
									system("pause");
									break;
								}

								iAttack = rand() % (tMonster.iAttackMax - tMonster.iAttackMin + 1) + (tMonster.iAttackMin);

								int iArmorMin = tPlayer.iArmorMin;
								int iArmorMax = tPlayer.iArmorMax;

								if (tPlayer.bEquip[EQ_ARMOR])
								{
									iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
									iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
								}
								
								iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;
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
								break;
						} //BATTLE
					} //MODE
				} //MAP
				break;
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
							while (1)
							{
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
						case SM_ARMOR:
							while (true)
							{
								system("cls");
								cout << "**************************** 방어구상점 ****************************" << endl;
								for (int i = 0; i < STORE_ARMOR_MAX; ++i)
								{
										cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName <<
												"\t종류 : " << tStoreArmor[i].strTypeName << endl;
										cout << "공격력 : " << tStoreArmor[i].iMin << " ~ " << tStoreArmor[i].iMax << endl;
										cout << "판매가격 : " << tStoreArmor[i].iPrice <<
												"\t구매가격 : " << tStoreArmor[i].iSell << endl;
										cout << "설명 : " << tStoreArmor[i].strDesc << endl << endl;
								}
								cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl << endl;
								cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << endl;
								cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
								cout << "구입하고 싶은 물품을 고르세요 : ";
								cin >> iMenu;
								if (cin.fail())
								{
										cin.clear();
										cin.ignore(1024, '\n');
										continue;
								}
								else if (iMenu == STORE_ARMOR_MAX + 1)
										break;
								else if (iMenu < 1 || iMenu > STORE_ARMOR_MAX + 1)
								{
										cout << "잘못 선택하였습니다." << endl;
										system("pause");
										continue;
								}
								int iArmorIndex = iMenu - 1;
								if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
								{
										cout << "가방이 꽉 찼습니다." << endl;
										system("pause");
										continue;
								}
								else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
								{
										cout << "보유금액이 부족합니다." << endl;
										system("pause");
										continue;
								}
								tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];
								++tPlayer.tInventory.iItemCount;
								tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;
								cout << tStoreArmor[iArmorIndex].strName << " 아이템을 구매하였습니다." << endl;
								system("pause");
							}
							break ;
					}
				}
				break ;
			case MM_INVENTORY:
				while (true)
				{
					system("cls");
					cout << "**************************** 가방 ****************************" << endl;
					cout << "================== Player ==================" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " <<
							tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;

					if (tPlayer.bEquip[EQ_WEAPON] == true)
					{
							cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin <<
									" ~ " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
					}
					else
					{
							cout << "공격력 : " << tPlayer.iAttackMin << " ~ "
									<< tPlayer.iAttackMax;
					}
					if (tPlayer.bEquip[EQ_ARMOR] == true)
					{
							cout << "\t방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin
									<< " ~ " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}

					else
					{
							cout << "\t방어력 : " << tPlayer.iArmorMin << " ~ " << tPlayer.iArmorMax << endl;
					}
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
							"\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					if (tPlayer.bEquip[EQ_WEAPON])
							cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
					else
							cout << "장착무기 : 없음";
					if (tPlayer.bEquip[EQ_ARMOR])
							cout << "\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
					else
							cout << "\t장착방어구 : 없음" << endl;
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " Gold" << endl << endl;
					for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i)
					{
							cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName <<
									"\t종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
							cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " ~ " <<
									tPlayer.tInventory.tItem[i].iMax << endl;
							cout << "판매가격 : " << tPlayer.tInventory.tItem[i].iPrice <<
									"\t구매가격 : " << tPlayer.tInventory.tItem[i].iSell << endl;
							cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
					}
					cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
					cout << "장착할 아이템을 선택하세요 : ";
					cin >> iMenu;

					if (cin.fail())
					{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
					}
					else if (iMenu == tPlayer.tInventory.iItemCount + 1)
							break;
					else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemCount + 1)
					{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
					}
					int idx = iMenu - 1;

					EQUIP eq;
					switch (tPlayer.tInventory.tItem[idx].eType)
					{
						case IT_WEAPON:
							eq = EQ_WEAPON;
							break;
						case IT_ARMOR:
							eq = EQ_ARMOR;
							break;
					}
					if (tPlayer.bEquip[eq] == true)
					{
						_tagItem        tSwap = tPlayer.tEquip[eq];
						tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
						tPlayer.tInventory.tItem[idx] = tSwap;
					}
					else
					{
							tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
							for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; ++i)
									tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
							--tPlayer.tInventory.iItemCount;
							tPlayer.bEquip[eq] = true;
					}
					cout << tPlayer.tEquip[eq].strName << " 아이템을 장착하였습니다." << endl;
					system("pause");
				}
				break;
			default:
				cout << "잘못 선택하였습니다." << '\n';
				break ;
		}
	}
	return (0);
}
