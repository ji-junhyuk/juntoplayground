#include <string.h>
#include <stdio.h>

int main()
{
	char s[100] = "ABC";
	wchar_t ws[100] = L"ABC";

	printf("ASCII: %s", s);
	wprintf(L"UNICODE: %s", ws);

	strcpy(s, "Hello!");
	wcscpy(ws, L"Hello!");
	printf("ASCII: %s", s);
	wprintf(L"UNICODE: %s", ws);

	strcat(s, "+String");
	wcscat(ws, L"+String");
	printf("ASCII: %s", s);
	wprintf(L"UNICODE: %s", ws);

	printf("s length: %d", strlen(s));
	printf("ws length: %d", wcslen(ws));
}
