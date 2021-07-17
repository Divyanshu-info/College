import urllib.request
import urllib.parse
import urllib.error
import xml.etree.ElementTree as ET

address = input("Enter location: ")
print("Retrieving "+address)
parms = dict()
uh = urllib.request.urlopen(address)
data = uh.read()
print('Retrieved', len(data), 'characters')
tree = ET.fromstring(data)

results = tree.findall('.//count')
print("Count: " + str(len(results)))
# count the no. of elements
summ = 0
for i in results:
    temp = i.text
    summ += int(temp)
print("Sum: "+str(summ))
