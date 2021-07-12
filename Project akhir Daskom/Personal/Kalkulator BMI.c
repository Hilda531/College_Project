/*Dibuat oleh: Hilda Auliana (personal project)

Keterangan program:
Program ini digunakan untuk untuk mendata serta menghitung dan mengkategorikan Indeks Massa Tubuh
(IMT) setiap pasien, atau dikenal juga sebagai Body Mass Index (BMI).
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int age;
    char name[50];
    char result[50];
    float height;
    float weight;
}human;

human n[50];
float BMI(human*b, int u);
void keputusan(float *a, int p);

int main(){
    //Tampilan awal
    int i, pasien = 0;
    float bmi[50];
    char next;

    printf("\t\t\t         _/_/_/_/  _/_/      _/_/  _/_/_/ \n");
    printf("\t\t\t          _/   _/   _/_/  _/_/      _/    \n");
    printf("\t\t\t         _/_/_/    _/  _/  _/      _/     \n");
    printf("\t\t\t        _/   _/   _/      _/      _/      \n");
    printf("\t\t\t     _/_/_/_/  _/_/_/  _/_/_/  _/_/_/     \n");

    printf("\nSelamat datang!");
    printf("\nSilahkan masukkan beberapa data berikut ini.\n");

    do{
        //Input data
        printf("\nNama Pasien %d: ", pasien+1);
        scanf("%s", &n[pasien].name);
        printf("Umur Pasien %d: ", pasien+1);
        scanf("%d", &n[pasien].age);

        printf("Tinggi Badan (cm)\t: ");
        scanf("%f", &n[pasien].height);
        printf("Berat Badan (kg)\t: ");
        scanf("%f", &n[pasien].weight);

        bmi[pasien] = BMI(n, pasien);               //Memanggil fungsi untuk menghitung BMI
        printf("\nHasil bmi = %.1f", bmi[pasien]);  //Menampilkan hasilBMI

        pasien += 1;

        //Pilihan untuk menambah jumlah pasien
        printf("\n\nPasien Selanjutnya? [y/n] ");
        scanf("%s", &next);
        if(next == 'n' || next == 'N'){
            i = 0;
        }
        else if (next == 'y' || next == 'Y'){
            i = 1;
        }
        printf("\n-------------------------------------------------------------------------------------------\n");
    }while(i);

    //Menampilkan hasil kategori BMI pasien secara keseluruhan
    printf("\n========================================== HASIL ==========================================");
    printf("\nNo.\tNama \t\tUmur \t\tTB(cm) \t\tBB(kg) \t\tHasil");
	printf("\n===========================================================================================");

    for (int j = 0; j < pasien; j++){
        keputusan(&bmi[j], j);
        printf("\n%d \t%s \t\t%d thn \t\t%.2f \t\t%.2f \t\t%s", j+1, n[j].name, n[j].age,
               n[j].height, n[j].weight, n[j].result);
    }
    printf("\n===========================================================================================\n");
    return 0;
}

//Kalkulasi BMI pasien
float BMI(human *b, int u){
    float r;
    float tb;
    tb = (b+u)->height / 100;
    r = ((b+u)->weight) / (tb*tb);
    return r;
}

//Mengkategorikan BMI berdasarkan hasil kalkulasi
void keputusan(float *a, int p){
    if (*a <= 18.4){
        strcpy(n[p].result, "Kekurangan Bobot");
    }
    else if (*a <= 22.9 && *a >= 18.5){
        strcpy(n[p].result, "Sehat");
    }
    else if (*a <= 24.9 && *a >= 23){
        strcpy(n[p].result, "Kelebihan Bobot");
    }
    else if (*a <= 29.9 && *a >= 25){
        strcpy(n[p].result, "Obesitas 1");
    }
    else if (*a >= 30){
        strcpy(n[p].result, "Obesitas 2");
    }
}

