#include<bits/stdc++.h>
#include<cmath>
#include<array>
using namespace std;
#define MAX 32
int pow2array[10];
void setpow2array()
{
	for(int i=0;i<10;i++)
	{
		pow2array[i]=pow(2,i);

	}
}

bool diffispow2(int a , int b)
{
	for(int i=0;i<10;i++)
		if(a==pow2array[i]&&a==b+1)
			return false;
	for(int i=0;i<10;i++)
		if(b==pow2array[i]&&b==a+1)
			return false;	

	for(int i=0;i<10;i++)
		if(abs(a-b)==pow2array[i])
			return true;

	return false;	
}
int numberof1(int a)
{
		bitset<MAX> toinput(a);
		int one_count=0;
		for (int j=0;j<MAX;j++)
		{
			if(toinput[j]==1)
				one_count++;

		}
		return one_count;
}
struct Implicant {
	 //integer array of size in sorted order
	bool paired;
	int size;
	vector<int> intvector;
	Implicant(int _size) {
	size = _size;
	paired=false;

	}
	Implicant(int _size, Implicant i1, Implicant i2) {
	size=_size;
	paired=false;
	for(int i=0;i<size/2;i++)
		intvector.push_back(i1.intvector[i]);
	for(int i=0;i<size/2;i++)
		intvector.push_back(i2.intvector[i]);
	sort(intvector.begin(),intvector.end());
	}
	int sizeofthis()
	{
		return intvector.size();
	}
	int sumofthis()
	{
		int sum=0;
		return accumulate(intvector.begin(),intvector.end(),0);

	}
	void disp()
	{
		for(int i=0;i<intvector.size();i++)
		cout<<intvector[i]<<",";
		cout<<endl;

	}
};
bool isSuperset(Implicant new1,Implicant old1)
{
	int count=0;
	int sizenew=new1.intvector.size();
	int sizeold=old1.intvector.size();
	for(int i=0;i<sizenew;i++)
	{
		for(int j=0;j<sizeold;j++)

		{
			if(new1.intvector[i]==old1.intvector[j])
				count++;
		}
	}
	if(count==sizenew)
		return true;
	else 
		return false;
}

struct Bucket {
	vector<Implicant> implicants;
	int num_implicants()
	{
		return implicants.size();
	}
	void disps()
	{

		for(int i=0;i<implicants.size();i++)
			implicants[i].disp();
	}

};
struct BucketStore {
	stack<Bucket*> store;

};
bool checkvalid(vector<int> a,vector<int> b)
{
	bool toAdd=false;
	int sizeindex=0;
	int diff,newdiff;
	diff = b[sizeindex] -a[sizeindex];	
	if(log2(diff) == floor(log2(diff))){	
		toAdd=true;			
	} 					
	for(sizeindex=1; sizeindex<b.size(); sizeindex++){				
		newdiff = b[sizeindex] -a[sizeindex];	
		if(diff!=newdiff){
			toAdd=false;			
			break;					
		}	
						
	}
	if(toAdd && diff==1){
		if( log2(b[sizeindex-1]) ==floor(log2(b[sizeindex-1])) ){
			toAdd=false;			
		}	
	}
	return toAdd;
}
int isKthbitplaceSet(int n, int k)
{
    if (n & (1 << (k - 1)))
        return 1;
    else
        return 0;
}
char* expressionret(Implicant implicant,list<char> inputs){

	int index1=0,index2=0;
	char* exp=(char*)malloc((index1+1)* sizeof(char));
	list<char> :: iterator it1;
	it1=inputs.begin();
	while(it1!=inputs.end()){
		int bitplace,newbitplace;
		int index=0;
		bitplace=isKthbitplaceSet(implicant.intvector[index],index2+1);
		index=index+1;;	
		while(index<implicant.size){
			newbitplace=isKthbitplaceSet(implicant.intvector[index],index2+1);
			if(bitplace!=newbitplace){
				break;
			}
		index++;
		}
		if(index==implicant.size){
			*(exp+index1)=*it1;
			index1=index1+1;
			exp=(char*)realloc(exp,(index1+1)* sizeof(char));	
			if(bitplace==0){
				*(exp+index1)='\'';
				index1=index1+1;
			exp=(char*)realloc(exp,(index1+1)* sizeof(char));	
			}	
		}
			
		it1++;
		index2++;	
	}
	*(exp+index1)='\0';
	
	return exp;
	

}
bool checkflag(Implicant a,Implicant b)
{
	if(a.sizeofthis()!=b.sizeofthis())
		return false;
	int index=b.sizeofthis();
	for(int i=0;i<index;i++)
		if(a.intvector[i]!=b.intvector[i])
			return false;

		return true;
}

