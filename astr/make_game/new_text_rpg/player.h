#pragma once
#include "character.h"
class CPlayer :
	public CCharacter
{
	private:
		enum JOB
		{
			JOB_NONE,
			JOB_KNIGHT,
			JOB_ARCHER,
			JOB_MAGICION,
			JOB_END
		};
	private:
		CPlayer();
		CPlayer(const CPlayer &player);
		~CPlayer();
	private:
		friend class CObjectManager;
	private:
		JOB		m_e_job;
		string	m_str_job_name;
		int		m_i_gold;
	public:
		void add_gold(int i_gold);
		void drop_gold();
	public:
		int get_gold()	const
		{
			return m_i_gold;
		}
	public:
		virtual bool init();
		virtual void render();
		virtual CPlayer *clone();
};
