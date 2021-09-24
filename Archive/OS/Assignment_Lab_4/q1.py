import tabulate


ram_size = int(input("Input Ram size (MB)\t"))
part_size = int(input("Input size of partition\t"))
no_of_part = ram_size/part_size
p_lst = list()
size_lst = list()
def printtable():
    table = zip(p_lst, size_lst)
    print(tabulate.tabulate(table, \
        headers=["Partition No.", "Process Name","Process size"],\
                showindex="always", stralign="center",numalign="center"))
    dfrag = 0
    for i in size_lst:
        dfrag += (part_size - i)
    print(f"fragmentation = {dfrag}")
    print(f"Free Space = {ram_size-sum(size_lst)}")
    quit()

while(True):
    p_name = input("Input Process name\t")
    p_size = int(input("Input Process size\t"))
    if p_size <= part_size:
        p_lst.append(p_name)
        size_lst.append(p_size)
    while(True):
        if len(p_lst)>=no_of_part:
            print("Table is full")
            printtable()
        c = int(input("1. Add another process\n2. Remove a process\n3. End\n"))
        if c == 1:
            break
        if c == 2:
            try:
                p_name = input("Input Process name\t")
            except:
                print("process not found")
                continue
            t = p_lst.index(p_name)
            p_lst[t] = None
            size_lst[t] = None
        if c == 3:
            printtable()
