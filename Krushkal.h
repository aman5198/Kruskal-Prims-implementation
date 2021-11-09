/*For using Priority_Queue_ADT*/
/*For using MFSET_ADT*/
#include "MFSET.h"
#include "prims.h"
#define Max_Value 10000
class Krushkal
{
    // insert new nodes into adjacency list from given graph
public:
    //int N;
    UDGraph* KRUSHAL_ALGO(UDGraph* graph);
};

UDGraph * KRUSHAL_ALGO(UDGraph* graph)
{
    int n = graph->number_nodes;
    int c = n;
    
    UDGraph* mst_graph;
    mst_graph = new (UDGraph);
    mst_graph = mst_graph->Initialize_Graph(n);
    /*Creating a graph*/
    priorityQueue* pq;
    pq= new priorityQueue(36);
    
    /*Creating an array of Priority_Queue_ADT as Min heap*/
    pQueueNode temp;
    //NODE TEMP; 
    /*Creating an instance of Priority_Queue_ADT to store deleted node*/
    MFSET* M;
    M= new MFSET(n);
    /*Creating an array of MFSET_ADT*/
 //   cout<<"Adding in PQ"<<endl;
    int i,j;
    for(int i=0;i<graph->number_nodes;i++){
        addNode(graph->list[i],pq,i);
    }
  //  cout<<"Done adding  in PQ"<<endl;
    // for(i=0;i<n;i++)
    // {
    //     for(j=i;j<n;j++)
    //     {
    //        if((Cost_of_edge(graph,i,j)!=0) && (Cost_of_edge(graph,i,j)!= Max_Value))
    //         {
    //             /*inserting nodes in a min heap (Priority Queue)*/
    //             Insert_PQ (PQ1, Cost_of_edge(graph,i,j),i,j);
    //         }
    //     }
    // }
    
    /* Allocation of nodes i to i th component so that each vertex belong to a separate component */
//    cout<<"Mfset is Initialised"<<endl;
    for(i=0;i<n;i++)
    {
        M->initial(i,i);
    }
//    cout<<"Mfset is Initialised---Done"<<endl;
//    cout<<"Value of c "<<c<<endl;
    
    while (c!=1)
    {
        /* TEMP stores the min cost node from the min heap top*/
//        cout<<"Iteration++====================="<<endl;
        temp = pq->getMin();
//        cout<< temp.sourceNode <<" "<<temp.destNode<<" "<<temp.cost<<" "<<endl;
        /*Finding the component of the deleted edge vertices*/
        int uc= M->find(temp.sourceNode);
        int vc= M->find(temp.destNode);
//         cout<<"First component"<<uc<<endl;
//         cout<<"Second Component"<<vc<<endl;
        /*If the above 2 components are different then add the edge 
        connecting the 2 vertices of these respective component and 
        merge the 2 components into 1 component*/
        if(uc!=vc)
        {    //cout<<"If is checked"<<endl;
            mst_graph= mst_graph->add_Edge(mst_graph,temp.sourceNode,temp.destNode,temp.cost);
            
            //cout<<"edge added in mst"<<endl;
            M->merge(uc, vc);
           // cout<<"Components are merged"<<endl;
            c=c-1;
        }
    }
    cout<<"Number of Nodes in MST "<<mst_graph->number_nodes<<endl;
    /*Return MST*/
    return mst_graph;
}

// int main()
// {
//     struct timespec start, end; 

//     double time_taken_prim, time_taken_krushal;
//     UDGraph *aList;
//     aList = new (UDGraph);
    
//     UDGraph *mst1;
//     mst1 = new (UDGraph);
//     cout << "create_graph" << endl;
//     aList = aList->read_graph("filename.txt");
//     cout<<endl;
//     cout<<endl<<aList->list[5]->ver_name;
//     cout<<endl<<aList->list[5]->ver_name;
//     cout<<endl<<aList->list[5]->ver_name;
//     cout<<"Number of nodes"<<aList->number_nodes<<endl;
//     aList->printGraph(aList);
//     Krushkal *g1;
//     QueueNode* pointer = new QueueNode();
//     g1 = new Krushkal();
//     clock_gettime(CLOCK_MONOTONIC, &start); 
//     // start timer
//     mst1 = KRUSHAL_ALGO(aList);
//     // apply kruskal algo on Graph G1 and returns PRIMs MST G3
//     clock_gettime(CLOCK_MONOTONIC, &end); 
//     // stop timer

//     time_taken_krushal = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000; 
//     time_taken_krushal = time_taken_krushal/1000;  // time difference in miliseconds
//      int total_cost= mst1->print(mst1);
//      cout<<"Total_cost"<<total_cost<<endl;
//      cout<<"Time Taken "<<time_taken_krushal<<endl;
//      cout<<"End Krushkal"<<endl;
     
//     }