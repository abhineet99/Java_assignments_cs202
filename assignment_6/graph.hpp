#include<bits/stdc++.h>
#include"vertex.hpp"
#include"edge.hpp"
using namespace std;
class my_graph{
private:
	edge* adj_matrix[100][100];
	edge* adj_matrix_1[100][100];
	int curr_vertex;
	vertex* vert[100];
	int check_there(vertex* v1);

	
	
public:
	void printRoute(int* parent, int index, int size);


	void largest();
	int mysize1();
	int mysize();
	my_graph();
	int add_vertex(vertex*);
	void add_edge(vertex*,vertex*,edge*);
	void shortest_graph(vertex* v1,vertex* v2);
	void shortest_graph2(vertex* v1,vertex* v2);
//	map<int,int> shortest_graph1(int c,int a, int b,map<int,int> state);
//	map<int,int> shortest_graph2(int c,int a, int b,map<int,int> state);
	map<int,float> shortest_graph3(int initial,int v1i,int v2i, map <int,float> state);
	map<int,float> shortest_graph4(int initial,int v1i,int v2i, map <int,float> state);
	void print_adj();
	void update_adj();

};


void my_graph::print_adj()
{
	for(int i=0;i<100;i++)
	{
		cout<<endl;
		for(int j=0;j<100;j++)
		{
			if(adj_matrix[i][j]!=NULL)
			cout<<i;
			else
				cout<<"__";
		}
	}	
}


my_graph::my_graph()
{
	for(int i=0;i<100;i++)
		vert[i]=NULL;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		{
			adj_matrix[i][j]=NULL;
		}
	curr_vertex=0;	
}

