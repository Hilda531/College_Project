def main():
    grades = []
    while True:
        i = input("Enter grade: ")
        if i == 'done':
            break
        grades.append(int(i))
    print("Grade average:", avg(grades))
def avg(grades):
    return round(sum(grades) / len(grades))
main()