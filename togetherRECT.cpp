#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<conio.h>
#include<math.h>
using namespace std;

void predefined()
{   fstream f1;
	f1.open("Rect.asm");
	string a;
	int i=1,h,pos,k,m;
	while(!f1.eof())
	{pos=f1.tellg();
	getline(f1,a);
	m=a.size();
	h=0;
	while(a[h]==' ')
	h++;
	if(a[h]=='@')
	{i=1+h;
	//cout<<a[i]<<"A{I"<<endl;
	if(a[i]=='R')
			{ 
				if((a[i+2]=='\0'||a[i+3]=='\0')||(a[i+2]==' '||a[i+3]==' '))
			    switch(a[i+1])
				{   
					case '0':
						{a[i]='0'; a[i+1]='\0';break;}
				    case '1':
				    {
					if(a[i+2]=='\0')
					{a[i]='1'; a[i+1]='\0';}
					else
					{
						switch(a[i+2])
						{       case '0':
							    {a[i]='1'; a[i+1]='0';a[i+2]='\0';break;}
						        case '1':
							    {a[i]='1'; a[i+1]='1';a[i+2]='\0';break;}
								case '2':
							    {a[i]='1'; a[i+1]='2';a[i+2]='\0';break;}
							    case '3':
							    {a[i]='1'; a[i+1]='3';a[i+2]='\0';break;}
							    case '4':
							    {a[i]='1'; a[i+1]='4';a[i+2]='\0';break;}
							    case '5':
							    {a[i]='1'; a[i+1]='5';a[i+2]='\0';break;}
						}
					}
					break;}	
				    case '2':
				    {a[i]='2'; a[i+1]='\0';break;}
				    case '3':
				    {a[i]='3'; a[i+1]='\0';break;}
				    case '4':
				    {a[i]='4'; a[i+1]='\0';break;}
				    case '5':
				    {a[i]='5'; a[i+1]='\0';break;}
				    case '6':
				    {a[i]='6'; a[i+1]='\0';break;}
				    case '7':
				    {a[i]='7'; a[i+1]='\0';break;}
				    case '8':
				    {a[i]='8'; a[i+1]='\0';break;}
				    case '9':
				    {a[i]='9'; a[i+1]='\0';break;}
				    
				}
			}
	else
	{
			if((a[i]=='S')&&(a[i+1]=='P'))
			{a[i]='0';a[i+1]='\0';}
			else 
			{
			if((a[i]=='L')&&a[i+1]=='C'&&a[i+2]=='L')
			     {a[i]='1';a[i+1]='\0';}
			else {
				 if((a[i]=='A')&&a[i+1]=='R'&&a[i+2]=='G')
			           {a[i]='2';a[i+1]='\0';}
			          else {
					  if((a[i]=='T')&&(a[i+1]=='H'))
		                   	{cout<<"ho"<<endl;
							if((a[i+2]=='I')&&(a[i+3]=='S'))
							{a[i]='3';a[i+1]='\0';}
							if((a[i+2]=='A')&&(a[i+3]=='T'))
							{a[i]='4';a[i+1]='\0';}
							}
		                  	}}
       }
       if(a.compare(i,6,"SCREEN")==0)
       {a[i]='1';a[i+1]='6';a[i+2]='3';a[i+3]='8';a[i+4]='4';a[i+5]='\0';
	   }
	   if(a.compare(i,3,"KBD")==0)
       {a[i]='2';a[i+1]='4';a[i+2]='5';a[i+3]='7';a[i+4]='6';a[i+5]='\0';
	   }
   }
  
}
k=0+h;
while(a[k]!='\0')
k++;
i=k;
while((i<m)&&(a[i]!='/'))
{a[i]='\0';i++;}
f1.seekp(pos);
f1<<a;
if(f1)
f1<<endl;cout<<"a:"<<a<<endl;
//f1<<a<<endl;

  /* k=0+h;
   while(k<m)
   { f1<<'\0';k++;
   }
   k=0+h;
   f1.seekp(pos);
   while(a[k]!='\0')
   {f1<<a[k];k++;}
  pos=pos+ m;
  f1.seekg(pos);  */
 }
//k=0+h;
/*while(a[k]!='\0')
k++;
i=k;
while((i<m)&&(a[i]!='/'))
{a[i]='\0';i++;}*/

 
 f1.close();  
}

int dlabel()
{
	fstream f;
	int c=0,k;
	f.open("Rect.asm");
	string a;
	while(!f.eof())
	{   k=0;
		getline(f,a);
		while((a[k]!='(') && (a[k]!='\0') &&(a[k]!='/'))
		k++;
		if(a[k]=='(')
		c++;
	}
	f.close();
	return c;
}


