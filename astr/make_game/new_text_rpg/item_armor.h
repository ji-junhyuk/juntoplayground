#pragma once
#include "item.h"
class CItemArmor :
	public CItem
{
	protected:
		CItemArmor();
		CItemArmor(const CItemArmor &item);
		~CItemArmor();
	private:
		friend class CStore;
		friend class CStoreArmor;
	private:
		int m_i_armor_min; 
		int m_i_armor_max; 
	public:
		void set_armor_info(int i_min, int i_max)
		{
			m_i_armor_min = i_min;
			m_i_armor_max = i_max;
		}
	public:
		virtual bool init();
		virtual bool render();
		virtual CItemArmor *clone();
};
