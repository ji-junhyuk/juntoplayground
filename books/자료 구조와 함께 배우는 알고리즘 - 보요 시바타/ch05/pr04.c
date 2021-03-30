void recur2(int n)
{
	if (n > 0)
	{
		recur(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}
/*
1. Top-down analysis
n = 4, r(2)p(4)r(3)
r(0)p(2)r(1)(p4)r(1)p(3)r(2)
p(2)p(1)p(4)p(1)p(3)pp(2)(p1)

2. Bottom-up analysis
n = 0, no print
n = 1, p(1) 
n = 2, p(2) p(1)
n = 3, p(1)p(3)p(2)p(1)
n = 4, p(2)p(1) p(4) p(1)p(3)p(2)p(1)

