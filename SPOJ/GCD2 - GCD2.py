def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
test=int(input())

for i in range(0,test):
    inp=input()
    inp=inp.split()
    a=int(inp[0])
    b=int(inp[1])
    c=gcd(a,b)
    print(c)
