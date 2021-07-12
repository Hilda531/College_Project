/*Dibuat oleh: Hilda Auliana (Modul 6 - FUNCTIONS)

Keterangan program:
Program ini dibuat untuk mengkalkulasikan damage per second dan combat effectiveness
berdasarkan 4 atribut dasar Ctuber milik kita dan musuh, kemudian memutuskan apakah
harus melawan atau menghindar.
*/

#include <stdio.h>

//Deklarasi variabel global
char n[50][15];
float fp[15];
float rof[15];
float a[15];
float e[15];

float dps[15];
float ce[15];

int exit;
int i;

//Deklarasi fungsi
int input(int j);
float damage_per_second(int k);
float combat_effectiveness(int l);
void toString();

int main(){
    do{
        for(i = 1; i <= 2; i++){
            if (i == 1)
                printf("### MY CTUBER ###");
            else
                printf("\n\n### ENEMY CTUBER ###");

            input(i);
            dps[i] = damage_per_second(i);
            ce[i] = combat_effectiveness(i);
        }

        toString();

        printf("\n\nLanjut? \n");
        scanf(" %d", &exit);
    }while(exit);
    getch();
    printf("\n----------------------------------------------------------");
    return 0;
}

//Mengambil input
int input(int j){
    printf("\nMasukkan nama Ctuber : ");
    scanf("%s", &n[j]);

    do{
        printf("\nMasukkan Firepower : ");
        scanf("%f", &fp[j]);
        if (fp[j] < 0)
            printf("Error input yang dimasukkan tidak tepat\n");
    }while(fp[j] < 0);

    do{
        printf("\nMasukkan Rate of Fire : ");
        scanf("%f", &rof[j]);
        if (rof[j] < 0)
            printf("Error input yang dimasukkan tidak tepat\n");
    }while(rof[j] < 0);

    do{
        printf("\nMasukkan Accuracy : ");
        scanf("%f", &a[j]);
        if (a[j] < 0)
            printf("Error input yang dimasukkan tidak tepat\n");
    }while(a[j] < 0);

    do{
        printf("\nMasukkan Evation : ");
        scanf("%f", &e[j]);
        if (e[j] < 0)
            printf("Error input yang dimasukkan tidak tepat\n");
    }while(e[j] < 0);
}

//Menghitung damage per second
float damage_per_second(int k){
    dps[k] = (fp[k]*rof[k])/60;
    return dps[k];
}

//Menghitung combat effectiveness
float combat_effectiveness(int l){
    ce[l] = (30*fp[l]) + (40*(rof[l]*rof[l])/120) + 15*(a[l] + e[l]);
    return ce[l];
}

//Menampilkan hasil akhir
void toString(){
    printf("\n\n### RESULT ###");

    for(i = 1; i <= 2; i++){
        printf("\n%s", n[i]);
        printf("\nDamage Per Second = %.2f", dps[i]);
        printf("\nCombat Effectiveness = %.2f\n", ce[i]);
    }

    if(dps[1] > dps[2] && ce[1] > ce[2]){
        printf("\n\nGas Lawan");
    }
    else{
        printf("\n\nKaburrr");
    }
}
