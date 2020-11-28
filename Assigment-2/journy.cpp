#include <iostream>
#include <fstream>
#include <string>
#include "Edgelist.cpp"

using namespace std;
Edgelist<string> name;

Edgelist<Edge> neighbors(int node , Edgelist<Edge>& MST)
{
   
    Edgelist<Edge> neighbors;
    for (int i = 0; i < MST.size() ;i++)
    {
        Edge temp_edge = MST[i];
        if (temp_edge.src == node )
        {
            swap(temp_edge.src,temp_edge.des);
            
            neighbors.push_back(temp_edge);
        }
        else if (node == temp_edge.des)
        {
           
            neighbors.push_back(temp_edge);
        }
    }
    return neighbors;
}

void DFS(Edgelist<Edge>& MST, int start, int target)
 {
    Edgelist<bool> visited; 
    
    for(int j =0 ; j<MST.size(); j++)
    {
        visited.push_back(false);
    }

    Edgelist<Edge> vertices;
    Edge temp_edge;
    Edgelist<Edge> path;
    Edgelist<Edge> Finalpath; 
    temp_edge.src = start;
    temp_edge.des = start;
    temp_edge.weight = 0;

    vertices.push_back(temp_edge);

    while(!vertices.empty()) {
       temp_edge = vertices.pop();
       int u = temp_edge.src;
    
       path.push_back(temp_edge);
      
    if (temp_edge.des == target)
    {
        break;
    }

       Edgelist<Edge> neber = neighbors(u, MST);
   
        for(int i=0; i < neber.size(); i++ )
        {
            int v = neber[i].src;

            if (u == v)
            {
                v = neber[i].des;
            }
            if (!visited[v])
            {
                vertices.push_back(neber[i]);
            }
        }
    }


    int last = path[path.size()-1].src;
    int counter = path.size()-1;
 
    Finalpath.push_back(path[counter]);
    
    while (last != start && counter >= 0)
     {
        counter--;
        if(last == path[counter].des)
        {
           Finalpath.push_back(path[counter]);
            last = path[counter].src;
        }

     }
    while (!Finalpath.empty())
    {
        Edge temp_edge2=Finalpath.backpop();
         cout<< name[temp_edge2.src] << ' '<< name[temp_edge2.des] <<' '<<temp_edge2.weight<<endl;
        cout<< temp_edge2.src << ' '<<temp_edge2.des <<' '<<temp_edge2.weight<<endl;
    }
}

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



int main(int argc , char * agrv[])
{
  char* Locationfile = agrv[1];
  char* start = agrv[2];
  char* end = agrv[3];
  Edgelist<Edge> edgelist;
  Edge edge;
  

  ifstream  inf(Locationfile);
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
 
  int counter = 1;

  if (edge.cityname[0]=='*')
  {
   break;
  }
   size_t pos = edge.cityname.find('[');
  if (pos !=string::npos)
  {
    edge.cityname = edge.cityname.substr(0,pos);
  }
  name.insert(edge.cityname);
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
DFS(MST,1 ,22);


cout << " ----------------------"<<endl;



inf.close();
return 0;


}