int my_graph::add_vertex(vertex* my_vertex)
{
	int flag=0;
	int i;
	for (i=0;i<100;i++)
	{
		if(vert[i]!=NULL)
		{	
			if(my_vertex->getName()==vert[i]->getName())
			{
				flag=1;
				break;
			}
		}
		else
			break;	
	}
	if(flag!=1)
	{
		vert[i]=my_vertex;

	}
	return i;

}
int my_graph::check_there(vertex* my_vertex)
{
	int flag=0;
	int i;
	for (i=0;i<100;i++)
	{
		if(vert[i]!=NULL)
		{	
			if(my_vertex->getName()==vert[i]->getName())
			{
				flag=1;
				break;
			}
		}
		else
			break;	
	}
	if(flag!=1)
	{
		return -1;

	}
	return i;
}
int my_graph::mysize()
{
	int count=0;
	for(int i=0;i<100;i++)
	{
		if(vert[i]==NULL)
			break;
		else
		{
			//cout<<count<<vert[i]->getName()<<endl;
			count++; 
		}
	}

	shortest_graph2(vert[0],vert[21]);
	//cout<<count<<endl;
	return count;
}
int my_graph::mysize1()
{
	int count=0;
	for(int i=0;i<100;i++)
	{
		if(vert[i]==NULL)
			break;
		else
			count++; 
	}
	//shortest_graph(vert[1],vert[2]);
	return count;
}
void my_graph::add_edge(vertex* v1,vertex* v2,edge* a)
{
	int v1i=0;
	int v2i=0;
	v1i=add_vertex(v1);
	v2i=add_vertex(v2);
	adj_matrix[v1i][v2i]=a;
	adj_matrix[v2i][v1i]=a;


}
void my_graph::update_adj()
{
	edge* a=new edge;
	a->setDistance(1);
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		{
			if(adj_matrix[i][j]==NULL)
				adj_matrix_1[i][j]=NULL;
			else
				adj_matrix_1[i][j]=a;

		}
}	
void my_graph::shortest_graph(vertex* v1,vertex* v2)
{
	//cout<<"yes";
	int v1i= check_there(v1);
	int v2i= check_there(v2);
	if(v1i==-1||v2i==-1)
	{
		cout<<"Vertices Not in the Graph!!"<<endl;
	}
	else
	{
		
		
		map<int,float> state;
		//pair <int, int> (1, 40)
		for(int i=0;i<mysize1();i++)
			state[i]=99999999;;
		state[v1i]=0;
		state=shortest_graph3(v1i,v1i,v2i,state);
		//for(int i=0;i<mysize1();i++)
		//	cout<<state[i]<<endl;
		//map<int,float>::iterator it;
		//it=state.find(v2i);
		//cout<<it->second;
	}
}
void my_graph::shortest_graph2(vertex* v1,vertex* v2)
{
	update_adj();
	int v1i= check_there(v1);
	int v2i= check_there(v2);
	if(v1i==-1||v2i==-1)
	{
		cout<<"Vertices Not in the Graph!!"<<endl;
	}
	else
	{
		
		
		map<int,float> state;
		//pair <int, int> (1, 40)
		for(int i=0;i<mysize1();i++)
			state[i]=99999999;;
		state[v1i]=0;
		state=shortest_graph4(v1i,v1i,v2i,state);
		// for(int i=0;i<mysize1();i++)
		// 	cout<<state[i]<<endl;
		// map<int,float>::iterator it;
		// it=state.find(v2i);
		// cout<<it->second;
	}
}
/*
map<int,int> my_graph::shortest_graph1(int initial,int v1i,int v2i, map <int,int> state)
{	
	map<int,int>::iterator it;
	map<int,int>::iterator it1;
	set<int>::iterator it2;
	//it=state.find(vert[v2i]);
	int flag=0;
	cout<<"IN SG 1"<<endl;
	cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
	cout<<"i was here"<<vert[v1i]->getName()<<endl;
	//it2=visited.find(vert[v1i]);
	for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
	{
		//cout<<"i was";
		//cout<<*it2<<endl;
		if(v1i==(*it2))
		{
			//cout<<"i was";
			flag=1;
		}

	}
	if(flag==1)// if the vertex is already visited 
	{
		cout<<"in deep shit"<<endl;
		return state;
	}
	//edge* sad_array[100];
	if(visited.size()==mysize1())// if the number of visited vertices is equal to the total no. of vertices
	{
		cout<<"i was here2"<<endl;
		//cout<<state[vert[v2i]]<<endl;
		return state;
	}
	if(flag==0)
	{
		for(int i=0;i<100;i++)// checking the vertex's neighbours
			{

				if(adj_matrix[v1i][i]!=NULL)
				{
					//sad_array[i]=adj_matrix[v1i][i];
					if(i!=initial)// shouldnt update the first vertex's distance
					{
						it1=state.find(v1i);
						it=state.find(i);
						if(it->second==0)//if this vertex is undiscovered
						{
							state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];
							cout<<"c this "<<adj_matrix[v1i][i]->getDistance()<<endl;
						}
						else if(adj_matrix[v1i][i]->getDistance()+state[v1i]<it->second)//if we found a shorter path
						{
							state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];
						}
					}
				}
				// else
				// 	sad_array[i]=NULL;

			}
		int sad_array[100]={-1};
		for(int i=0;i<100;i++)
			sad_array[i]=-1;
		bool sad_bool[100]={0};
		for(int i=0;i<100;i++)
			sad_bool[i]=0;
		for(int j=0;j<100;j++)
		{
			int min=999999999;
			int minindex=-1;
			for(int i=0;i<100;i++)
			{
				if(adj_matrix[v1i][i]!=NULL)
				if(adj_matrix[v1i][i]->getDistance()<min&&sad_bool[i]==0)
				{
					minindex=i;
					min=adj_matrix[v1i][i]->getDistance();
				}
			}
			if(minindex==-1)
				break;
			else
			{
				sad_bool[minindex]=1;
				sad_array[j]=minindex;
			}


		}
		int j=0;
		visited.insert(v1i);
		for(int i=0;i<100;i++)
			cout<<sad_array[i]<<'\t';
		while(sad_array[j]!=-1&&j<100)
		{
			state=shortest_graph2(initial,sad_array[j],v2i,state);
			j++;
		}
		while(sad_array[j]!=-1&&j<100)
		{
			state=shortest_graph1(initial,sad_array[j],v2i,state);
			j++;
		}


		cout<<"yhan b tha"<<endl;
		cout<<state[v2i]<<endl;
		return state;
	}
	else
	{
		cout<<flag<<"   "<<endl;
		cout<<"yhan b tha2";
		return state;
	}


	

}*/
void my_graph::printRoute(int* parent, int index, int size){
    if(parent[index]==-1){
        cout<<vert[index]->getName()<<endl;
        return;
    }
    else{
        cout<<vert[index]->getName()<<"<-->";
        printRoute(parent, parent[index], mysize1());
    }
}

