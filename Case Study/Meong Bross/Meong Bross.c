/*Dibuat oleh: Hilda Auliana (Modul 4 - IF STATEMENT & WHILE LOOP)

Keterangan program:
Program ini dibuat untuk memprediksi koordinat akhir dari permainan Meong Bross.
*/

#include <stdio.h>

int main(){
	int x = 0;  //Koordinat X
	int y = 0;  //Koordinat Y
	int i = 1;
	int a;      //Banyaknya perintah yang dapat dijalankan
	char b;     //Jenis perintah
	printf("Masukkan banyak perintah : ");
	scanf("%d", &a);

	while (i <= a){

        	printf("\nMasukkan perintah : ");
        	scanf(" %c", &b);
        	i+=1;

        	/*Jika bergerak ke Utara, maka Meong Bross akan bergerak sejauh 1 satuan
        	searah sumbu-Y positif*/
        	if(b == 'U'){
			y+=1;
			printf ("Meong bross bergerak ke Utara\n");
		}

        	/*Jika bergerak ke Selatan, maka Meong Bross akan bergerak sejauh 1 satuan
        	searah sumbu-Y negatif*/
        	else if(b == 'S'){
			y-=1;
			printf ("Meong bross bergerak ke Selatan\n");
		}

        	/*Jika bergerak ke Timur, maka Meong Bross akan bergerak sejauh 1 satuan
        	searah sumbu-X positif*/
		else if(b == 'T'){
			x+=1;
			printf ("Meong bross bergerak ke Timur\n");
		}

        	/*Jika bergerak ke Barat, maka Meong Bross akan bergerak sejauh 1 satuan
        	searah sumbu-X negatif*/
		else if(b == 'B'){
			x-=1;
			printf ("Meong bross bergerak ke Barat\n");
		}

		/*Jika mendapat input H, maka program akan terhenti*/
		else if(b == 'H'){
            		printf ("Meong bross Berhenti\n");
			break;
		}

		/*Jika mendapat input lain, maka posisi Meong Bross akan tetap*/
		else{
			x += 0;
			y += 0;
			printf ("Posisi meong bross tetap\n");
		}
	}
	/*Menampilkan hasil koordinat akhir*/
	printf ("\nKarakter Meong Bross berada di koordinat (x = %d, y = %d)", x, y);
	getch();
	printf("\n----------------------------------------------------------");
	return 0;
}
