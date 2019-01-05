#include <iostream>

using namespace std;

#define x 10
int A[x][x];
int k,i,p,m;
int a,b;


void main()
{
	randomize();
	setlocale(LC_ALL,"rus");
	Color(0,15);
	cout<<"Практическая работа. ТЕМА: Диагональ Матрицы. \n";
	Color(15,0);
	cout<<"автор: Моренко А.А.\n\n\n";
	
	a=40;
	b=90;
	for(k=0;k<x;k++)
	{
		for(i=0;i<x;i++)
		{
			A[k][i]=a+rand()%(b-a+1);
			printf("%4i",A[k][i]);
		}
		cout<<endl;
	}

	for(k=0;k<x;k++)
	{
		for(i=0;i<x;i++)
		{
			if(A[i][i]<A[i+1][i+1])
			{
				p=A[i][i];
				A[i][i]=A[i+1][i+1];
				A[i+1][i+1]=p;
			}
		}
	}

	cout<<"\n\n";
	for(k=0;k<x;k++)
	{
		for(i=0;i<x;i++)
		{
			printf("%4i",A[k][i]);
		}
		cout<<endl;
	}

	cout<<endl<<endl;
	system("pause");
}
----------------------------------------------------------------
#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int n,m;
char z[256];

fstream inf,otf;

void main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL,"rus");

	inf.open("data.txt",ios::in);
	if(!inf) return;
	otf.open("res.txt",ios::out);
	if(!otf) return;

	
	while(!inf.eof())
	{
		inf>>n;
		cout<<endl<<"\tдесятичное число A10= "<<n<< endl;
		int i=0;
		while(n>0)
		{
			m=n%8;
			n=n/8;

			switch(m)
			{
			case 0: z[i]='0'; break;
			case 1: z[i]='1'; break;
			case 2: z[i]='2'; break;
			case 3: z[i]='3'; break;
			case 4: z[i]='4'; break;
			case 5: z[i]='5'; break;
			case 6: z[i]='6'; break;
			case 7: z[i]='7'; break;
			}
			i++;
		}
		
		cout<<endl<<endl<<"\t\tвосьмеричное число A8= ";
		
		for(i=strlen(z)-1;i;i--)
		{
			cout<<z[i];
			otf<<z[i];

		}
		cout<<z[0]<<endl;
		otf<<z[0]<<endl;
		
		for(int k=0;k<=255;k++) z[k]=*"";
		cout<<endl;
	}

	otf.flush();
	otf.close();
	inf.close();
	
	cout<<endl<<endl<<endl;

	system("pause");

}

--------------------------------------
#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int n,m;
char z[256];

fstream inf,otf;

void main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL,"rus");

	inf.open("data.txt",ios::in);
	if(!inf) return;
	otf.open("res.txt",ios::out);
	if(!otf) return;



    int number = 0;
    char octa[80];
    int mult = 1;


	while(!inf.eof())
	{
	inf>>octa;
	 cout<<endl<<endl<<"\t восьмеричное число A8= "<<octa<<endl;
    for(int i = strlen(octa); i; i--, mult *= 8)
    {
         if(octa[i-1] != '0') number += mult*((int)octa[i-1]-'0');
    }
    
	cout<<endl<<endl<<"\t\tдесятичное число A10= "<< number << endl;
    otf<<number<<endl;

	mult=1;
	number=0;
	}

	otf.flush();
	otf.close();
	inf.close();
	cout<<endl<<endl<<endl;
	

	 system("pause");

}


-------------------------------------

#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int n,m;
char z[256];

fstream inf,otf;

