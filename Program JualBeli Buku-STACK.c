#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct pembelian {
	char kode[50],judul[100];
};

struct pembelian buku[100];
int j,l,total=0,i=0,x=0,beli=0,check,kemas;
char pil,kodebuku[50],dibeli[50][5],hapus[50],terhapus[50][5];

int tambah(){
	do{
        system("cls");
        printf("\n---------");
        printf("\nPembelian Buku");
        printf("\n---------\n\n");
        printf("Masukkan kode buku dibeli : ");
        fflush(stdin);
        gets(kodebuku);
        check=0;
		for(i=0;i<total;i++){
            if(strcmp(buku[i].kode,kodebuku)==0){
                check=1;
                kemas=i;
            }
        }
        if(check==0){
            printf("\nMaaf kode buku tidak ditemukan !\n");
            getch();
        }
        else{
            printf("\nJudul buku\t: %s\n",buku[kemas].judul);
            strcpy(dibeli[beli],buku[kemas].kode);
            beli++;
            printf("\nBuku sudah ditambahkan!\n");
        }
        printf("\nIngin beli lagi? (y/n) : ");
        pil=getch();
    }
	while(pil=='y'||pil=='Y');
	main();
}

int batal(){
    system("cls");
    printf("\n----------------------");
    printf("\nPembatalan Pembelian Buku");
    printf("\n----------------------\n\n");
    printf("Masukkan kode buku yang akan terhapus\t: ");
    fflush(stdin);
    gets(hapus);
    for(j=0;j<total;j++){
         printf("%s - %s",buku[j].kode,hapus);
        if(strcmp(buku[j].kode,hapus)==0){
            printf("\nApakah Anda yakin akan menghapus buku %s?(y/n) : ",buku[j].judul);
            break;
        }
    }
    if(pil=='y'||pil=='Y'){
        for(i=beli-1;i>=0;i--){
            if(strcmp(dibeli[i],hapus==0)) {
                strcpy(dibeli[i],"");
                for(l=x;l>=0;l--){
                    strcpy(terhapus[l],dibeli[beli]);
                    beli++;
                }
            }
            else{
                strcpy(terhapus[x],dibeli[i]);
                beli--;
                x++;
            }
        }
    }
}

int tampil(){
    system("cls");
    printf("\n-----------------------");
    printf("\nDaftar Pembelian Buku");
    printf("\n-----------------------\n\n");
    printf("+---------------------------------+\n");
    printf("| No |  Kode Buku  |  Judul Buku  |\n");
    printf("+---------------------------------+\n");
    for(i=0;i<beli;i++){
        printf("|%-4d|%-13s|",i+1,dibeli[i]);
        for(j=0;j<total;j++){
            if(strcmp(buku[j].kode,dibeli[i])==0){
                printf("%-14s|\n",buku[j].judul);
            }
        }
        printf("+---------------------------------+\n");
    }
    getch();
    main();
}

int daftar(){
	do{
        check=0;
	    system("cls");
	    printf("\n-----------");
        printf("\nDaftar Buku");
        printf("\n-----------\n\n");
		printf("Masukkan kode buku\t: ");
		fflush(stdin);
		gets(kodebuku);
		for(i=0;i<total;i++){
            if(strcmp(buku[i].kode,kodebuku)==0){
                check=1;
            }
        }
        if(check==1){
            printf("\nKode buku sudah ada !\n");
            getch();
        }
        else{
            strcpy(buku[total].kode,kodebuku);
            printf("\nMasukkan judul buku : ");
            fflush(stdin);
            gets(buku[total].judul);
            printf("\nData tersimpan..\n");
            total++;
        }
        printf("\nIngin tambah lagi? (y/n) : ");
        pil=getch();
    }
    while(pil=='y'||pil=='Y');
	main();
}

int main(){
	int menu=0;
	system("cls");printf("\n");
	printf("\t\tNama : Firyanul Rizky ( 1708561006 )\n\n");
	printf("\t\t-----------------\n");
	printf("\t\tProgram Pembelian Buku\n");
	printf("\t\t-----------------\n\n");
	printf("\t\t1. Tambah Pembelian Buku\n");
	printf("\t\t2. Pembatalan Pembelian Buku\n");
	printf("\t\t3. Lihat Daftar Pembelian Buku\n");
	printf("\t\t4. Tambah Daftar Buku\n");
	printf("\t\t5. Keluar\n");printf("\n");
	printf("\t\tPilihan : ");
	scanf("%d",&menu);
	switch(menu){
		case 1 : tambah();break;
		case 2 : batal();break;
		case 3 : tampil();break;
		case 4 : daftar();break;
		case 5 : return 0;break;
		default: printf("/nPilihan yang Anda masukkan salah !\n");
	}
	return 0;
}
