#pragma once

template <typename T>
class CVectorNode
{
	private:
		CVectorNode()
		{
		}
		~CVectorNode()
		{
		}
	private:
		template <template T>
			friend class CVector;
	private:
		T	m_data;
		int	m_i_index;
};

template <typename T>
class CVector
{
	public:
		CVector()
		{
			m_i_size = 0;
			m_i_capasity = 2;
			m_p_array = new NODE[m_i_capasity + 2];
		}
		CVector(int i_size)
		{
			m_p_array = new NODE[i_size + 2];
			m_i_capasity = i_size;
			m_i_size = 0;
		}
		~CVector()
		{
			delete[] m_p_array;
		}
	private:
		typedef CVectorNode<T> NODE;
		typedef CVectorNode<T> *PNODE;
	private:
		PNODE			m_p_array;
		unsigned int	m_i_size;
		unsigned int	m_i_capasity;
	public:
		void push_back(const T& data)
		{
			if (full())
				resize(m_i_size * 2);
			m_p_array[m_i_size + 1].m_data = data;
			m_p_array[m_i_size + 1].m_i_index = m_i_size;
			++m_i_size;
		}
		void resize(int i_size)
		{
			PNODE p_array = new NODE[i_size + 2];
			memcpy(p_array + 1, m_p_array + 1, sizeof(NODE) * m_i_size);
			delete[] m_p_array;
			m_p_array = p_array;
			m_i_capasity = i_size;
		}
		void clear()
		{
			delete[] m_p_array;
			m_i_size = 0;
			m_i_capasity = 2;
			m_p_array = new NODE[m_i_capasity + 2];
		}
		bool full()
		{
			return m_i_size == m_i_capasity;
		}
		bool empty()
		{
			return m_i_size == 0;
		}
		unsigned int size() const
		{
			return m_i_size;
		}
		unsigned int capacity() const
		{
			return m_i_capasity;
		}
		T operator [](int idx)
		{
			return m_p_array[idx + 1].m_data;
		}
		void reverse(int i_size)
		{
			delete[] m_p_array;
			m_p_array = new NODE[i_size + 2];
			m_i_capasity = i_size;
			m_i_size = 0;
		}
};
