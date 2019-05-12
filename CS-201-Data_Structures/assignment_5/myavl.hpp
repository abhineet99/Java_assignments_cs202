#include<bits/stdc++.h>
#include"node.h"
#include"entry.h"
using namespace std;
class myavl{

 
    public:
     // void remove(string word);
      //int size();
      myavl();
      bool isEmpty();
      void insert(entry*);
      node* insert(node*,entry*);
      void remove(string k);
      void search(string k);
      void display(string word1,string word2);
      int getsize();
      void Inorder(); 
      void print();
      int search(string,int);
      int count(string key,string key2);



    private:
      int count1(node* root,string s) ;
      //int count2(node* root,string s) ;
      int search(node* root1,string key, int num) ;
      void print2(node* curr_node, int level); 
      void search(node* root,string key);
      node* remove(node* root,string key);
      node* findpred(node* lol1) ;
      int display(string word1,string word2,node* curr_node,int num);
       int size;
      node *root;
      node* leftRotate(node *);  // Left Rotation
      node* rightRotate(node *); // Right Rotation
      
      int height(node*);
      int getBalance(node *);
      int compstring(string a,string b);
      void Inorder(node* curr_node) ;
      int bachche(node* lol);

};
int myavl::count(string key,string key2)
{
  //Inorder();
  //cout<<size<<'\t'<<count1(root,key)<<'\t'<<count1(root,key2)<<endl;
  return 0-count1(root,key)+count1(root,key2)+1;
}
 void myavl::Inorder()
 {
  // cout<<root->lol->word<<endl;
  // if(root->right!=NULL)
  // {
  //   cout<<"YEA!"<<'\t'<<root->right->lol->word<<endl;
  // }
  Inorder(root);
  //cout<<endl;
 } 
void myavl::Inorder(node* curr_node) 
{ 
    if (curr_node == NULL) 
    {
     // cout<<"you're ****ed";
        return; 
    }
    //cout<<"you're  not ****ed";
    Inorder(curr_node->left); 
    cout << curr_node->lol->word << " "; 
    Inorder(curr_node->right); 
} 
myavl::myavl()
{
  root=NULL;
}

int myavl::getsize()
{
  return size;
}

bool myavl::isEmpty()
{
  if(root==NULL)
    return true;
  else
    return false;
}
int myavl::height(node* a)
{
  if(a!=NULL)
    return a->height;
  else
    return 0;
}
int myavl::compstring(string a,string b)
{
 int len1=a.length();
 int len2=b.length();
 bool eqlen=0;
 if(len1==len2)
  eqlen=1;
  bool equal=1;
  if(eqlen==1)
  {
    for(int i=0;i<len1;i++)
      if(a[i]!=b[i])
        equal=0;
  }
  if(eqlen==1&&equal==1)
    return -1;
  if(eqlen==1)
  {
    int i;
    for(i=0;i<len1;i++)
      if(a[i]!=b[i])
        break;
      if(a[i]>b[i])
        return 1;
      else return 0;
  }
  int min;
  if(len1<len2)
    min=len1;
  else
    min=len2;

  bool equal2=1;
  if(eqlen==0)
  {int i;
    for(i=0;i<min;i++)
    {
      if(a[i]!=b[i])
      {
        equal2=0;
        break;
      }
    }
    if(equal2==0)
      if(a[i]>b[i])
        return 1;
      else return 0;
    else
      {
        if(len1>len2)
          return 1;
        else
          return 0;
      }  


  } 



}
int myavl::getBalance(node *mynode) 
{ 
    if (mynode == NULL)//being cautious 
        return 0; 
    return height(mynode->left) - height(mynode->right); 
} 
node* myavl::leftRotate(node *x) 
{ 
    node *y = x->right; 
    node *T2 = y->left; 
    node *T3=y->right;
    node *T1=x->left;
   // x->bachche=bachche(T1)+bachche(x->left);
    y->left = x; 
    x->right = T2; 
    //rotaion done
    int max;
      if(height(x->right)>height(x->left))
        max=height(x->right);
      else
        max=height(x->left);
      x->height=max+1;

      if(height(y->right)>height(y->left))
        max=height(y->right);
      else
        max=height(y->left);
      y->height=max+1;
      //updated heights
      int val;
      if(T2==NULL)
      val=-1;
      else 
      val=T2->bachche;
    x->bachche = x->bachche- (y->bachche + 1) + (val + 1); 
    y->bachche = y->bachche - (val + 1) + (x->bachche + 1); 
  
   
   // y->bachche=bachche(y->left)+bachche(y->right);
    return y; 
} 
int myavl::bachche(node* lol)
{
  if(lol!=NULL)
    return lol->bachche;
  else
    return 0;
}
node* myavl::rightRotate(node *y) 
{ 
    node *x = y->left; 
     
    node *T2 = x->right; 
    node * T3=y->right;
   // y->bachche=bachche(T2)+bachche(T3);
  y->left = T2; 
    x->right = y; 
   
  
    // Updating heights of affected nodes after rotations 
    int max;
      if(height(y->right)>height(y->left))
        max=height(y->right);
      else
        max=height(y->left);
      y->height=max+1;
      if(height(x->right)>height(x->left))
        max=height(x->right);
      else
        max=height(x->left);
      x->height=max+1;

     // x->bachche=bachche(x->left)+bachche(x->right);
      int val;
    if(T2==NULL)
      val=-1;
      else 
      val=T2->bachche;
    y->bachche = y->bachche- (x->bachche + 1) + (val + 1); 
    x->bachche = x->bachche - (val + 1) + (y->bachche + 1); 

   

  

    return x; 
}
void myavl::print() 
{ 
    for (int i=1;i<=height(root);i++) 
    {
        print2(root, i);
        cout<<endl<<"____________________________________________________________________________________________________"<<endl; 
    }
} 
  