void evaluator()
{
	

	std::vector<int> input1;
	vector<Implicant>prime_implicants;
	int a=1;
	int count =0;
	std::vector<Implicant> nopair;
	cout<<"Enter the minterms, enter -1 when done"<<endl;
	while(a)
	{
		cin>>a;
		if(a<0)
			break;
		input1.push_back(a);
		count++;
	}
	
	sort(input1.begin(),input1.end());
	bool allpair=0;
	int size_of_bucket=floor(log2(input1[input1.size()-1]))+1;
	int size=size_of_bucket+1;
	size--;
	Bucket* pBucket=new Bucket[size_of_bucket+1];
	int i;
	int imp_size=1;
	for(i=0;i<input1.size();i++)
	{
		Implicant e(imp_size);
		e.intvector.push_back(input1[i]);	
		pBucket[numberof1(input1[i])].implicants.push_back(e);
	}
	BucketStore bStore;
	bStore.store.push(pBucket);
	while(1)
	{

		Bucket* nBucket=new Bucket[size];
		imp_size*=2;

		int count=0;

		for(int i=0;i<size;i++)
			{   
				for(int j=0;j<pBucket[i].num_implicants();j++)
					for(int k=0;k<pBucket[i+1].num_implicants();k++)
						if(checkvalid(pBucket[i].implicants[j].intvector,pBucket[i+1].implicants[k].intvector))
						//if(diffispow2(pBucket[i].implicants[j].sumofthis(),pBucket[i+1].implicants[k].sumofthis()))
						{
							int flag=1;

							pBucket[i].implicants[j].paired=true;
							pBucket[i+1].implicants[k].paired=true;
							Implicant e(imp_size,pBucket[i].implicants[j],pBucket[i+1].implicants[k]);
							for(int j=0;j<nBucket[i].implicants.size();j++)
							{
								

								if(nBucket[i].implicants[j].intvector==e.intvector)
									flag=0;
							}
							if(flag==1)
							{nBucket[i].implicants.push_back(e);

							}
							count++;

						}

			}
		if(count==0)
			break;		

		size--;
		bStore.store.push(nBucket);

		pBucket=nBucket;	
		if(count==0)
			break;	

	}
	size++;
	Bucket ess_prime_implicants;

	while(!bStore.store.empty())
	{	

	 Bucket *popBucket=bStore.store.top();

	 bStore.store.pop();
		for(int i=0;i<size;i++)
		{	
			for(int r=0;r<popBucket[i].implicants.size();r++)
			{	int check=1;
				if(prime_implicants.size()==0)
				prime_implicants.push_back(popBucket[i].implicants[r]);


				for(int k=0;k<prime_implicants.size();k++)
				{

					cout<<endl;
					if(isSuperset(popBucket[i].implicants[r],prime_implicants[k]))
						check*=0;
				}
				if(check==1)
				{
					int flag=0;
					for(int h=0;h<prime_implicants.size();h++)
					{
						if(checkflag(prime_implicants[h],popBucket[i].implicants[r]))
							flag+=1;
					}
					if(flag==0)
					prime_implicants.push_back(popBucket[i].implicants[r]);
				}
			}
			
		}
		size--; 
	}

	for(int i=0;i<input1.size();i++)
	{

		int j=input1[i];
		int check=0;
		int n=-1;
		int y=-1;
		for(int f=0;f<prime_implicants.size();f++)
		{
			
			for(int k=0;k<prime_implicants[f].intvector.size();k++)
			{
				if (prime_implicants[f].intvector[k]==j)
					{check++;
					n=i;
					y=f;

				}

			}
		}

		if(check==1)
		{
	
			ess_prime_implicants.implicants.push_back(prime_implicants[y]);
		
		}
	}

	vector<Implicant>::iterator it;

	vector<int>:: iterator it2;
	
	
	while(!input1.empty())
	{
		
		for(it2=input1.begin();it2!=input1.end();)
		{
			//cout<<"p1";
			int flag=0;
			for(int i=0;i<ess_prime_implicants.num_implicants();i++)
			{ //cout<<"STEP 1"<<endl;
				for(int b=0;b<ess_prime_implicants.implicants[i].intvector.size();b++)
				{//cout<<"STEP 2"<<endl;
					if(*it2==ess_prime_implicants.implicants[i].intvector[b])
						{//cout<<"STEP 3"<<endl;
							input1.erase(it2);
							flag=1;
							break;

							}
				}
			if(flag==1)
			break;	
			}
			
			if(flag!=1)
			++it2;		
					

		}
		
		int p=0;
		for(it = prime_implicants.begin(); it != prime_implicants.end(); )
		{
			int check=0;	//cout<<"IMNOOB"<<endl;
			for(int i=0;i<(*it).intvector.size();i++)
				for(int g=0;g<input1.size();g++)
					if((*it).intvector[i]==input1[g])
						check++;

			if(check==0)
				prime_implicants.erase(it);
			else
				++it;
				++p;

		}

		int maxcontain=0;

		p=0;
		vector<Implicant>::iterator it1;
		int flag1=0;
		for(it = prime_implicants.begin(); it != prime_implicants.end(); it++,p++ )
		{
			int contain=0;
			for(int r=0;r<(*it).intvector.size();r++)
			{			
				for(int g=0;g<input1.size();g++)
				{
					if(prime_implicants[p].intvector[r]==input1[g]){
						contain++;
					}
					//continue;
				}
			}
			if(contain>maxcontain)
				{
					maxcontain=contain;
					it1=it;
					flag1=1;
				}
		}

		if(flag1==1)
		ess_prime_implicants.implicants.push_back(*it1);


	}	
	vector<Implicant>::iterator it1;

	list<char> inputs;
	cout<<"Enter the number of variables"<<endl;
	int var;
	cin>>var;
	char c;
	while(var--)
	{
		cout<<"Enter variable and press enter"<<endl;
		cin>>c;
		inputs.push_back(c);

	}
	

	cout<<"minimised expression:"<<endl;
	it1=ess_prime_implicants.implicants.begin();
	while(it1!=ess_prime_implicants.implicants.end()){

		char* str=expressionret(*it1,inputs);
		cout<<str<<endl;
		it1++;	
	}
		
}	



int main()
{
	setpow2array();
	evaluator();
	return 0;

}