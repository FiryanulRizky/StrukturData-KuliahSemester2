#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<malloc.h>

struct desa_dampingan {
	int kode;
	int status;
	char nama[32];
	char keadaan[32];
	char presentase[10];
	struct desa_dampingan *next;
}*kepala,*ekor,*saat_ini,*sekarang,*ini;

int tambah();int view();

int kode=1,input=1;

int main()
{
    while(1)
    {
        int pilih;
        system("cls");
        printf("\n\tPROGRAM LIST KEADAAN DESA DAMPINGAN UDAYANA MENGAJAR\n");
        printf("\t====================================================\n\n");
        printf("\tDesa Terunyan\n");
        printf("\tKintamani - Bangli\n\n");
        printf("\tMuhammad Firyanul Rizky\t\t<1708561006>\n\n");
        printf("\t+---------- MENU ----------+\n");
        printf("\t|   1. Input Data Dusun    |\n");
        printf("\t|   2. View Data Dusun     |\n");
        printf("\t+--------------------------+\n\n");
        printf("\tPilihan : ");
        scanf("%d",&pilih);
        switch(pilih)
        {
            case 1:system("cls");printf("*-- Menu 1 Input Nama Dusun  --*\n\n");tambah();kode++;input++;break;
            case 2:system("cls");printf("*-- Menu 2 View Data Dusun --*\n\n");view();break;
        }
        system("pause");
        system("cls");
    }
}

int tambah()
{
	if(input == 1)
	{
		ini = (struct desa_dampingan*)malloc(sizeof(struct desa_dampingan));
		kepala = ini;
		ekor = ini;
		ini->kode = kode;
		fflush(stdin);
		printf("\nInput Data Dusun\n");
		if(kode<10)
		{
			printf("Kode Dusun : 0%d\n",kode);
		}
		else if(kode<100&&kode>=10)
		{
			printf("Kode Dusun : %d\n",kode);
		}
		printf("Nama Dusun : ");gets(ini->nama);
        printf("Permasalahan (Sosial/Ekonomi/Pendidikan) : ");gets(ekor->keadaan);
		printf("Presentase Kesulitan : ");gets(ekor->presentase);
		ekor->next = NULL;

	}
	else
	{
		ekor->next = (struct desa_dampingan*) malloc(sizeof(struct desa_dampingan));
		ekor = ekor->next;
		ekor->kode = kode;
		fflush(stdin);
		printf("\nInput Data Dusun\n");
		if(kode<10)
		{
			printf("Kode Dusun : 0%d\n",kode);
		}
		else if(kode<100&&kode>=10)
		{
			printf("Kode Dusun : %d\n",kode);
		}
		printf("Ketik Nama Dusun : ");gets(ekor->nama);
        printf("Permasalahan (Sosial/Ekonomi/Pendidikan) : ");gets(ekor->keadaan);
		printf("Presentase Kesulitan : ");gets(ekor->presentase);
		ekor->next=NULL;
	}
}

int view()
{
	saat_ini = kepala;
	int urutan=1;
    printf("+-- Permasalahan --++-------- Presentase -------+\n");
    printf("|   1. Sosial      ||   1.(0-30%) = Sejahtera   |\n");
    printf("|   2. Ekonomi     ||   2.(30-60%) = Menengah   |\n");
    printf("|   3. Pendidikan  ||   3.(60-100%) = Sulit     |\n");
    printf("+------------------++---------------------------+\n\n");
	printf(" No.\tKode Dusun\tNama Dusun\tPermasalahan\tPresentase Keadaan\n");
	while(saat_ini!=NULL)
    {
			printf(" %d.\t",urutan);
			if(saat_ini->kode<10)
			{
				printf("0%d\t\t",saat_ini->kode);
			}
			else if(saat_ini->kode<100&&saat_ini->kode>=10)
			{
				printf("%d\t\t",saat_ini->kode);
			}
			printf(" %s\t\t%s\t\t%s\n",saat_ini->nama,saat_ini->keadaan,saat_ini->presentase);
            saat_ini = saat_ini->next;
            urutan++;
    }
    printf("\n");
}
