#include "../ch01/stdafx.h"

class CMyData
{
	public:
		CMyData() { }
		virtual ~CMyData() { }
		void set_data(int i_param) { m_i_data = i_param; }
		int get_data() { return m_i_data; }
	private:
		int m_i_data = 0;
};

class CMyDataEx : public CMyData
{
	public:
		void set_data(int i_param)
		{
			if (i_param > 10)
				i_param = 10;
			CMyData::set_data(i_param);
		}
		void print_data()
		{
			cout << "print_data(): " << get_data() << '\n';
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyData *p_data = new CMyDataEx; // 파생 형식의 객체를 기본형식으로 포인팅 합니다.
	CMyDataEx *p_new_data = NULL;

	p_data->set_data(15);

	p_new_data = static_cast<CMyDataEx *>(p_data);
	p_new_data -> print_data();
	delete p_data;
	return 0;
}
