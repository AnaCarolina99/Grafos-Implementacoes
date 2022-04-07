#include <cstdlib>
#include <iostream>
#include <string>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

//Classe para os componentes de um grafo 
struct Grafo{

    int i,j,mov;
    
    //Construtor 1
    Grafo(){

    }

    //Construtor 2
    Grafo(int i, int j, int mov) : i(i), j(j), mov(mov){
    }

};

int valorResult1(char c);
int valorResult2(char c);
int menorCaminho(int i, int alvo[], int cavalo[]);
bool verificar(int a, int b, int i);

int main(){

    int i = 30, s = 8, valor1, valor2, valor3 , valor4 ;
    string str = "", str1 = "";
    char s1,s2,s3,s4;

    //Loop para percorrer a quantidade obtida pela entrada "s"
    while (s > 0)
    {
        //1 entrada
        cin >> str;

       s1 = str.at(0);
       s2 = str.at(1);

        valor1 = valorResult1(s1);
        valor2 = valorResult2(s2); 

        //2 entrada
        cin >> str1;

        s3 = str1.at(0);
        s4 = str1.at(1);

        valor3 = valorResult1(s3);
        valor4 = valorResult2(s4);

        int alvo[] = {valor1,valor2};
        int cavalo[] = {valor3,valor4}; 


            cout << "To get from "<< str<< " to "<< str1 << " takes "<< "4" << " knight moves." << endl;

            cout << "To get from "<< str<< " to "<< str1 << " takes "<< menorCaminho(i,alvo,cavalo) << " knight moves." << endl;

        

        s--;
    }
   
}

//Retorna o valor da 1 entrada em valor de int
int valorResult1(char c){
    return (int) c - 87;
}

//Retorna o valor da 2 entrada em valor de int
int valorResult2(char c){
    return (int) c - 48;
}

//Retorna o menor carrinho percorrido entre as 2 entradas
int menorCaminho(int i, int alvo[], int cavalo[]){

    int x[] = {-2,-1,1,2,-2,-1,1,2};
    int y[] = {-1,-2,-2,-1,1,2,2,1};

    queue<Grafo> g;

    g.push(Grafo(cavalo[0],cavalo[1],0));

    int a,b;
    bool neigh[i+1][i+1];
    Grafo gg;

    //Loop que deixa todos os vertices inicialmente falsos
    for(int j = 1; j<= i;j++){

        for(int k = 1; k<= i;k++){

            neigh[j][k] = false;
        }
    }

    neigh[cavalo[0]][cavalo[1]] = true;

    //Loop que verifica os vertices do grafo nao vazios
    while(!g.empty()){

        gg = g.front();
        g.pop();

        if(gg.i == alvo[0] && gg.j == alvo[1]){

            return gg.mov;
        }

        //Loop para percorrer o caminho do cavalo no tabuleiro
        for(int j = 0; j< 8; j++){

            a = gg.i + x[j];
            b = gg.j + y[j];
            
            if(verificar(a,b,i) && !neigh[a][b]){

                neigh[a][b] = true;
                g.push(Grafo(a,b,gg.mov + 1));
                
            }
        }
    }
    return 0;
}

//Verificar se as entradas contem no intervalo dado
bool verificar(int a, int b, int i){

    if(a >= 1 && a <= i && b >= 1 && b <= i)
        return true;
    return false;
}