void main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL,"rus");

	inf.open("data.txt",ios::in);
	if(!inf) return;
	otf.open("res.txt",ios::out);
	if(!otf) return;

	
	while(!inf.eof())
	{
		inf>>n;
		cout<<endl<<"\tдесятичное число A10= "<<n<< endl;
		int i=0;
		while(n>0)
		{
			m=n%2;
			n=n/2;
			if(m==1) z[i]='1';else z[i]='0';
			i++;
		}
		
		cout<<endl<<endl<<"\t\tдвоичное число A2= ";
		
		for(i=strlen(z)-1;i;i--)
		{
			cout<<z[i];
			otf<<z[i];

		}
		cout<<z[0]<<endl;
		otf<<z[0]<<endl;
		
		for(int k=0;k<=255;k++) z[k]=*"";
		cout<<endl;
	}

	otf.flush();
	otf.close();
	inf.close();
	
	cout<<endl<<endl<<endl;

	system("pause");

}

--------------------------------------------

#include <time.h>
#include <math.h>
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

int n,m;
char z[256];

fstream inf,otf;

void main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL,"rus");

	inf.open("data.txt",ios::in);
	if(!inf) return;
	otf.open("res.txt",ios::out);
	if(!otf) return;



    int number = 0;
    char binary[80];
    int mult = 1;


	while(!inf.eof())
	{
	inf>>binary;
	 cout<<endl<<endl<<"\t двоичное число A2= "<<binary<<endl;
    for(int i = strlen(binary); i; i--, mult *= 2)
    {
         if(binary[i-1] == '1') number += mult;
         else if(binary[i-1] != '0')
         {
             cout << "error" << endl;
             exit(1);
         }
     }
    
	cout<<endl<<endl<<"\t\tдесятичное число A10= "<< number << endl;
    otf<<number<<endl;

	mult=1;
	number=0;
	}

	otf.flush();
	otf.close();
	inf.close();
	cout<<endl<<endl<<endl;
	

	 system("pause");

}

-------------------------------------------

#include <iostream>
#include <fstream>

using namespace std;

int a [15] [15];
int i,j,n,m,k;
fstream inf;
int s[15];

void main()

{
	setlocale (LC_ALL,"rus");
	inf.open("data.txt", ios::in);
	if(!inf) return;
	
	inf>>n;
	
	for (i=0;  i<n; i++)
	{
		for(j=0; j<n;j++)
		{
			inf>>a[i][j];
			cout<<" "<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;

	inf.close();

	int p;
	for(p=0;p<(2*n+2);p++) s[p]=0;

	for(p=0;p<2*n;p++)
	{
		for(k=0;k<n;k++)
		{
			if(p<n) s[p]+=a[k][p]; else s[p]+=a[p][k];
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)s[p]+=a[i][j];
			if(i==(n-j))s[p+1]+=a[i][j];
		}
	}

	for(k=0;k<(2*n+2);k++) cout<<k+1<<" -> "<<s[k]<<endl;

	cout<<endl<<endl;		
	system("pause");
}


--------------------------------------
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


fstream inf;
string t,z;
char LL;
int i,j,k,p,s;

void main()
{
	setlocale(LC_ALL,"rus");
 
	inf.open("OS_W.txt",ios::in);
	if(!inf) return;
	
	s=p=0;
	while(!inf.eof())
	{
		getline(inf,t);
		
		z=t;
		z+="\n";
		k=z.size();
		for(i=0;i<k;i++)
		{
			if((z[i]==' ')||(z[i]=='\n')) s++;
			if(z[i]==(char)151) p++;
		}

		cout<<z;
	}

	cout<<endl<<endl<<"слов: "<<s-p<<endl<<endl;
	inf.close();
	system("pause");
}

--------------------------------------

#include <iostream>

using namespace std;

int k,i,j,p,m,n,a,b;

void main()
{
	setlocale(LC_ALL,"rus");
	cout<<"Практическая работа. ТЕМА: ЗМЕЙКА ЦИФР. \n";
	cout<<"автор: МОРЕНКО А.А.\n\n\n";
	
	m=7;
	n=10;
	
	for(k=1;k<=m;k++)
	{
		p=k;
		for(i=1;i<=n;i++)
		{
			if(i%2!=0) printf("%4i",p+(i-1)*m);
			else printf("%4i",i*m-p+1);
		}
		cout<<endl;
	}


	cout<<endl<<endl;
	system("pause");
}


