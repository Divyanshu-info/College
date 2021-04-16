items = {0:" ", 1:"Fan", 2:"Lights", 3:"TV", 4:"AC", 5:"All_Off"}
items_list = {0:0,1:0,2:0,3:0,4:0,5:0}
lst = [1,2,3]
def work_command(value):
    lst.clear()
    if value != 0:
        if items_list[value] == 0:
            print(f"{items[value]} is now on")
            items_list[value]+=1
        else:
            print(f"{items[value]} is now off")
            items_list[value]-=1

lst.append(1)
lst.append(2)
print(lst)
work_command(1)
print(lst)