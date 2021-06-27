#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct biodata {
    char nama[100];
    int usia;
    char gender[10];
};

struct biodata a[100];
int index=0;

int tambah()
{
    printf("Masukan Nama Mahasiwa : ");
    scanf("%[^\n]",a[index].nama);fflush(stdin);
    printf("Masukan usia    : ");
    scanf("%d",&a[index].usia);fflush(stdin);
    printf("Masukan Jenis Kelamin : ");
    scanf("%[^\n]",a[index].gender);fflush(stdin);
    index++;
    kembali();
}

int edit()
{
    int keindex;
    printf ("Masukan Index biodata Mahasiswa : ");
    scanf ("%d",&keindex);fflush(stdin);
    printf ("Masukan Nama Mahasiswa : ");
    scanf ("%[^\n]",a[keindex].nama);
    printf ("Masukan usia   : ");
    scanf ("%d",&a[keindex].usia);fflush(stdin);
    printf ("Masukan Jenis Kelamin : ");
    scanf ("%[^\n]",a[keindex].gender);
    kembali();
}

int hapus()
{
    int keindex,i;
    printf ("Masukan Index Yang Ingin Dihapus : ");
    scanf ("%d",&keindex);
    for (i=keindex;i<index;i++)
    {
        a[i]=a[i+1];
    }
    index--;kembali();
}

int simpan()
{
    int i,pilih;
    FILE *fp;
    fp=fopen("biodata.txt","w");
    for (i=0;i<index;i++)
    {
        fprintf(fp,"%s;%d;%s;\n",a[i].nama,a[i].usia,a[i].gender);
    }
    fclose(fp);
    printf("Baca File dulu ?\n");
    scanf("%d",pilih);
    if(pilih==1)
    {
       FILE *fp;
        fp=fopen("biodata.txt","r");
        while (fscanf(fp,"%[^;];%d;%[^;];\n",a[index].nama,&a[index].usia,a[index].gender)!=EOF)
        {
            index++;
        }
        fclose(fp);
    }
    else {
        printf("Input Salah !\n");
    }
    kembali();
}

int tampil()
{
    int pil;
    int i;
    for (i=0;i<index;i++)
    {
        printf ("%d  %s  %d  %s\n",i,a[i].nama,a[i].usia,a[i].gender);
    }
    kembali();
}

struct node {
    int data;
    struct node *next;
}*head,*head1,*temp,*tail,*tail1;

int menu_baru(){
    int pil,i,bil;
    printf("Program Penggabungan Dua List\n");
    printf("=============================\n\n");
    printf("Input 1\n");
    for(i=1;i<=3;i++){
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Masukkan Bilangan %d : ", i);
        scanf("%d", &bil);
        if(head==NULL){
            tail=head=temp;
            head->data=bil;
            head->next=NULL;
        }
        else{
            temp->data=bil;
            tail->next=temp;
            tail=temp;
            tail->next=NULL;
        }
    }

    printf("\nInput 2\n");
        for(i=1;i<=3;i++){

        temp=(struct node *)malloc(sizeof(struct node));

        printf("Masukkan Bilangan %d : ", i);
        scanf("%d", &bil);
        if(head1==NULL){
            tail1=head1=temp;
            head1->data=bil;
            head1->next=NULL;
        }
        else{
            temp->data=bil;
            tail1->next=temp;
            tail1=temp;
            tail1->next=NULL;
        }
    }
    tail->next=head1;
    struct node *a;
    a=head;
    printf("\nHasil Gabungannya adalah ");
    while(a!=NULL)
    {
        printf("%d ",a->data);
        a=a->next;
    }
    printf("\n");
    kembali();
}

int kembali()
{
    int pil;
    printf("\nKembali Ke Menu ?\n");
    printf("[1] Ya\n");
    printf("[2] Tidak\n\n");
    printf("Ketik Pilihan : ");
    scanf("%d",&pil);
    if(pil==1)
    {
        main();
    }
    else {
        system("cls");
        printf("\nTerimakasih !\n");
    }
}

int main()
{
    kembali:
    system("cls");
    int menu;
    printf("Program Sederhana Operasi File\n");
    printf("==============================\n\n");
    printf("+------------ BIODATA MAHASISWA ------------+\n");
    printf("|   [1] Tambah biodata Mahasiswa            |\n");
    printf("|   [2] Tampil biodata Mahasiswa            |\n");
    printf("|   [3] Edit biodata Mahasiswa              |\n");
    printf("|   [4] Hapus biodata Mahasiswa             |\n");
    printf("|   [5] Simpan & Keluar                     |\n");
    printf("|   [6] Penggabungan List dengan Pointer    |\n");
    printf("+-------------------------------------------+\n");
    printf ("\nPilih : ");
    scanf ("%d",&menu); fflush(stdin);
    printf ("\n");
    switch(menu)
    {
        case 1: tambah();break;
        case 2: tampil();break;
        case 3: edit();break;
        case 4: hapus();break;
        case 5: simpan();break;
        case 6: menu_baru();break;
    }
    if(menu!=6)
    {
        printf("Pilihan Salah !\n");
        return 0;
    }
}
