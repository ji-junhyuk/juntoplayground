#include "../ch01/stdafx.h"
# define DEFAULT_FARE 1000

class CPerson
{
	public:
		CPerson() { }
		virtual ~CPerson() 
		{
			cout << "virtual ~CPerson()" << '\n';
		}
		virtual void calc_fare() = 0;
		virtual unsigned int get_fare() { return m_i_fare; }
	protected:
		unsigned int m_i_fare = 0;
};

class CBaby : public CPerson
{
	public:
		virtual void calc_fare()
		{
			m_i_fare = 0;
		}
};

class CChild : public CPerson
{
	public:
		virtual void calc_fare()
		{
			m_i_fare = DEFAULT_FARE * 50 / 100;
		}
};

class CTeen : public CPerson
{
	public:
		virtual void calc_fare()
		{
			m_i_fare = DEFAULT_FARE * 75 / 100;
		}
};

class CAdult : public CPerson
{
	public:
		virtual void calc_fare()
		{
			m_i_fare = DEFAULT_FARE;
		}
};

int _tmain(int argc, _TCHAR *argv[])
{
	CPerson *arr_list[3] = { 0 };
	int i_age = 0;
	for (auto &person : arr_list)
	{
		cout << "나이를 입력하세요: ";
		cin >> i_age;
		if (i_age < 8)
			person = new CBaby;
		else if (i_age < 14)
			person = new CChild;
		else if (i_age < 20)
			person = new CTeen;
		else
			person = new CAdult;
		person->calc_fare();
	}
	for (auto person : arr_list)
		cout << person->get_fare() << "원" << '\n';
	for (auto person : arr_list)
		delete person;
	return 0;
	return 0;
}
