#pragma once

#define SAFE_DELETE(p) if (p) { delete p; p = NULL; }
#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = NULL; }

#define DECLARE_SINGLE(Type)	\
	private:\
	static Type *m_p_inst;\
	public:\
	static Type *get_inst()\
{\
	if (!m_p_inst)\
	m_p_inst = new Type;\
	return m_p_inst;\
}\
static void destroy_inst()\
{\
	SAFE_DELETE(m_p_inst);\
}\
private:\
Type();\
~Type();

#define DEFINITION_SINGLE(Type) Type *Type::m_p_inst = NULL;
#define GET_SINGLE(Type) Type::get_inst()
#define DESTROY_SINGLE(Type) Type::destroy_inst()
