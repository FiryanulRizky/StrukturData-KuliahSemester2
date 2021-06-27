//Latihan program Antrian
#include <stdio.h>
#include <string.h>
#define max 4

int head = -1; int tail = -1; int queue[max];

int main()
{
	int pil = 0;
	
	while(1){
		printf("Selamat datang : \n");
		printf("-------------- : \n");
		printf("Pilih aksi : \n");
		printf("1. Ambil antrian \n");
		printf("2. Selesaikan antrian \n");
		printf("3. Tampilkan antrian \n");
		
		scanf("%i", &pil);
		int num;
		if(pil==1){
			printf("Masukkan nomor antrian : ");
			scanf("%i",&num);
			insert(num);
		}
		else if(pil==2){
			num = del();
		}
		else if(pil==3){
			int i;
			if(head == -1 || head == tail+1){
				printf("Antrian kosong\n");
			}
			else{
			printf("Menampilkan antrian : \n");
			for(i=head;i<=tail;i++){
				printf("<%i> \n", queue[i]);;	
			}
			
		}	
	}
	}
}

int insert(int num)
{
	if(tail == 4-1){
		printf("Antrian penuh!\n\n");	
	}
	if(head == -1){
		head = 0;
	}
	tail++;
	queue[tail] = num;

}

int del()
{
	int element;
	if(head==-1 || head == tail+1){
		printf("Antrian kosong");
	return ;
	}
	element = queue[head];
	head++;
	printf("Antrian %i telah di hapus.\n", element);
	return element;
}

