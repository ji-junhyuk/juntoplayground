#pragma once

#include "value.h"

class CInventory
{
	private:
		vector<class CItem *>	m_vec_item;
		int						m_i_inven_max;
	public:
		void set_inven_max(int i_max)
		{
			m_i_inven_max = i_max;
		}
		int get_inven_max()	const
		{
			return m_i_inven_max;
		}
		bool full() const
		{
			return m_i_inven_max == m_vec_item.size();
		}
	public:
		bool init();
		void add_item(class CItem *p_item);
		void run();
		DECLARE_SINGLE(CInventory)
};
