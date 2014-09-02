/*
 * 	ASA - P1
 *
 *  	Author: Francisco Maria Calisto
 *
 *  	Number: 70916
 *
 *
 *  	Author: Carlos Costa
 *
 *  	Number: 69854
 *
 *
 *	Algorithm: Tarjan
 *
 *	Algoritmo de Teoria de Grafos para procurar Componentes Fortemente Ligadas
 *	de um dado Grafo, neste caso Grafo Dirigido.
 *
 */

#include <cstdio>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>


struct node
{
	std::vector < int > edges;
    
    	
	int index;				// Indice do Grafo
	int lowlink;			// Indice mais curto de qq no conhecido
							// como possivel de atingir
    
	bool instack;			// Booleano que ve se esta 
							// na Stack ou nao
					
	int id;					// ID da pessoa (vertice)
	
	node() {};
	node(int Id) : edges(std::vector < int >()), index(0), lowlink(0), instack(false), id(Id) {};

	void add_edge (int id)
    {
		edges.push_back(id);
	}
};

typedef struct node Node;


std::vector < Node > graph;
std::stack < Node* > stack_aux;

int index = 1;

/*
 *  scc: guarda os vertices dos componentes fortemente ligados (scc)
 */

std::vector < std::vector < int > > scc;


int scc_size()
{
	return scc.size();
}

void scc_calc(Node &n)
{
	/*
	 *	define o indece de profundidade do no n para o menor indice nao utilizado
	 */

	n.index = index;
	n.lowlink = index;
	index++;
	stack_aux.push(&n);

	n.instack = true;

	/*
	 *	O seguinte ciclo considera os sucessores do no n
	 */
	
	for (std::vector < int > ::iterator it = n.edges.begin(); it != n.edges.end(); *++it)
	{
			if (graph[*it].index == 0)
	    	{

	    		/*
	    		 *	Se o sucessor ainda nao foi visitado
	    		 *	entao recursao nele proprio
	    		 */

				scc_calc(graph[*it]);
				n.lowlink = std::min(n.lowlink, graph[*it].lowlink);
			}
			else if (graph[*it].instack)
	   		{

	   			/*
	    		 *	Se o sucessor estiver na pilha
	    		 *	entao tambem esta na atual SCC
	    		 */

				n.lowlink=std::min(n.lowlink, graph[*it].index);
			}
	}

	/*
	 *	No caso em que n e uma raiz do no do Grafo entao e feito pop
	 *	da pilha e gera um SCC
	 */

	if (n.lowlink == n.index)
	{
		Node *aux;
		scc.push_back(std::vector < int > ());
		do
		{
			aux = stack_aux.top();
			stack_aux.pop();
			aux->instack = false;
			scc.back().push_back(aux->id);
		}
		while (aux->id != n.id);
	}
}

void scc_create()
{
	for (std::vector < Node >::iterator it = graph.begin(); it != graph.end(); *++it)
	{
		if (it->index == 0)
		{
			scc_calc(*it);
		}
	}
}


/*
 *  scc_max: da-nos o scc com mais elementos
 */

int scc_max()
{
	int max = scc[0].size();
	for (std::vector < std::vector < int > > ::iterator it = scc.begin(); it != scc.end(); *++it)
	{

    /*
     *  unsigned: tem como objectivo poder comparar dois numeros
     */
    
		(unsigned) max < (*it).size() ? max = (*it).size() : max = max;
	}

	return max;
}


int scc_disref ()
{
	int disref = 0;
	int scc_act = 1;		// Actual Componente Fortemente Ligado

	bool broken;
	
	/*
	 *	a seguinte condicao serve para a situacao em que nao temos uma e uma
	 *	so SCC, ou seja, quando todo o nosso Grafo nao e uma SCC.
	 *
	 *	c.c.: retorna 0 (numa situacao em que nem sequer existe Grafo),
	 *	ou conta o numero de scc's;
	 */
	 
	 while(scc_size() != 1)
	 {
	 
		for (std::vector < std::vector <int> >::iterator it = scc.begin(); it != scc.end(); *it++)
		{

			/*
     		 *  SCC actual passa a ser o sucessor em 0
     		 */


			scc_act = graph[(*it)[0]].lowlink;
	    
			for (std::vector < int > ::iterator it_in = (*it).begin(); it_in != (*it).end(); *++it_in)
	    	{
				for (std::vector < int > ::iterator it_g = graph[*it_in].edges.begin(); it_g != graph[*it_in].edges.end(); *++it_g)
				{
					if (graph[*it_g].lowlink != scc_act)
		    		{

		    			/*
     		 			 *  Caso em que o LL do sucessor nao e o atual
     		 			 *	entao passa a ser quebrado
     		 			 */

		    				broken = true;
							break;
					}

				}

				if (broken)
				{

					/*
     		 		 *  Caso em que o sucessor ja esta quebrado e acaba
     		 		 */

					break;
				}
		
			}
	    
			if (!broken)
	    	{

	    		/*
     			 *  Caso em que o sucessor nao esta quebrado
     			 *	entao passa a frente
     		 	 */

				disref++;
			}
	    
			broken = false;
		}

		return disref;
	}
	
	return 1;
	
}


int main()
{
	
	int receive, send, nodes, edges;
	
	scanf ("%d %d", &nodes, &edges);
	
	for (int i = 0; i < nodes; i++)
	{
		graph.push_back(Node(i));
	}
	
	for (int i = 0; i < edges; i++)
	{
		scanf ("%d %d", &send, &receive);
		graph[send - 1].add_edge(receive - 1);
	}
	
	scc_create();
	
	printf ("%d\n", scc_size());
	printf ("%d\n", scc_max());
	printf ("%d\n", scc_disref());
	
	return 0;
}
