#pragma once

#include "value.h"

class CStore
{
	protected:
		CStore();
	public:
		virtual CStore();
	private:
		friend class CStoreManager;
	public:
		virtual bool init() = 0;
		virtual void run() = 0;
};
