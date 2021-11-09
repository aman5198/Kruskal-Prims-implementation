#include "priority_queue.h"
#include<sys/time.h>

UDGraph* prims(UDGraph* aList,priorityQueue* pq){
    UDGraph* mst= new (UDGraph);
    mst=mst->Initialize_Graph(aList->number_nodes);

    pQueueNode temp;
    int inMST[aList->number_nodes],weigth[aList->number_nodes],prev[aList->number_nodes];
    int src,dest,cost;
    int i=1;
    while(i < pq->queueCapacity){
        inMST[i]=0;
        weigth[i]=MAX_VAL;
        pq->insertValue(i,-1,MAX_VAL);
        i++;
    }


    weigth[0]=0;
    pq->insertValue(0,-1,0);

 

    while(pq->queueSize > 0){
        temp=pq->getMin();
        // cout << "chck" << temp.cost << endl;
        src=temp.sourceNode;
        cost=temp.cost;
        Node* r=aList->list[temp.sourceNode];
                        
        while(r != NULL){

            if(pq->inQueue(r->ver_name) && r->cost < weigth[r->ver_name]){
                if(weigth[r->ver_name] != MAX_VAL){
                    mst->delete_Edge_p(mst,prev[r->ver_name],r->ver_name);
                }
                weigth[r->ver_name]=r->cost;
                prev[r->ver_name]=src;
                pq->decreaseKey(src,r->ver_name,r->cost);
                mst->add_Edge(mst,src,r->ver_name,r->cost);
            }
            r=r->next;  
        }
    }

    cout<<"Number of Nodes in MST "<<mst->number_nodes<<endl;
    return mst;
}

// int main()
// {       
//     struct timespec start, end; 
//     double time_taken_prim, time_taken_krushal;
//     UDGraph *aList;
//     aList = new (UDGraph);
//     cout << "create_graph" << endl;
//     aList = aList->read_graph("filename.txt");
//   //  cout << aList->list[5]->ver_name << endl;
//     cout<<endl;
//     cout<<"Number of nodes"<<aList->number_nodes<<endl;
//     aList->printGraph(aList);

//     priorityQueue* pq;
//     pq= new priorityQueue(aList->number_nodes);
    
//     UDGraph* mst_prims=new UDGraph;
//     int runtime=0;

//     clock_gettime(CLOCK_MONOTONIC, &start); 
//     // start timer
//     mst_prims=prims(aList,pq);
//     // apply kruskal algo on Graph G1 and returns PRIMs MST G3
//     clock_gettime(CLOCK_MONOTONIC, &end); 
//     // stop timer

//     time_taken_prim = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000; 
//     time_taken_prim = time_taken_prim/1000;  // time difference in miliseconds
//     int total_cost= mst_prims->print(mst_prims);

//     cout << "Prim’s algorithm MST (total cost: " << total_cost << "; runtime: " << time_taken_prim << " )" << endl;
//     //  cout<<"Total_cost"<<total_cost<<endl;
//     //  cout<<"Time Taken "<<time_taken_prim<<endl;
//      cout<<"End Prims"<<endl;

//}