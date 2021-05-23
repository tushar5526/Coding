k = int(input())
t = int(input())

while t:
    t -= 1
    n = int(input())

    if n == 1:
        print("1")
        print('1')
        continue
    elif n == 2:
        print(abs(1-2**k))
        print('01')
        continue
    a = list()

    for i in range(1, n+1):
        a.append(i**k)
    sy = a[n-2]
    sz = a[n-1]
    c = n-3
    s = ['1', '0']
    min = None

    while c >= 0:
        if abs(sz + a[c] - sy) < abs(sy + a[c] - sz):
            min = abs(sz + a[c] - sy)
            sz += a[c]
            s += '1'
        else:
            min = abs(sy + a[c] - sz)
            sy += a[c]
            s += '0'
        c -= 1
        
    s = s[::-1]  
    print("sz sy",sz,sy)  
    # print(min)
    # print(''.join(s))
    