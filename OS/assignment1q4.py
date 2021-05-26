print("Creating New File")
f = open("NewFile.txt", "w+")
print("Adding 10 Lines")
for i in range(10):
	f.write("Line no. %d\n" % (i+1))
	
f = open("NewFile.txt",'r')
print("Printing New File")
contents = f.read()
print(contents)
f.close()
print("Opening File to append new lines")
p=open("NewFile.txt", "a+")
print("Appending new line")
for i in range(11, 16):
	p.write("Line no. %d\n" % (i+1))
print("Print New File with appended data")
p = open("NewFile.txt", 'r')

contents = p.read()
print(contents)
p.close()
