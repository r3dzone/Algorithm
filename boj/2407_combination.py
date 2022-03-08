n,m = input().split()
n = int(n)
m = int(m)
facto = [1]

for i in range(1,103):
    facto.append(facto[-1]*i)
    
print(facto[n]//(facto[n-m]*facto[m]))