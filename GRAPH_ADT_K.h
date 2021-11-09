
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const int MAX_VAL = 10000;

class Node
{
public:
    int ver_name, cost;
    Node *next;
    Node()
    {
        this->ver_name = INT_MAX;
        this->cost = INT_MAX;
        this->next = NULL;
    }
};
class QueueNode{
    public:
        int cost;
        int sourceNode;
        int destNode;
        QueueNode* link=NULL;
};
class UDGraph
{
    // insert new nodes into adjacency list from given graph
public:
    //int N;
    Node **list;
    QueueNode* pointer=NULL;
    int number_nodes=0;
    UDGraph *read_graph(string filename);
    void printGraph(UDGraph *al);
    void traverseGraph(Node *r);
    UDGraph* Initialize_Graph(int n);
    int first_Vertex(UDGraph *al, int i);
    int next_Vertex(UDGraph *al, int ver, int i);
    bool isEdge(UDGraph *al, int i, int j);
    int cost(UDGraph *al, int i, int j);
    UDGraph* add_Edge(UDGraph *al, int i, int j,int cost);
    int  print(UDGraph * al);
    UDGraph*  delete_Edge(UDGraph *al, int i, int j);
    UDGraph* delete_Edge_p(UDGraph * al, int i, int j);
};

UDGraph *UDGraph::read_graph(string filename)
{
    UDGraph *var;
    var = new (UDGraph);
    Node *temp;
    //int cost_matrix[N][N];
    fstream fp,fq;
    int m;
    
    fp.open(filename, ios::in);
    int num = 1;

    //===============Read File and check the number of vertics and edges==========

    if (!fp)
    {
        cout << "No such file exist" << endl;
        return 0;
    }
    else
    {
        fp >> m;
        while (!fp.eof())
        {
            num = num + 1;
            fp >> m;
        }
    }
    cout << "Number of elements in Cost Matrix: " << num << endl;
    long long sr = sqrt(num);
    if (sr * sr == num)
    {
        cout << "Square matrix is checked" << endl;
        cout << "Dimensions " << sr << " * " << sr;
    }

    else
    {
        cout << "Cost Matrix is not of Form n*n" << endl;
        return 0;
    }
    fp.close();
   //=======Read the cost matrix=========================================
   fq.open(filename, ios::in);

    if (!fq)
    {
        cout << "No such file exist" << endl;
        return 0;
    }
    
   var->list=new Node*[sr];
   
   for (int i=0;i<sr;i++)
    {
        var->list[i]=NULL; 
        for(int j=0;j<sr;j++)
        {
            fq>>m;
            if(m != -1 & i!=j )
           {
               
               temp=new(Node);
               temp->ver_name = j;
               temp->cost= m;
               temp->next =var->list[i];
               var->list[i]=temp;
               
           }
           else
           continue;            
        }

    }
   fq.close();
   var->number_nodes=sr;
  // free(temp);
    return var;

}
void UDGraph::traverseGraph(Node* r){

    if(r != NULL){
        cout << "("<<r->ver_name<< ","<<r->cost<< "), ";
        traverseGraph(r->next);
        
    }
}
void UDGraph::printGraph(UDGraph* al){
int N= al->number_nodes; 
      for(int i=0;i<N;i++){
          cout << i << " : ";
          traverseGraph(al->list[i]);
          cout << endl;
      }
  }
UDGraph* UDGraph:: Initialize_Graph(int n)
{   

    UDGraph *var;
    var = new (UDGraph);
    var->list=new Node*[n];
    var->number_nodes=n;
   for (int i=0;i<n;i++)
    {
        var->list[i]=NULL; 
    }

return var;
}
bool UDGraph::isEdge(UDGraph *al,int i, int j)
{
    Node * test= al->list[i];
    while(test!=NULL && test->ver_name!=j)
    {
        test=test->next;
    } 
    if(test==NULL)
    {
       // free(test);
      return false;
    }
    else
    {
       // free(test);
     return true;
    }
    


}


