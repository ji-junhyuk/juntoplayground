#ifndef TEXT_RPG
# define TEXT_RPG
using namespace std;

# define NAME_SIZE              32
# define ITEM_DESC_LENGTH       512
# define INVENTORY_MAX          20
# define STORE_WEAPON_MAX       3
# define STORE_ARMOR_MAX                3
# define LEVEL_MAX              10

enum MAIN_MENU
{
        MM_NONE,
        MM_MAP,
        MM_STORE,
        MM_INVENTORY,
        MM_EXIT
};

enum MAP_TYPE
{
        MT_NONE,
        MT_EASY,
        MT_NORMAL,
        MT_HARD,
        MT_BACK
};

enum ITEM_TYPE
{
        IT_NONE,
        IT_WEAPON,
        IT_ARMOR,
        IT_BACK
};

enum  JOB
{
        JOB_NONE,
        JOB_KNIGHT,
        JOB_ARCHER,
        JOB_WIZARD,
        JOB_END
};

enum EQUIP
{
        EQ_WEAPON,
        EQ_ARMOR,
        EQ_MAX
};

enum BATTLE
{
        BATTLE_NONE,
        BATTLE_ATTACK,
        BATTLE_BACK
};

enum STORE_MENU
{
        SM_NONE,
        SM_WEAPON,
        SM_ARMOR,
        SM_BACK
};

struct _tag_item
{
        char            str_name[NAME_SIZE];
        char            str_type_name[NAME_SIZE];
        ITEM_TYPE       e_type;
        int                     i_min;
        int                     i_max;
        int                     i_price;
        int                     i_sell;
        char            str_desc[ITEM_DESC_LENGTH];
};

struct _tag_inventory
{
        _tag_item        t_item[INVENTORY_MAX];
        int                     i_item_count;
        int                     i_gold;
};

struct _tag_player
{
        char                    str_name[NAME_SIZE];
        char                    str_job_name[NAME_SIZE];
        JOB                             e_job;
        int                             i_attack_min;
        int                             i_attack_max;
        int                             i_armor_min;
        int                             i_armor_max;
        int                             i_hp;
        int                             i_hp_max;
        int                             i_mp;
        int                             i_mp_max;
        int                             i_exp;
        int                             i_level;
        _tag_item                t_equip[EQ_MAX];
        bool            b_equip[EQ_MAX];
        _tag_inventory   t_inventory;
};

struct _tag_monster
{
        char    str_name[NAME_SIZE];
        int             i_attack_min;
        int             i_attack_max;
        int             i_armor_min;
        int             i_armor_max;
        int             i_hp;
        int             i_hp_max;
        int             i_mp;
        int             i_mp_max;
        int             i_level;
        int             i_exp;
        int             i_gold_min;
        int             i_gold_max;
};

struct _tag_level_up_status
{
        int i_attack_min;
        int i_attack_max;
        int i_armor_min;
        int i_armor_max;
        int i_hp_min;
        int i_hp_max;
        int i_mp_min;
        int i_mp_max;
};

const int g_i_level_up_exp[LEVEL_MAX] = { 4000,10000,20000,35000,50000,70000,100000, 150000, 200000, 400000 };

_tag_level_up_status g_t_level_up_table[JOB_END - 1] = {};

int                     output_main_menu();
int                     get_input();
void            loop_map(_tag_player* p_player, _tag_monster* p_monster_arr);
int             output_map_menu();
int             select_job();
void            set_player(_tag_player* p_player);
void            set_monster(_tag_monster* p_monster_arr);
void            output_battle_tag(int i_menu);
void            output_player_info(_tag_player* p_player);
void            output_monster_info(_tag_monster* p_monster);
int                     output_battle_menu();
void            run_battle(_tag_player* p_player, _tag_monster* p_monster_arr, int i_menu);
void            battle(_tag_player* p_player, _tag_monster* p_monster);
void            run_store(_tag_inventory* p_inventory, _tag_item* p_weapon, _tag_item* p_armor);
void            buy_item(_tag_inventory* p_inventory, _tag_item* p_store, int i_item_count, int i_store_type);
int                     output_store_item_list(_tag_inventory* p_inventory, _tag_item* p_store, int i_item_count);
void            run_inventory(_tag_player* p_player);
int                     output_inventory(_tag_player* p_player);

_tag_monster                             create_monster(const char* p_name, int i_attack_min, int i_attack_max, int i_armor_min, int i_armor_max, int i_hp, int i_mp, int i_level, int i_exp, int i_gold_min, int i_gold_max);
_tag_level_up_status    create_level_up_status(int i_attack_min, int i_attack_max, int i_armor_min, int i_armor_max, int i_hp_min, int i_hp_max, int i_mp_min, int i_mp_max);
_tag_item                                create_item(const char* p_name, ITEM_TYPE e_type, int i_min, int i_max, int i_price, int i_sell, const char* p_desc);
EQUIP compute_equip_type(ITEM_TYPE e_type);

#endif
