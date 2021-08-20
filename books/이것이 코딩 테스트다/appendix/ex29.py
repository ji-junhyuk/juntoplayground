from itertools import combinations
from itertools import product
from itertools import combinations_with_replacement

data = ['A', 'B', 'C']
result = list(combinations(data, 2))
print(result)

result = list(product(data, repeat=2))
print(result)

result = list(combinations_with_replacement(data, 2))
print(result)
