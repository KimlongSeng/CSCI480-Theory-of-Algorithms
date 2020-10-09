#include <iostream>
#include <fstream>
#include <string>
#include "Edgelist.cpp"

using namespace std;

int KruskalMST(Edgelist<Edge>& graph,  int city_id, Edgelist<Edge>& MST) 
{ 
    if (graph.nodeCount == 0)
        return 0;

    int numMST = city_id;  // initially V disjoint classes  
    ParPtrTree unionfind(city_id);
    int weight = 0;
    

    while (numMST > 1 && !graph.empty())
    { 
        // pick the smallest edge
        Edge edge = graph.pop();
        int x = unionfind.FIND(edge.src); // root of src
        int y = unionfind.FIND(edge.des); // root of dest
        // if src and dest nodes are in different sets
        if (x != y) 
        { 
            int u = edge.src;
            int v = edge.des;
            // add weight
           // weight += edge.weight;
            // the ordering is not required, but...
            if (u > v) swap(u, v);
            // add u->v edge to MST
            MST.push_back({u, v, edge.weight});
            // combine equiv classes
            unionfind.UNION(u, v);
            numMST--; // one less MST
        } 
    } 
    return weight;
}



int main()
{
  Edgelist<Edge> edgelist;
  Edgelist<string> name;
  Edge edge;
  

  ifstream  inf("distances.txt");
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
  name.insert(edge.cityname);
  int counter =1;
  
  if (edge.cityname[0] == '*')
  {
   break;
  }
  while(city_id >= counter)
  {
    inf >> edge.weight;
    edge.des= city_id -counter;
    edgelist.insert(edge);
    counter++; 
  }
  inf >> ws;
  city_id++;
  
}

Edgelist<Edge>MST;
KruskalMST(edgelist,city_id,MST);
int total_weight =0;
for (int i=0 ; i < MST.size();i++)
{
  cout << name[MST[i].src] << " " << name[MST[i].des] << ' ' << MST[i].weight<< endl;
  total_weight = total_weight +MST[i].weight;
}

cout << "total Weight : " << total_weight<<endl; 



inf.close();
return 0;


}