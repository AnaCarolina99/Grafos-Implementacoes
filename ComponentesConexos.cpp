#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

//Classe para os componentes de um grafo
class Componente{
    public:
    char letter;
    string color;

    Componente(){
        letter = 'b';
        color = "White";
    }
};

void visit(int i, Componente vertices[], int** adj, int t);

int main(){
    int i,j,k,l;
    int t;
    int Case = 1;
    char c1,c2;

    cin>> i;
    //Loop para percorrer a quantidade obtida pela entrada "i"
    while(i>0){

        cin>> j;
        cin>> k;

        t = j;
        int **edge;
        Componente vertices[j];
        edge = (int**)malloc(j*sizeof(j * sizeof(int*)));

            //Loop com o objetivo de acessar todos os vertices do grafo e colocarem um valor incial 
            for(int a = 0;a<j;a++){

                edge[a] = (int*)malloc(j * sizeof(int));

                    for (int b = 0; b < j; b++)
                    {
                        edge[a][b] = 0;
                    }
            }

            //Loop para iniciar os vertices com as letras
            for (int a = 0; a < j; a++)
            {
                vertices[a].letter = 97 + a;
            }

            //Loop de leitura e escrita das arestas adjacentes ao vertice
            for (int a = 0; a < k; a++)
            {
                cin >> c1;
                cin >> c2;

                edge[c1-97][c2-97] = 1;
                edge[c2-97][c1-97] = 1;
            }

            cout << "Case #" << Case << ":" << endl;
            l = 0;

            //Loop para visitar todos os vertices "brancos" e acessar o metodo visit
            for (int a = 0; a < j; a++)
            {
                if(vertices[a].color == "White"){
                    visit(a,vertices,edge,t);

                    l = l + 1;
                    cout << endl;
                }
            }

            cout << l << " connected components" << endl;
            cout << endl;
            i--;
            Case++;            
            
    }
    return 0;
}

//Metodo void com o objetivo de visitar todo os vertices adjacentes que estao em branco
void visit(int i, Componente vertices[], int** adj, int t){

    vertices[i].color = "Grey";
    cout << vertices[i].letter << ",";
    
    for (int a = 0; a < t; a++)
    {
        if(adj[vertices[i].letter - 97][a] == 1){
            if (vertices[a].color == "White")
            {
                visit(a,vertices,adj,t);
            }
            
        }
    }

    vertices[i].color = "Black";
    
}