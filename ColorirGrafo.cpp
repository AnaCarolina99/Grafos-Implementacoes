#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Classe do grafo que sera colorido
class Grafo{

    public:
    string color;
    int n;
    

    Grafo(){
        color = "White";
        n = -1;
    }

};


void visit(Grafo ver[], int** edge, int a, int b);
bool veri(Grafo ver[], int** edge, int i, int k);


int main(){

    bool resp;
    int i,j,k,l,s,c1,c2;
    
    cin >> s;
    
    //Loop para percorrer a quantidade obtida pela entrada "s"
    while(s > 0){

        cin >> i;
        cin >> j;
        cin >> k;
        cin >> l;

        Grafo vertices[i];

        int** edge;

        edge = (int**)malloc(i * sizeof(int *));

        //Loop com o objetivo de acessar todos os vertices do grafo e colocarem um valor incial 
        for(int a = 0; a < i; a++){

            edge[a] = (int*)malloc(i * sizeof(int));

            for(int b = 0; b < i; b++){

                edge[a][b] = 0;
            }
        }

        //Loop para ler a cor de cada vertice
        for(int a = 0; a < i; a++){

            cin >> vertices[a].n;
        }            

        //Loop de leitura e escrita das arestas adjacentes ao vertice
        for(int a = 0; a < j; a++){

            cin >> c1;
            cin >> c2;

            edge[c1-1][c2-1] = 1;
            edge[c2-1][c1-1] = 1;
        }

        //Verificar se é possivel construir o grafo
        resp = veri(vertices,edge,i,k);
        if(resp){

            cout << "Y"<< endl << endl;

        }else{

            cout << "N"<< endl << endl;

        }

        s--;

    }

    return 0;

}

    //Metodo que retorna um boolean que verifica se é possivel construir o grafo
    bool veri(Grafo ver[], int **edge, int a, int b){

        int c = 0;

        for(int i = 0; i < a; i++){

            for(int j = 0; j < a; j++){

                if((b>0) && (i!=j) && (edge[i][j] == 0) && (ver[i].n != ver[j].n)){

                    edge[i][j] = 1;

                    b--;
                }
            }    
        }

        for(int i = 0; i < a; i++){

            if(ver[i].color == "White"){

                visit(ver,edge,i,a);

                c = c + 1;
            }
        }

        if(b > 0 || c > 1){

            return false;

        }else{

            return true;

        }
    }

    //Metodo void com o objetivo de visitar todas as arestas vizinhas e colorir de "cinza"
    void visit(Grafo ver[], int **edge, int a, int b){

        ver[a].color = "Grey";

        for(int i = 0; i < b; i++){

            if(edge[a][i] == 1){

                if(ver[i].color == "White"){

                    visit(ver,edge,i,b);
                }
            }
        }

        ver[a].color = "Black";
    }