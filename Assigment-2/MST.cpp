#include <iostream>
#include <fstream>
#include <string>
#include "Edgelist.cpp"

using namespace std;

int KruskalMST(Edgelist& graph, pair<int,int> MST[], int city_id) 
{ 
    if (graph.nodeCount == 0)
        return 0;

    int numMST = city_id;  // initially V disjoint classes  
    ParPtrTree unionfind(city_id);
    int weight = 0;

    while (numMST > 1 && !graph.empty())
    { 
        // pick the smallest edge
        Edge edge = graph.edges.top();
        graph.edges.pop();
        int x = unionfind.FIND(edge.src); // root of src
        int y = unionfind.FIND(edge.dest); // root of dest
        // if src and dest nodes are in different sets
        if (x != y) 
        { 
            int u = edge.src;
            int v = edge.dest;
            // add weight
            weight += edge.weight;
            // the ordering is not required, but...
            if (u > v) swap(u, v);
            // add u->v edge to MST
            MST.push_back({u, v});
            // combine equiv classes
            unionfind.UNION(u, v);
            numMST--; // one less MST
        } 
    } 
    return weight;
}



int main()
{
  Edgelist edgelist;
  Edge edge;

  ifstream  inf("Testdistances.txt");
  string junkline;
  getline(inf,junkline);
  getline(inf,junkline);
  inf >> ws;
  int city_id = 0;
 

while (!inf.eof())
{
  edge.src = city_id;
 
  getline(inf,edge.cityname);
  inf >> ws;
  size_t pos = edge.cityname.find('[');
  if (pos !=string::npos)
  {
    edge.cityname = edge.cityname.substr(0,pos);
  }
int counter =0;
  
  if (edge.cityname.find('*'))
  {
   break;
  }
  while(city_id > counter)
  {
    inf >> edge.weight;
    edge.des= city_id -counter;
    edgelist.insert(edge.src,edge.des,edge.weight);
    counter++; 
  }
  inf >> ws;
  city_id++;
 
}
pair <int,int> MST[city_id-1];




inf.close();
return 0;


}