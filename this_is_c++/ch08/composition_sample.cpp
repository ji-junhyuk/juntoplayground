#include "../ch01/stdafx.h"

class CNode
{
	friend class CMyList;
	public:
	explicit CNode(const char *p_size_name)
	{
		strcpy_s(m_size_name, sizeof(m_size_name), p_size_name);
	}
	private:
	char m_size_name[32];
	CNode *p_next = nullptr;
};

class CMyList
{
	public:
		CMyList() : m_head_node("dummy head") { }
		~CMyList()
		{
			CNode *p_node = m_head_node.p_next;
			CNode *p_delete = nullptr;

			while (p_node)
			{
				p_delete = p_node;
				p_node = p_node->p_next;
				delete p_delete;
			}
			m_head_node.p_next = nullptr;
		}
		void add_new_node(const char *p_size_name)
		{
			CNode *p_node = new CNode(p_size_name);
			p_node->p_next = m_head_node.p_next;
			m_head_node.p_next = p_node;
		}
		void print()
		{
			CNode *p_node = m_head_node.p_next;
			while (p_node)
			{
				cout << p_node->m_size_name << '\n';
				p_node = p_node->p_next;
			}
		}
	private:
		CNode m_head_node;
};

class CMyUi
{
	public:
		int print_menu()
		{
			cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
			cout.flush();
			int i_input = 0;
			cin >> i_input;
			system("cls");
			return i_input;
		}
		void run()
		{
			char size_name[32];
			int i_input = 0;
			while ((i_input = print_menu()) > 0)
			{
				switch(i_input)
				{
					case 1:
						cout << "이름: ";
						cout.flush();
						cin >> size_name;
						m_list.add_new_node(size_name);
						break;
					case 2:
						m_list.print();
						break;
					default:
						break;
				}
			}
		}
	private:
		CMyList m_list;
};
		
int _tmain(int argc, _TCHAR *argv[])
{
	CMyUi ui;
	ui.run();
	return 0;
}
