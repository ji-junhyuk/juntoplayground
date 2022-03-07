#pragma once

#include "store.h"

class CStoreArmor	:
	public CStore
{
	private:
		CStoreArmor();
		~CStoreArmor();
	private:
		friend class CStoreManager;
	public:
		virtual bool init();
		virtual void run();
};