void myavl::print2(node* curr_node, int level) 
{ 
    if (curr_node == NULL) 
        return; 
    if (level == 1) 
        cout<<curr_node->lol->word<<"  "; 
    else if (level > 1) 
    { 
        print2(curr_node->left, level-1); 
        print2(curr_node->right, level-1); 
    } 
} 
node* myavl::insert(node* curr_node,entry* obj)

{
  
  
  
  
  if(curr_node==NULL)
  {
    size++;
    node* lol1= new node;
  lol1->right=NULL;
  lol1->left=NULL;
  lol1->lol=obj;
  lol1->height=1;
  lol1->bachche=0;
   // cout<<"kya hua"<<endl;
    curr_node=lol1;
    if(root==NULL)
    {
     // cout<<"aya"<<endl;
      root=curr_node;
    }
    return curr_node;
    //if(curr_node==NULL)
      //cout<<"ab gaye"<<endl;
  }
  
  else
  {
    curr_node->bachche++;
    if (compstring(obj->word,curr_node->lol->word)==0) 
        curr_node->left  = insert(curr_node->left, obj); 
    else if (compstring(obj->word,curr_node->lol->word)==1) 
        curr_node->right = insert(curr_node->right, obj); 
    else
    { 
        curr_node->lol->meaning=obj->meaning;
        return curr_node;
    }
      int max;
      if(height(curr_node->right)>height(curr_node->left))
        max=height(curr_node->right);
      else
        max=height(curr_node->left);
      curr_node->height=max+1;
//compstring(lol1->lol->word,curr_node->lol->word)==1 word>lol
//compstring(lol1->lol->word,curr_node->lol->word)==0 word<lol  
//cout<<"yo"<<endl;  
      int balance=getBalance(curr_node);
    //  cout<<height(curr_node)<<endl;
      if (balance > 1 && compstring(obj->word,curr_node->left->lol->word)==0) 
        return rightRotate(curr_node); 
  //cout<<"yo1"<<endl;  
   
      if (balance < -1 && compstring(obj->word,curr_node->right->lol->word)==1) 
          return leftRotate(curr_node); 
        //cout<<"yo2"<<endl;  
      if (balance > 1 && compstring(obj->word,curr_node->left->lol->word)==1) 
      { 
         curr_node->left =  leftRotate(curr_node->left); 
         return rightRotate(curr_node); 
      }  
      //cout<<"yo3"<<endl;  
      if (balance < -1 && compstring(obj->word,curr_node->right->lol->word)==0) 
      { 
        //cout<<"yo4"<<endl;  
         curr_node->right = rightRotate(curr_node->right); 
         return leftRotate(curr_node); 
      } 
       
      return curr_node; 
  }

}
void myavl::insert(entry* obj)

