#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct data{
	char nama[100];
	int nim,spi,ukt,no;
	struct data *next;
	struct data *temp;
	struct data *current;
	struct data *last;
};struct data *head = NULL;

int pil2,antrian=0,i,nim2, spi2, ukt2;
char nama2[100], pil;

struct data* tambah(struct data** head){
 	struct data *data2;
	data2 = (struct data*) malloc(sizeof(struct data));
	struct data *last = *head;
	system("cls");
	printf("\n+-------------------------------------+\n");
	printf("| Tambah Antrian Pembayaran SPI & UKT |\n");
	printf("+-------------------------------------+\n\n");
	printf("NIM : ");
	scanf("%d",&nim2);
	fflush(stdin);
	printf("NAMA : ");
	gets(nama2);
	printf("SPI : ");
	scanf("%d",&spi2);
	printf("UKT : ");
	scanf("%d",&ukt2);

	data2->nim = nim2;
	strcpy(data2->nama,nama2);
	data2->spi = spi2;
	data2->ukt = ukt2;

	data2->next=NULL;
	if(*head==NULL)
	{
		*head=data2;
		printf("\nData Tersimpan\nNomor Antrian : %d", ++antrian);
		data2->no=antrian;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=data2;

 printf("\nData Tersimpan\nNomor Antrian : %d", ++antrian);
 data2->no=antrian;
 return;
}

void proses(struct data *current)
{
	struct data *temp;
	system("cls");
	printf("\n+-----------------------------+\n");
	printf("| Proses Pembayaran SPI & UKT |\n");
	printf("+-----------------------------+\n\n");
	printf("Masukkan NIM : ");
	scanf("%d",&nim2);
	if(nim2==current->nim)
		{
			printf("\nNama 		= %s \n", current->nama);
			printf("SPI 		= Rp. %d \n", current->spi);
			printf("UKT 		= Rp. %d \n\n", current->ukt);
			printf("Apakah akan melanjutkan Proses Pembayaran ? (y/t) ");
			scanf("%s",&pil);
			if(pil=='y')
			{
				head=current->next;
			}
		}
		temp = current;
		current=current->next;
	while(current!=NULL)
	{
		if(nim2==current->nim)
		{
			printf("\nNama 		= %s \n", current->nama);
			printf("SPI 		= Rp. %d \n", current->spi);
			printf("UKT 		= Rp. %d \n\n", current->ukt);
			printf("Apakah akan melanjutkan Proses Pembayaran ? (y/t) ");
			scanf("%s",&pil);
			if(pil=='y')
			{
				temp->next=current->next;
			}
		}
		temp = temp->next;
		current = current->next;
	}
	printf(" Pembayaran Telah Selesai");
}

void tampil(struct data *current)
{
	i=0;
	printf("+---------------------------------------------------------------------------------------------+\n");
	printf("|                          Daftar Antrian Pembayaran SPI & UKT                                |\n");
	printf("+---------------------------------------------------------------------------------------------+\n");
	printf("+--------------+------------------------------+-----------------------+-----------------------+\n");
	printf("| No. Atnrian  |              Nama            |          SPI          |          UKT          |\n");
	printf("+--------------+------------------------------+-----------------------+-----------------------+\n");
	if(current==NULL)
	{
		printf("|                               data kosong                          ");
	}
    while (current != NULL)
    {
    	printf("| %-12d | %-28s | Rp. %14d | Rp. %14d |\n",current->no, current->nama, current->spi, current->ukt);
    	printf("+--------------+------------------------------+-----------------------+-----------------------+\n");
        current = current->next;
		i++;
    }
}

int main ()
{
	menu:
	system("cls");
	printf("\n");
	printf("\t\t+----------------------------------+\n");
	printf("\t\t|       PEMBAYARAN SPI & UKT       |\n");
	printf("\t\t+----------------------------------+\n");
	printf("\t\t| \tMenu :                     |\n");
	printf("\t\t| \t1. Tambah Antrian          |\n");
	printf("\t\t| \t2. Proses Pembayaran       |\n");
	printf("\t\t| \t3. Lihat Antrian           |\n");
	printf("\t\t| \t4. Keluar                  |\n");
	printf("\t\t+----------------------------------+\n\n");
	printf("\t\t Pilihan : ");
	scanf("%d",&pil2);
	switch(pil2)
	{
		case 1 : tambah(&head);break;
		case 2 : proses(head);break;
		case 3 : tampil(head);break;
		case 4 : return 0;break;
		default : printf("\nInput Salah !\n");
	}
	getch();goto menu;
}
