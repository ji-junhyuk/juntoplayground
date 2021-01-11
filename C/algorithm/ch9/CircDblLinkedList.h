/* 원형 이중연결 리스트(헤더부) */
#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList

#include "Member.h"

/*--- 노드 ---*/
typedef struct __node {
    Member data;                   /* 데이터 */
    struct __node *prev;           /* 앞쪽노드에 대한 포인터 */
    struct __node *next;           /* 뒤쪽노드에 대한 포인터 */
} Dnode;

/*--- 원형 이중연결 리스트 ---*/
typedef struct {
    Dnode *head;                   /* 머리 dummy 노드에 대한 포인터 */
    Dnode *crnt;                   /* 주목노드에 대한 포인터 */
} Dlist;

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist *list);

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const Dlist *list);

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const Dlist *list);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode *search(Dlist *list, const Member *x,
              int compare(const Member *x, const Member *y));

/*--- 모든 노드의 데이터를 리스트 순서로 나타냄 ---*/
void Print(const Dlist *list);

/*--- 모든 노드의 데이터를 리스트 순서 거꾸로 나타냄 ---*/
void PrintReverse(const Dlist *list);

/*--- 주목노드를 하나 뒤쪽으로 나아가도록 ---*/
int Next(Dlist *list);

/*--- 주목노드를 하나 앞쪽으로 되돌아가도록 ---*/
int Prev(Dlist *list);

/*--- p가 가리키는 노드 바로 뒤에 노드를 삽입 ---*/
void InsertAfter(Dlist *list, Dnode *p, const Member *x);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist *list, const Member *x);

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist *list, Dnode *p);

/*--- 머리노드를 삭제 ---*/
void RemoveFront(Dlist *list);

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(Dlist *list);

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(Dlist *list);

/*--- 모든 노드를 삭제 ---*/
void Clear(Dlist *list);

/*--- 원형 이중연결 리스트의 뒤처리 ---*/
void Terminate(Dlist *list);
#endif