#include<iostream>
#include<string.h>
using namespace std;
int l4;
int values[10];
char letters[10];

void assign(char str[])
{
	int i,j,l;
	l=strlen(str);
	for(i=0;i<l;i++) 
	{
		for(j=l4-1;j>=0;j--)
		{
			if(letters[j]==str[i])
				break;
		}
		if(j==-1)
		{
			letters[l4]=str[i];
			l4++;
		}
	}
}

int pos(char str[], char x)
{
	int i,l;
	l=strlen(str);
	for(i=0;i<l;i++)
	{
		if(str[i]==x)
			return i;
	}
}

void findnext()
{
	int i=l4-1;
	values[i]++;
	while(values[i]==10)
	{
		values[i]=0;
		i--;
		values[i]++;
	}
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return n*fact(n-1);	
}

int perm(int n, int r)
{
	return fact(n)/fact(n-r);
}

int main()
{
	int i,j,k,n1,n2,n3,l1,l2,l3,p,sol=0,tries;
	char w1[20],w2[20],w3[20];
	
	cout<<"enter the words: \n";
	gets(w1);
	cout<<"+";
	gets(w2);
	cout<<"=";
	gets(w3);
	
	l1=strlen(w1); l2=strlen(w2); l3=strlen(w3); l4=0;
	assign(w1); assign(w2); assign(w3);
	
	if(l4>10)
	{
		cout<<"Input is wrong try again.";
		return 0;
	}
	cout<<letters;
	
	for(i=0;i<l4;i++)
		values[i]=0;
		
	p=0;
	tries=perm(10,l4);
	for(i=1;i<=tries;i++)
	{
		findnext();
		for(j=0;j<l4;j++)
		{
			for(k=j+1;k<l4;k++)
			{
				if(values[j]==values[k])
				{
					findnext();
					j=-1;
					break;
				}
			}
		}
		n1=0; n2=0; n3=0;
		for(j=0;j<l1;j++)
			n1=(n1*10)+values[pos(letters,w1[j])];
		for(j=0;j<l2;j++)
			n2=(n2*10)+values[pos(letters,w2[j])];
		for(j=0;j<l3;j++)
			n3=(n3*10)+values[pos(letters,w3[j])];	
			
		if(n1+n2==n3)
		{
			sol++;
			cout<<"\n\nSolution "<<sol<<" found in "<<i<<" tries\n\n";
			for(j=0;j<l4;j++)
			{
				cout<<letters[j]<<"="<<values[j]<<"\n";
			}
		}
		if(i==tries)
		{
			if(sol==0)
				cout<<"\n\nNo solution found";
			else
				cout<<"\n"<<sol<<" solutions found";	
		}
	}	
	return 0;
}
