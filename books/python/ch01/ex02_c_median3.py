def med3(a, b, c):
    if a >= b:
        if b >= c:
            return b
        elif a <= c:
            return a
        else:
            return c
    elif a > c:
        return a
    elif b > c:
        return c
    else:
        return b

print('Find median')
a = int(input('a: '))
b = int(input('b: '))
c = int(input('c: '))

print(f'median: {med3(a, b, c)}')
