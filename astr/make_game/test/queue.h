#pragma once

template <typename T>
class CQueueNode
{
	private:
		CQueueNode()	:
			m_p_next(NULL),
			m_p_prev(NULL)
		{
		}
		~CQueueNode()
		{
		}
	private:
		template <typename T>
			friend class CQueue;
	private:
		T		m_data;
		CQueueNode<T> *m_p_next;
		CQueueNode<T> *m_p_prev;
};

template <typename T>
class CQueue
{
	public:
		CQueue()
		{
			m_p_begin = new NODE;
			m_p_end = new NODE;
			m_p_begin->m_p_next = m_p_end;
			m_p_end->m_p_prev = m_p_begin;
			m_i_size = 0;
		}
		~CQueue()
		{
		}
	private:
		typedef CQueueNode<T> NODE;
		typedef CQueueNode<T> *PNODE;
	private:
		PNODE 			m_p_begin;
		PNODE 			m_p_end;
		unsigned int	m_i_size;
	public:
		void push(const T& data)
		{
			PNODE p_node = new NODE;
			p_node->m_data = data;
			PNODE p_prev = m_p_end->m_p_prev;
			p_prev->m_p_next = p_node;
			p_node->m_p_prev = p_prev;
			p_node->m_p_next = m_p_end;
			m_p_end->m_p_prev = p_node;
			++m_i_size;
		}
		T	pop()
		{
			if (empty())
				return (0);
			PNODE p_node = m_p_begin->m_p_next;
			T data = p_node->m_data;
			m_p_begin->m_p_next = p_node->m_p_next;
			p_node->m_p_next->m_p_prev = m_p_begin;
			delete p_node;
			--m_i_size;
			return data;
		}
		bool empty()
		{
			return m_i_size == 0;
		}
};

template <typename T, int SIZE = 100>
class CCircleQueue
{
	public:
		CCircleQueue()
		{
			m_i_size = 0;
			m_i_head = 0;
			m_i_tail = 0;
		}
		~CCircleQueue()
		{
		}
	private:
		T				m_data[SIZE + 1];
		unsigned int	m_i_size;
		unsigned int	m_i_head;
		unsigned int	m_i_tail;
	public:
		void push(const T& data)
		{
			if (full())
				return ;
			int idx = (m_i_tail + 1) % (SIZE + 1);
			m_data[idx] = data;
			m_i_tail = idx;
			++m_i_size;
		}
		T pop()
		{
			if (empty())
				return 0;
			int idx = (m_i_head + 1) % (SIZE + 1);
			T	data = m_data[idx];
			m_i_head = idx;
			--m_i_size;
			return data;
		}
		bool full()
		{
			return m_i_size == SIZE;
		}
		bool empty()
		{
			return m_i_size == 0;
		}
};
