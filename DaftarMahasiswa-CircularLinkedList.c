#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct angkatan_mhs {
    int nilai,angkatan_data;
    char nama[50];
    struct angkatan_mhs * next;
};

int angkatan_data,i,n,j,nilai_baru;
struct angkatan_mhs* head=NULL;
char nama_baru[50],y;

int main()
{
 system ("cls");
 printf("--------------------\n");
 printf("Circular Linked List\n");
 printf("--------------------\n\n");
 printf("Input Jumlah Angkatan : ");
 scanf("%d",&angkatan_data);
 for(i=1;i<angkatan_data;i++)
    {
        printf("Angkatan : %d\n\n",i);
        printf("Jumlah Data : ");
        scanf("%d",&n);
        for(j=1;j<n;j++)
        {
            printf("Data  : %d\n",j);
            printf("Nama  : ");
            scanf("%s",&nama_baru);
            printf("Nilai : ");
            scanf("%d",&nilai_baru);
            insert(&head);
        }
    }
}

void insert(struct angkatan_mhs** start)
{
    struct angkatan_mhs* new_angkatan_mhs = (struct angkatan_mhs*) malloc(sizeof(struct angkatan_mhs));
    struct angkatan_mhs* input=*start;
    strcpy(new_angkatan_mhs->nama,nama_baru);
    new_angkatan_mhs->nilai=nilai_baru;
    new_angkatan_mhs->angkatan_data=i;
    new_angkatan_mhs->next=NULL;
    if (*start == NULL)
    {
        *start = new_angkatan_mhs;
        return;
    }
    while (input->next != NULL)
        input = input->next;
    input->next=new_angkatan_mhs;
    return;
}
