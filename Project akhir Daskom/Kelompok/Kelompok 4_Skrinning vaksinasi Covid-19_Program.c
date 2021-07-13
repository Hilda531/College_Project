/*Project Kelompok 4

Keterangan program:
Program ini dibuat untuk membantu petugas medis dalam mendata banyaknya pasien
yang dapat menerima vaksin, yang tidak dapat menerima vaksin, ditunda, dan
memerlukan konsultasi dokter akibat keterbatasan vaksin covid-19 yang ada.

Peran dalam kelompok:
Membuat program prototype signup dan login, tampilan tabel pendataan akhir, dan
perhitungan banyaknya pasien yang akan mendapat vaksin, yang tidak, ditunda, atau 
perlu konsultasi pada dokter.
*/

#include <stdio.h>
#include<conio.h>
#include <string.h>

int log_in(int a);

struct data_pasien{
    	char nama[30];
    	int umur;
    	float suhu;
    	int sistole;
    	int diastole;
    	char hasil[100];
};

int main(){
    	int a, i=0, j=0, stok;
    	int A = 0, B = 0, C = 0, D = 0;
    	char username[10];
    	char next, kondisi, tipe, obat, hiv, vak2;
    	float suhu;
    	int sistolik, hari, HbA1C, waktu, cd4;

   	printf("=============== WELCOME ===============");
    	printf("\n1. Sign up\n2. Log in");

    	printf("\n\nPilih: ");
    	scanf("%d", &a);

    	log_in(a);

    	//input skrinning maksimal
    	printf("\n\nBerapa banyak pasien yang bisa diskrinning hari ini? ");
    	scanf("%d", &stok);

    	struct data_pasien pasien[stok];

    	for(i=1; i<=stok; i++){
		j=i;

		//input data pasien
		printf("\n\n*** MASUKKAN DATA PASIEN [%d] ***", i);
		printf("\n\nNama Pasien %d: ", i);
		scanf("%s", pasien[i].nama);

		while (1){

	    		//input umur
    	    		printf("Umur: ");
	    		scanf("%d", &pasien[i].umur);

	    		//input suhu
	    		printf("Masukkan suhu tubuh pasien (Celcius) = ");
	    		scanf("%f", &pasien[i].suhu);

	    		//input tekanan darah
  	    		printf("Masukkan tekanan darah pasien (sistole/diastole mmHg)");
	    		printf("\nSistole = ");
	    		scanf("%d", &pasien[i].sistole);
	    		printf("Diastole = ");
	    		scanf("%d", &pasien[i].diastole);

	    		//statement if-else umur
	    		if (pasien[i].umur <= 18){
				printf("Pasien TIDAK DAPAT diberikan vaksin, belum cukup umur");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
	    		}

	    		//statement if-else suhu
	    		if (pasien[i].suhu >= 37.5){
				printf("Vaksinasi DITUNDA hingga suhu pasien di bawah 37.5 derajat celcius dan skrinning COVID-19 ulang hasilnya negatif");
				C+=1;
				strcpy(pasien[i].hasil, "DITUNDA");
				break;
	    		}

	    		//statement if-else tekanan darah
   	    		if (pasien[i].sistole > 140 || pasien[i].diastole > 90){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
	    		}

	    		else{
				printf("\n");
	    		}

	    		printf("\n===PERTANYAAN===\n");
	    		printf("Jawablah pertanyaan berikut sesuai kondisi pasien!");
	    		printf("\nPetunjuk pengisian : Masukkan jawaban berupa 'y' untuk yes dan 'n' untuk no.\n");

	    		//pertanyaan vaksin
	    		printf("\nApakah pasien pernah menerima vaksin sebelumnya?");
	    		VAKSIN:
	    		printf("\n[y/n] ");
	    		scanf(" %c", &kondisi);
		
	    		if (kondisi == 'y'){
				printf("\nApakah pasien memiliki riwayat alergi berat atau mengalami gejala sesak napas, bengkak dan kemerahan setelah divaksinasi COVID-19 sebelumnya?");
				GEJALA:
				printf("\n[y/n] ");
				scanf(" %c", &vak2);
				if (vak2 == 'y'){
		    			printf("Pasien TIDAK DAPAT diberikan vaksin kedua.");
		    			B+=1;
		    			strcpy(pasien[i].hasil, "TIDAK");
		    			break;
				}
				else if (vak2 == 'n'){
		    			printf("\n");
				}
				else{
		    			printf("Input tidak valid! ");
		    			goto GEJALA;
				}
	    		}
		
	    		else if (kondisi == 'n'){
				printf("\n");
	    		}
		
	    		else{
				printf("Input tidak valid! ");
				goto VAKSIN;
	    		}

	    		//pertanyaan 1
	    		pertanyaan_1:
	    		printf("Apakah pasien menderita autoimun sistemik?\nContoh : SLE/Lupus, Sjogren, vaskulitis, dan autoimun lainnya.");
	    		printf("\n[y/n] ");
	    		scanf(" %c", &kondisi);
	
	    		if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
	    		}
		
	    		else if (kondisi == 'n'){
				printf("\n");
	    		}
	
	    		else{
				printf("Input tidak valid! ");
				goto pertanyaan_1;
	    		}

	    		//pertanyaan 2
	    		pertanyaan_2:
	    		printf("Apakah pasien menderita penyakit jantung?\nContoh : gagal jantung atau jantung koroner");
	    		printf("\n[y/n] ");
	    		scanf(" %c", &kondisi);
			
	    		if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
	    		}
	
	    		else if (kondisi == 'n'){
				printf("\n");
	    		}
			
	    		else{
				printf("Input tidak valid! ");
				goto pertanyaan_2;
	    		}

	    		//pertanyaan 3
	    		pertanyaan_3:
	    		printf("Apakah pasien pernah terkonfirmasi menderita COVID-19?");
	    		printf("\n[y/n] ");
	    		scanf(" %c", &kondisi);
			
	    		if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
	    		}
			
	    		else if (kondisi == 'n'){
				printf("\n");
	    		}
			
	    		else{
				printf("Input tidak valid! ");
				goto pertanyaan_3;
	    		}

			//pertanyaan 4
			pertanyaan_4:
			printf("Apakah pasien menderita reumatik autoimun atau rhematoid arthritis?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_4;
			}

			//pertanyaan 5
			pertanyaan_5:
			printf("Apakah pasien sedang hamil atau menyusui?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_5;
			}

			//pertanyaan 6
			pertanyaan_6:
			printf("Apakah pasien menderita penyakit ginjal?\nContoh : penyakit ginjal kronis/sedang menjalani hemodialisis/dialisis peritoneal/transplantasi ginjal/sindroma nefrotik dengan kortikosteroid");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_6;
			}

			//pertanyaan 7
			pertanyaan_7:
			printf("Apakah pasien mengalami gejala ISPA?\nContoh : batuk/pilek/sesak napas");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Berapa lama gejala sudah berlangsung?");
				GEJALA_ISPA:
				printf("\nLama gejala berlangsung (hari)= ");
				scanf("%d", &hari);
				if (hari < 7){
					printf("Pasien TIDAK DAPAT diberikan vaksin");
					B+=1;
					strcpy(pasien[i].hasil, "TIDAK");
					break;
				}
				else if (hari > 7){
					printf("\n");
				}
				else{
				printf("Input tidak valid!Hanya masukkan input berupa angka!");
				goto GEJALA_ISPA;
				}

			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_7;
			}

			//pertanyaan 8
			pertanyaan_8:
			printf("Apakah pasien menderita penyakit paru?\nContoh : asma atau PPOK");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_8;
			}

			//pertanyaan 9
			pertanyaan_9:
			printf("Apakah pasien menderita diabetes melitus?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Diabetes tipe berapa yang diderita pasien?");
				TIPE_DIABETES:
				printf("\nTipe diabetes yang diderita pasien (1/2)= ");
				scanf(" %c", &tipe);
				if (tipe == '1'){
					printf("Pasien TIDAK DAPAT diberikan vaksin");
					B+=1;
					strcpy(pasien[i].hasil, "TIDAK");
					break;
				}
				else if (tipe == '2'){
					printf("Berapa HbA1C pasien?");
					printf("\nHbA1C pasien (mmol/mol) =");
					scanf("%d", &HbA1C);
					if(HbA1C >= 58){
						printf("Pasien TIDAK DAPAT diberikan vaksin");
						B+=1;
						strcpy(pasien[i].hasil, "TIDAK");
						break;
					}
					else{
						printf("\n");
					}
				}
				else{
				printf("Input tidak valid!Hanya masukkan input berupa angka!");
				goto TIPE_DIABETES;
				}
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_9;
			}

			//pertanyaan 10
			pertanyaan_10:
			printf("Apakah menderita tuberkulosis (TBC)?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Apakah pasien mendapatkan obat anti TBC?");
				TBC:
				printf("\n[y/n] ");
				scanf(" %c", &obat);
				if (obat == 'y'){
					printf("Berapa lama sejak terakhir pasien mengonsumsi obat tersebut?");
					printf("\nJeda waktu mengonsumsi obat (hari) = ");
					scanf("%d", &waktu);
					if (waktu <= 14){
						printf("Vaksinasi ditunda ");
						strcpy(pasien[i].hasil, "DITUNDA");
						C+=1;
						break;
					}
					else if (waktu > 14){
						printf("\n");
					}
				}
				else if (obat == 'n'){
						printf("Pasien TIDAK DAPAT diberikan vaksin");
						B+=1;
						strcpy(pasien[i].hasil, "TIDAK");
						break;
					}
				else{
				printf("Input tidak valid!Hanya masukkan input berupa angka!");
				goto TBC;
				}

			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_10;
			}

			//pertanyaan 11
			pertanyaan_11:
			printf("Apakah pasien menderita penyakit hipertiroid/hipotiroid karena autoimun?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_11;
			}

			//pertanyaan 12
			pertanyaan_12:
			printf("Apakah pasien menderita penyakit saluran pencernaan kronis?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_12;
			}

			//pertanyaan 13
			pertanyaan_13:
			printf("Apakah pasien menderita penyakit kanker?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_13;
			}

			//pertanyaan 14
			pertanyaan_14:
			printf("Apakah pasien merupakan penerima produk darah atau transfusi?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_14;
			}

			//pertanyaan 15
			pertanyaan_15:
			printf("Apakah pasien menderita penyakit kelainan darah?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_15;
			}

			//pertanyaan 16
			pertanyaan_16:
			printf("Apakah pasien sedang menjalani terapi aktif jangka panjang terhadap penyakit kelainan darah?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_16;
			}

			//pertanyaan 17
			pertanyaan_17:
			printf("Apakah pasien memiliki anggota keluarga serumah yang kontak erat/suspek/konfirmasi/sedang dalam perawatan penyakit COVID-19?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien TIDAK DAPAT diberikan vaksin");
				B+=1;
				strcpy(pasien[i].hasil, "TIDAK");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\n");
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_17;
			}

			//pertanyaan 18
			pertanyaan_18:
			printf("Apakah pasien menderita HIV/AIDS?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Apakah diketahui berapa kadar CD4 dalam darah pasien? ");
				HIV:
				printf("\n[y/n] ");
				scanf(" %c", &hiv);
				if (hiv == 'y'){
					printf("Berapa kadar CD4 dalam darah?\nKadar CD4 (sel/ml) = ");
					scanf("%d", &cd4);

					if (cd4 <= 200) {
						printf("Pasien TIDAK DAPAT diberikan vaksin");
						B+=1;
						strcpy(pasien[i].hasil, "TIDAK");
						break;
					}

					else {
						printf("\n");
					}
				}

				else if (hiv == 'n'){
					printf("Pasien TIDAK DAPAT diberikan vaksin");
					B+=1;
					strcpy(pasien[i].hasil, "TIDAK");
					break;
					}

				else{
				printf("Input tidak valid!Hanya masukkan input berupa angka!");
				goto HIV;
				}
			}

			else if (kondisi == 'n'){
				printf("\n");
			}

			else{
				printf("Input tidak valid! ");
				goto pertanyaan_18;
			}

			//pertanyaan 19
			pertanyaan_19:
			printf("Apakah pasien memiliki penyakit lain yang belum disebutkan?");
			printf("\n[y/n] ");
			scanf(" %c", &kondisi);
			
			if (kondisi == 'y'){
				printf("Pasien harap BERKONSULTASI kepaada dokter.");
				D+=1;
				strcpy(pasien[i].hasil, "KONSUL");
				break;
			}
			
			else if (kondisi == 'n'){
				printf("\nPasien DAPAT diberikan vaksin. Silahkan masuk ke ruangan vaksinasi.");
				A+=1;
				strcpy(pasien[i].hasil, "YA");
				break;
			}
			
			else{
				printf("Input tidak valid! ");
				goto pertanyaan_19;
			}

		}//while

		if (i<stok){
			printf("\n\n[NEXT PATIENT]");
			printf("\n[y/n] = ");
			scanf(" %c", &next);
		}

		if (next == 'n'){
			break;
		}
		else{
			continue;
		}

	} //for

	printf("\n\n\n===================== VAKSINASI HARI INI =====================\n");
	printf("\nNo.\tNama\t\tUmur\tTekanan Darah\t\tHasil");
	printf("\n===============================================================");
    
	for(i=1; i<=j; i++){
		printf("\n%d\t%s\t\t%d\t%d / %d mmHg\t\t%s", i, pasien[i].nama, pasien[i].umur, pasien[i].sistole, pasien[i].diastole, pasien[i].hasil);
	}
    	printf("\n\nTotal Pasien = %d", j);
	printf("\n\tVaksin: %d pasien\n\tTidak Vaksin: %d pasien\n\tDitunda: %d pasien\n\tKonsul: %d pasien", A, B, C, D);

	getch();
	return 0;
}

