#include <unistd.h>

void ft_putnbr(int nb)
{
    char c;
   
    if (nb < 0)
    {
        nb = -nb;
        write(1, "-", 1);
    }
    
    if (nb < 10)
    {
        c = nb + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}



int func1(int n)
{
    int i;
    int sum;

    sum = 0;
    i = 0;
    while (i <= n)
    {
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
        i++;
    }
    return sum;
}

int main()
{
    func1(16);
    func1(34567);
    func1(27639);
    
    return 0;
}
