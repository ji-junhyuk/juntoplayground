//
// Created by junto on 20. 12. 31..
//

#include "Member.h"

int MemberNoCmp(const Member *x, const Member *y)
{
    return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

int MemberNameCmp(const Member *x, const Member *y)
{
    return strcmp(x->name, y->name);
}

void PrintMember(const Member *x)
{
    printf("%d %s", x->no, x->name);
}
/*--- ȸ�� ������(��ȣ�� �̸�)�� ǥ��(�� �ٲ� ����) ---*/
void PrintLnMember(const Member *x)
{
    printf("%d %s\n", x->no, x->name);
}

Member ScanMember(const char *message, int sw)
{
    Member temp;
    printf("%s Enter the data.\n", message);
    if (sw & MEMBER_NO) { printf("number : "); scanf("%d", &temp.no); }
    if (sw & MEMBER_NAME) { printf("name : "); scanf("%s", temp.name); }
    return temp;
}