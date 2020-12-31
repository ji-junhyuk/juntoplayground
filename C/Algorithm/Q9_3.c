//
// Created by junto on 20. 12. 31..
//
void Purge(List *list, int compare(const Member *x, const Member *y))
{
    Index ptr = list->head;

    while (ptr != NULL) {
        Index ptr2 = ptr;
        Index pre = ptr;

        while (list->n[ptr2].next != NULL) {
            ptr2 = list->n[pre].next;
            if (!compare(&list->n[ptr].data, &list->[ptr2].data)) {
                list->n[pre].next = list->n[ptr2].next;
                DeleteIndex(list, ptr2);
            }
            else {
                pre = ptr2;
            }
        }
        ptr = list->n[ptr].next;
    }
    list->crnt = list->head;
}

Node *Retrieve(List *list, int n)
{
    Index ptr = list->head;

    while (n >= 0 && ptr != NULL) {
        if (n-- == 0) {
            list->crnt = ptr;
            return ptr;
        }
        ptr = list->n[ptr].next;
    }
    return NULL;
}