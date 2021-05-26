import csv
remaining_money = 0
invested_money = 0
no_of_shares = 0
pivot = 318
shares = list()
diff = list()
profit = list()
with open('/home/divyanshu/Downloads/SBIN.NS.csv') as csv_file:
    no_of_shares = 0
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        try:
            money_i_have = 3000
            curr_value = int(float(row[-3]))
            money_i_have +=remaining_money
            no_of_shares_i_can_buy = money_i_have // curr_value
            no_of_shares += no_of_shares_i_can_buy
            remaining_money = money_i_have % curr_value
            invested_money += no_of_shares_i_can_buy * curr_value
            shares.append(no_of_shares_i_can_buy)
            diff.append((pivot - curr_value))
            profit.append(no_of_shares_i_can_buy* (pivot-curr_value))
        except:
            pass
    print(sum(profit))
