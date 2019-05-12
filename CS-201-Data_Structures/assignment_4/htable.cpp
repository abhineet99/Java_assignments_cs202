#include<bits/stdc++.h>
#include<string>
#include"htable.h"
#include"entry.h"
#include<cmath>
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;



htable::htable(long long int max1)
{
	col=0;
	max=max1;
	obj1=new entry;
	obj1->setword("NULL123");
	myarray= new entry[max];
	for(long long int i=0;i<max;i++)
		myarray[i]=*obj1;
	size1=0;

}
void htable::setcomp(int comp12,int comp22)
{
	comp1=comp12;
	comp2=comp22;
}

unsigned long long int htable::hashfunc1(string s)
{
	//cout<<"uo";
	// ull a=0;
	// ull b =0;
	// ull i=0;
	// while(i<s.length())
	// {
	// 	if(i%2==1)
	// 	{
	// 		//cout<<"see a now "<<a<<endl;
	// 		a+=s[i]*(i+1);
	// 	}
	// 	else
	// 		b+=s[i]*(i+1);
	// 	i++;
	// }
	// int digits=0;
	// cout<<a<<'\t'<<b<<endl;
	// ll acopy=a;
	// while(acopy!=0)
	// {
	// 	acopy=acopy/10;
	// 	digits++;
	// }
	// ull ans=1;
	// while(digits--)
	// {
	// 	ans*=10;
	// }
	
	
	// cout<<ans*b+a<<endl;
	// //cout<<comp1<<'\t'<<comp2<<endl;
	// return ((comp1*ans*b+a)+comp2)%max;
	ull toret=0;
	int a=39;
	for(ll i=0;i<s.length();i++)
	{
		toret+=pow(a,i)*s[i];
	}
	//cout<<"uo";
	return (toret*comp1+comp2)%max;
	
}
long long int htable::hashfunc2(long long int k)
{
	return 13-(k%13); 
}
void htable::insert(string word,string meaning)
{
	//cout<<"lel";
	if(size1>=max)
	{
		cout<<"Table full! Not possible!"<<endl;
		return;
	}
	else
	{
	entry* obj= new entry;
	obj->setword(word);
	obj->setmeaning(meaning);
	ll hcode=hashfunc1(word);
	st.insert(hcode);
	//cout<<hcode<<endl;
	ll hcode2=hashfunc2(hcode);
	string test="NULL123";
	long long int i=1;
	ll nowindex=hcode;
	int flag=0;
	//cout<<"c4"<<endl
	while(test.compare(myarray[nowindex].getword()))
	{

		//cout<<hcode<<"see this"<<word<<endl;
		//cout<<myarray[nowindex].getword()<<endl;
		if(hcode!=809)
		col++;
		//cout<<myarray[nowindex].getword()<<endl;
		if(!word.compare(myarray[nowindex].getword()))
		{
			flag=1;
			break;
		}
		nowindex=(hcode+i*hcode2)%max;
		i++;
	}
	//cout<<"c5"<<endl;
	myarray[nowindex]=*obj;
	if(flag!=1)
		size1++;
	}
	//cout<<"c6"<<endl;
}
int htable::getcol()
	{
		return col;
	}
void htable::remove(string word)
{
	ll hcode=hashfunc1(word);
	ll hcode2=hashfunc2(hcode);
	string test="NULL123";
	long long int i=1;
	ll nowindex=hcode;
	int flag=0;
	while(test.compare(myarray[nowindex].getword()))
	{
		if(!word.compare(myarray[nowindex].getword()))
		{
			flag=1;
			break;
		}
	}	
	if(flag==1)
	{
	myarray[nowindex]=*obj1;
	size1--;
	cout<<"Done!"<<endl;
	}
	else
		cout<<"Word not found !!"<<endl;
}
long long int htable::size()
{
	return size1;
}
void htable::search(string word)
{
	//cout<<"c3"<<endl;
	ll hcode=hashfunc1(word);
	ll hcode2=hashfunc2(hcode);
	string test="NULL123";
	long long int i=1;
	ll nowindex=hcode;
	int flag=0;
	//cout<<"c4"<<endl;
	while(test.compare(myarray[nowindex].getword()))
	{
		if(!word.compare(myarray[nowindex].getword()))
		{
			flag=1;
			break;
		}
		nowindex=(hcode+i*hcode2)%max;
		i++;
	}
	if(flag==1)
	{
	cout<<myarray[nowindex].getword()<<endl;
	}
	
}
void htable::sugbox(string s)
{
	//cout<<"Couldn't find the word :( , perhaps you were looking for :"<<endl;
	string k=s;
	//cout<<"c1"<<endl;
	for(int i=0;i<s.length();i++)//wetrospective
	{
		for(int j=0;j<26;j++)
		{
			k[i]='a'+j;
			search(k);
		}
		k=s;
	}
	//cout<<"c2"<<endl;
	for(int i=0;i<s.length();i++)//wretrospective
	{
		//cout<<"c2"<<endl;
		string my=s;
		//ll index2=0;
		
			my.erase(my.begin() + i); 
			//cout<<"yo dekho "<<my<<endl;
			search(my);
			
		
		//cout<<my<<endl;
		
	}
	//cout<<"c5"<<endl;
	for(int i=0;i<s.length()+1;i++)
	{
		string k;
		k=s;
		k.append(" ");
		ll index2=0;
		for(int j=0;j<s.length();j++)
		{
			if(j==i)
			{
				k[index2]='a';
				k[index2+1]=s[j];
				index2++;
			}
			else

				k[index2]=s[j];
			

			index2++;
		}
		for(int j=0;j<26;j++)
		{
			k[i]='a'+j;
			//cout<<"yolo"<<k<<endl;
			search(k);
		}

	}
	for(int i=0;i<s.length()-1;i++)//adjacent swapping
	{
		string h=s;
		char c=h[i];
		h[i]=h[i+1];
		h[i+1]=c;
		search(h);
	}
}
void htable::spellcheck(string s)
{
		ll hcode=hashfunc1(s);
	ll hcode2=hashfunc2(hcode);
	string test="NULL123";
	long long int i=1;
	ll nowindex=hcode;
	int flag=0;
	while(test.compare(myarray[nowindex].getword()))
	{
		if(!s.compare(myarray[nowindex].getword()))
		{
			flag=1;
			break;
		}
		nowindex=(hcode+i*hcode2)%max;
		i++;
	}
	if(flag==1)
	{
	cout<<"Meaning is:"<<myarray[nowindex].getmeaning()<<endl;
	}
	else
	{
		cout<<"Couldn't find the word :( , perhaps you were looking for :"<<endl;
		sugbox(s);
	}
}