int comdef(string x)
{   int i,f=0;
	string a[16];
	a[0]="0";
	a[1]="1";
	a[2]="2";
	a[3]="3";
	a[4]="4";
	a[5]="5";
	a[6]="6";
	a[7]="7";
	a[8]="8";
	a[9]="9";
	a[10]="10";
	a[11]="11";
	a[12]="12";
	a[13]="13";
	a[14]="14";
	a[15]="15";
	for(i=0;i<16;i++)
	{
		if(x.compare(a[i])==0)
		{f=1;break;
		}
	}
	return f;
}

int already(string x)
{    int i,f=0,j;
    
	string alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i=0;j=0;
	while((x[i]!='\0')&&(f==0))
	{
		for(j=0;j<52;j++)
		{if(x[i]==alpha[j])
		{
			f=1;
			break;
		}
	    }
	    
	    i++;
	}
	return f;
}

void search(string t[],int arr[],int n,int zen[],string all[],int n1)
{ cout<<"SEARCH";   
int i,j,find[n1][2],count=0,x,y,f,m,mn;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n1;j++)
		if(t[i].compare(all[j])==0)
		{    cout<<"COMP:"<<all[j]<<endl;
			find[count][0]=j;
			find[count][1]=i;
			count++;
		}	
	}cout<<"HII"<<endl;cout<<count<<endl;
	int c[count],d[count],flag,pole;
	for(i=0;i<count;i++)
	{//cout<<"G"<<endl;
	x=find[i][0];c[i]=zen[x];cout<<"c:"<<c[i]<<endl;cout<<"find:"<<find[i][0]<<endl;
	y=find[i][1];d[i]=arr[y];cout<<"d:"<<d[i]<<endl;
	}cout<<"out"<<endl;
	   int rtn,s=0,q,dk,rt;
	   string symbol[n1];
		for(i=0;i<n1;i++)
		{     pole=0;cout<<"in"<<endl;
			  for(j=0;j<count;j++)
			  {if(find[j][0]==i)
			  {pole=1;cout<<"II:"<<find[j][0]<<endl;break;}
			  }
			  if(pole==0)
			  { cout<<"i:"<<i<<endl;
			  	rtn=comdef(all[i]);cout<<"R1:"<<rtn<<endl;
			  	rt=already(all[i]);cout<<"R@:"<<rt<<endl;
			  	  if((rtn==0)&&(rt==1))
			  	  {cout<<"SUC"<<endl;
					if(s==0)
					{symbol[s]=all[i];s++;cout<<s<<"KKKKKK"<<endl;cout<<all[i]<<endl;cout<<symbol[s-1]<<endl;
					}
					else
					{  dk=1;
					    for(q=0;q<s;q++)
						{if(all[i].compare(symbol[q])==0)
						  {dk=0;break;}
						}
						if(dk==1)
						{
						symbol[s]=all[i];
						s++; cout<<"SYMQ:"<<symbol[s-1]<<endl;
						}
					}
					
				  }
			  	  
			  }
	    }
	for(i=0;i<s;i++)
	cout<<"SYM:"<<symbol[i]<<endl;
	string a1,a2; int symvalue,k,g,h;
	fstream f1,f2;
	f1.open("Rect.asm");
	f2.open("temporary.asm",ios::out);
	i=0;f=0;
	while(!f1.eof())
	{ flag=0;
	i++;
	getline(f1,a1);
		for(f=0;f<count;f++)
		{if(i==c[f])
		 {flag=1;
		 f2<<'@'<<d[f]<<endl;break;}
		}
		if(flag==0)
		{   k=0;
	           while((a1[k]!='@')&&(a1[k]!='\0'))
	           k++;
	           if(a1[k]=='@')
    	      {  k++;
			     g=k;h=0;
			     while((a1[g]!='\0')&&(a1[g]!=' ') && (a1[g]!='/'))
		        {  h++;g++;}
			      a2=a1.substr(k,h);
			
		      }
		      else
		      a2='\0';
			for(f=0;f<s;f++)
			{  symvalue=16+f;
			   if(a2.compare(symbol[f])==0)
		    	{flag=1;
				f2<<'@'<<symvalue<<endl;break;
				}
			}
		}
	if(flag==0)
	f2<<a1<<endl;
	}
	f1.close();
	f2.close();
	remove("Rect.asm");
	rename("temporary.asm","Rect.asm");
}



