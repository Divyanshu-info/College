import csv
temp = list()
with open('/home/divyanshu/Desktop/New Folder/Text File.txt') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        try:
            for i in row:
                temp.append(i.split())
        except:
            pass
    for item in temp:
        print(item[0], end=' ')
