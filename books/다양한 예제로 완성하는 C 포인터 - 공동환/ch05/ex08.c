#include <stdio.h>
#include <stddef.h>
int main()
{
	char c = 'A';
	wchar_t wc = L'A';

	printf("ASCII: %c", c);
	wprintf(L"UNICODE: %c", wc);

	printf("ASCII: %ld", sizeof(c));
	printf("UNICODE: %ld", sizeof(wc));
}