void label(string t[],int arr[],int num)
{   int i=-1,k,h=0,c=0,z=0,g,j; 
	fstream f;
	string x;
	//int u=0;
	f.open("Rect.asm");
	string a;
	while(!f.eof())
	{ 
     getline(f,a);
     k=0;
     while((a[k]!='@')&&(a[k]!='\0'))
     k++;
     if(a[k]=='@')
     z=1;
     if(z==1)
     i++;
     k=0;
     while((a[k]!='(') && (a[k]!='\0') &&(a[k]!='/'))
     k++;
	     if(a[k]=='(')
	     {  
	     	h=0;
	     	k++;g=k;
	     	while((a[g]!='\0')&&(a[g]!=')') && (a[g]!='/'))
	     	{   
	     	h++;g++;
			 }
			 if(a[g]==')')
			{x=a.substr(k,h);
			cout<<"Xsearch:"<<x<<endl;
			 t[c]=a.substr(k,h);
			 arr[c]=i;
			 i=i-1;
			 for(h=0;h<=c;h++)
			 cout<<"T{top}:"<<t[h]<<" "<<arr[h]<<endl;
			 c++;
		}
		 }
	 
     
	}
	f.close();

}


void append()
{
	fstream f;
	f.open("Rect.asm",ios::app);
	f<<endl<<"//rough\0";
	f.close();
}
int atnum()
{  cout<<"ATNUM!!!!!!!!"<<endl;
    fstream f;
	f.open("Rect.asm");
	string a;int k,c=0,count=0;
	while(!f.eof())
	{   c++; 
	getline(f,a);
	k=0;
	while((a[k]!='@')&&(a[k]!='\0'))
	k++;
    	if(a[k]=='@')
    	{count++;cout<<"Aaaa:"<<a<<endl;}
	
	}
	f.close();
	return count;
}

int at(int zen[],string all[])
{
	fstream f;
	f.open("Rect.asm");
	string a;int k,c=0,num=0,g,h,z=0;cout<<"INALL"<<endl;
	while(!f.eof())
	{   c++;
	getline(f,a);
	k=0;
	while((a[k]!='@')&&(a[k]!='\0'))
    k++;
    	if(a[k]=='@')
    	{ zen[num]=c;
    	  num++;
    	  k++;
			g=k;h=0;
			while((a[g]!='\0')&&(a[g]!=' ') && (a[g]!='/'))
		     {h++;g++;}
			all[z]=a.substr(k,h);
			cout<<"IN:"<<all[z]<<endl;
			z++;
		}
		
	
	}
	f.close();
}

void dtob(int b[],int num)
{
	int i;
	
	
	for(i=15;i>=0;i--)
	{  if(num>0)
		{
		b[i]=num%2;
		num=num/2;
	    }
	    else
	    b[i]=0;
	    
	}
	//return(*a);
}

int con(char a)
{ int c;
 switch(a)
 {
 	case '1':
 		{c=1;break;
		 }
	case '2':
 		{c=2;break;
		 }
	case '3':
 		{c=3;break;
		 }
	case '4':
 		{c=4;break;
		 }
	case '5':
 		{c=5;break;
		 }
	case '6':
 		{c=6;break;
		 }
	case '7':
 		{c=7;break;
		 }
	case '8':
 		{c=8;break;
		 }
	case '9':
 		{c=9;break;
		 }
	case '0':
 		{c=0;break;
		 }		 
 }
 return c;	
}

int dest(string a,int b[])
{ int w=0;
int k=0;
while(a[k]==' ')
k++;
  b[10]=0;b[11]=0;b[12]=0;
  if(a[k+1]==';')
  w=1;
   if(a[k+1]!=';')
	{
	switch(a[k])
		{   case '0':
			    {b[10]=0;b[11]=0;b[12]=0;w=1;
			    break;}				
			case 'M':
				{ b[10]=0; b[11]=0; b[12]=1;w=1;
	     		break;}
			case 'D':
				{ b[10]=0; b[11]=1; b[12]=0;w=1;
	     		break;}
			case 'A':
				{ b[10]=1; b[11]=0; b[12]=0;w=1;
	     		break;}	
		}
	}
		
	if(a[k+1]!='=')
	{   switch(a[k+1])
			{
			case 'D':
				{ b[11]=1;
	     		break;}
			case 'M':
				{ b[12]=1;
	     		break;}	
	       }
    if(a[k+2]!='\0')
    {   if(a[k+2]=='D')
    	b[11]=1;
	}
	
	}	
	return w;
}

