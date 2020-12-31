//
// Created by junto on 20. 12. 31..
//

/* 커서에 의한 선형 리스트(헤더부) */
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList

#include "Member.h"

#define Null 1					/* 빈 커서 */

typedef int Index;				/* 커서 형 */

/*--- 노드 ---*/
typedef struct {
    Member data;				/* 데이터 */
    Index next;					/* 뒤쪽노드 */
    Index Dnext;				/* 프리 리스트의 뒤쪽노드 */
} Node;

/*--- 선형 리스트 ---*/
typedef struct {
    Node *n;					/* 리스트 본체(배열) */
    Index head;					/* 머리노드 */
    Index max;					/* 사용 중인 꼬리 레코드 */
    Index deleted;				/* 프리 리스트의 머리노드 */
    Index crnt;					/* 주목노드 */
} List;

/*--- 선형 리스트를 초기화(가장 큰 요솟수는 size) ---*/
void Initialize(List *list, int size);

/*--- 함수 compare에 의해 x와 같은 것으로 판단되는 노드를 검색 ---*/
Index search(List *list, const Member *x,
             int compare(const Member *x, const Member *y));

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List *list, const Member *x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List *list, const Member *x);

/*--- 머리노드를 삭제 ---*/
void RemoveFront(List *list);

/*--- 꼬리노드를 삭제 ---*/
void RemoveRear(List *list);

/*--- 주목노드를 삭제 ---*/
void RemoveCurrent(List *list);

/*--- 모든 노드를 삭제 ---*/
void Clear(List *list);

/*--- 주목노드의 데이터를 나타냄 ---*/
void PrintCurrent(const List *list);

/*--- 주목노드의 데이터를 나타냄(줄바꿈 문자 붙임) ---*/
void PrintLnCurrent(const List *list);

/*--- 모든 노드의 데이터를 나타냄 ---*/
void Print(const List *list);

/*--- 선형 리스트의 뒤처리 ---*/
void Terminate(List *list);
#endif