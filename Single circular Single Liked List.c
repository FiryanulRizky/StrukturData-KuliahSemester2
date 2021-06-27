#include <stdio.h>
#include <stdlib.h>

struct NODE {

    int bilangan;struct NODE *next;

};

void tambah(struct NODE *link_list, int data);
void tampil(struct NODE *link_list);
void hapus(struct NODE *link_list, int data);

int main()
{
    int data = 0;int input = 1;struct NODE *link_list;

    link_list = (struct NODE *) malloc(sizeof(struct NODE));
    link_list->bilangan = 0;
    link_list->next = NULL;

    while (input != 0)
    {

        printf("\t\tProgram Sederhana Single Link List dengan Circular\n\n");
        printf("\t\t+-----------Silahkan Masukkan Pilihan-----------+\n");
        printf("\t\t|           1) Tambahkan data Angka             |\n");
        printf("\t\t|           2) Hapus data                       |\n");
        printf("\t\t|           3) Tampilkan data                   |\n");
        printf("\t\t|           0) Keluar Program                   |\n");
        printf("\t\t+-----------------------------------------------+\n\n");
        printf("\t\tMasukkan Pilihan : ");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                printf("\nMasukkan Angka yang ingin ditambahkan: ");
                scanf("%d", &data);
                tambah(link_list, data);
                system("cls");
                break;

            case 2:
                printf("\nMasukkan Angka yang ingin dihapus: ");
                scanf("%d", &data);
                hapus(link_list, data);
                system("cls");
                break;

            case 3:
                printf("\nMenampilkan Angka : \n");tampil(link_list);
                break;

            case 0:
                printf("\nSelesai\n");
                input = 0;
                break;

            default : printf("\nInput Salah\n");
            break;

        } /* switch */
    } /* while */

    free(link_list);
    return (0);
}

void tampil(struct NODE *link_list)
{
    while (link_list->next != NULL)
    {
        printf("%d ", link_list->bilangan);
        link_list = link_list->next;
    }

    printf("%d\n\n", link_list->bilangan);
}

void tambah(struct NODE *link_list, int data)
{
    while (link_list->next != NULL)
        link_list = link_list->next;

    link_list->next = (struct NODE *) malloc(sizeof(struct NODE));
    link_list->next->bilangan = data;
    link_list->next->next = NULL;
}

void hapus(struct NODE *link_list, int data)
{
    struct NODE *temp;
    temp = (struct NODE *) malloc(sizeof(struct NODE));

    if (link_list->bilangan == data)
    {
        /* remove the node */
        temp = link_list->next;
        free(link_list);
        link_list = temp;
    } else
    {
        while (link_list->next->bilangan != data)
            link_list = link_list->next;

        temp = link_list->next->next;
        free(link_list->next);
        link_list->next = temp;
    }
}