{
  //cout<<"lol"<<endl;
  root= insert(root,obj);

}
int myavl::display(string word1,string word2,node* curr_node, int num)
{
   if (curr_node == NULL) 
    {
     
        return 0; 
    }

  
   num+= display(word1,word2,curr_node->left,0);
    if(compstring(word1,curr_node->lol->word)!=1)
    if(compstring(word2,curr_node->lol->word)!=0) 
    {
    cout << curr_node->lol->word << " "; 
    num++;
  }
    num+=display(word1,word2,curr_node->right,0); 
    return num;
}
void myavl::display(string word1,string word2)
{
//cout<<root->lol->word<<endl;
  cout <<display(word1,word2,root,0)<<endl;
}
node* myavl::findpred(node* lol1) 
{ 
    
    while (lol1->left != NULL) 
        lol1 = lol1->left; 
  
    return lol1; 
} 
void myavl::remove(string word)
{
  if (search(word,0)==1)
  {
  root=remove(root,word);
size--;
}
  else
    cout<<"Not present!"<<endl;
}
node* myavl::remove(node* root,string key) 
{ 
  
    if (root == NULL) 
        return root; 
    if (compstring( key,root->lol->word )==0) 
{
        root->left =remove(root->left, key);  
root->bachche=root->bachche-1;}
    else if (compstring( key,root->lol->word )==1)
    { 
        root->right = remove(root->right, key);
        root->bachche=root->bachche-1; 
      }
    else
    { 
        
        if( (root->left != NULL) && (root->right != NULL) ) 
        { 
            node* temp = findpred(root->right); 
            root->lol = temp->lol; 
            root->right = remove(root->right, temp->lol->word);
            root->bachche=root->bachche-1;   
           
        } 
        else
        { 
          node* temp=NULL;
            // root->right = remove(root->right, temp->lol->word); 
            if(root->left!=NULL)
            temp =root->left;
            else if(root->right!=NULL)
              temp=root->right;
  
            
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else
            *root = *temp;
            delete(temp); 
            
        } 
    } 
    if (root == NULL) 
      return root;
       int max;
      if(height(root->right)>height(root->left))
        max=height(root->right);
      else
        max=height(root->left);
      root->height=max+1; 
    int balance = getBalance(root); 
    if (balance > 1 && getBalance(root->left) >= 0) 
        return rightRotate(root); 
    if (balance > 1 && getBalance(root->left) < 0) 
    { 
        root->left =  leftRotate(root->left); 
        return rightRotate(root); 
    } 
    if (balance < -1 && getBalance(root->right) <= 0) 
        return leftRotate(root); 
    if (balance < -1 && getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
  
    return root; 
}
  


void myavl:: search(string key)
{
  search(root,key);
}


void myavl::search(node* root,string key) 
{ 
    if (root == NULL) 
        return ; 
    if (compstring( key,root->lol->word )==0) 
        search(root->left, key);  
    else if (compstring( key,root->lol->word )==1) 
        search(root->right, key); 
    else
      cout<<root->lol->meaning<<endl;
   } 
int myavl::search(string s,int num )
{
  //cout<<"ye bhi"<<search(root,s,0)<<endl;
  return search(root,s,0);
}
int myavl::search(node* root1,string key,int num) 
{
//cout<<num<<endl; 
    if (root1 == NULL) 
        return 0; 
    if (compstring( key,root1->lol->word)==0) 
    {
        return search(root1->left, key,num);
         
    }
    else if (compstring( key,root1->lol->word)==1) 
        return search(root1->right, key,num); 
    else
      return 1;
   } 
int myavl::count1(node* root,string s) 
{ 
    int toret = 0; 
 
    while (root != NULL) { 
      int bye;
        if(root->left==NULL)
          bye=-1;
        else
          bye=root->left->bachche;
        if (compstring(s,root->lol->word)==0) { 
             
            root = root->left; 
        } else if (compstring(s,root->lol->word)==1) 
        {toret= toret+ bye + 1 + 1;
            root = root->right; 
          }
        else {                 //found the exact word
            toret= toret+ bye+ 1; 
            break; 
        } 
    } 
    return toret; 
}
