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
  bool operator>(const Edge &compare)
  {
      return this->weight > compare.weight;
  } 
};
template <class T>
class Edgelist {
    public:
    struct indata
        {
            T data;
            indata *next,*last;
            
        };
        indata * head; // pointer to the header node
        indata * tail; // pointer to the trailer node
        size_t nodeCount; // keep track of number of nodes
        Edgelist(); 
        bool empty();
        void push_back(const T &);
        size_t size();
        T& operator[](const int &);
        void insert(const T &); 
        T pop();
        
   };
    template <class T>
        Edgelist<T>::Edgelist() {
            this->nodeCount = 0;
            head= new indata;
            tail = new indata;
            head->next = tail;
            tail->next = NULL;
            head->last =NULL;
            tail->last = head;
        }

        template <class T>
        bool Edgelist<T>::empty()
         {
            return this->nodeCount == 0;
        }
        
        
    
        // adds an element to the end (insert end)
        template <class T>
        void Edgelist<T>::push_back(const T &newdata)
         {
            indata *prior, *knew;
            prior = tail->last;
            knew = new indata;
            prior->next = knew;
            tail->last = knew;
            knew->next = tail;
            knew->last = prior;
            knew->data = newdata;
            nodeCount++;
        }
    
       
        
        // return the size of the list
        template <class T>
        size_t Edgelist<T>::size() {
            return this->nodeCount;
        }

        template <class T>
        T &Edgelist<T>::operator[](const int &i) 
        {
            if (!empty())
            {
                indata *current =head->next; 
                for (int z=0 ; z<i ;z++)
                {
                    current = current->next;
                }
                return current->data;

            }
            else {
                cerr <<"index out of bound"<<endl;
                exit(1);
            }
        }

        template <class T>
        T Edgelist<T>::pop()
        {
            indata *prior, *next;
            prior =  head->next;
            next = prior->next;
            head->next = next;
            next->last = head;
            T retrundata = prior->data;
            delete prior;
            return retrundata;
        }
    
    
       template<class T>
        void Edgelist<T>::insert( const T &data)
        {
            indata *prior, *knew, *next;
            knew= new indata;
            knew->data = data;
            prior =head;
            next = head->next;
            while(next != tail && knew->data > next->data)
            {
                prior = next;
                next = next->next;
            }
             prior->next = knew;
             knew->last=prior;
             knew->next =next;
             next->last = knew; 
             nodeCount++;
             
        }
