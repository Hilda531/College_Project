/*Dibuat oleh: Hilda Auliana (Modul 8 - ARRAY 2)

Keterangan program:
Program ini dibuat untuk menghitung hasil pengurangan isi dari elemen array
multidimensional 5x5 ketika nilai kolom lebih besar dibandingkan nilai baris.
*/

#include <stdio.h>

int c; //variabel kolom
int r; //variabel baris
int a; //untuk menghitung pengurangan input
int Data[5][5]; //array input 5x5

int main(){
//nilai input akan dimasukkan ke array
    for (r = 0; r < 5; r++){
        //loop baris
        for(c = 0; c < 5; c++){
            //loop kolom
            printf("Data[%d][%d] = ", r+1, c+1);
            scanf("%d", &Data[r][c]); //mengambil input
        }
        printf("\n");
    }
    matrix();   //menampilkan matriks array
    count();    //menampilkan hasil pengurangan
    getch();
    printf("\n----------------------------------------------------------");
    return 0;
}

int matrix(){
//membuat matrix array 5x5
    printf("Masukkan Data: \n");
    for (r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            printf("%d ", Data[r][c]);
		}
		printf("\n"); //spasi baris
	}
}

int count(){
//menghitung pengurangan data array
    for (r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            if (c > r){
                /*mengurangi setiap nilai ketika nilai baris
                  lebih besar dibanding nilai kolom*/
                a -= Data[r][c];
            }
		}
	}
	//hasil pengurangan ditampilkan
	printf("Hasil pengurangan dari setiap element diagonal adalah: %d\n", a);
}
