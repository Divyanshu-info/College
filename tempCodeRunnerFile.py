from collections import Counter
import random

def process(a, value):
    duplicate_dict = Counter(a)
    maxx = max(duplicate_dict.items(), key=lambda x : x[1])
    print(maxx)
    a.pop(0)
    a.append(value)
    return maxx, a

value = 1
a = [5, 1, 3, 0, 2, 1, 5, 0,
 5, 1, 2, 2, 1, 0, 2, 5, 3,
  0, 0, 0, 4, 2, 3, 5, 0, 3,
   5, 4, 1, 2, 2, 5, 5, 5, 3,
    1, 2, 2, 3, 0, 3, 2, 5, 0,
     2, 2, 3, 3, 3, 4, 2, 1, 4,
      5, 1, 0, 2, 0, 5, 4, 0, 2,
       4, 4, 0, 4, 1, 3, 4, 4, 4,
        3, 2, 4, 3, 4, 1, 0, 0, 0,
         5, 0, 3, 5, 3, 4, 1, 5, 2,
          0, 0, 4, 1, 4, 3, 0, 3, 4,
           2, 3]

maxx, a = process(a,value)