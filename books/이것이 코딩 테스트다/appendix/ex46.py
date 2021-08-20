import requests

target = "https://jsonplaceholder.typicode.com/users"
response = requests.get(url=target)

data = response.json()

name_list = []
for user in data:
    name_list.append(user['name'])

print(name_list)
