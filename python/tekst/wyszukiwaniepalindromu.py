#wersja 1
def isPalindrome(s): 
    return s == s[::-1] 

s = "malayalam"
ans = isPalindrome(s) 
print(ans)
#wersja 2
def isPalindrome1(str):  
    for i in range(0, len(str)//2): 
        if str[i] != str[len(str)-i-1]: 
            return False
    return True

s = "malayalam"
ans = isPalindrome1(s) 
print(ans)
#wersja 3
def isPalindrome2(s): 
    rev = ''.join(reversed(s)) 
    if (s == rev): 
        return True 
    return False

s = "malayalam"
ans = isPalindrome2(s) 
print(ans)
#wersja 4
x = "malayalam"
w = "" 
for i in x: 
    w = i + w 
    if (x==w): 
        print("YES") 
