n = int(input())
a=[]
a.append([])
for i in range(n):
    data = list(map(int, input().split()))
    a.append([])
    a[i].append(data[0])
    a[i].append(data[1])
    a[i].append(data[2])

ans = 0
for i in range(n):
    for j in range(i):
        if ((abs(a[i][0]+a[i][1]+a[i][2] - a[j][0]-a[j][1]-a[j][2])<=10)and(abs(a[i][0]-a[j][0])<=5)and(abs(a[i][1]-a[j][1])<=5)and(abs(a[i][2]-a[j][2])<=5)):
             ans += 1
            
print(ans)