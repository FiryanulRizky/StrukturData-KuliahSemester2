#include <stdio.h>
#include <malloc.h>

struct data{
	int bil;
	struct data *next;
	struct data *prev;
};
struct data *temp,*head_temp,*head;
int count=0;

struct data *input_data(int bil, int list)
{
	if(list==0)
	{
		temp = (struct data*)malloc(sizeof(struct data));
		temp->next=NULL;
		temp->prev=NULL;
		temp->bil = bil;
		head_temp=temp;
		return temp;
	}
	else
	{
		temp=head_temp;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next = (struct data*)malloc(sizeof(struct data));
		temp->next->prev=temp;
		temp=temp->next;
		temp->bil=bil;
		temp->next=NULL;
	}
}

int main()
{
	int i,j,n,pil;
	printf("Ketik Jumlah List: ");
	scanf("%d",&n);
	int n_data,urut[n],bil,n_bil=0;
	struct data *id[n];
	for(i=0;i<n;i++)
	{
		printf("Input List %d\n",i+1);
		printf("Ketik Jumlah Data: ");scanf("%d",&n_data);
		for(j=0;j<n_data;j++)
		{
			printf("Data %d: ",j+1);scanf("%d",&bil);
			if(j==0)
			id[i] = input_data(bil,j);
			else
			input_data(bil,j);
			count++;
		}
	}
	printf("Ketik Urutan: ");
	for(i=0;i<n;i++)
	{
		
		scanf("%d",&urut[i]);
		urut[i] = urut[i]-1;
	}
	awal:printf("Menu:\n1. Double LL\n2. Circular Double LL\nPilihan: ");scanf("%d",&pil);
	head=id[urut[0]];
	switch(pil)
	{
		case 1:
			{
				for(i=0;i<n-1;i++)
				{
					temp = id[urut[i]];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next = id[urut[i+1]];
					temp->next->prev = temp;
				}
				temp = id[urut[0]];
				while(temp!=NULL)
				{
					printf("%d ",temp->bil);
					temp=temp->next;
				}
				break;
			}
		case 2:
			{
				for(i=0;i<n;i++)
				{
					if(i==n-1)
					{
						temp = id[urut[i]];
						while(temp->next!=NULL)
						{
							temp=temp->next;
						}
						temp->next=id[urut[0]];
						temp->next->prev = temp;
						goto print;
					}
					temp = id[urut[i]];
					while(temp->next!=NULL)
					{
						temp=temp->next;
					}
					temp->next = id[urut[i+1]];
					temp->next->prev = temp;
				}
				print:temp = head;
				do
				{
					printf("%d ",temp->bil);
					temp=temp->next;
				}while(temp!=head);
				break;
			}
		default:
			{
				printf("Pilihan Tidak Tersedia!\n");
				goto awal;
			}
	}
}
