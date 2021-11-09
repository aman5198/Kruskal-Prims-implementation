#include <iostream>

using namespace std;

class MFSET{

    int total_nodes;
    int *component;
    int *nodes_in_component; 

public:

    MFSET(int size){
        total_nodes = size;
        component = new int[size];
        nodes_in_component = new int[size];
        for(int i = 0; i < size; i++)
        {
            nodes_in_component[i]=0;
        }
    }

    void merge(int, int);
    int find(int); 
    void initial(int, int);

};

void MFSET:: merge(int A, int B){

    if(nodes_in_component[B] > nodes_in_component[A])
    {
        int temp = B;
        B = A;
        A = temp; 
    }

    nodes_in_component[A] = nodes_in_component[A] + nodes_in_component[B];

    for(int node = 0; node < total_nodes; node++)
    {
        if(component[node] == B)
        {
            component[node] = A;
        }
    }

    nodes_in_component[B] = 0;

}

int MFSET:: find(int x){
    return component[x];
} 

void MFSET:: initial(int A, int x){
    component[x] = A;
    nodes_in_component[A]++; 
}

// int main(){
//     MFSET set_a(3);
//     set_a.initial(1,1);
//     set_a.initial(2,2);
//     int mem = set_a.find(1);
//     int mem_a = set_a.find(2);
//     cout<<mem<<" "<<mem_a<<endl;
//     set_a.merge(1,2);
//     mem = set_a.find(1);
//     mem_a = set_a.find(2);
//     cout<<mem<<" "<<mem_a<<endl;
// }