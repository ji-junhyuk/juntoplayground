# Find max
print('Find max')
a = int(input('a: '))
b = int(input('b: '))
c = int(input('c: '))

maximum = a;
if b > maximum: maximum = b
if c > maximum: maximum = c

print(f'최댓값은 {maximum}입니다.')
