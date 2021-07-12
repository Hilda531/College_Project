/* Dibuat oleh: Hilda Auliana

Keterangan:
Program ini digunakan untuk menjumlahkan buah 2 matriks dimana besar dan isi dari matriks
tersebut ditentukan oleh user.
*/

#include <stdio.h>

void enterData(int s);
void addMatrices(int s);
void display(int s);

int input1[10][10];
int input2[10][10];
int result[10][10];

int s;
int i, j;

int main(){
	printf("input matrix size: ");
	scanf("%d", &s);

	enterData(s);
	addMatrices(s);
	display(s);

	printf("\npress any key to exit");
	getch();
	return 0;
}

void enterData(int s){
	printf("\ninput %d numbers for matrix1: \n", s*s);
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			printf("matrix1[%d][%d]: ", i + 1 ,j + 1);
			//scanf("%d", &input1[i][j]);
			scanf("%d", (*(input1 + i) + j));
		}
	}

	printf("\ninput %d numbers for matrix2: \n", s*s);
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			printf("matrix2[%d][%d]: ", i + 1 ,j + 1);
			//scanf("%d", &input2[i][j]);
			scanf("%d", (*(input2 + i) + j));
		}
	}
}

void addMatrices(int s){
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
			//result[i][j] = input1[i][j] + input2[i][j];
			*(*(result + i) + j) = *(*(input1 + i) + j) + *(*(input2 + i) + j);
		}
	}
}

void display(int s){
	printf("\nresult: \n");
	for(i = 0; i < s; i++){
		for(j = 0; j < s; j++){
				//printf("%d ", result[i][j]);
				printf("%d ", *(*(result + i) + j));
		}
		printf("\n");
	}
}
