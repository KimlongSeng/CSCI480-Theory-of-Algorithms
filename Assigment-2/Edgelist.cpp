#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

class ParPtrTree {
  
  public:
    // constructor
    int *parents; // parent pointer vector
    int *weights; // weights for weighted union
    ParPtrTree(size_t size) : parents( new int[size]), weights (new int [size]) {
        for(int i=0; i < size; i++)
        {
            weights[i]= -1;
            parents[i]= -1;
        }
         //create parents vector
         // each node is its own root to start
         // set all base weights to 1
    }
    int FIND(int node) {
    if (parents[node] == -1) return node;
    parents[node] = FIND(parents[node]);
    return parents[node];
}

// Merge two subtrees if they are different
void UNION(int node1, int node2) {
    int root1 = FIND(node1);
    int root2 = FIND(node2);
    // MERGE two trees
    if (root1 != root2) {
        if (weights[root1] < weights[root2]) {
            parents[root1] = root2;
            weights[root2] += weights[root1];
        }
        else {
            parents[root2] = root1;
            weights[root1] += weights[root2];
        }
    }    
}
};

struct Edge {
    int src , des , weight;
  string cityname ;
  Edge* next, *last;
};

class Edgelist {
    public:
        Edge * head; // pointer to the header node
        Edge * tail; // pointer to the trailer node
        size_t nodeCount; // keep track of number of nodes
        
    public:
        Edgelist() {
            this->nodeCount = 0;
            head= new Edge;
            tail = new Edge;
            head->next = tail;
            tail->next = NULL;
            head->last =NULL;
            tail->last = head;
        }
    
        bool empty() const {
            return this->nodeCount == 0;
        }
    
        // adds an element to the end (insert end)
        void push_back(int src ,int des ,int weight) {
            Edge *prior, *knew;
            prior = tail->last;
            knew = new Edge;
            prior->next = knew;
            tail->last = knew;
            knew->next = tail;
            knew->last = prior;
            knew->src = src;
            knew->weight = weight;
            knew->des = des;
            nodeCount++;
        }
    
       
        
        // return the size of the list
        size_t size() {
            return this->nodeCount;
        }

        // return string representation of linked list
        string toString() {
            stringstream ss;
            ss << "[";
            Edge * curr = head->next; // ignore header and stop before trailer
            while (curr != tail) {
                ss << " " << curr->src << curr->des << curr->weight;
                curr = curr->next;
            }
            ss << " ]";
            return ss.str();
        }
        Edge pop()
        {
            Edge *prior, *next;
            prior =  head->next;
            next = prior->next;
            head->next = next;
            next->last = head;
            Edge tempedge ;
            tempedge.src = prior->src;
            tempedge.des =prior->des;
            tempedge.weight= prior->weight;
            delete prior;
            return tempedge;
        }
    
    
       
        void insert(int src ,int des ,int weight)
        {
            Edge *prior, *knew, *next;
            knew= new Edge;
            knew->src =src;
            knew->weight = weight;
            knew->des = des;
            prior =head;
            next = head->next;
            while(next != tail && knew->weight < next->weight)
            {
                prior = next;
                next = next->next;
            }
             prior->next = knew;
             knew->last=prior;
             knew->next =next;
             next->last = knew;       
        }

};