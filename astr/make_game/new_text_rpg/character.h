#pragma once
#include "obj.h"

class CCharacter :
	public CObj
{
	protected:
		CCharacter();
		CCharacter(const CCharacter& character);
		virtual ~CCharacter() = 0;
	protected:
		CHARACTERINFO m_t_info;
	public:
		CHARACTERINFO get_character_info() const
		{
			return m_t_info;
		}
		void set_character_info(int i_at_min, int i_at_max, int i_ar_min, int i_ar_max, int i_hp, int i_mp, int i_level, int i_exp);
	public:
		virtual bool init();
		virtual void render();
		virtual CCharacter *clone() = 0;
};
