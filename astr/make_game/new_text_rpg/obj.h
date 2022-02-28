#pragma once

#include "value.h"

class CObj
{
	protected:
		CObj();
		CObj(const CObj &obj);
		virtual ~CObj() = 0;
	private:
		friend class CObjectManager;
	protected:
		string 		m_str_name;
		OBJECT_TYPE m_e_type;
	public:
		OBJECT_TYPE get_object_type() const;
	public:
		void set_name(char *p_name)
		{
			m_str_name = p_name;
		}
	public:
		virtual bool init();
		virtual void render();
		virtual CObj *clone() = 0;
};
