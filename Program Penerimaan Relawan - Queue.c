#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front = -1;
int rear = -1;

int no=0;
struct data{
	char nama[100];
	char fakultas[75];
	char jurusan[30];
	char line[20];
	long int angkatan;
	char alasan[100];
	char harapan[100];
	int antrian;
};
struct data que[MAX];
void enqueue(char a[100],char b[75],char c[30],long int d,char e[20],char f[100],char g[100])
{
	if(rear>=MAX-1)
		printf ("full");
	else
	{
		if(rear==-1 && front == -1)
		{
			rear = 0;
			front = 0;
		}
		else

		rear++;
		strcpy(que[rear].nama,a);
		strcpy(que[rear].fakultas,b);
		strcpy(que[rear].jurusan,c);
		que[rear].angkatan = d;
		strcpy(que[rear].line,e);
		strcpy(que[rear].alasan,f);
		strcpy(que[rear].harapan,g);
		que[rear].antrian = ++no;

	}
}
int dequeue()
{
	int p;
	if(front==-1 || front>rear)
	{
		printf ("kosong");
		return -1;

	}

	else
	{
		p = que[front].antrian;
		front++;
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
	return p;

	}
}

void tampil()
{
	int i;

	if(front==-1 || front>rear)
	{
			printf ("antrian kosong!!!");
	}
	else
	{
	    for (i=front;i<=rear;i++)
        {
	    printf(" No. Antrian      : %d\n",que[i].antrian);
	    printf(" Nama Lengkap     : %s\n",que[i].nama);
        printf(" Fakultas         : %s\n",que[i].fakultas);
        printf(" Jurusan          : %s\n",que[i].jurusan);
        printf(" Angkatan         : %ld\n",que[i].angkatan);
        printf(" Line             : %s\n",que[i].line);
        printf(" Alasan Bergabung : %s\n",que[i].alasan);
        printf(" Harapan Kedepan  : %s\n",que[i].harapan);
        printf("\n\n");
        }
    }
}
int main (int argc, char *argv[])
{
	int item; int pilih; int p;
	char a[100],b[75],c[30],e[20],f[100],g[100];
	long int angkatan;
	do{
		system("cls");

		printf("\t\t*** Program Penerimaan Relawan Udayana Mengajar ***\n");
		printf("\t\t                 Periode 2018 \n\n");
		printf("\t+--------------------- Pilihan Menu -----------------------+\n");
        printf("\t| 1 untuk Memasukkan Antrian Kloter Relawan                |\n");
        printf("\t| 2 untuk Menghapus Antrian Relawan yang mendaftar         |\n");
        printf("\t| 3 untuk Menampilkan Antrian Relawan Yang telah mendaftar |\n");
        printf("\t| 4 untuk keluar                                           |\n");
        printf("\t+==========================================================+\n\n");
        printf("\nPilihan : ");
        scanf("%d",&pilih);
        printf("\n");
        switch(pilih)
        {
            case 1:
				printf("Nama Lengkap : ");fflush(stdin);
				gets(a);fflush(stdin);
				printf("Fakultas : ");fflush(stdin);
				gets(b);fflush(stdin);
				printf("Jurusan : ");fflush(stdin);
				gets(c);fflush(stdin);
				printf("Angkatan : ");fflush(stdin);
				scanf("%ld",&angkatan);
				printf("Line : ");fflush(stdin);
				gets(e);fflush(stdin);
				printf("Alasan Bergabung : ");fflush(stdin);
				gets(f);fflush(stdin);
				printf("Harapan Kedepan : ");fflush(stdin);
				gets(g);fflush(stdin);
				enqueue(a,b,c,angkatan,e,f,g);

			   break;
            case 2:
				p=dequeue();
				printf("\n Relawan dengan urutan ke - %d Sudah Berhasil Bergabung dan Telah Terhapus dalam Antrian\n",p);
			   break;
            case 3:tampil();
			   break;
            default:printf("==Terima kasih== \n");
        }
        system("pause");

	}
	while(pilih != 4);
	return 0;
}