//function log-in
int log_in(int a){
	char u1[50], u2[50], p1[50], p2[50];
    	int i, j, k = 0;

    	do{
    		switch (a){
        		case 1:
            			printf("\n=============== SIGN UP ===============\n");

            			printf("\nusername\t: ");
            			scanf("%s", &u1);
            			printf("password\t: ");
            			do{
                			p1[i]=getch();
                			if(p1[i]!='\r'){
                    				printf("*");
                			}
                			i++;
            			}while(p1[i-1]!='\r');

            			p1[i-1]='\0';

            			//printf("\nYou have entered %s as password.", p1);
            			printf("\n\n--------------------\n");
            			printf("| SIGN UP SUCCESS! |");
            			printf("\n--------------------\n");

            			k = 1;

        		case 2:
            			printf("\n================ LOGIN ================\n");
            			do{
            				printf("\nusername\t: ");
            				scanf("%s", &u2);
            				if(strcmp(u1, u2) == 0 || strcmp("COVIDtuntas", u2) == 0){
                				printf("password\t: ");
                				int i=0;
                				do{
                    					p2[i]=getch();
                    					if(p2[i]!='\r'){
                        					printf("*");
                    					}
                    					i++;
                				}while(p2[i-1]!='\r');
               					
						p2[i-1]='\0';
                    				if (strcmp(p1, p2) == 0 || strcmp("aamiin", p2) == 0){

                        				printf("\n\n------------------\n");
                        				printf("| LOGIN SUCCESS! |");
                        				printf("\n------------------\n");
                        				printf("\n\n*** SKRINNING VAKSINASI COVID-19 ***");

                        				k = 0;
                        				j = 0;
                    				}
                    				else {
                        				printf("\nAkses ditolak!\n");
                        				j = 1;
                    				}
                			}
                			
					else {
                    				printf("Username tidak terdaftar!\n");
                    				j = 1;
                			}
            			}while(j);
    			}
    	}while(k);
}
