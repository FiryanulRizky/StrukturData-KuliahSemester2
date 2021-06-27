#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int queue[10], i, front=-1, rear=-1, dequeue, pilihan, urutan=0, tmp;

do {
    system("pause");
    system("cls");
    printf("1. Masukkan Antrian\n");
    printf("2. Keluarkan Antrian\n");
    printf("3. Lihat Antrian\n");
    printf("4. Keluar\n\n");
    printf("Silahkan masukkan pilihan anda : ");
    scanf("%d", &pilihan);
    printf("\n");


    if(pilihan==1)
    {
        if(rear==9)
        {
            printf("Antrian Penuh\n\n");
        }
        else if(rear==-1)
        {
            front++;
            rear++;
            printf("Masukkan nilai : ");
            scanf("%d", &dequeue);
            queue[rear]=dequeue;
            urutan++;
            printf("\nNomor urut : %d\n", urutan);
            printf("Langsung dilayani\n\n");}
        else {
            rear++;
            printf("Masukkan nilai : ");
            scanf("%d", &dequeue);
            queue[rear]=dequeue;
            urutan++;
            printf("\nNomor urut : %d\n", urutan);
            printf("Anda harus menunggu %d antrian lagi\n\n", rear);
        }
    }

    else if(pilihan==2)
    {
        if(rear==-1)
        {
            printf("Antrian kosong\n\n");
        }
        else {
            printf("Data dengan nilai %d sudah dilayani\n\n", queue[front]);
            tmp=queue[front];
            for(i=front;i<=rear;i++)
            {
                queue[i]=queue[i+1];
            }
            queue[rear]=tmp;
            urutan++;
            printf("Data dengan nilai %d masuk antrian kembali dengan no. urut %d\n", queue[rear], urutan);

        if(rear==0)
        {
            printf("Yang bersangkutan langsung dilayani\n\n");
        }
        else {
            printf("Yang bersangkutan harus menunggu %d antrian lagi\n\n", rear);
            }
        }
    }

    else if(pilihan==3)
    {
        if(rear==-1)
        {
            printf("Antrian kosong\n\n");
        }
        else {for(i=front;i<=rear;i++)
        {
            printf("Antrian ke-%d : %d\n", i+1, queue[i]);
        }
        printf("\n");
        }
    }

    else if(pilihan==4)
    {
        printf("Anda telah selesai menggunakan program Queue Circular\n\n");
    }
    else {printf("Pilihan yang anda masukkan tidak valid\n\n");}
    } while(pilihan!=4);

getch();
}
