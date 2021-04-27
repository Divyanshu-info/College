import json

with open('/home/divyanshu/Desktop/New Folder/vscode-python-snippet-pack-master/snippets/python_snippets.json') as f:
    data = json.load(f)

data2 = dict(data)

for i in data2:
    #print(i)
    a = data2[i]["prefix"]
    if a.startswith("."):
        data.pop(i)

for i in data:
    #print(i)
    a = data[i]["prefix"]
    if a.startswith("."):
        print(a)
with open('data.txt', 'w') as outfile:
    json.dump(data, outfile)