void comp(string a,int b[])
{  int i=0,k,g,h;
h=0;
while(a[h]==' ')
h++;
i=i+h;
	while(a[i]!='='&&a[i]!='\0'&&a[i]!=';')
	{
	i++;cout<<"K"<<a[i]<<" ";}
	g=i;
	cout<<"I"<<i<<endl;
	if(a[i]=='\0')
	{ b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=0;b[9]=0;
	}
	
	if(a[i]=='=')
	{for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
	i=i+1;cout<<"IN"<<i<<endl;
	cout<<"A{I{"<<a[i]<<endl;
	switch(a[i])
	{
		case '0':
			{
				b[3]=0;b[4]=1;b[5]=0;b[6]=1;b[7]=0;b[8]=1;b[9]=0;
				break;
			}
		case '1':
			{
				b[3]=0;b[4]=1;b[5]=1;b[6]=1;b[7]=1;b[8]=1;b[9]=1;
				break;
			}
		case '-':
			{   if(a[i+1]=='1')
				{b[3]=0;b[4]=1;b[5]=1;b[6]=1;b[7]=0;b[8]=1;b[9]=0;}
				break;
			}	
		case 'D':
			{
				b[3]=0; b[4]=0; b[5]=0; b[6]=1; b[7]=1; b[8]=0; b[9]=0;
				cout<<"inside d"<<endl;
				for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
				break;
				
			}
		case 'A':
			{
				b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=0;b[9]=0;
				break;
			}
		case 'M':
			{
				b[3]=1;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=0;b[9]=0;
				break;
			}			
	}
	cout<<"!"<<endl;
	for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
	if(a[i+1]!='\0')
	{
	if(a[i]=='!')
	   {
			switch(a[i+1])
			{
			case 'D':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=1;b[7]=1;b[8]=0;b[9]=1;
					break;
				}
			case 'A':
				{
					b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=0;b[9]=1;
					break;
				}
			case 'M':
				{
					b[3]=1;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=0;b[9]=1;
					break;
				}				
			}
		}
	if(a[i]=='-')
	    {
	  	switch(a[i+1])
			{
			case 'D':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=1;b[7]=1;b[8]=1;b[9]=1;
					break;
				}
			case 'A':
				{
					b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=1;
					break;
				}
			case 'M':
				{
					b[3]=1;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=1;
					break;
				}				
			}
	    }
	cout<<"2"<<endl;    
	for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
	cout<<a[i]<<"A{I"<<i<<endl;
	if((a[i+1]=='+')&&(a[i+2]=='1'))		
{
		switch(a[i])
			{
			case 'D':
				{   cout<<"IN D"<<endl;
					b[3]=0;b[4]=0;b[5]=1;b[6]=1;b[7]=1;b[8]=1;b[9]=1;
					break;
				}
			case 'A':
				{
					b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=1;b[8]=1;b[9]=1;
					break;
				}
			case 'M':
				{
					b[3]=1;b[4]=1;b[5]=1;b[6]=0;b[7]=1;b[8]=1;b[9]=1;
					break;
				}				
			}
			}
			cout<<"3"<<endl;
	for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
	if((a[i+1]=='-')&&(a[i+2]=='1'))		
	{
	switch(a[i])
			{
			case 'D':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=1;b[7]=1;b[8]=1;b[9]=0;
					break;
				}
			case 'A':
				{
					b[3]=0;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=0;
					break;
				}
			case 'M':
				{
					b[3]=1;b[4]=1;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=0;
					break;
				}				
			}		
   }
   
   if((a[i]=='D')&&(a[i+2]=='A') )
   {
   	switch(a[i+1])
			{
			case '+':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=1;b[9]=0;
					break;
				}
			case '-':
				{
					b[3]=0;b[4]=0;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=1;
					break;
				}
			case '&':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=0;b[9]=0;
					break;
				}		
			case '|':
				{
					b[3]=0;b[4]=0;b[5]=1;b[6]=0;b[7]=1;b[8]=0;b[9]=1;
					break;
				}					
			}		
   }
   
   if((a[i]=='D')&&(a[i+2]=='M'))
   {
   	switch(a[i+1])
			{
			case '+':
				{
					b[3]=1;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=1;b[9]=0;
					break;
				}
			case '-':
				{
					b[3]=1;b[4]=0;b[5]=1;b[6]=0;b[7]=0;b[8]=1;b[9]=1;
					break;
				}
			case '&':
				{
					b[3]=1;b[4]=0;b[5]=0;b[6]=0;b[7]=0;b[8]=0;b[9]=0;
					break;
				}		
			case '|':
				{
					b[3]=1;b[4]=0;b[5]=1;b[6]=0;b[7]=1;b[8]=0;b[9]=1;
					break;
				}					
			}		
   }

   
   if((a[i+1]=='-')&&(a[i+2]=='D'))
   {
   	switch(a[i])
   	{
   	         case 'A':
				{
					b[3]=0;b[4]=0;b[5]=0;b[6]=0;b[7]=1;b[8]=1;b[9]=1;
					break;
				}
			case 'M':
				{
					b[3]=1;b[4]=0;b[5]=0;b[6]=0;b[7]=1;b[8]=1;b[9]=1;
					break;
				}					
	   }
   }
   
   
}
}
if(a[i]==';'&&a[i+1]=='J')
   switch(a[i-1])
	{
		case '0':
			{
				b[3]=0;b[4]=1;b[5]=0;b[6]=1;b[7]=0;b[8]=1;b[9]=0;
				break;
			}
		case '1':
			{
				b[3]=0;b[4]=1;b[5]=1;b[6]=1;b[7]=1;b[8]=1;b[9]=1;
				break;
			}
		case '-':
			{   if(a[i+1]=='1')
				{b[3]=0;b[4]=1;b[5]=1;b[6]=1;b[7]=0;b[8]=1;b[9]=0;}
				break;
			}	
		case 'D':
			{
				b[3]=0; b[4]=0; b[5]=0; b[6]=1; b[7]=1; b[8]=0; b[9]=0;
				cout<<"inside d"<<endl;
				for(k=0;k<16;k++)
	cout<<b[k]<<" ";
	cout<<endl;
				break;
				
			}}
}

