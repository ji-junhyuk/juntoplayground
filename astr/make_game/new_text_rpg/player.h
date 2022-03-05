#pragma once
#include "character.h"
class CPlayer :
	public CCharacter
{
	private:
		enum JOB
		{
			JOB_NONE,
			JOB_KNIGHT,
			JOB_ARCHER,
			JOB_MAGICION,
			JOB_END
		};
		enum EQUIP
		{
			EQ_WEAPON,
			EQ_ARMOR,
			EQ_END
		};
	private:
		CPlayer();
		CPlayer(const CPlayer &player);
		~CPlayer();
	private:
		friend class CObjectManager;
	private:
		JOB		m_e_job;
		string	m_str_job_name;
		int		m_i_gold;
		class CItem*	m_p_equip[EQ_END];
	public:
		void add_gold(int i_gold);
		void drop_gold();
	public:
		int get_gold()	const
		{
			return m_i_gold;
		}
		class CItem* get_equip(EQUIP eq) const
		{
			return m_p_equip[eq];
		}
		virtual int get_damage();
		virtual int get_armor();
	public:
		class CItem *equip(class CItem *p_item);
	public:
		virtual bool init();
		virtual void render();
		virtual CPlayer *clone();
};
