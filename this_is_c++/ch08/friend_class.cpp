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
		CMyList() : m_head_node("Dummy node") { }
		~CMyList()
		{
			CNode *p_node = m_head_node.p_next;
			CNode *p_delete = nullptr;
			while (p_node)
			{
				p_delete = p_node;
				p_node = p_node->p_next;
				cout << p_delete->m_size_name << '\n';
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
	private:
		CNode m_head_node;
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyList list;
	list.add_new_node("길동");
	list.add_new_node("준혁");
	list.add_new_node("준토");
	return (0);
}
