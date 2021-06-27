#include <stdio.h>
#include <stdlib.h>
#define max_data 100
#define max_list 10

struct list{
	int data;
	struct list *next;
	struct list *before;
};

struct list *start;
struct list *insert (int jml_data);

int main()
{
	int i,jml_list,jml_data,pil;
	struct list *ptr,*preptr;
	printf("Program Rantai Bilangan\n");
	printf("Ketik Jumlah List : ");
	scanf("%d",&jml_list);
	struct list *list_data[jml_list];
	int urutan[jml_list];
	for(i=0;i<jml_list;i++)
	{
		printf("\nInput List %d\n",i+1);
		printf("Ketik Jml Data : ");
		scanf("%d",&jml_data);
		list_data[i] = insert(jml_data);
	}
	system("cls");
	printf("List Data\n");
	for(i=0;i<jml_list;i++)
	{
		ptr=list_data[i];
		printf("List %d\n",i+1);
		while(ptr!=NULL)
		{
			printf("%d",ptr->data);
			if(ptr->next!=NULL)
				printf("-->");
			ptr=ptr->next;
		}
		printf("\n");
	}
	printf("Ketik Urutan List : \n");
	for(i=0;i<jml_list;i++)
	{
		scanf("%d",&urutan[i]);
	}
	printf("Menu : \n");
	printf("1. Double LL\n");
	printf("2. Circular Double LL\n");
	printf("Pilihan : ");
	scanf("%d",&pil);
	
	ptr=list_data[urutan[0]-1];
	start=ptr;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	for(i=1;i<jml_list;i++)
	{
		ptr->next = list_data[urutan[i]-1];
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
			ptr->before=preptr;
		}
	}
	if(pil==2)
	{
		ptr->next = list_data[urutan[0]-1];
		preptr = ptr;
		ptr = ptr->next;
		ptr->before = preptr;
		tail = ptr;
	}
	ptr=start;
	
	//Tampilkan rantaian bilangan
	//double linked list
	if(pil==1)
	{
		while(ptr!=NULL)
		{
			printf("%d",ptr->data);
			if(ptr->next!=NULL)
				printf("-->");
			ptr=ptr->next;
		}
	}
	//circular double linked list
	else if(pil == 2)
	{
		while(ptr!=preptr)
		{
			printf("%d",ptr->data);
			if(ptr->next!=NULL)
				printf("-->");
			ptr=ptr->next;
		}
		printf("%d",ptr->data);
	}
}

struct list *insert (int jml_data)
{
	int i,datai;
	struct list *ptr,*preptr,*head;
	for (i=0;i<jml_data;i++)
	{
		fflush(stdin);
		preptr = ptr;
		if (i==0)
		{
			ptr = (struct list*) malloc(sizeof(struct list));
			printf("Data %d : ",i+1);
			scanf("%d",&datai);
			ptr->data = datai;
			ptr->next = NULL;
			ptr->before = NULL;
			head = ptr;
		}
		else
		{
			ptr = ptr->next;
			ptr = (struct list*) malloc(sizeof(struct list));
			printf("Data %d : ",i+1);
			scanf("%d",&datai);
			ptr->data = datai;
			preptr->next = ptr;
			ptr->next = NULL;
			ptr->before = preptr;
		}
	}
	return head;
}
