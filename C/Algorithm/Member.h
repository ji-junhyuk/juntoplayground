//
// Created by junto on 20. 12. 31..
//

#ifndef ___Member
#define ___Member

typedef struct {
    int no; 			/* ��ȣ */
    char name[20]; 		        /* �̸� */
} Member;

#define MEMBER_NO 	1
#define MEMBER_NAME 	2

int MemberNoCmp(const Member *x, const Member *y);

int MemberNameCmp(const Member *x, const Member *y);

void PrintMember(const Member *x);

void PrintLnMember(const Member *x);

Member ScanMember(const char *message, int sw);
#endif