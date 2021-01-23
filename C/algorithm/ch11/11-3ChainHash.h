//
// Created by junto on 1/24/21.
//

#ifndef ___ChainHash
#define ___ChainHash
#include "11-1Member.h"

typedef struct __node {
    Member data;
    struct __node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} ChainHash;

int Initialize(ChainHash *h, int size);

Node *Search(const ChainHash *h, const Member *x);

int Add(ChainHash *h, const Member *x);

int Remove(ChainHash *h, const Member *x);

void Dump(const ChainHash *h);

void Clear(ChainHash *h);

void Terminate(ChainHash *h);
#endif
