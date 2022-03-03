#pragma once
#include "item.h"
class CItemWeapon :
	public CItem
{
	protected:
		CItemWeapon();
		CItemWeapon(const CItemWeapon &item);
		virtual ~CItemWeapon();
	private:
		friend class CStore;
		friend class CStoreWeapon;
	private:
		int m_i_attack_min;
		int m_i_attack_max;
		float m_f_critical;
	public:
		void set_weapon_info(int i_min, int i_max, float f_critical);
	public:
		virtual bool init();
		virtual void render();
		virtual CItemWeapon *clone();
};
