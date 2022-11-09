#include<bits/stdc++.h>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool tie=false;
int row,col;
char token='x';
string n1="";
string n2="";
void functionone()
{
   cout<<"enter the ename of the player:\n";
   getline(cin,n1);
   cout<<"enter the name of the player two:\n";
   getline(cin,n2);
   cout<<n1<<" is the first player so he/she will play first"<<endl;
   cout<<n2<<" is the second player so he/she wil play second"<<endl;
   cout<<"    |   |  \n";
   cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"| "<<space[0][2]<<"\n";
   cout<< " __|___|__\n";
   cout<<"    |   |  \n";
   cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"| "<<space[1][2]<<"\n";
   cout<< " __|___|__\n";
   cout<<"    |   |  \n";
   cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"| "<<space[2][2]<<"\n";
   cout<<"    |   |  \n";
   
}
void functiontwo()
{
	int digit;
	if(token=='x')
	{
		cout<<n1<<"please enter"<<endl;
		cin>>digit;
	}
	else if(token=='o')
	{
		cout<<n2<<" please enter"<<endl;
		cin>>digit;
	}
	if(digit==1)
	{
	  row=0;
	  col=0;	
	}
	else if(digit==2)
	{
	  row=0;
	  col=1;	
	}
	else if(digit==3)
	{
	  row=0;
	  col=2;	
	}
	else if(digit==4)
	{
	  row=1;
	  col=0;	
	}
   else if(digit==5)
	{
	  row=1;
	  col=1;	
	}
   else if(digit==6)
	{
	  row=1;
	  col=2;	
	}
	else if(digit==7)
	{
	  row=2;
	  col=0;	
	}
	else if(digit==8)
	{
	  row=2;
	  col=1;	
	}
	else if(digit==9)
	{
	  row=2;
	  col=2;	
	}
	else if(digit<1||digit>9)
	{
		cout<<"invalid"<<endl;
	}
	if(token=='x'&&space[row][col]!='x'&&space[row][col]!='o')
	{
		space[row][col]='x';
		token='o';
	}
	else if(token=='o'&&space[row][col]!='x'&&space[row][col]!='o')
	{
		space[row][col]='o';
		token='x';
	}
	else
	{
		cout<<"There is no empty space"<<endl;
		functiontwo();
	}
	functionone();
}
bool functionthree()
{
	for(int i=0;i<3;i++)
	{
	   if(space[i][0]==space[i][1]&&space[i][0]==space[i][2]||space[0][i]==space[1][i]&&space[0][i]==space[2][i])
	   {
	   	return true;
		   }	
		   for(int i=0;i<3;i++)
		   {
		   	for(int j=0;j<3;j++)
		   	{
		   		if(space[i][j]!='x'&&space[i][j]!='o')
		   		{
		   			return false;
				   }
			   }
		   }
		tie=true;
		return true;
	}
}
int main()
{
    cout<<"enter the name of the two players"<<endl;
	cin>>n1;
	cin>>n2;
	while(!functionthree())
	{
		functionone();
		functiontwo();
		functionthree();
	}
		if(token=='x'&&tie==false)
		{
			cout<<n2<<" wins!!"<<endl;
			}	
		else if(token=='o'&&tie==false)
		{
			cout<<n1<<"wins!!"<<endl;
		}
		else
		{
			cout<<"it is a draw!"<<endl;
		}
	return 0;	
}
