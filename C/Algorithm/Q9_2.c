//
// Created by junto on 20. 12. 31..
//

Node *Retrieve(List *list, int n)
{
    Node *ptr = list ->head;

    while (n >= 0 && ptr != NULL) {
        if (n-- == 0) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}