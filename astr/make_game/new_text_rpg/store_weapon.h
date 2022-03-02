#pragma once

#include "store.h"

class CStoreWeapon	:
	public CStore
{
	private:
		CStoreWeapon();
		~CStoreWeapon();
	private:
		friend class CStoreManager;
	public:
		virtual bool init();
		virtual void run();
};
