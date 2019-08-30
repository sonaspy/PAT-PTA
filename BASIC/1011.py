# author - sonaspy@outlook.com 
# coding - utf_8 

n = eval(input())


for i in range(1,n+1):
    f = False
    str_in = input()
    a,b,c= eval(','.join(str_in.split()))
    if a + b > c:
        print("Case #{}: true".format(i))
    else:
        print("Case #{}: false".format(i))
