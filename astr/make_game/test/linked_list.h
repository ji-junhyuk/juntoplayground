#pragma once

template <typename T>
class CListNode
{
	private:
		CListNode() :
			m_p_next(NULL),
			m_p_prev(NULL)
		{
		}
		~CListNode()
		{
		}
	private:
		template <typename T>
			friend class CLinkedList;
		template <typename T>
			friend class CListIterator;
		template <typename T>
			friend class CReverseIterator;
	private:
		T				m_data;
		CListNode<T>	*m_p_next;
		CListNode<T>	*m_p_prev;
};

template <typename T>
class CListIterator
{
	public:
		CListIterator()
		{
		}
		~CListIterator()
		{
		}
	private:
		template <typename T>
			friend class CLinkedList;
	private:
		typedef CListNode<T> NODE;
		typedef CListNode<T> *PNODE;
	public:
		PNODE	m_p_node;
	public:
		bool operator == (const CListIterator<T>& iter)
		{
			return m_p_node == iter.m_p_node;
		}
		bool operator != (const CListIterator<T>& iter)
		{
			return m_p_node != iter.m_p_node;
		}
		void operator ++()
		{
			m_p_node = m_p_node->m_p_next;
		}
		void operator --()
		{
			m_p_node = m_p_node->m_p_prev;
		}
		T operator *()
		{
			return m_p_node->m_data;
		}
};

template <typename T>
class CLinkedList
{
	public:
		CLinkedList()
		{
			m_p_begin = new NODE;
			m_p_end = new NODE;

			m_p_begin->m_p_next = m_p_end;
			m_p_end->m_p_prev = m_p_begin;
			m_i_size = 0;
		}
		~CLinkedList()
		{
			clear();
			delete m_p_begin;
			delete m_p_end;
			m_i_size = 0;
		}
	private:
		typedef CListNode<T> NODE;
		typedef CListNode<T> *PNODE;
	public:
		typedef CListIterator<T>	iterator;
		typedef CReverseIterator<T> reverse_iterator;
	private:
		PNODE			m_p_begin;
		PNODE			m_p_end;
		unsigned int	m_i_size;
	public:
		void push_back(const T& data)
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
		void push_front(const T& data)
		{
			PNODE p_node = new NODE;
			p_node->m_data = data;
			PNODE p_first = m_p_begin->m_p_next;
			p_first->m_p_prev = p_node;
			p_node->m_p_next = p_first;
			p_node->m_p_prev = m_p_begin;
			m_p_begin->m_p_next = p_node;
			++m_i_size;
		}
		unsigned int size() const
		{
			return m_i_size;
		}
		bool empty() const
		{
			return m_i_size == 0;
		}
		void clear()
		{
			PNODE p_node = m_p_begin->m_p_next;
			while (p_node != m_p_end)
			{
				PNODE p_next = p_node->m_p_next;
				delete p_node;
				p_node = p_next;
			}
			m_p_begin->m_p_next = m_p_end;
			m_p_end->m_p_prev = m_p_begin;
			m_i_size = 0;
		}
		iterator begin()
		{
			iterator	iter;
			iter.m_p_node = m_p_begin->m_p_next;
			return	iter;
		}
		iterator end()
		{
			iterator	iter;
			iter.m_p_node = m_p_end;
			return	iter;
		}
		reverse_iterator rbegin()
		{
			reverse_iterator iter;
			iter.m_p_node = m_p_end->m_p_prev;
			return iter;
		}
		reverse_iterator rend()
		{
			reverse_iterator iter;
			iter.m_p_node = m_p_begin;
			return iter;
		}
};

template <typename T>
class CReverseIterator
{
	CReverseIterator()
	{
	}
	~CReverseIterator()
	{
	}
	private:
		template <typename T>
			friend class CLinkedList;
	private:
		typedef CListNode<T> NODE;
		typedef CListNode<T> *PNODE;
	private:
		PNODE	m_p_node;
	public:
		bool operator ==(const CReverseIterator<T>& iter)
		{
			return m_p_node == iter.m_p_node;
		}
		bool operator !=(const CReverseIterator<T>& iter)
		{
			return m_p_node != iter.m_p_node;
		}
		void operator ++()
		{
			m_p_node = m_p_node->m_p_prev;
		}
		void operator --()
		{
			m_p_node = m_p_node->m_p_next;
		}
		T operator *()
		{
			return m_p_node->m_data;
		}
};



































































