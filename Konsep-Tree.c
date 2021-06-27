#include <stdio.h>
#include <stdlib.h>

struct tree{
	int value;
	struct tree *kiri, *kanan;
}*root,*temp,*cabang;

int main()
{
	int i,arah,bil;
    root=(struct tree*)malloc(sizeof(struct tree));
	root->kanan=root->kiri=NULL;

	printf("Program Binary Tree\nby : Firyanul Rizky (1708561006)\n\nKetik Bilangan Root : "); scanf("%d",&root->value);
    cabang=root;
	for(i=1;i<=5;i++)
    {
        printf("Ketik Cabang(0:kiri, 1:kanan) : "); scanf("%d",&arah);
		arah=arah%2;
		temp=(struct tree*)malloc(sizeof(struct tree));
		temp->kanan=temp->kiri=NULL;
        printf("Ketik bilangan : "); scanf("%d",&temp->value);
		if(arah==0){
			cabang->kiri=temp;
			cabang=temp;
		}
		else{
			cabang->kanan=temp;
			cabang=temp;
		}
	}
    printf("Data bilangan (dibaca dari root sampai habis ke kedalaman) : ");
	cabang=root;
	while(cabang!=NULL){
		if(cabang->kanan!=NULL){
			printf("%d - ",cabang->value);
			cabang=cabang->kanan;
		}
		else{
			if(cabang->kiri!=NULL){
				printf("%d - ",cabang->value);
				cabang=cabang->kiri;
			}
			else{
				printf("%d",cabang->value);
				break;
			}
		}
	}
	return 0;
}

