#include "GRAPH_ADT_K.h"

class pQueueNode{
    public:
        int cost;
        int sourceNode;
        int destNode;
};

class priorityQueue{
    public:
        pQueueNode* queue;
        int queueSize;
        int queueCapacity;

        priorityQueue(int capacity){
            
            this->queue=(pQueueNode*) malloc (capacity*sizeof(pQueueNode));
            this->queueSize=0;
            this->queueCapacity=capacity;
        }

        void insertValue(int source,int dest, int cost);
        pQueueNode getMin();
        void decreaseKey(int source, int newdest ,int newCost);
        void swap(pQueueNode* first, pQueueNode* second);
        bool inQueue(int val);
        void restructure(int index);
};

bool priorityQueue::inQueue(int val){
    for(int i=0; i<queueSize;i++){
        if(queue[i].sourceNode==val)return true;
    }
    return false;
}

void priorityQueue::decreaseKey(int source,int newdest,int newcost){
    int i;
    for(i=0;i<queueSize; i++){
        if(queue[i].sourceNode==newdest){
            break;
        }
    }

    queue[i].destNode=newdest;
    queue[i].cost=newcost;

  //  cout << i;
    restructure(0);
 //   cout << "decrease: ";
 //   for(int i=0 ; i < queueSize ; i++){
 //       cout << queue[i].cost << " ";
 //   }
  //  cout << endl;
}

void priorityQueue::swap(pQueueNode* first, pQueueNode* second){
    int temp;

    temp=second->cost;
    second->cost=first->cost;
    first->cost=temp;

    temp=second->sourceNode;
    second->sourceNode=first->sourceNode;
    first->sourceNode=temp;

    temp=second->destNode;
    second->destNode=first->destNode;
    first->destNode=temp;    
}

//Inserting Node at the end then swapping it with its parent until the min heap property is satisfied.
void priorityQueue::insertValue(int source,int dest, int cost){
    if(queueCapacity==queueSize){
        cout << "Queue is full";
        return;
    }

    int index=queueSize;
    queue[index].cost=cost;
    queue[index].sourceNode=source;
    queue[index].destNode=dest;

    queueSize++;
      
    while(index != 0 && queue[(index-1)/2].cost > queue[index].cost){
        swap(&queue[(index-1)/2],&queue[index]);
        index=(index-1)/2;
    }

}

//Recursive method to restructure the queue at index . We are assuming the subpart is already perfectly structured.

void priorityQueue::restructure(int index){
    int left=2*index + 1, right=2*index + 2 , min_element = index;

    if(right < queueSize ){
        if(queue[right].cost < queue[index].cost){
            min_element=right;
        }
    }

    if(left < queueSize){
        if(queue[left].cost < queue[min_element].cost){
            min_element=left;
        }
    }

    if(min_element != index){
        swap(&queue[index],&queue[min_element]);
        restructure(min_element);
    }
}

pQueueNode priorityQueue::getMin(){
    pQueueNode temp;
    if(queueSize == 0){
        cout << "queue is empty";
        return temp;
    }

    temp=queue[0];
    queueSize=queueSize-1;
    queue[0]=queue[queueSize];
    restructure(0);
    // cout << "delete : "; 
    // for(int i=0 ; i < queueSize ; i++){
    //     cout << queue[i].cost << " ";
    // }
   // cout << endl;
    return temp;
}

void addNode(Node *r, priorityQueue* pq,int i){
    if(r != NULL){
        pq->insertValue(i,r->ver_name,r->cost);
//        cout << "("<<r->ver_name<< ","<<r->cost<< "), ";
        addNode(r->next,pq,i);
    }
}

// int main()
// {
//     UDGraph *aList;
//     aList = new (UDGraph);
//     cout << "create_graph" << endl;
//     aList = aList->read_graph("filename.txt");
//     cout<<endl;
//     cout<<"Number of nodes"<<aList->number_nodes<<endl;
//     aList->printGraph(aList);

//     cout << aList->list[5]->ver_name;
//     priorityQueue* pq;
//     pq= new priorityQueue(6);
  
//     for(int i=0;i<5;i++){
//         addNode(aList->list[i],pq,i);
//     }

//     pQueueNode minimum;
//     minimum = pq->getMin();
//     minimum = pq->getMin();
//     minimum = pq->getMin();
//     minimum = pq->getMin();

//     cout << minimum.cost << minimum.destNode << minimum.sourceNode;

//     for(int i=0;i<pq->queueSize;i++){
//         cout << pq->queue[i].cost << " " ;
//     }

// }