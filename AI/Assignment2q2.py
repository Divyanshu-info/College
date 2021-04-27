def palindrome(s):
    if len(s) == 1:
        return True
    if s[0] == s[-1]:
        return palindrome(s[1:-1])
    else:
        return False
n = list()

a = input("Enter string: ")
if len(a) < 1:
    print("Invalid String")
elif(palindrome(a) == True):
    print("String is a Palindrome")
else:
    print("String is not a Palindrome")
