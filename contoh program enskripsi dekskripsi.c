#include<stdio.h>
#include <stdlib.h>


//Fungsi Menu Utama//
 int main(void){
    int ch;
    char opsi[3];
    fflush(stdin);
    system("cls");
    printf("\n\t\t\t\t------------PRAKTIKUM ALPROG MODUL 3------------");
    printf("\n\t\t\t\t-------------------KELOMPOK 5-------------------");
    printf("\n\t\t\t\t\t================================");
    printf("\n\t\t\t\t\t\t    Program 5    ");
    printf("\n\t\t\t\t\t================================");
	printf("\n\t\t\tPilih operasi yang diinginkan:     \n");
	printf("\t\t\t[1] Enkripsi                         \n");
	printf("\t\t\t[2] Dekripsi                         \n");

    while(1){
        ch = getch();
        if(ch == 49){
            printf("1");
            system("cls");
            enkripsi();
            break;
        }
        else if(ch == 50){
            printf("2");
            system("cls");
            dekripsi();
            break;
    	}
        else if(ch == 48){
            system("cls");
            printf("\t\t\t=====TERIMA KASIH=====\n");
            exit(0);
            break;
        }
        else{
            printf("\n\t\t\tInputan error! Silahkan masukan kembali !\n\a");
            system("pause");
            system("cls");
            main();
        }
    }

return(0);
}

//Fungsi Untuk Enkripsi Teks//
int enkripsi()
{
	char pesan[100], ch;
	int i, key;
	printf("\t\t\t=====================================\n");
    printf("\t\t\t\t    PROGRAM ENKRIPSI\n");
    printf("\t\t\t=====================================\n");
	printf("\t\t\tMasukan pesan yang akan di-enkripsi : ");
	gets(pesan);
	printf("\t\t\tMasukan jumlah pergeseran : ");
	key=validasi_enkripsi();

	for(i = 0; pesan[i] != '\0'; i++){
		ch = pesan[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			pesan[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			pesan[i] = ch;
		}
	}

	printf("\t\t\tHasil Enkripsi : %s", pesan);
	opsi();
	return 0;
}

// Fungsi untuk Dekripsi Teks//
int dekripsi()
{
	char pesan[100], ch;
	int i, key;
	printf("\t\t\t=====================================\n");
    printf("\t\t\t\t   PROGRAM DEKRIPSI\n");
    printf("\t\t\t=====================================\n");
	printf("\t\t\tMasukan Pesan yang akan di-dekripsi: ");
	gets(pesan);
	printf("\t\t\tMasukan Jumlah Pergeseran key : ");
//	scanf("%d", &key);
	key=validasi_dekripsi();

	for(i = 0; pesan[i] != '\0'; ++i){
		ch = pesan[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			pesan[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}

			pesan[i] = ch;
		}
	}

	printf("\t\t\tHasil Dekripsi : %s", pesan);
	opsi();
	return 0;
}
// Fungsi Validasi Inputan Enkripsi//
int validasi_enkripsi(){
    int key;
    int input, bil;
	char huruf;
		input=scanf("%d%c", &bil, &huruf);
		if(input!=2 || huruf!='\n')
		{
			spam();
			printf("\t\t\tmasukan nilai salah,silahkan masukan angka bukan huruf !.\n\n");
			system("pause");
			system("cls");
			enkripsi();
		}else
		{

		return bil;
		}
}

// Fungsi Validasi Inputan Dekripsi//
int validasi_dekripsi(){
    int key;
    int input, bil;
	char huruf;
		input=scanf("%d%c", &bil, &huruf);
		if(input!=2 || huruf!='\n')
		{
			spam();
			printf("\t\t\tmasukan nilai salah,silahkan masukan angka bukan huruf !.\n\n");
			system("pause");
			system("cls");
			dekripsi();
		}else
		{

		return bil;
		}
}

void spam(void){
    char spam;
    while ((spam = getchar()) != '\n' && spam != EOF) ;
}

//Fungsi untuk kembali ke Menu Utama//
void opsi(){
    int ch3;
	fflush(stdin);
    printf("\n\n\t\t\tKembali ke Menu Utama ?(Y/N) =");
    ch3 = getch();
    if(ch3 == 121 || ch3 == 89){
        system("cls");
        main();
    }
    else if(ch3 == 110 || ch3 == 78){
        printf("n");
        system("cls");
        printf("\t\t\tTERIMAKASIH\n\n");
        exit(0);
    }
    else {
        printf("\n\t\t\tInputan error! Silahkan masukan kembali !\n\a");
		system("pause");
        system("cls");
        opsi();
    }
}

