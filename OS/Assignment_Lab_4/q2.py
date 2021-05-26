import tabulate


ram_size = int(input("Input Ram size (MB)\t"))
Process_Table = list()
Partition_table = list()
part_bool = list()
Allocacated_table = dict()

def printtable():
    table = zip(Process_Table, Partition_table)
    print(tabulate.tabulate(table,
                            headers=["Partition No.",
                                     "Process Name", "Process size"],
                            showindex="always", stralign="center", numalign="center"))
    quit()


def check_allocation(size):
    # for u,v in Allocacated_table.items():
    #     if size <= u-v:
    #         Allocacated_table[u] = size
    tempp = None
    summ = 0
    # for j in range(len(part_bool)):
    j = 0
    temp = 0
    while(j < len(part_bool)):
        temp = 0
        for i in range(j, len(part_bool)):
            if part_bool[i] == False:
                if tempp == None:
                    tempp = i
                temp += Partition_table[i]
                try:
                    if part_bool[i+1] != False:
                        j = i
                        continue
                except:
                    pass
        else:
            if summ != 0 and temp == 0:
                pass
            elif summ == 0 and temp != 0:
                summ = temp
        j += 1
    if size <= summ:
        Allocacated_table[tempp] = size
    return summ, tempp


while(True):
    p_name = input("Input Process name\t")
    p_size = int(input("Input Process size\t"))
    if p_size <= ram_size - sum(Partition_table):
        Process_Table.append(p_name)
        Partition_table.append(p_size)
        Allocacated_table[p_size] = p_size
        part_bool.append(True)
    else:
        check = check_allocation(p_size)
        if p_size <= check[0]:
            Partition_table.pop(check[1])
            Process_Table.pop(check[1])
            part_bool.pop(check[1])
            Process_Table.insert(check[1], p_name)
            Partition_table.insert(check[1], p_size)
            part_bool.insert(check[1], True)
        else:
            print("No allocation Possible")

    while(True):
        c = int(input("1. Add another process\n2. Remove a process\n3. End\n"))
        if c == 1:
            break
        if c == 2:
            try:
                p_name = input("Input Process name\t")
            except:
                print("process not found")
                continue
            t = Process_Table.index(p_name)
            Process_Table[t] = None
            part_bool[t]  = False
            Allocacated_table[t] = 0
        if c == 3:
            printtable()
