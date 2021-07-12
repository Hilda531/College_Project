/*Dibuat oleh: Hilda Auliana (Modul 10 - STRUCTURES)

Keterangan program:
Program ini akan menghitung masing-masing cost dari 3 buah rocket, kemudian menjumlahkan
keseluruhan budget yang dibutuhkan untuk menerbangkan setiap roket tersebut.
*/

#include <stdio.h>
#include <string.h>

//struct input data awal
typedef struct{
    char name[50];
    char size[50];
    char country[50];
    int machine;
    int booster;
}rocket;

//struct perhitungan cost
typedef struct{
    int size;
    int machine;
    int booster;
    int result;
}cost;

//deklarasi struct dan fungsi
rocket data[50];
cost cpl[50];
int input(int j);
int cost_per_launch(int k);
void total_budget();

//deklarasi variabel global
int i;
int c[50];

int main(){
    //Proses utama
    for(i = 0; i < 3; i++){
        input(i);
        c[i] = cost_per_launch(i);
    }
    total_budget();
    getch();
    printf("\n----------------------------------------------------------");
    return 0;
}

//Data input akan diperoleh
int input(int j){
    printf("Nama roket %d: ", j+1);
    scanf("%s", &data[j].name);

    printf("Ukuran roket: ");
    scanf("%s", &data[j].size);

    printf("Jumlah mesin roket: ");
    scanf("%d", &data[j].machine);

    printf("Jumlah booster roket: ");
    scanf("%d", &data[j].booster);

    printf("Negara pemilik roket: ");
    scanf("%s", &data[j].country);

    printf("\n");
}

//Menghitung cost per launch
int cost_per_launch(int k){
    int a;

    //Cost per size
    if(strcmp(strlwr(data[k].size), "large") == 0){
        cpl[k].size = 1000000;
    }
    else if(strcmp(strlwr(data[k].size), "medium") == 0){
        cpl[k].size = 500000;
    }
    else if(strcmp(strlwr(data[k].size), "small") == 0){
        cpl[k].size = 300000;
    }

    //Cost tambahan
    cpl[k].machine =  data[k].machine * 500000;
    cpl[k].booster =  data[k].booster * 700000;

    //Jumlah cost per launch
    a = cpl[k].size + cpl[k].machine + cpl[k].booster;

    //Diskon tambahan
    if(strcmp(strlwr(data[k].country), "usa") == 0){
        a = a - (a * 20 / 100);
    }
    return a;
}

//Menampilkan budget akhir
void total_budget(){
    int add = 0;
    printf("\n\n=== HASIL HITUNGAN COST ===");

    for(i = 0; i < 3; i++){
        //Print total budget
        printf("\n%s ($ %d)", data[i].name, c[i]);
        add += c[i];
    }
    printf("\n\nTotal cost: %d\n", add);
}