map<int,float> my_graph::shortest_graph4(int initial,int v1i,int v2i, map <int,float> state)
{	
	map<int,float>::iterator it;
	map<int,float>::iterator it1;
	set<int>::iterator it2;
	int* parent=new int[mysize1()];
	parent[initial] = -1;
	//int parent[mysize1()];
	set <int> visited;
	//it=state.find(vert[v2i]);
	//int flag=0;
	//cout<<"IN SG 3"<<endl;
	//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
	//cout<<"i was here"<<vert[v1i]->getName()<<endl;
	//it2=visited.find(vert[v1i]);
	// for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
	// {
	// 	//cout<<"i was";
	// 	//cout<<*it2<<endl;
	// 	if(v1i==(*it2))
	// 	{
	// 		//cout<<"i was";
	// 		flag=1;
	// 	}

	// }
	int minindex=initial;
	// if(flag==1)// if the vertex is already visited 
	// {
	// 	cout<<"in deep shit"<<endl;
	// 	return state;
	// }
	//edge* sad_array[100];
	if(visited.size()==mysize1())// if the number of visited vertices is equal to the total no. of vertices
	{
		//cout<<"i was here2"<<endl;
		//cout<<state[vert[v2i]]<<endl;
		return state;
	}
	while(visited.size()!=mysize1())
	{
		//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
		//cout<<"i was here"<<vert[v1i]->getName()<<endl;
		//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
		v1i=minindex;
		//cout<<v1i<<endl;
		for(int i=0;i<100;i++)// checking the vertex's neighbours
			{

				if(adj_matrix[v1i][i]!=NULL)
				{
					
					//sad_array[i]=adj_matrix[v1i][i];
					if(i!=initial)// shouldnt update the first vertex's distance
					{
						//cout<<"c this "<<endl;
						it1=state.find(v1i);
						it=state.find(i);
						// if(it->second==99999999)//if this vertex is undiscovered
						// {
						// 	state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];

						// 	cout<<"c this "<<adj_matrix[v1i][i]->getDistance()<<endl;
						// }
						if((adj_matrix_1[v1i][i]->getDistance()+state[v1i])<it->second)//if we found a shorter path
						{

							state[i]=adj_matrix_1[v1i][i]->getDistance()+state[v1i];
							parent[i] = v1i;
						}
					}
				}
				// else
				// 	sad_array[i]=NULL;
			}

			float sad_array[100];
		for(int i=0;i<100;i++)
			sad_array[i]=state[i];
		bool sad_bool[100]={0};
		for(int i=0;i<100;i++)
			sad_bool[i]=0;
		int min=9999999;
		minindex=-1;
		visited.insert(v1i);
		for(int j=0;j<100;j++)
		{	

			int flag=0;		
				for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
				{
					//cout<<"i was";
					//cout<<*it2<<endl;
					if(j==(*it2))
					{
						//cout<<"i was"<<endl;
						flag=1;
					}

				}
			//	cout<<"i was here aswell"<<endl;
			if(flag==0&&sad_array[j]<min&&j<mysize1())
			{
				minindex=j;				
				min=sad_array[j];
			}
			//cout<<"i was here aswell2"<<endl;
			
		}

		//int j=0;
		
		// for(int i=0;i<100;i++)
		 //	cout<<sad_array[i]<<'\t';
		// while(sad_array[j]!=-1&&j<100)
		// {
		// 	state=shortest_graph2(initial,sad_array[j],v2i,state);
		// 	j++;
		// }
		// while(sad_array[j]!=-1&&j<100)
		// {
		// 	state=shortest_graph1(initial,sad_array[j],v2i,state);
		// 	j++;
		// }
		//cout<<"yhan b tha"<<endl;
		//cout<<state[v2i]<<endl;
		
	}
		cout<<state[v2i]<<endl;
		    printRoute(parent,v2i ,mysize1());


	return state;
	
}
map<int,float> my_graph::shortest_graph3(int initial,int v1i,int v2i, map <int,float> state)
{	
	map<int,float>::iterator it;
	map<int,float>::iterator it1;
	set<int>::iterator it2;
	set <int> visited;
	int* parent=new int[mysize1()];
	parent[initial]=-1;

	//it=state.find(vert[v2i]);
	//int flag=0;
	//cout<<"IN SG 3"<<endl;
	//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
	//cout<<"i was here"<<vert[v1i]->getName()<<endl;
	//it2=visited.find(vert[v1i]);
	// for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
	// {
	// 	//cout<<"i was";
	// 	//cout<<*it2<<endl;
	// 	if(v1i==(*it2))
	// 	{
	// 		//cout<<"i was";
	// 		flag=1;
	// 	}

	// }
	int minindex=initial;
	// if(flag==1)// if the vertex is already visited 
	// {
	// 	cout<<"in deep shit"<<endl;
	// 	return state;
	// }
	//edge* sad_array[100];
	if(visited.size()==mysize1())// if the number of visited vertices is equal to the total no. of vertices
	{
		//cout<<"i was here2"<<endl;
		//cout<<state[vert[v2i]]<<endl;
		return state;
	}
	while(visited.size()!=mysize1())
	{
		//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
		//cout<<"i was here"<<vert[v1i]->getName()<<endl;
		//cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
		v1i=minindex;
		//cout<<v1i<<endl;
		for(int i=0;i<100;i++)// checking the vertex's neighbours
			{

				if(adj_matrix[v1i][i]!=NULL)
				{
					
					//sad_array[i]=adj_matrix[v1i][i];
					if(i!=initial)// shouldnt update the first vertex's distance
					{
						//cout<<"c this "<<endl;
						it1=state.find(v1i);
						it=state.find(i);
						// if(it->second==99999999)//if this vertex is undiscovered
						// {
						// 	state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];

						// 	cout<<"c this "<<adj_matrix[v1i][i]->getDistance()<<endl;
						// }
						if((adj_matrix[v1i][i]->getDistance()+state[v1i])<it->second)//if we found a shorter path
						{

							state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];
														parent[i] = v1i;

						}
					}
				}
				// else
				// 	sad_array[i]=NULL;
			}
			float sad_array[100];
		for(int i=0;i<100;i++)
			sad_array[i]=state[i];
		bool sad_bool[100]={0};
		for(int i=0;i<100;i++)
			sad_bool[i]=0;
		int min=9999999;
		minindex=-1;
		visited.insert(v1i);
		for(int j=0;j<100;j++)
		{	

			int flag=0;		
				for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
				{
					//cout<<"i was";
					//cout<<*it2<<endl;
					if(j==(*it2))
					{
						//cout<<"i was"<<endl;
						flag=1;
					}

				}
			//	cout<<"i was here aswell"<<endl;
			if(flag==0&&sad_array[j]<min&&j<mysize1())
			{
				minindex=j;				
				min=sad_array[j];
			}
			//cout<<"i was here aswell2"<<endl;
			
		}

		//int j=0;
		
		 //for(int i=0;i<100;i++)
		 	//cout<<sad_array[i]<<'\t';
		// while(sad_array[j]!=-1&&j<100)
		// {
		// 	state=shortest_graph2(initial,sad_array[j],v2i,state);
		// 	j++;
		// }
		// while(sad_array[j]!=-1&&j<100)
		// {
		// 	state=shortest_graph1(initial,sad_array[j],v2i,state);
		// 	j++;
		// }
		//cout<<"yhan b tha"<<endl;
		//cout<<state[v2i]<<endl;
		
	}
			    printRoute(parent,v2i ,mysize1());

	cout<<state[v2i]<<endl;
	return state;

	
}
void my_graph::largest()
{
	int area[mysize1()];
	for(int i=0;i<mysize1();i++)
		area[i]=0;
	for(int i=0;i<mysize1();i++)
	{
		for(int j=0;j<mysize1();j++)
			if(adj_matrix[i][j]!=NULL)
				area[i]++;
	}
	int max=-1;
	int maxindex=-1;
	for(int i=0;i<mysize1();i++)
		if(area[i]>max)
		{
			maxindex=i;
			max=area[i];
		}

	cout<<vert[maxindex]->getName()<<endl;	
}
/*
map<int,int> my_graph::shortest_graph2(int initial,int v1i,int v2i, map <int,int> state)
{	
	map<int,int>::iterator it;
	map<int,int>::iterator it1;
	set<int>::iterator it2;
	//it=state.find(vert[v2i]);
	int flag=0;
	cout<<"IN SG 2"<<endl;
	cout<<"see the damn size!  "<<mysize1()<<'\t'<<visited.size()<<endl;
	cout<<"i was here"<<vert[v1i]->getName()<<endl;
	//it2=visited.find(vert[v1i]);
	for(it2=visited.begin();it2!=visited.end();it2++)//checking if vertex is visited
	{
		//cout<<"i was";
		//cout<<*it2<<endl;
		if(v1i==(*it2))
		{
			//cout<<"i was";
			flag=1;
		}

	}
	if(flag==1)// if the vertex is already visited 
	{
		cout<<"in deep shit"<<endl;
		return state;
	}
	//edge* sad_array[100];
	if(visited.size()==mysize1())// if the number of visited vertices is equal to the total no. of vertices
	{
		cout<<"i was here2"<<endl;
		//cout<<state[vert[v2i]]<<endl;
		return state;
	}
	if(flag==0)
	{
		for(int i=0;i<100;i++)// checking the vertex's neighbours
			{

				if(adj_matrix[v1i][i]!=NULL)
				{
					//sad_array[i]=adj_matrix[v1i][i];
					if(i!=initial)// shouldnt update the first vertex's distance
					{
						it1=state.find(v1i);
						it=state.find(i);
						if(it->second==0)//if this vertex is undiscovered
						{
							state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];
							cout<<"c this "<<adj_matrix[v1i][i]->getDistance()<<endl;
						}
						else if(adj_matrix[v1i][i]->getDistance()+state[v1i]<it->second)//if we found a shorter path
						{
							state[i]=adj_matrix[v1i][i]->getDistance()+state[v1i];
						}
					}
				}
				// else
				// 	sad_array[i]=NULL;

			}
		//visited.insert(v1i);



		cout<<"yhan b tha"<<endl;
		cout<<state[v2i]<<endl;
		return state;
	}
	else
	{
		cout<<flag<<"   "<<endl;
		cout<<"yhan b tha2";
		return state;
	}


	

}






















*/