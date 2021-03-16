#include <stdio.h>
int main()
{
	char* s = "ABC";
	wchar_t* ws = L"ABC";

	printf("ASCII: %s", s);
	wprintf(L"UNICODE: %S", ws);
}
