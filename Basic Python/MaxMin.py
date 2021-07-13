max = None
min = None
while True:
    numb = input('Masukkan angka: ')
    try:
        y = int(numb)
    except:
        if numb == "selesai":
            break
        print('Error')
        continue
    if max is None:
        max = y
        min = y
    elif y > max:
        max = y
    elif y < min:
        min = y
print("Nilai terbesar =", max)
print("Nilai terkecil =", min)
print('DONE!')