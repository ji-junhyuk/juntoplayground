a = [1, 4, 3]
print("a: ", a)

a.append(2)
print("append: ", a)

a.sort()
print("ascending: ", a)

a.sort(reverse = True)
print("descending: ", a)

a.reverse()
print("reverse: ", a)

a.insert(2, 3)
print("2, 3: ", a)

print("3: ",a.count(3))

a.remove(1)
print("remove 1: ", a)
