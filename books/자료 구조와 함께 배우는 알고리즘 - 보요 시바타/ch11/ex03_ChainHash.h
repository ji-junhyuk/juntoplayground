#ifndef CHAINHASH
#define CHAINHASH
#include "../ch09/Member.h"

typedef struct __node 
{
	Member data;
	struct __node *next;
} Node;

typedef struct 
{ 
	int size;
	Node **table;
} ChainHash;

int Initialize(ChainHash *h, int size);

Node *Search(ChainHash *h, Member *x);

int Add(ChainHash *h, const Member *x);

int Remove(ChainHash *h, const Member *x);

void Dump(const ChainHash *h);

void Clear(ChainHash *h);

void Terminate(ChainHash *h);
#endif
