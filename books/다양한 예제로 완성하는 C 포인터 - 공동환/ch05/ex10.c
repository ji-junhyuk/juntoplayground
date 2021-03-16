#include <stdio.h>
int main()
{
	char s[] = "ABC";
	wchar_t ws[] = L"ABC";

	printf("ASCII: %s", s);
	wprintf(L"UNICODE: %s", ws);

	printf("ASCII: %ld", sizeof(s));
	printf("UNICODE: %ld", sizeof(ws));
}
