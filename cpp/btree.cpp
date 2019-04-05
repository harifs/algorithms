#include<iostream.h>
#include<stdlib.h>

typedef struct bTree
{
   int value;
   struct bTree *leftS;
   struct bTree *rightB;
}btree;

class Btree
{
  btree *root;
  int size,count;

  public:
  Btree() // Constructor #1 - defaults the root node value to zero
  {
      root = (btree *) malloc(sizeof(btree));
      root->value=0;
      root->leftS=NULL;
      root->rightB=NULL;
      size=1;
  }
  Btree(int n) // Constructor #2
  {
      root = (btree *) malloc(sizeof(btree));
      root->value=n;
      root->leftS=NULL;
      root->rightB=NULL;
      size=1;
  }
  ~Btree() // Desctructor
  {
      free(root);
      size=0;
  }
  int addElem(int n)
  {
    cout<<"In addElem Funcion! n="<<n<<endl;
    int rflag,lflag;
    btree *tmp,*elem,*parent;
    tmp = (btree *) malloc(sizeof(btree)); 
    elem = (btree *) malloc(sizeof(btree)); 
    parent = (btree *) malloc(sizeof(btree)); 
    elem->value=n;
    elem->leftS=NULL;
    elem->rightB=NULL;
    tmp=root;
    cout<<"n="<<n<<";root-val="<<tmp->value<<endl;
    do
    {
      parent=tmp;
      rflag=0;
      lflag=0;
      if(n>tmp->value)
      {
        rflag=1;
        tmp=tmp->rightB;
      }
      else
      {
        lflag=1;
        tmp=tmp->leftS;
      }
    }
    while (tmp);
    tmp = (btree *) malloc(sizeof(btree)); 
    tmp=elem;
    if(rflag) parent->rightB=tmp;
    if(lflag) parent->leftS=tmp;

    cout<<"After: tmp-val="<<tmp->value<<";parent->val:"<<parent->value<<";lflag="<<lflag<<";rflag="<<rflag<<endl;
    cout<<"Exiting addElem Funcion!"<<endl;
    return ++size;
  }

  void printTree()
  {
    btree *tmp;
    count=1;
    tmp = (btree *) malloc(sizeof(btree)); 
    tmp=root;
    cout<<"element #"<<count<<":"<<tmp->value;
    if(tmp->rightB) printTree(tmp->rightB);
    if(tmp->leftS) printTree(tmp->leftS);
  }

  void printTree(btree *tmp)
  {
    //cout<<"In printTree Function!"<<endl;
    btree *right,*left;
    right = (btree *) malloc(sizeof(btree)); 
    left = (btree *) malloc(sizeof(btree)); 
    right=tmp->rightB;
    left=tmp->leftS;
    count++;
    cout<<"element #"<<count<<":"<<tmp->value;
    if(right) {cout<<"right!"; printTree(right);}
    if(left) {cout<<"left!"; printTree(left);}
    //cout<<"Exiting printTree Funcion!"<<endl;
  }
};

void main()
{
  Btree *btreeObj = new Btree(4);
  int s;
  s=(*btreeObj).addElem(1);
  s=(*btreeObj).addElem(2);
  s=(*btreeObj).addElem(7);
  s=(*btreeObj).addElem(3);
  cout<<"Size of Btree:"<<s<<"\n";
  (*btreeObj).printTree();
  delete btreeObj;
}
