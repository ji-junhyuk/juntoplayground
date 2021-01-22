//
// Created by junto on 21. 1. 23..
//

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode *AllocBinNode (void)
{
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
    n->data = *x;
    n->left = left;
    n->right = right;
}

BinNode *Search (BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL)
        return NULL;
    else if ((cond = MemberNoCmp(x, &p->data)) == 0)
        return p;
    else if (cond < 0)
        Search(p->left, x);
    else
        Search(p->right, x);
}

BinNode *Add (BinNode *p, const Member *x)
{
    int cond;
    if (p == NULL) {
        p = AllocBinNode();
        SetBinNode(p, x, NULL, NULL);
    } else if ((cond = MemberNoCmp(x, &p->data)) == 0)
        printf("error %d already enrolled.", x->no);
    else if (cond < 0)
        p->left = Add(p->left, x);
    else
        p->right = Add(p->right, x);
    return p;
}

int Remove (BinNode **root, const Member *x)
{
    BinNode *next, *temp;
    BinNode **left;
    BinNode **p = root;

    while (1) {
        int cond;
        if (*p == NULL) {
            printf("error: %d not enroll\n", x->no);
            return -1;
        }
        else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
            break;
        else if (cond < 0)
            p = &((*p)->left);
        else
            p = &((*p)->right);
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

void PrintTree (const BinNode *p)
{
    if (p != NULL) {
        PrintTree(p->left);
        PrintLnMember(&p->data);
        PrintTree(p->right);
    }
}

void FreeTree (BinNode *p)
{
    if (p != NULL) {
        FreeTree(p->left);
        FreeTree(p->right);
        free(p);
    }
}