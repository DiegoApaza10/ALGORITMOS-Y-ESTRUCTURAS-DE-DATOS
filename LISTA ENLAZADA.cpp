#include<iostream>
using namespace std;
template<class T>
class Nodo
{
   public:
     T    m_Dato;
     Nodo * m_pSig;
   public:
     Nodo(T d)
     {
        m_Dato = d;
        m_pSig =0;
     }
};


template<class T>
class Lista
{
	
   	private:
   		
	    Nodo<T> * m_pHead;
	public:
	    Lista()
	    {
	    	m_pHead =0; 
	    }
	    ~Lista(){}
	      
	    void Add(T d)
	    {
	    	Nodo<T>  * pNew = new Nodo<T>(d);
	        if(!m_pHead) 
	          m_pHead = pNew;
	        else
	        {
	            pNew->m_pSig = m_pHead;
	            m_pHead = pNew;           
	        }
	    }
	      
	    void print()
	    {
	        Nodo<T> * pTmp = m_pHead;
	        while(pTmp)
	        {
	        cout<<pTmp->m_Dato<<" --> ";
	        pTmp = pTmp->m_pSig;
	            
	        }
	    }
	      
	    void delete_last()
		{
			if (m_pHead == NULL){
				cout<<"La lista esta vacia"<<endl;
			}
			else if (m_pHead->m_pSig == NULL){
				delete(m_pHead);
				m_pHead = NULL;
			}
			else{
				Nodo<T> *temp = m_pHead;
				while (temp->m_pSig->m_pSig != NULL) {
					temp = temp->m_pSig;
				}
				delete(temp->m_pSig);
				temp->m_pSig= NULL;
			}
		}
		void printReverse()
		{
			Nodo<T> *temp = NULL ;
			Nodo<T> *prev = NULL ;
			Nodo<T> *actual = m_pHead ;
		    while(actual!= NULL) {
		        temp = actual->m_pSig;
		        actual->m_pSig = prev;
		        prev = actual;
		        actual = temp;
		    }
		    m_pHead = prev;
		    
		    print();
		}					

     
};
int main()
{
  
  Lista<int> A;
  A.Add(4);
  A.Add(14);
  A.Add(24);
  A.Add(44);
  A.Add(64);
  A.print();
  A.delete_last();
  cout<<"\n";
  A.print(); cout<<"\n";
  A.printReverse();
  /*Nodo<int> A(4);
  cout<<"Donde vives?" <<&A<<endl;
   cout<<"Donde vives el dato del nodo?" <<&(A.m_Dato)<<endl;
  cout<<"Tamaño "<<sizeof(Nodo<int>)<<endl;
  cout<<"suma de variables "<<sizeof(int) + sizeof(Nodo<int>*)<<endl;*/
  
  
  return 1;  
}