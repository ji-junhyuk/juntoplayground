#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void Print(List *lt)
{
	for (Reset(lt); HasNext(lt); Next(lt))
		printf("%g ", *(double *)GetItem(lt));
	puts("");
}

void *AllocData(double data)
{
	double *p = (double *)malloc(sizeof(double));
	*p = data;

	return p;
}

void FreeData(void *p)
{
	free(p);
}

void main()
{
	List lt;

	Initialize(&lt);
	Add(&lt, AllocData(10.1));
	Add(&lt, AllocData(20.1));
	Add(&lt, AllocData(30.1));
	
	Print(&lt);
	for (Reset(&lt); HasNext(&lt); Next(&lt))
		FreeData(GetItem(&lt));

	Uninitialize(&lt);
}
