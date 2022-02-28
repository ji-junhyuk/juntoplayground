#pragma once

#include "value.h"

class CObj;
class CObjectManager
{
	private:
		unordered_map<string, class CObj*> m_map_obj;
	public:
		bool init();
		CObj *create_object(const string &str_key, OBJECT_TYPE e_type);
		CObj *find_object(const string &str_key);
		CObj *clone_object(const string &str_key);
	DECLARE_SINGLE(CObjectManager)
};
