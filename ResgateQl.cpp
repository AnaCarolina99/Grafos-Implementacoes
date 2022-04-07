#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

// Classe do grafo de queda livre
class Grafo{

    public:
    int i,j,inicio;

    Grafo(){
        i = 0;
        j = 0;
        inicio = -1;
    }

};

void min(Grafo v[], int n, double **edge);

int main(){

    int a,b;

    cin>> a;
    
     //Loop para percorrer a quantidade obtida pela entrada "a"
    while (a > 0)
    {
        cin>> b;

        Grafo vertices[b];
        double ** edge;
        double valor = 0;

        edge = (double **)malloc(b*sizeof(double *));

        //Loop com o objetivo de acessar todos os vertices do grafo e colocarem um valor incial 
        for (int i = 0; i < b; i++)
        {
            edge[i] = (double *)malloc(b*sizeof(double));

                for (int j = 0; j < b; j++)
                {
                    edge[i][j] = 0.0;
                }
        }
        //Loop que recebe como entrada as coordenadas
        for (int i = 0; i < b; i++)
        {
            cin >> vertices[i].i;
            cin >> vertices[i].j;
        }

        //Loop para calcular a distancia entre as pessoas envolvidas
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < b; j++)
            {
                edge[i][j] = sqrt(pow((vertices[i].i - vertices[j].i),2) + pow((vertices[i].j - vertices[j].j),2));
            }
            
        }

        min(vertices,b ,edge);

        //Loop com a função de calcular o peso total das respectivas arestas
        for (int i = 0; i < b; i++)
        {
            valor += edge[i][vertices[i].inicio];
        }

        cout << fixed << setprecision(2);
        cout << valor/100 << endl;
        cout << endl;
        a--;

    }
    return 0;
    
}

//Metodo void com a funcao de calcular o peso minimo 
void min(Grafo v[], int n ,double **edge){

        int i,j,inicio;
        double valorPeso = 99999;
        v[0].inicio = 0;
        j = 0;

        while (true)
        {
            inicio = 1;
            for (int a = 0; a < n; a++)
            {
                if(v[a].inicio != -1){
                    for (int b = 0; b < 5; b++)
                    {
                        if ((a != b) && v[b].inicio == -1)
                        {
                            if(inicio){

                                valorPeso = edge[a][b];
                                j = a;
                                i = b;

                                inicio = 0;
                            }else
                            {
                                if(valorPeso > edge[a][b]){
                                    valorPeso = edge[a][b];

                                    j = a;
                                    i = b;

                                }
                            }
                            
                        }
                        
                    }
                    
                }
            }

            if (inicio == 1)
            {
                break;
            }

            v[i].inicio = j;  
            
        }
        
}
