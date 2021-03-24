#ifndef LIST_H_CPOINTER
#define LIST_H_CPOINTER
typedef struct _node
{
	void *data;
	struct _node *prev;
	struct _node *next;
} Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *current;
} List;

Node *AllocNode(void *data);
void Initialize(List *lt);
void Uninitialize(List *lt);
void Add(List *lt, void *data);
void Remove(List *lt);
void Insert(List *lt, void *data);
void Reset(List *lt);
void *GetItem(List *lt);
void Next(List *lt);
int HasNext(List *lt);
#endif
