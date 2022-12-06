


/************************************
Author: Cristian López Del Alamo
Course: Data Structure
*************************************/
//ALUMNO: DIEGO FRANCISCO APAZA ANDALUZ

#include <list>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;


template<class V, class A>
class Edge;



template<class V,class A>//tipo de vertice y tipo de arista
class Vertex	//VERTICE
{
    public:
     V                   m_Dato;   //DATO DE TIPO STRING
     list<Edge<V,A> >    m_list_Edge; //LISTA DE ADYACENCIAS ME GUARDA ARISTAS CON TIPO DE DATO "A" Y "V" 
	 								//NECESITA SABER A QUE NODO LLEGA
  
    Vertex(V vertice)
    {
        m_Dato = vertice;
    }

};



template<class V,class A> //ARISTA
class Edge
{
    public:
        A                   m_Dato;
        Vertex<V,A>  *      m_pVertex; //PUNTERO A UN VERTICE

        Edge(A a, Vertex<V,A>  *q=0)
        {
            m_Dato = a;
            m_pVertex=q;
        }
};



template<class V,class A>
class Graph //GRAFO
{
   private:
      list< Vertex <V,A> >   m_Graph; //LISTA DE VERTICES 
   public:
   	Graph(){};

   void Insert(V Vertice) //INSERTAR VERTICE
   {
        m_Graph.push_back(Vertex<V,A>(Vertice));
   };
   
   void Insert_Edge(A a, V v1, V v2) //INSERTAR ARISTA
   {
   	
         Vertex<V,A>  * p = find_Vertice(v1);
         Vertex<V,A>  * q = find_Vertice(v2);
  
        
   };
   
   /*
   Vertex<V,A>  *  find_Vertex(V v)
   {
    typedef typename   list< Vertex <V,A> > ::iterator Iterator_Vertex; 
    Iterator_Vertex  p = std::find(m_Graph.begin(), m_Graph.end(), Vertex<V,A>(v));
    return *(*p);
   } 
   */
	Vertex<V,A> * find_Vertice(V v)
	{
		Vertex <V,A> * aux = m_Graph.begin();
		int a=0;
		while(aux)
		{
			if(aux->m_Dato == v)
			{
				return aux;
			}
			typedef typename   list< Vertex <V,A> > ::iterator Iterator_Vertex; 
			aux= std::next(m_Graph.begin(),a);
			a++;
		}
		return NULL;
		
	}
     
     
     
    /*
   
   bool find_edge(V v, A a)
   {
        Vertex<V,A>  * p = find_Vertex(v);
        // write your code here 
         
		return 0;
   }
   */
   
   void Print()
   {
       typedef typename   list< Vertex <V,A>>::iterator Iterator_Vertex; 
       typedef typename   list< Edge <V,A>>::iterator Iterator_Edge; 
       
       Iterator_Vertex it = m_Graph.begin();
       Iterator_Edge it2 = m_list_Edge.begin();
       
       for(; it != m_Graph.end();it++)
       {
       	  
          cout<<it->m_Dato<<endl;
          for(; it2 != m_list_Edge.end();it2++)
          	cout<<it2->m_Dato<<endl;
          	
     
       }

   }

   

};

int main()
{
   Graph<string, int>  G;
   G.Insert("Arequipa");
   G.Insert("Lima");
   G.Insert("Cusco");
   G.Insert("Puno");
   G.Insert("Tacna");
   G.Insert("Ica");

   G.Insert_Edge(100,"Arequipa","Cusco");
   G.Insert_Edge(160,"Tacna","Cusco");
   G.Insert_Edge(1500,"Arequipa","Lima");
   G.Insert_Edge(1500,"Puno","Ica");
   G.Insert_Edge(1070,"Cusco","Puno");
   G.Insert_Edge(400,"Arequipa","Puno");
   G.Insert_Edge(600,"Ica","Tacna");
   
   G.Print();

   return 0;
        
}
