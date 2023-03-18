#include <iostream>
#include <windows.h>
void starter(char [8][8]);
void player(char [8][8],int,int,char);
void print(char [8][8]);
int winner(char [8][8]);
int per(char [8][8]);
int per2(char [8][8]);
void point(char [8][8]);
using namespace std;
int main()
{
	char a[8][8],b[8][8],c='O',undo;
	int n,m;
	starter(a);
	for(;;)
	{
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
				b[i][j]=a[i][j];
		if(per(a)==1)
		{
			if(per2(a)==-1)
				player(a,n,m,c);
			else
			{
				if(per2(a)==1)
					cout<<"the winner is player 1"<<endl;
				if(per2(a)==0)
					cout<<"the winner is player 2"<<endl;
				return 0;
			}
		}
		if(per(a)==0)
		{
			if(winner(a)==1)
			cout<<"the winner is player 1"<<endl;
			else
				cout<<"the winner is player 2"<<endl;
			system("pause");
			return 0;
		}
		cout<<"do you want to undo? (Y/N):";
		cin>>undo;
		system("cls");
		print(a);
		if(undo=='y')
		{
			for(int i=0;i<8;i++)
				for(int j=0;j<8;j++)
					a[i][j]=b[i][j];
			system("cls");
			print(a);
			if(c=='X')
				c='O';
			else
				c='X';
		}
		if(c=='X')
			c='O';
		else
			c='X';
	}
}
void starter(char a[8][8])
{
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if((i==4 && j==4)||(i==3 && j==3))
				a[i][j]='X';
			else if((i==3 && j==4)||(i==4 && j==3))
				a[i][j]='O';
			else
				a[i][j]='-';
	print(a);
}
void player(char a[8][8],int n,int m,char c)
{
	if(c=='O')
		cout<<"player 1(O):"<<endl;
	else
		cout<<"player 2(X):"<<endl;
	cout<<"row:";
	cin>>n;
	cout<<"column:";
	cin>>m;
	if(a[n][m]=='-')
	{
		if(m!=0)
		{
			int i,j;
			for(j=m-1;a[n][j]!=c;j--)
				if(a[n][j]=='-')
					break;
			if(a[n][j]==c)
				for(j=m-1;a[n][j]!=c;j--)
					a[n][j]=a[n][m]=c;
		}
		if(m!=7)
		{
			int i,j;
			for(j=m+1;a[n][j]!=c;j++)
				if(a[n][j]=='-')
					break;	
			if(a[n][j]==c)
				for(j=m+1;a[n][j]!=c;j++)
					a[n][j]=a[n][m]=c;
		}
		if(n!=0)
		{
			int i,j;
			for(i=n-1;a[i][m]!=c;i--)
				if(a[i][m]=='-')
					break;	
			if(a[i][m]==c)
				for(i=n-1;a[i][m]!=c;i--)
					a[i][m]=a[n][m]=c;
		}
		if(n!=7)
		{
			int i,j;
			for(i=n+1;a[i][m]!=c;i++)
				if(a[i][m]=='-')
					break;	
			if(a[i][m]==c)
				for(i=n+1;a[i][m]!=c;i++)
					a[i][m]=a[n][m]=c;
		}
		if(n!=0)
		{
			int i,j;
			for(i=n-1,j=m-1;a[i][j]!=c;i--,j--)
				if(a[i][j]=='-')
					break;	
			if(a[i][j]==c)
				for(i=n-1,j=m-1;a[i][j]!=c;i--,j--)
					a[i][j]=a[n][m]=c;
		}
		if(n!=7)
		{
			int i,j;
			for(i=n+1,j=m+1;a[i][j]!=c;i++,j++)
				if(a[i][j]=='-')
					break;	
			if(a[i][j]==c)
				for(i=n+1,j=m+1;a[i][j]!=c;i++,j++)
					a[i][j]=a[n][m]=c;
		}
		if(n!=0)
		{
			int i,j;
			for(i=n-1,j=m+1;a[i][j]!=c;i--,j++)
				if(a[i][j]=='-')
					break;	
			if(a[i][j]==c)
				for(i=n-1,j=m+1;a[i][j]!=c;i--,j++)
					a[i][j]=a[n][m]=c;
		}
		if(n!=7)
		{
			int i,j;
			for(i=n+1,j=m-1;a[i][j]!=c;i++,j--)
				if(a[i][j]=='-')
					break;	
			if(a[i][j]==c)
				for(i=n+1,j=m-1;a[i][j]!=c;i++,j--)
					a[i][j]=a[n][m]=c;
		}
	}	
	else
	{
		system("cls");
		print(a);
		cout<<"XXX WRONG MOVE XXX"<<endl;
		player(a,n,m,c);
	}
	if(a[n][m]=='-')
	{
		system("cls");
		print(a);
		cout<<"XXX WRONG MOVE XXX"<<endl;
		player(a,n,m,c);
	}
	system("cls");
	print(a);
}
void print(char a[8][8])
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout<<"   ";
	for(int i=0;i<8;i++)
		cout<<i<<"  ";
	cout<<endl;
	for(int i=0;i<8;i++)
	{
		SetConsoleTextAttribute(h, 0x07);
		cout<<i<<' ';
		for(int j=0;j<8;j++)
		{
			if((i+j)%2==0)
				SetConsoleTextAttribute(h, 0x37);
			else
				SetConsoleTextAttribute(h, 0x47);
			cout<<' '<<a[i][j]<<' ';
			SetConsoleTextAttribute(h, 0x07);
		}
		cout<<endl<<endl;
	}
	point(a);
}
int winner(char a[8][8])
{
	int i,j,n=0,m=0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(a[i][j]=='X')
				n++;
			else
				m++;
	if(n==0)
		return 0;
	else if(m==0)
		return 1;
	else if(n>m)
		return 0;
	else
		return 1;
}
int per(char a[8][8])
{
	int i,j,x=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if(a[i][j]=='-')
				x++;
	if(x>=1)
		return 1;
	else
		return 0;
}
int per2(char a[8][8])
{
	int i,j,x=0,o=0;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			if(a[i][j]=='O')
				o++;
			else if(a[i][j]=='X')
				x++;
	if(x==0)
		return 1;
	else if(o==0)
		return 0;
	else
		return -1;
}
void point(char a[8][8])
{
	int i,j,x=0,o=0;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			if(a[i][j]=='O')
				o++;
			else if(a[i][j]=='X')
				x++;
	cout<<"player 1:"<<o<<' '<<char(15)<<' '<<"player 2:"<<x<<endl;
}
