import requests

target = "http://google.com"
response = requests.get(url=target)
print(response.text)
