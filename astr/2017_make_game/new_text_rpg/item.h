#pragma once
#include "obj.h"
class CItem :
	public CObj
{
	protected:
		CItem();
		CItem(const CItem &item);
	public:
		virtual ~CItem();
	protected:
		ITEMINFO	m_t_info;
	public:
		void set_item_info(ITEM_TYPE e_type, int i_price, int i_sell, char *p_desc);
	public:
		ITEMINFO get_item_info() const
		{
			return m_t_info;
		}
	public:
		virtual bool init();
		virtual void render();
		virtual CItem *clone() = 0;
};
