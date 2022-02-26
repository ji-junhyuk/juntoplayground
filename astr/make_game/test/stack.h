#pragma once

template <typename T>
class CStackNode
{
	private:
		CStackNode()	:
			m_p_next(NULL)
		{
		}
		~CStackNode()
		{
		}
	private:
		template <typename T>
			friend class CStack;
	private:
		T				m_data;
		CStackNode<T>	*m_p_next;
};

template <typename T>
class CStack
{
	public:
		CStack()
		{
			m_p_begin = new NODE;
			m_p_end = new NODE;
			m_p_begin->m_p_next = m_p_end;
			m_i_size = 0;
		}
		~CStack()
		{
			PNODE p_node = m_p_begin;
			while (p_node)
			{
				PNODE p_next = p_node->m_p_next;
				delete p_node;
				p_node = p_next;
			}
		}
	private:
		typedef CStackNode<T> NODE;
		typedef CStackNode<T> *PNODE;
	private:
		PNODE			m_p_begin;
		PNODE			m_p_end;
		unsigned int	m_i_size;
	public:
		void push(const T& data)
		{
			PNODE p_node = new NODE;
			p_node->m_data = data;
			PNODE p_next = m_p_begin->m_p_next;
			p_node->m_p_next = p_next;
			m_p_begin->m_p_next = p_node;
			++m_i_size;
		}
		T pop()
		{
			if (empty())
				return (0);
			PNODE p_node = m_p_begin->m_p_next;
			PNODE p_next = p_node->m_p_next;
			T data = p_node->m_data;
			delete p_node;
			m_p_begin->m_p_next = p_next;
			--m_i_size;
			return data;
		}
		T top()
		{
			if (empty())
				return 0;
			return m_p_begin->m_p_next->m_data;
		}
		bool empty()
		{
			return m_i_size == 0;
		}
};
