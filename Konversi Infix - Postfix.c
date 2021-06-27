#include <stdio.h>
#include <conio.h>
#define ukuran 100
int top=-1;
char stack[ukuran];

//fungsi push
void push(char )
{
	if(top>=ukuran-1)
	{
		printf ("Stack Penuh");
		return;
	}

	else
	{
		top++;
		stack[top]=item;
	}
}
//funsi pop
char pop()
{
	char item;
	item=stack[top];
	top--;
	return (item);
}
//fungsi untuk operator yang digunakan
int cek_operator(char simbol)
{
	if(simbol=='^'||simbol=='/'||simbol=='*'||simbol=='+'||simbol=='-')
		return 1;
	else
		return 0;
}
//fungsi prioritas operator
int prioritas(char simbol)
{
	if(simbol=='^')
		return 3;
	else if(simbol=='*' || simbol=='/')
		return 2;
	else if(simbol=='+' || simbol=='-')
		return 1;
    else
    	return 0;
}
int main()
{
	char infix[ukuran],postfix[ukuran],temp,item;
	int i=0,j=0;

	printf ("Masukan Nilai Infix : ");
	gets(infix);

	//Kondisi pengecekan karakter

	while (infix[i]!='\0')
	{
		item = infix[i];
		//untuk operator ( langsung di push ke stack
		if(item=='(')
		{
			push(item);
		}
		//untuk operand diletakkan langsung di postfix
		else if (item>='A' && item<='Z'|| item>='a' && item<='z')
		{
			postfix[j] = item;
			j++;
		}
		else if (cek_operator(item)==1)
		{
			temp=pop();
			while(cek_operator(temp)==1 && prioritas(temp)>=prioritas(item))
		 	{
		 		postfix[j] = temp;
		 		j++;
		 		temp=pop();
			}
			push(temp);
			push(item);

		}
		else if(item==')')
		{
			temp=pop();
			while(temp!='(')
			{
				postfix[j] = temp;
				j++;
				temp=pop();
			}
		}
		else
		{
			printf ("\nData yang anda masukan salah \n");
			getch();

		}
	i++;
	}
	while(top>-1)
	{
		postfix[j] = pop();
		j++;
	}
	postfix[j]='\0';
	printf ("Hasil infix ke postfix adalah : ");
	puts(postfix);
	return 0;
}
