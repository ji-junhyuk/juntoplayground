#include <iostream>
using namespace std;

class CListNode
{
	public:
		CListNode() :
			m_p_next(NULL),
			m_p_prev(NULL)
		{
		}
		~CListNode()
		{
		}
	public:
		int m_i_data;
		CListNode *m_p_next;
		CListNode *m_p_prev;
};

class CList
{
	public:
		CList()
		{
			m_p_begin = new CListNode;
			m_p_end = new CListNode;

			m_p_begin->m_p_next = m_p_end;
			m_p_end->m_p_prev = m_p_begin;

			m_i_size = 0;
		}
	private:
		CListNode	*m_p_begin;
		CListNode	*m_p_end;
		int			m_i_size;
	public:
		void push_back(int i_data)
		{
			CListNode *p_node = new CListNode;
			p_node->m_i_data = i_data;
			CListNode *p_prev = m_p_end->m_p_prev;
			p_prev->m_p_next = p_node;
			p_node->m_p_prev = p_prev;
			p_node->m_p_next = m_p_end;
			m_p_end->m_p_prev = p_node;
			++m_i_size;
		}
		bool empty()
		{
			return m_i_size == 0;
		}
		void clear()
		{
			CListNode *p_node = m_p_begin->m_p_next;
			while (p_node != m_p_end)
			{
				CListNode *p_next = p_node->m_p_next;
				delete p_node;
				p_node = p_next;
			}
			m_p_begin->m_p_next = m_p_end;
			m_p_end->m_p_prev = m_p_begin;
			m_i_size = 0;
		}
		~CList()
		{
			clear();
			delete m_p_begin;
			delete m_p_end;
		}
		int pop_back()
		{
			CListNode *p_prev = m_p_end->m_p_prev;
			if (p_prev == m_p_begin)
				return INT_MAX;
			int i_data = p_prev->m_i_data;
			CListNode *p_prev_p = p_prev->m_p_prev;
			p_prev_p->m_p_next = m_p_end;
			m_p_end->m_p_prev = p_prev_p;
			--m_i_size;
			delete p_prev;
			return i_data;
		}
};

int main(void)
{
	CList list;
	
	for (int idx = 0; idx < 100; ++idx)
	{
		list.push_back(idx);
	}
	while (!list.empty())
	{
		cout << list.pop_back() << '\n';
	}
	return (0);
}
