#include "../ch01/stdafx.h"

class CMyObject
{
	public:
		CMyObject() { }
		virtual ~CMyObject() { }
		virtual int get_device_id() = 0;
	protected:
		int m_i_device_id;
};

void print_id(CMyObject *p_obj)
{
	cout << "device id: " << p_obj->get_device_id() << '\n';
}

class CMyTV : public CMyObject
{
	public:
		CMyTV(int i_id) { m_i_device_id = i_id; }
		virtual int get_device_id()
		{
			cout << "CMyTV::get_device_id()" << '\n';
			return m_i_device_id;
		}
};

class CMyPhone : public CMyObject
{
	public:
		CMyPhone(int i_id) { m_i_device_id = i_id; }
		virtual int get_device_id()
		{
			cout << "CMyPhone::get_device_id()" << '\n';
			return m_i_device_id;
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyTV a(5);
	CMyPhone b(10);

	::print_id(&a);
	::print_id(&b);
	return 0;
}
