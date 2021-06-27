#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ht{
	char identitas[300];
	struct ht *next;
}node;

node *hashTabel[10000];
int hashTabelSize = 10;

int identitashash(char identitas[])
{
	int c,s=0,i;
	for (i = 0; i<strlen(identitas);i++)
	{
		c = identitas[i];
		s = s + c;
	}
	return s;

}
void TampilanMenu(){
	printf ("\t\tOpen Hash Table\n");
	printf ("\tTambah Tekan Tombol	1\n");
	printf ("\tCari Tekan Tombol	2\n");
	printf ("\tHapus Tekan Tombol	3\n");
	printf ("\tTampil Tekan Tombol	4\n");
}
void TambahData()
{
	int ascii,key;
	node *n,*n1;
	printf ("Tambah Data...\n");
	n = (node *)malloc(sizeof(node));
	printf ("Masukan identitas : ");
	scanf ("%s",n->identitas);
	n->next = NULL;
	ascii = identitasToKey(n->identitas);
	key = ascii % hashTabelSize;
	if(hashTabel[key]==NULL)
	{
		hashTabel[key] = n;
	}
	else
	{
		for(n1=hashTabel[key];n1->next!=NULL;n1=n1->next);
		n1->next = n;
	}

}
int CariData (char Bidentitas[])
{
	int ascii = identitashash(Bidentitas);
	int key = ascii % hashTabelSize;
	node *n;
	for (n=hashTabel[key];n!=NULL;n = n->next)
	{
		if(strcmp(n->identitas,Bidentitas)==0 )
		{
			return key;
		}
		return 0;
	}
}
void TampilList(node *n)
{
		node *n1;
		for(n1=n;n1!=NULL;n1=n1->next)
		{
			printf (" %s",n1->identitas);
		}
}
void TampilData()
{
	int i;
	for (i = 0;i<hashTabelSize;i++)
	{
		printf ("\nHash Tabel [%d]: ",i);
		TampilList(hashTabel[i]);
	}
}
void HapusData(char Bidentitas[])
{
	printf ("Hapus Data...\n");
	int ascii = identitashash(Bidentitas);
	int key = ascii % hashTabelSize;
	node *n,*n1;
	if(strcmp(hashTabel[key]->identitas, Bidentitas)==0)
	{
		n = hashTabel[key];
		hashTabel[key] = hashTabel[key]->next;
		free(n);
		return;

	}
	for (n = hashTabel[key]; n->next!=NULL;n=n->next)
	{
		n1=n->next;
		if(strcmp(n1->identitas,Bidentitas)==0)
		{
			n->next = n1->next;
			free(n1);
			break;
		}
	}

}
int main()
{
	char Bidentitas[300];
	int key,count=1;
	TampilanMenu();
	printf ("\n");
	while((count==1) || (count==2) || (count==3) || (count==4))
	{
		if(count==1)
		{
			TambahData();
		}
		if(count==2)
		{
			printf ("Masukan identitas : ");scanf ("%s",Bidentitas);
			key=CariData(Bidentitas);
			if(key==0)
			{
				printf ("identitas Tidak Ada Dalam Record\n");
			}
			else
			{
				printf ("Data Ditemukan Pada HashTabel Key %d",key);
				TampilList(hashTabel[key]);
			}

		}
		if(count==3)
		{
			printf ("Masukan identitas : ");scanf ("%s",Bidentitas);
			key=CariData(Bidentitas);
			if(key == 0)
			{
				printf ("identitas Tidak Ada Dalam Record\n");
			}
			else
			{
				HapusData(Bidentitas);
			}
		}
		if(count==4)
		{
			TampilData();
		}
		printf ("\nMasukan Pilihan : ");scanf ("%d",&count);
	}

	return 0;
}
