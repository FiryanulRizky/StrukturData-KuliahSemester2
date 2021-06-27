#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct NODE{
	char nama[10];
	char alamat[10];
	int id;
	int status;
	struct NODE *next;
	struct NODE *prev;
}*head,*n,*a,*tail,*temp;

void insert();
void tampil();
void del();
int search();

int main(){
	int menu,jumlah, hapus,id=1,sel;
	int total=0;
	printf("Program Pembeli Sembako murah\n");
	printf("Masukan jumlah pembeli = ");scanf("%d",&jumlah);
	do{
		system("cls");
		printf("1.Input Pembeli \n2.View Data Pembeli \n3.Hapus Pembeli\n4.Keluar\nPilihan= ");scanf("%d",&menu);
		switch(menu){
			case 1:
					do{
						system("CLS");
						if(total!=jumlah){
							char nama[10],alamat[10];
							printf("Nama pembeli : ");fflush(stdin);
							gets(nama);
							printf("Alamat Pembeli : ");fflush(stdin);
							gets(alamat);
							printf("ID pembeli = P0%d",id);
							insert(nama,alamat,id);
							id++;
							total++;
							printf("jumlah pembeli akttif = %d",total);

						}
						else{
							printf("Jumlah pembeli penuh\n");
						}
						printf("input lagi ? 1.Ya/2.Tidak = ");fflush(stdin);scanf("%d",&sel);
					}while(sel!=2);
			break;
			case 2:
					tampil();
					getch();	
			break;
			case 3:
				do{
						printf("ID pembeli yang akan dihapus = P0");scanf("%d",&hapus);
						if(search(hapus)!=0){
							del(hapus);
							total--;
						}
						else{
							printf("Pembeli sudah tidak aktif\n");
						}
					printf("Hapus lagi ? 1.Ya/2.Tidak = ");fflush(stdin);scanf("%d",&sel);
					}while(sel!=2);
			break;
				
		}	
	}while(menu!=4);
	printf("TTERIMAKASI!!!!");
	return 0;
}

void insert(char nama[10],char alamat[10],int id){
	char ID[5],*num;
	n = (struct NODE*)malloc(sizeof(struct NODE));
	strcpy(n->nama,nama);
	strcpy(n->alamat,alamat);
	n->id=id;
	n->status=1;
	if(head==NULL){
		head=n;
		head->next=head->prev=NULL;
	}
	else{
		n->next=head;
		head->prev=n;
		head=n;
	}
	printf("\n%s berhasil ditambahkan\n",n->nama);
}

void tampil(){
	printf("Data pengunjung \n");
	printf("ID \t\t|Nama\t\t|Alamat\n");
	temp=head;
	while(temp!=NULL){
		if(temp->status!=0)
			printf("P0%d\t\t|%s\t\t|%s\n",temp->id,temp->nama,temp->alamat);
		temp=temp->next;
	}
}

int search(int id){
	temp=head;
	while(temp!=NULL){
		if(temp->status!=0 && temp->id==id){
			return 1;
		}
		else{
			temp=temp->next;
		}
	}
	return 0;
}

void del(int id){
	temp=head;
	while(temp!=NULL){
		if(temp->status!=0 && temp->id==id){
			temp->status=0;
			return;
		}
		else{
			temp=temp->next;
		}
	}
}
