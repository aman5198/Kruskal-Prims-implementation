#include"Krushkal.h"


int main(){
    struct timespec startp, endp, startk,endk; 
    double time_taken_prim, time_taken_krushal;
    UDGraph *aList;
    aList = new (UDGraph);
    cout << "create_graph" << endl;
    aList = aList->read_graph("filename.txt");
    cout<<endl;
    cout<<"Number of nodes"<<aList->number_nodes<<endl;
    aList->printGraph(aList);

    cout << endl << endl << "---------------------------------------------------------------------------------------------------" << endl << endl;
    priorityQueue* pq;
    pq= new priorityQueue(aList->number_nodes);
    
    UDGraph* mst_prims=new UDGraph;
    int runtime=0;

    clock_gettime(CLOCK_MONOTONIC, &startp); 
    // start timer
    mst_prims=prims(aList,pq);
    // apply prims algo on Graph G1 and returns PRIMs MST G3
    clock_gettime(CLOCK_MONOTONIC, &endp); 
    // stop timer

    time_taken_prim = (endp.tv_sec - startp.tv_sec) * 1000000 + (endp.tv_nsec - startp.tv_nsec) / 1000; 
    time_taken_prim = time_taken_prim/1000;  // time difference in miliseconds
    int total_cost= mst_prims->print(mst_prims);
    cout << "Prim’s algorithm MST (total cost: " << total_cost << "; runtime: " << time_taken_prim << "ms )" << endl << endl;
    cout<<"------------------------------End Prims-------------------------------------"<<endl << endl << endl;

    
    UDGraph *mst_kruskal;
    mst_kruskal = new (UDGraph);

    Krushkal *g1;
    QueueNode* pointer = new QueueNode();
    g1 = new Krushkal();
    clock_gettime(CLOCK_MONOTONIC, &startk); 
    // start timer
    mst_kruskal = KRUSHAL_ALGO(aList);
    // apply kruskal algo on Graph G1 and returns PRIMs MST G3
    clock_gettime(CLOCK_MONOTONIC, &endk); 
    // stop timer

    time_taken_krushal = (endk.tv_sec - startk.tv_sec) * 1000000 + (endk.tv_nsec - startk.tv_nsec) / 1000; 
    time_taken_krushal = time_taken_krushal/1000;  // time difference in miliseconds
    total_cost= mst_kruskal->print(mst_kruskal);
    cout << "Kruskal’s algorithm MST (total cost: " << total_cost << "; runtime: " << time_taken_prim << "ms )" << endl;
     cout<<"End Krushkal"<<endl;



}