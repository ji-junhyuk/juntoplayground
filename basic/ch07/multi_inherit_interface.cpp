#include "../ch01/stdafx.h"

class CMyUSB
{
	public:
		virtual int get_usb_version() = 0;
		virtual int get_transfer_rate() = 0;
};

class CMySerial
{
	public:
		virtual int get_signal() = 0;
		virtual int get_rate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
	public:
		virtual int get_usb_version() { return 0; }
		virtual int get_transfer_rate() { return 0; }
		virtual int get_signal() { return 0; }
		virtual int get_rate() { return 0; }
};

int _tmain(int argc, _TCHAR *argv[])
{
	CMyDevice dev;
	return 0;
}
