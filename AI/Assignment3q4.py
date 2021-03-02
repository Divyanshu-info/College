res = ['FSXM', 'GS8A', 'L78', 'Z6P', 'NY4', '3R3I', '7G',
       'UHK3', 'V0V', '8CMM', '6J', 'RNS', 'BLI9', 'PQ7',
       'S7', 'FWD6', 'PO9', 'LOJL', 'EE', '727', '6D1',
       'G632', '8B', 'SKY4', 'CJP6', 'SUG', 'AQYS', 'IYR',
       'KRZB', '6MP', 'U2DD', '1Z', '36', '4W', 'L5EF',
       'SZ', '0E', '940', '0K8', 'G8TA', 'A6VB', '4W9X',
       'H73', 'U66', 'CU9', 'ESR7', 'M2LG', '1QX', 'BG6',
       'RZX', '8LA', 'WIQV', 'R3', 'WS', 'XY', 'ZOBP',
       'OI', 'CGO', 'HS6', '25EC', '9AY', 'B5GS', 'LG',
       'AV', 'Y4', 'RSG', 'BZ8', '2RPH', '0Z6U', 'NLX',
       'CZ', 'HAH1', 'HY', 'XJ', 'SE1X', 'PL', 'YT', 'DN',
       'YV9M', '8T', 'Q2TW', 'Z70', '1EBM', '55', 'OAZ3',
       'II9E', '3RQD', 'VNAU', 'B2ZH', 'Y3MM', '519', 'K8W0',
       '60SB', 'B0', '8C', '3S', 'TDU', 'PA5N', 'CBP6', 'R7YA']

count = 0
for i in res:
    if len(i) == 3 and i[0] == i[-1]:
        count += 1
print(count)