void jp(string a,int b[])
{ //cout<<"INDIDE JP FUNCTION 8888888888888888888888"<<endl;
  int i=0,h;
  h=0;
  while(a[h]==' ')
  h++;
  i=i+h;
	while(a[i]!=';'&&a[i]!='\0')
	i++;
	cout<<"I"<<i<<endl;
	if(a[i]=='\0')
	{ b[13]=0;b[14]=0;b[15]=0;
	}	
	else
	{  
	if(a.compare(i+1,3,"JGT")==0)
    {b[13]=0;b[14]=0;b[15]=1;}
	if(a.compare(i+1,3,"JEQ")==0)
	{b[13]=0;b[14]=1;b[15]=0;}
	if(a.compare(i+1,3,"JGE")==0)
	{b[13]=0;b[14]=1;b[15]=1;}
	if(a.compare(i+1,3,"JLT")==0)
	{b[13]=1;b[14]=0;b[15]=0;}
	if(a.compare(i+1,3,"JNE")==0)
	{b[13]=1;b[14]=0;b[15]=1;}
	if(a.compare(i+1,3,"JLE")==0)
	{b[13]=1;b[14]=1;b[15]=0;}
	if(a.compare(i+1,3,"JMP")==0)
	{b[13]=1;b[14]=1;b[15]=1;}
	}
	
}

void finalcreation()
{  string a;
int num,i,k,c,w=2,h;
int b[16];
	ifstream f1;
	ofstream f2;
	f2.open("Rect.hack");
	f1.open("Rect.asm");
	while(!f1.eof())
	{   getline(f1,a);
	h=0;
	while(a[h]==' ')
	h++;
		if(a[0+h]=='@')
			{i=0+h;num=0;
			while(a[i]!='\0')
	      	i++;
			for(k=1+h;k<(i);k++)
			{
			c=con(a[k]);
			num=num+(c*pow(10,i-k-1));
			}
		    dtob(b,num);
		    for(k=0;k<16;k++)
		    {f2<<b[k];}
	  	     f2<<endl;
			}
		else 
		{   
			for(i=0;i<3;i++)
			b[i]=1;
			w=dest(a,b);
			if(w==1)
		    {
			comp(a,b);
			jp(a,b);
			for(k=0;k<16;k++)
		    {f2<<b[k];}
	  	     f2<<endl;
		    
		    }
		
	    }
	}
	f2.close();
	f1.close();
	/*int b[16];
	int i;
	dtob(b,65534);
	for(i=0;i<=15;i++)
	cout<<b[i];*/
	//return 1;
}

int main()
{  int num,n1,i;
   append();
predefined();
num=dlabel();
  n1=atnum();
  int zen[n1];
  string all[n1];
  at(zen,all);
  cout<<"N!"<<n1<<endl;
  for(i=0;i<n1;i++)
  cout<<all[i]<<endl;
   int arr[num];
   string t[num];
   cout<<num<<endl;
   label(t,arr,num);
  search(t,arr,num,zen,all,n1);
  finalcreation();
  cout<<"END"<<endl;
	return 1;
}
