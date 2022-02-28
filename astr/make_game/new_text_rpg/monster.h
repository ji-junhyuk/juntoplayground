#pragma once
#include "character.h"
class CMonster :
	public CCharacter
{
	private:
		CMonster();
		CMonster(const CMonster &monster);
	public:
		~CMonster();
	private:
		friend class CObjectManager;
	private:
		ini m_i_gold_min;
		ini m_i_gold_max;
	public:
		void set_gold(int i_min, int i_max)
		{
			m_i_gold_min = i_min;
			m_i_gold_max = i_max;
		}
	public:
		int	get_gold_min()	const
		{
			return m_i_gold_min;
		}

		int get_gold_max()	const
		{
			return m_i_gold_max;
		}
	public:
		virtual bool init();
		virtual void render();
		virtual CMonster *clone();
};
