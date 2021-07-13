a = 5
b = 4
x = int(input('Banyak suku: '))
sum = 0
for n in range(1, x+1):
    u = a * b**(n-1)
    sum = sum + u
    print('suku ke-{}:'.format(n), u)
print('jumlah:', sum)
print('rata-rata:', sum/n)