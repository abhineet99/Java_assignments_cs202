
class myavl{

  int size;
  node *root;
    public:
        MAVLTree();
      int size();
      bool isEmpty();
      void insert(string s);
      void remove(string k);
      string search(string k);
      void display();


    private:
      
      void rotateLeft(node *);  // Left Rotation
      void rotateRight(node *); // Right Rotation
      void rotateRightLeft(node *); // Right Left Rotation
      void rotateLeftRight(node *); // Left Right Rotation
      int height(node*);
      int getBalance(node *);
      bool compstring(string a,string b);
};

int myavl::size()
{
  return size;
}

bool isEmpty()
{
  if(head==NULL)
    return true;
  else
    return false;
}
int height(node* a)
{
  if(a!=NULL)
    return a->height;
  else
    return 0;
}
int compstring(string a,string b)
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
    for(int i=0;i<len1;i++)
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
  {
    for(int i=0;i<min;i++)
    {
      if(a[i]!=b[i])
      {
        equal2=0;
        break;
      }
    }
    if(equal2=0)
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
int getBalance(node *mynode) 
{ 
    if (mynode == NULL)//being cautious 
        return 0; 
    return height(mynode->left) - height(mynode->right); 
} 
node* leftRotate(node *x) 
{ 
    node *y = x->right; 
    node *T2 = y->left; 
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
   
  
    return y; 
} 
struct node *rightRotate(node *y) 
{ 
    node *x = y->left; 
    node Node *T2 = x->right; 
  
  
    x->right = y; 
    y->left = T2; 
  
    // Updating heights of affected nodes after rotations 
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
    
  

    return x; 
}
node* myavl::insert(node* curr_node,entry* obj)

{
  
  
  
  node* lol1= new node;
  lol1->right=NULL;
  lol1->left=NULL;
  lol1->lol=obj;
  if(curr_node==NULL)
    head=lol1;
  else
  {
    if (compstring(lol1->lol->word,curr_node->lol->word)==1) 
        curr_node->right  = insert(curr_node->left, obj); 
    else if (compstring(lol1->lol->word,curr_node->lol->word)==0) 
        curr_node->right = insert(curr_node->right, obj); 
    else
    { 
        curr_node->lol->word=lol1->lol->word;
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
      int balance=getBalance(curr_node);
      if (balance > 1 && compstring(lol1->lol->word,curr_node->left->lol->word)==0) 
        return rightRotate(curr_node); 
  
   
      if (balance < -1 && compstring(lol1->lol->word,curr_node->right->lol->word)==1) 
          return leftRotate(curr_node); 
      if (balance > 1 && compstring(lol1->lol->word,curr_node->left->lol->word)==1) 
      { 
         curr_node->left =  leftRotate(curr_node->left); 
         return rightRotate(curr_node); 
      }  
      if (balance < -1 && compstring(lol1->lol->word,curr_node->right->lol->word)==0) 
      { 
         curr_node->right = rightRotate(curr_node->right); 
         return leftRotate(curr_node); 
      }  
      return curr_node; 
  }

}


