string = input("Input String\n")
if len(string) > 0:
    letters = dict()
    for i in string:
        letters[i]=letters.get(i, 0) + 1
    #print(letters)
    least = min(letters, key=letters.get)
    print(f"Least frequent character is {str(least)}")            
else: 
    print("Invalid Input")
