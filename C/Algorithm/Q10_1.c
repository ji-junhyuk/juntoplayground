//
// Created by junto on 20. 12. 31..
//

void PrintTreeReverse(const BinNode *p)
{
    if (p != NULL) {
        PrintTreeReverse(p->right);
        PrintMember(&p->data);
        PrintTreeReverse(p->left);
    }
}