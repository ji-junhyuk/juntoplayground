//
// Created by junto on 20. 12. 31..
//

BinNode *GetMinNode(const BinNode *p)
{
    if (p == NULL)
        return NULL;
    else {
        while (p->left != NULL)
            p = p -> left;
        return p;
    }
}

BinNode *GetMaxNode(const BinNode *p)
{
    if (p == NULL)
        return NULL;
    else {
        while (p->right != NULL)
            p = p->right;
        return p;
    }
}