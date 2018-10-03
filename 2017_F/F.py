import math

def getDigit(num,base):
    return (num // base) % 10

def lowerBound(num):
    ret = 0
    base = 1
    base2 = 10**(length-1)
    while base < base2:
        digit1 = getDigit(num,base)
        digit2 = getDigit(num,base2)
        ret += min(abs(digit1-digit2),10-abs(digit1-digit2))
        base *= 10
        base2 /= 10
    return ret

def search(cur,base,pos,used):
    global ans
    global bound
    global length
    pows = []
    for i in range(0,length+1):
        pows.append(10**i)
    if (used >= ans):
        return
    if (pos == -1):
        ans = min(ans,used)
        return
    if (length-pos-1 < bound):
        if (used + lowerBound(cur) > ans + 2):
            return
        digit = getDigit(cur,base)
        search(cur,base*10,pos-1,used)
        if (digit >= 5):
            search((cur+base*(10-digit)) % pows[length],base*10,pos-1,used+(10-digit))
        """
        if digit >= 6:
            search((cur+base*(10-digit)) % pows[length],base*10,pos-1,used+(10-digit))            search(cur,base*10,pos-1,used)
        else:
            search(cur,base*10,pos-1,used)
            if (getDigit(cur,base) != 0):
                search((cur+base*(10-digit)) % pows[length],base*10,pos-1,used+(10-digit))"""
    else:
        left = getDigit(cur,base)
        right = getDigit(cur,pows[pos])
        if (left - right < 5):
            if (left < right):
                search(cur+(base*(right-left)),base*10,pos-1,used+abs(right-left))
            else:
                search(cur+pows[pos]*(left-right),base*10,pos-1,used+abs(right-left))
        else:
            search((cur+base*(10-(left-right))) % pows[length],base*10,pos-1,used+(10-(left-right)))
            search((cur+pows[pos]*(left-right)) % pows[length],base*10,pos-1,used+left-right)

def main():
    global length
    global bound
    number_str = input("")
    bound = len(number_str) / 2
    length = len(number_str)
    search(int(number_str),1,len(number_str)-1,0)
    print(ans)

length = 0
bound = 0
ans = 12345678
main()