int UDGraph::cost(UDGraph * al, int i, int j)
{
    int isedge= al->isEdge(al,i,j);
    if(isedge==true)
    {
    Node * test= al->list[i];
    while(test->next!=NULL && test->ver_name!=j)
    {
        test=test->next;
    } 
    if(test->next==NULL &&test->ver_name!=j)
    {
        //free(test);
      return -1;
    }
    else
    {
      int cost= test->cost;
      //free(test);
     return cost;
    }
    }
    else 
    {
        cout<<"No edge is present"<<endl;
return -1;
    }
    
    
}
int UDGraph:: UDGraph::next_Vertex(UDGraph * al,int i,int j)
{
    Node * test= al->list[i];
    while(test->next!=NULL && test->ver_name!=j)
    {
        test=test->next;
    } 
    if(test->next==NULL)
    {
      //  free(test);
      return -1;
    }
    else
    {
    int val=test->next->ver_name;
    //free(test);
    return val ;
    }
}

UDGraph* UDGraph:: add_Edge(UDGraph * al, int i, int j,int cost)
{   
    QueueNode* temp= new QueueNode ();
    
    temp ->cost=cost;
    temp ->destNode=j;
    temp->sourceNode= i;
    temp->link = pointer;
    pointer =temp;
    return al;
    }
    
UDGraph* UDGraph:: delete_Edge_p(UDGraph * al, int i, int j)
{   
    QueueNode* temp= new QueueNode ();
    QueueNode* temp1= new QueueNode ();
    temp=al->pointer;
    
        if(temp->link->sourceNode==i && temp->link->destNode==j)
        {
            //cout << "("<<temp->cost<<" "<<temp->sourceNode<<" "<<temp->destNode<< "), "<<endl;
            temp1=temp->link;
            temp->link=temp->link->link;
            return al;
        }
    
    while(temp->link)
    {   
       // cout << "("<<temp->cost<<" "<<temp->sourceNode<<" "<<temp->destNode<< "), "<<endl;
        if(temp->link->sourceNode==i && temp->link->destNode==j)
        {
            temp1=temp->link;
            temp->link=temp->link->link;
            break;
        }
        temp=temp->link;
    }
    return al;
    }
int UDGraph:: print(UDGraph * al)
{
    QueueNode* temp= new QueueNode ();
    temp=al->pointer;
    int total_cost=0;
    
    while(temp)
    {
        cout << "("<<temp->cost<<" "<<temp->sourceNode<<" "<<temp->destNode<< "), "<<endl;
        total_cost+=temp->cost;
        temp=temp->link;
    }
    return total_cost;
}
UDGraph* UDGraph:: delete_Edge(UDGraph *al, int i, int j)
{
    Node * test= al->list[i];
    Node * test1= al->list[j];
    Node * test_j= al->list[i];
    while(test_j->next!=NULL && test_j->next->ver_name !=j)
    {
        test_j=test_j->next;
    } 
    if(test_j)
    {
        Node * temp=new(Node);
        
        if(test_j->next)
        {
        temp= test_j->next;
        test_j->next=test_j->next->next;
        }
        else
        {
            temp= test_j->next;
        }
        free(temp);
    }
//    cout<<"One node deleted"<<endl;
    test_j=test1;
    
    while(test_j->next!=NULL && test_j->next->ver_name !=i)
    {
        test_j=test_j->next;
    } 
    
    if(test_j)
    {
        Node * temp1=new(Node);
    
        if(test_j->next)
        {
        temp1= test_j->next;
        test_j->next=test_j->next->next;
        }
        else
        {
            temp1= test_j->next;
        }
        
        
        free(temp1);
    }
//    cout<<"one node deleted========"<<endl;
    
               return al;

               
               
}
               
// main()
// {
//     UDGraph *aList;
//     aList = new (UDGraph);
//     cout << "create_graph" << endl;
//     aList = aList->read_graph("filename.txt");
//     cout<<endl;
//     cout<<"Number of nodes"<<aList->number_nodes<<endl;
//     aList->printGraph(aList);
//     //->printGraph(aList);
//     //aList->printGraph(aList);
//     int cost1=aList->cost(aList,0,1);
//     cout<<"cost "<<cost1<<endl;
//     // int index= aList->next_Vertex(aList,2,0);
//     // aList = aList->add_Edge(aList,0,4,10);
//     // aList = aList->add_Edge(aList,1,4,2);
//     // cout<<endl;
//     // aList->printGraph(aList);
    
//     aList = aList->delete_Edge(aList,0,2);
    
//     cout<<endl;
//     aList->printGraph(aList);
    
// }


