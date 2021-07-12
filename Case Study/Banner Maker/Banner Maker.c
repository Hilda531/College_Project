/*Dibuat oleh: Hilda Auliana (Modul 5 - DO-WHILE, FOR, DAN SWITCH)

Keterangan program:
Program ini merupakan simulasi Mindcraft Banner Maker dengan 2 jenis pattern berbeda.
*/

#include <stdio.h>

int main()
{
    int a; //Input ukuran banner
    int p; //Input untuk menentukan pattern
    int l; //Panjang
    int w; //Lebar
    int k; //Input untuk keluar program
    do
    {
        printf("Masukkan banyak baris resolusi = ");
        scanf("%d", &a);

        if(a > 0){
            printf("Masukkan pilihan pattern :\n 1. 0 dan / \n 2. $ dan =");
            printf("\nPilihan anda : ");
            scanf("%d", &p);
            for(w=1; w<=a; w++) //Menghitung lebar
            {
                for(l=1; l<=a; l++) //Menghitung panjang
                {
                    if(w==1 || w==a || l==1 || l==a) //Print frame banner
                    {
                        switch(p)
                        {
                            case 1 :
                                printf("0");
                                break;
                            case 2 :
                                printf("$");
                                break;
                        }
                    }
                    else if(l == w || l == (a + 1 - w)) //Print pola X pada banner
                    {
                        switch(p)
                        {
                            case 1 :
                                printf("0");
                                break;
                            case 2 :
                                printf("$");
                                break;
                        }
                    }
                    else
                    {
                        switch(p)
                        {
                            case 1 :
                                printf("/");
                                break;
                            case 2 :
                                printf("=");
                                break;
                        }
                    }
                }
                printf("\n");
            }
        }
        else{
            printf("Error pilihan yang dimasukkan tidak tepat");
        }
        printf("\n\nMasukkan 0 untuk keluar ");
        scanf("%d", &k);
	} while(k);
    getch();
    printf("\n----------------------------------------------------------");
    return 0;
}



