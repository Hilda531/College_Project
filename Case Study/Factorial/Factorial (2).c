/*Dibuat oleh: Hilda Auliana

Keterangan:
Berikut merupakan program komputasi Factorial menggunakan recursive user-defined function.
*/

#include <stdio.h>

int factorial(int n);

int main(){
    int num;
    printf("Input number: ");
    scanf("%d", &num);

    if (num < 0){
        printf("\nUndifined\n");
    }
    else{
        printf("\nFactorial number of %d is %d\n", num, factorial(num));
    }
    return 0;
}

int factorial(int n){
    int b;
    if(n <= 1){
        return 1;
    }
    b = n * factorial(n - 1);
    return b;
}
