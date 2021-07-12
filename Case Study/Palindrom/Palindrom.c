/*Dibuat oleh: Hilda Auliana (Modul 7 - ARRAY 1)

Keterangan program:
Program ini dibuat untuk mendeteksi kata-kata palindrom dan menghitung banyaknya huruf
vokal yang terdapat pada kata tersebut.
*/

#include <stdio.h>
#include <string.h>

void toString(int palin, int vcl){
    //Print palindrom jika nilai palin 0 atau print jumlah vokal jika nilai palin tidak 0

    if(palin == 0){
	printf("\nPalindrom\n");
	printf("Jumlah Vokal : %d\n", vcl);
    }
    else{
        printf("\nBukan Palindrom\n");
	printf("Jumlah Vokal : %d\n", vcl);
    }
}

int proses(char a[20]){
    //Jika terdeteksi huruf vokal, maka nilai vocal akan bertambah dan di return

    int i = 0;
    int vocal = 0;
    while (a[i] != '\0') {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] =='o' || a[i] == 'u'){
            vocal++;
	}
        i++;
    }
    return vocal;
}

int main(){
    char a[20], b[20];
    int c, p;

    printf("Input : ");
    gets(a);

    strlwr(a); // mengubang setiap string input menjadi lowercase
    strcpy(b, a); // men-copy string input ke dalam string b
    p = proses(a);

    if(strcmp(strrev(b), a) == 0){
    /*Ketika tidak terdapat perbedaan antara input yang telah dibalik dan yang belum
    (terdeteksi palindrom)*/
	c = 0;
	toString(c, p);
    }
    else{
    /*Ketika tidak terdeteksi palindrom*/
	c =  1;
	toString(c, p);
    }

    getch();
    printf("\n----------------------------------------------------------");
    return 0;
}
