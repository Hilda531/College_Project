/*Dibuat oleh: Hilda Auliana (Modul 9 - POINTERS)

Keterangan program:
Program dibuat untuk melihat akses data pada pointer dan menghitung hasil angka
yang dimasukkan oleh user.
*/

#include <stdio.h>

//deklarasi fungsi dan variabel global
int i, k;
void inputest(int test1[5], int test2[5]);
void displaytest(int test1[5], int test2[5]);
void addtest(int test1[5], int test2[5], int total[5]);

int main(){
    //deklarasi variabel lokal
    int test1[5]; int *test1Ptr;
    int test2[5]; int *test2Ptr;
    int total[5]; int *totalPtr;

    //dereferensi variabel
    test1Ptr = test1;
    test2Ptr = test2;
    totalPtr = total;

    do{
    inputest(test1Ptr, test2Ptr);       //mengambil input
	displaytest(test1Ptr, test2Ptr);    //menampilkan hasil input
    addtest(test1Ptr, test2Ptr, total); //menjumlahkan hasil input

    printf("\n\nMasukkan 0 untuk keluar : ");
	scanf("%d", &k);

	printf("\n");
    } while(k);

	getch();
    printf("----------------------------------------------------------");
	return 0;
}

//mengambil input test 1 dan test 2 sebanyak 5 kali
void inputest(int test1[5], int test2[5]){
	for(i = 0; i < 5; i++){
        printf("Masukkan Test 1 dan Test 2 : ");
		scanf("%d %d", test1 + i, test2 + i);
	}
}

//menampilkan input test 1 dan test 2 dalam bentuk array
void displaytest(int test1[5], int test2[5]){
	for(i = 0; i < 5; i++){
        printf("\nTest1[%d] = %d Test2[%d] = %d", i , *(test1 + i), i , *(test2 + i));
	}
}

//menampilkan hasil penjumlahan test 1 dan test 2
void addtest(int test1[5], int test2[5], int total[5]){
    printf("\n");
	for(i = 0; i < 5; i++){
        *(total + i) = *(test1 + i) + *(test2 + i);     //hasil penjumlahan dimasukkan ke variabel total menggunakan pointers
        printf("\nTotal[%d] = %d ", i, *(total + i));   //hasil ditampilkan
	}
}




