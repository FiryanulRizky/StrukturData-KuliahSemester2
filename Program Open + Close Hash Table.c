#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define maks 5

int main ()
{
    kembali:
    system("cls");
    int pil1,pil2;
    printf("Program Implementasi Open & Close Hash Table\n");
    printf("============================================\n\n");
    printf("Pilihan Menu : \n");
    printf("[1] Open Hash Table\n");
    printf("[2] Close Hash Table\n");
    printf("Ketik Pilihan : ");
    scanf("%d",&pil1);
    switch(pil1)
    {
        case 1 : openhash();break;
        case 2 : closehash();break;
        default : printf("Terimakasih !!\n");
        printf("\nKembali Ke Menu ? \n");
        printf("[1] Ya\n");
        printf("[2] Keluar\n\n");
        printf("Ketik Pilihan : ");scanf("%d",&pil2);
        if (pil2 == 1)
        {
            goto kembali;
        }
        else {
            printf("Pilihan Salah !!\n");
        }
    }
    return 0;
}

char htclose[maks][20];
int makstambah = 0;

int ubah(char *a){
    int k;
    while(*a != '\0'){
        k += *a;
        a++;
    }
    return k;
}


void tambah(char *a){
    int k;
    if(makstambah >= maks)
        printf("Data sudah penuh!!");
    else {
        k = ubah(a);
        while(strlen(htclose[k%maks]) != 0)
            k = (k+1);

        strcpy(htclose[k%maks], a);

        makstambah++;
        printf("Data berhasil di tambahkan!");
    }
}

void cari(char *a){
    int k;
    if(makstambah == 0)
        printf("Masih belum ada barang");
    else {
        k = ubah(a);
        while(strcmp(htclose[k%maks], a) > 0)
            k = (k+1);

        printf("%s ada di gudang %d",a, k%maks);
    }
}

void lihat(){
    int a;
    if(makstambah > 0){
        for(a=0;a<maks;a++)
            printf("Gudang[%d] = %s\n", a, htclose[a]);
    }else printf("Tidak ada barang dalam gudang!");
}

int closehash(){
    char masukan[20];
    int pilih = 0;
    while(pilih != 4){
        system("cls");
        printf("[Closed]---\n\n");
        printf("1. Tambah\n");
        printf("2. Cari\n");
        printf("3. Tampil\n");
        printf("4. Keluar\n");
        printf("Masukan pilihan : ");scanf("%d", &pilih);fflush(stdin);fflush(stdin);
        switch(pilih){
            case 1:
                printf("Masukan barang : ");scanf("%s", masukan);fflush(stdin);
                tambah(&masukan);
            break;
            case 2:
                printf("Cari barang : ");scanf("%s", masukan);fflush(stdin);
                cari(&masukan);
            break;
            case 3:
                lihat();
            break;
            case 4:
                printf("Terima kasih!");
            break;
            default:
                printf("Tidak ada menu dipilihih!\n");
            break;
        }

        getch();
    }
}
