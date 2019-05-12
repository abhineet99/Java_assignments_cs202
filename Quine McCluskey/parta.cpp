#include<bits/stdc++.h>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;

vector<int> answer;
/*
char * var number of variables and index
n is number of variables

*/
void printanspos(int n)
{
	set <int>toprint;
	for(int i=0;i<pow(2,n);i++)
		toprint.insert(i);
	sort(answer.begin(),answer.end());
	answer.erase( unique( answer.begin(), answer.end() ), answer.end() );
	cout<<"m(";
	for(int i=0;i<answer.size();i++)
	{
		toprint.erase(answer[i]);
	}
	set <int> :: iterator itr;
    
    for (itr = toprint.begin(); itr != toprint.end(); ++itr)
    {
    	if(itr!=toprint.begin())
			cout << "," << *itr;
		else
			cout<<*itr;
    }
    //cout << endl;
	// for(int i=0;i<toprint.size();i++)
	// {
	// 	cout<<toprint[i];
	// 	if(i!=toprint.size()-1)
	// 		cout<<",";
	// }
	cout<<")"<<endl;
}
void printans(int n)
{
	sort(answer.begin(),answer.end());
	answer.erase( unique( answer.begin(), answer.end() ), answer.end() );
	cout<<"m(";
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i];
		if(i!=answer.size()-1)
			cout<<",";
	}
	cout<<")"<<endl;
}

void bitsetevaluator(int a[],int n)
{
	int flag=0;
	int i;
	for (i = 0; i < n; ++i)
	{
		if(a[i]==-1)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		int b[n];
		int c[n];
		for(int j=0;j<n;j++)
		{
			if(j==i)
			{
				b[j]=0;
				c[j]=1;
			}
			else
				b[j]=c[j]=a[j];
		}
		bitsetevaluator(b,n);
		bitsetevaluator(c,n);
	}
	else
	{
		bitset<100> lel;
		for(int j=0;j<n;j++)
		{
			lel[j]=a[j];
		}
		answer.push_back(lel.to_ulong());
	}
}
void passer(string input,string var,int n){
	int iArray[n];
	for(int i=0;i<n;i++){
		iArray[i]=-1;
	}
	int index=0;
	char c=input[index];
	int comp=0;
	while(index<input.length()){
		c=input[index];
		if(c!='\''){
			int i;
			int flag=0;
			for(i=0;i<n;i++)
			{
				if(c==var[i])
				{					
					flag=1;
					break;					
				}
			}

			if(flag==1)
			{	
				if(index+1<input.length()&&input[index+1]=='\'')
				{					
					iArray[i]=0;
				}
				else if(index+1==input.length()){
					iArray[i]=1;
				}
				else{
					iArray[i]=1;
				}				
			}
		}
		index++;
	}

	bitsetevaluator(iArray,n);
}
void passerpos(string input,string var,int n){
	int iArray[n];
	for(int i=0;i<n;i++){
		iArray[i]=-1;
	}
	int index=0;
	char c=input[index];
	int comp=0;
	while(index<input.length()){
		c=input[index];
		if(c!='\''){
			int i;
			int flag=0;
			for(i=0;i<n;i++)
			{
				if(c==var[i])
				{					
					flag=1;
					break;					
				}
			}

			if(flag==1)
			{	
				if(index+1<input.length()&&input[index+1]=='\'')
				{					
					iArray[i]=1;
				}
				else if(index+1==input.length()){
					iArray[i]=0;
				}
				else{
					iArray[i]=0;
				}				
			}
		}
		index++;
	}

	bitsetevaluator(iArray,n);
}
void posevaluator(string input,string var,int n)
{
	int index=0;
	char c=input[index];
	string tosend;
	int len=input.length();
	while(index<len)
	{
		while(c!=')'&&index<input.length())
		{
			tosend+=c;

			index++;
			if(index<len)
			c=input[index];
		}
		//cout<<tosend<<"ye hai tosend"<<endl;
		passerpos(tosend,var,n);
		tosend.clear();
		index++;
		if(index<len)
			c=input[index];

	}
}


void sopevaluator(string input,string var,int n)
{
	int index=0;
	char c=input[index];
	string tosend;
	string::iterator it;
	int len=input.length();
	while(index<len)
	{
		while(c!='+'&&index<input.length())
		{
			tosend+=c;
			index++;
			if(index<len)
			c=input[index];
		}
		passer(tosend,var,n);
		tosend.clear();
		index++;
		if(index<len)
			c=input[index];

	}
}

int main()

{	
	std::ofstream out1("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out1.rdbuf());
	
	int num_var,num_out;
	string inp;
	string out;
	ifstream myfile;
	int line_num=0;
	int x=0;
	FILE *fp = fopen("posinput.txt","r");
	string var;
    if (fp == NULL)
      cout<<"Couldn't open file!"<<endl;
  	else
  		{
 		
		    do
		    {
		    	if (feof(fp))
		            break ;
		        char c = fgetc(fp);
		        if (feof(fp))
		            break ;
		        string mainstring;
		        string mainstring2;
		        while(c!='\n'&&c!=EOF)
		        {
		        	if (feof(fp))
		            break ;
		        	if(x==0)
		        	{
		        		inp+=c;
		        	}
		        	else if(x==1)
		        	{
		        		out+=c;
		        	}
		        	else
		        	{
		        		mainstring+=c;
		        	}
		        	c = fgetc(fp);
		        	if (feof(fp))
		            break ;
		        }
		        if(x==0)
		       	{
		       	num_var=(inp.length()-6)/2;
		       	cout<<inp<<endl;
		       	for(int i=7;i<7+num_var*2-1;i=i+2)
		       		{
		       			var+=inp[i];		       			
		       		}
		    	}
		        else if(x==1)
		        {
		        num_out=(out.length()-6)/3; 
		    		}
 				else
 				{
 					int mainlen=mainstring.length();
 						for(int i=3;i<mainlen;i++)
 							mainstring2+=mainstring[i];
 					if(mainstring2[0]=='(')
 					{
 						posevaluator(mainstring2,var,num_var);
 						cout<<out[8+(x-2)*3]<<". = ";
 						printanspos(num_var);
 						answer.clear();
 					}
 					else
 					{
 						sopevaluator(mainstring2,var,num_var);
 						cout<<out[8+(x-2)*3]<<". = ";
 						printans(num_var);
 						answer.clear();
 					}
 					mainstring.clear();
 				}
		        x++;
		        if (feof(fp))
		            break ;
		    }  while(1);
		fclose(fp);
    	}
		return 0;

}