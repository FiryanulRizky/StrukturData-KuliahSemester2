#include <stdio.h>
#include <stdlib.h>

struct node {
	int bil;
	struct node *next;
	struct node *prev;
}*head,*tail;

struct node *tambah(int bil_baru);

int main()
{
	int i,node_baru,bil_baru,pil;
	struct node *tunjuk1,*tunjuk2;

    menu:
    system("cls");
	printf("\t\t=======================\n");
	printf("\t\tProgram Rantai Bilangan\n");
	printf("\t\t=======================\n\n");
	printf("\t\tKetik Jumlah node : ");
	scanf("%d",&node_baru);

	struct node *node_bil[node_baru];
	int urutan[node_baru];
	for(i=0;i<node_baru;i++)
	{
	    system("cls");
	    printf("\n");
	    printf("\t\t  =============\n");
		printf("\t\t  Input node %d\n",i+1);
		printf("\t\t  =============\n\n");
		printf("\t\tKetik Jumlah bilangan : ");
		scanf("%d",&bil_baru);
		node_bil[i] = tambah(bil_baru);
	}
	system("cls");
	printf("\n");
	printf("\t\t===================\n");
	printf("\t\tInput Node Bilangan\n");
	printf("\t\t===================\n\n");
	for(i=0;i<node_baru;i++)
	{
		tunjuk1=node_bil[i];
		printf("\t\tnode %d : ",i+1);
		while(tunjuk1!=NULL)
		{
			printf("%d",tunjuk1->bil);
			if(tunjuk1->next!=NULL)
				printf(" ");
			tunjuk1=tunjuk1->next;
		}
		printf("\n");
	}
	printf("\n");
	printf("\t\tKetik Urutan node : ");
	for(i=0;i<node_baru;i++)
	{
		scanf("%d",&urutan[i]);
	}
	printf("\n");
	printf("\t\tMenu : \n\n");
	printf("\t\t1. Double Lingked List\n");
	printf("\t\t2. Circular Double Lingked List\n\n");
	printf("\t\tPilihan : ");
	scanf("%d",&pil);

	tunjuk1=node_bil[urutan[0]-1];
	head=tunjuk1;
	while(tunjuk1->next!=NULL)
	{
		tunjuk1 = tunjuk1->next;
	}
	for(i=1;i<node_baru;i++)
	{
		tunjuk1->next = node_bil[urutan[i]-1];
		while(tunjuk1->next!=NULL)
		{
			tunjuk2=tunjuk1;
			tunjuk1=tunjuk1->next;
			tunjuk1->prev=tunjuk2;
		}
	}
	if(pil==2)
	{
		tunjuk1->next = node_bil[urutan[0]-1];
		tunjuk2 = tunjuk1;
		tunjuk1 = tunjuk1->next;
		tunjuk1->prev = tunjuk2;
		tail = tunjuk1;
	}
	tunjuk1=head;

	if(pil==1)
	{
	    printf("\n");
	    printf("\t\tUrutan Double Lingked List : ");
		while(tunjuk1!=NULL)
		{
			printf("%d",tunjuk1->bil);
			if(tunjuk1->next!=NULL)
				printf(" ");
			tunjuk1=tunjuk1->next;
		}
		printf("\n");
	}

	else if(pil == 2)
	{
	    printf("\n");
	    printf("\t\tUrutan Circular Double Lingked List : ");
		while(tunjuk1!=tunjuk2)
		{
			printf("%d",tunjuk1->bil);
			if(tunjuk1->next!=NULL)
				printf(" ");
			tunjuk1=tunjuk1->next;
		}
		printf("%d",tunjuk1->bil);
	}
	printf("\n");
}

struct node *tambah (int bil_baru)
{
	int i,j;
	struct node *tunjuk1,*tunjuk2,*head;
	for (i=0;i<bil_baru;i++)
	{
		fflush(stdin);
		tunjuk2 = tunjuk1;
		if (i==0)
		{
			tunjuk1 = (struct node*) malloc(sizeof(struct node));
			printf("bil %d : ",i+1);
			scanf("%d",&j);
			tunjuk1->bil = j;
			tunjuk1->next = NULL;
			tunjuk1->prev = NULL;
			head = tunjuk1;
		}
		else
		{
			tunjuk1 = tunjuk1->next;
			tunjuk1 = (struct node*) malloc(sizeof(struct node));
			printf("bil %d : ",i+1);
			scanf("%d",&j);
			tunjuk1->bil = j;
			tunjuk2->next = tunjuk1;
			tunjuk1->next = NULL;
			tunjuk1->prev = tunjuk2;
		}
	}
	return head;
}
