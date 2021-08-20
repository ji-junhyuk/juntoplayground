import itertools

data = [1, 2]

for x in itertools.permutations(data, 2):
    print(list(x))

data = [1, 2, 3]

for x in itertools.combinations(data, 2):
    print(list(x), end=' ')
