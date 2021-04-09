#ifndef ___IntSet
#define ___IntSet

typedef struct 
{
	int max;
	int num;
	int *set;
} IntSet;

int Initialize(IntSet *s, int max);

int IsMember(const IntSet *s, int n);

void Add(IntSet *s, int n);

void Remove(IntSet *s, int n);

int Capacity(const IntSet *s);

int Size(const IntSet *s);

void Assign(IntSet *s1, const IntSet *s2);

int Equal(const IntSet *s1, const IntSet *s2);

IntSet *Union(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet *Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet *Difference(IntSet *s1, const IntSet *s2, const IntSet *s3);

void Print(const IntSet *s);

void PrintLn(const IntSet *s);

void Terminate(IntSet *s);

int IsFull(const IntSet *s);

void Clear(IntSet *s);

IntSet *symmetricDifference(IntSet *s1, const IntSet *s2, const IntSet *s3);

IntSet *ToUnion(IntSet *s1, const IntSet *s2);

IntSet *ToIntersection(IntSet *s1, const IntSet *s2);

IntSet *ToDifference(IntSet *s1, const IntSet *s2);

int IsSubset(const IntSet *s1, const IntSet *s2);

int IsProperSubset(const IntSet *s1, const IntSet *s2);

#endif
