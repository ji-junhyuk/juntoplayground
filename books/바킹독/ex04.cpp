void swap1(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void swap2(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
