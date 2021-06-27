#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

struct keranjang {
    char kode[5],judul[50];
}satu,dua;

int main ()
{
    struct keranjang satu[500],dua[500];
    int i,j,pil1,pil2,top1=0,top2=0;
    MENU:
    printf("\n");
    printf("\t\tNama : Firyanul Rizky ( 1708561006 )\n\n");
    printf("\t\t-------------------\n");
    printf("\t\tPROGRAM PINDAH BUKU\n");
    printf("\t\t-------------------\n\n");
    printf("\t\t1. Menambah Buku\n");
    printf("\t\t2. Pindah Buku (1 Buku)\n");
    printf("\t\t3. Tampilkan Buku (Keranjang 1 & 2)\n");
    printf("\t\t4. Keluar\n\n");
    printf("\t\tPilihan : ");scanf("%d",&pil1);
    switch(pil1){
    case 1 : printf("\n1. Ke Keranjang I\n2. Ke Keranjang 2\n");
             printf("\nPilihan : ");scanf("%d",&pil2);
             if(pil2 == 1)
             {
                for(i=0;i<=500;i++)
                {
                    if(strlen(satu[i].kode)==0)
                    {
                        printf("\nMasukkan Kode Buku : ");
                        scanf("%s",satu[i].kode);
                        printf("\nMasukkan Judul Buku : ");
                        scanf("%s",satu[i].judul);
                        top1=top1++;
                        break;
                    }
                }
             }
             else if (pil2 == 2)
             {
                for(i=0;i<=500;i++)
                {
                    if(strlen(dua[i].kode)==0)
                    {
                        printf("\nMasukkan Kode Buku : ");
                        scanf("%s",dua[i].kode);
                        printf("\nMasukkan Judul Buku : ");
                        scanf("%s",dua[i].judul);
                        top2=top2++;
                        break;
                    }
                }
             }
            system("cls");
            goto MENU;
            break;

    case 2 : printf("\nPindah Buku\n");
             printf("\n1. Keranjang I ke II");
             printf("\n2. Keranjang II ke I\n\n");
             printf("Pilihan : ");scanf("%d",&pil2);
             if(pil2==1){
                strcpy(dua[top2].kode, satu[top1].kode);
                strcpy(dua[top2].judul, satu[top1].judul);
                top2++;
                strcpy(satu[top1-1].kode,"");
                strcpy(satu[top1-1].judul,"");
                top1--;
             }
             else if (pil2==2) {
                strcpy(satu[top1].kode, dua[top1].kode);
                strcpy(satu[top2].judul, dua[top1].judul);
                top1++;
                strcpy(dua[top2-1].kode,"");
                strcpy(dua[top2-1].judul,"");
                top2--;
             }
             system("cls");
             goto MENU;
             break;

    case 3 : printf("\nList Keranjang I");
             for(i=top1;i>=0;i--)
             {
                 printf("%s\t",satu[i].kode);
                 printf("%s\n",satu[i].judul);
             }
             printf("\nList Keranjang II");
             for(i=top2;i>=0;i--)
             {
                 printf("%s\t",dua[i].kode);
                 printf("%s\n",dua[i].judul);
             }
             getch();
             system("cls");
             goto MENU;
             break;
        case 4 : break;
        default : printf("\nMasukan Anda tidak ada dalam list Menu !!\n");break;
    }
    return 0;
}
