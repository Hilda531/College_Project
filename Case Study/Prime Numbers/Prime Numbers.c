/*Dibuat oleh: Hilda Auliana

Keterangan:
Program ini akan menampilkan bilangan prima diantara 2 interval.
(User dapat memasukkan bilangan terbesar atau terkecil terlebih dahulu)
*/

#include <stdio.h>

int checkPrimeNumber(int n);

int main(){
    int a, b, n, f;
    int count = 1;
    int i;
    printf("First Interval\t: ");
    scanf("%d", &a);
    printf("Second Interval\t: ");
    scanf("%d", &b);

    if(a < b){
        for(n = a + 1; n <= b - 1; ++n){
            f = checkPrimeNumber(n);
            count *= f;
            if (f != 1 && n >= 2){
                i++;
                printf("\nPrime-%d = %d", i, n);
            }
        }
        if (count != 0){
            printf("\nNo Prime Numbers");
        }
    }
    else if(a > b){
        for(n = b + 1; n <= a - 1; ++n){
            f = checkPrimeNumber(n);
            count *= f;
            if (f != 1 && n >= 2){
                i++;
                printf("\nPrime-%d = %d", i, n);
            }
        }
        if (count != 0){
            printf("\nNo Prime Numbers");
        }
    }
    printf("\n\npress any key to exit");
    getch();
    return 0;
}

int checkPrimeNumber(int n){
    int i;
    for(i = 2; i <= n/2; ++i){
        if(n%i == 0){
            return 1;
        }
    }
    return 0;
}
