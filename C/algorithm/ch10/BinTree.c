/* 이진검색트리 프로그램(소스) */
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

/*--- 노드를 동적으로 할당 ---*/
static BinNode *AllocBinNode(void)
{
    return calloc(1, sizeof(BinNode));
}

/*--- 노드 멤버 값 설정 ----*/
static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;			/* 데이터 */
    n->left = left;			/* 왼쪽 포인터 */
    n->right = right;		/* 오른쪽 포인터 */
}

/*--- 검색 ---*/
BinNode *Search(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL)
        return NULL;										/* 검색 실패 */
    else if ((cond = MemberNoCmp(x, &p->data)) == 0)
        return p;                                           /* 검색 성공 */
    else if (cond < 0)
        Search(p->left, x);                                 /* 왼쪽 서브 트리에서 검색 */
    else
        Search(p->right, x);                                /* 오른쪽 서브 트리에서 검색 */
}

/*--- 노드 삽입 ---*/
BinNode *Add(BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL) {
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    }
    else if ((cond = MemberNoCmp(x, &p->data)) == 0)
        printf("【오류】 %d는 이미 등록되어 있습니다.\n", x->no);
    else if (cond < 0)
        p->left = Add(p->left, x);
    else
        p->right = Add(p->right, x);
    return p;
}

/*--- 노드 삭제 ---*/
int Remove(BinNode **root, const Member *x)
{
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while (1) {
        int cond;
        if (*p == NULL) {
            printf("【오류】 %d는 등록되어 있지 않습니다.\n", x->no);
            return -1;				/* 이 키는 없습니다. */
        }
        else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
            break;					/* 검색 성공 */
        else if (cond < 0)
            p = &((*p)->left);		/* 왼쪽 서브 트리에서 검색 */
        else
            p = &((*p)->right);		/* 오른쪽 서브 트리에서 검색 */
    }

    if ((*p)->left == NULL)
        next = (*p)->right;
    else {
        left = &((*p)->left);
        while ((*left)->right != NULL)
            left = &(*left)->right;
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }

    temp = *p;
    *p = next;

    free(temp);

    return 0;
}

/*--- 모든 노드의 데이터를 출력 ---*/
void PrintTree(const BinNode *p)
{
    if (p != NULL) {
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
}

/*--- 모든 노드 삭제 ---*/
void FreeTree(BinNode *p)
{
    if (p != NULL) {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}