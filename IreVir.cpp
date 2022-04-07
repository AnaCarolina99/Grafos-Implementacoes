#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>

#define MAX 1000
#define P push_back

using namespace std;

//Criando um objeto de vetor 
typedef vector<int> v;
int visit[MAX]; 
v grafo[MAX], trans[MAX];

int rua1(int i);
int rua2(int i);

int main(){
    int i,j, hand, origin, destiny;
    
    //Loop para ler as entradas e percorrer as ruas
    while(1){

        cin >> i;
        cin >> j;

        if(i== 0 && j ==0){
            break;
        }

        //Loop para incializar os vertices com um valor padrão
        for ( int a = 1; a <= i; a++)
        {
            grafo[a].clear();
            trans[a].clear();
            visit[a] = 0;
        }

        //Loop para percorrer os vertices e adicionar o valor 0 ou 1 para o grafo percorrido
        // se as ruas estão interligadas ou não
        for (int a = 0; a < j; a++)
        {
            cin >> origin;
            cin >> destiny;
            cin >> hand;

            if(hand == 2){
                
                grafo[origin].P(destiny);
                trans[destiny].P(origin);
                grafo[destiny].P(origin);
                trans[origin].P(destiny);
            }
            else{

                grafo[origin].P(destiny);
                trans[destiny].P(origin);
            }
        }
        
        if(rua1(1)!=i){

            cout << "0" << endl;
            continue;
        }

       if(rua2(1)!=i){

            cout << "0" << endl;
            continue;
        }

        cout << "1" << endl;
    }

    

}

//Percorre a 1 rua e retorna o seu valor
int rua1(int i){

    int resp = 1, v;
    visit[i] = 1;

    for(v::iterator it=grafo[i].begin();it!=grafo[i].end();it++){

        v = *it;

        if(!visit[v]){

            resp += rua1(v);
        }
    }
    return resp;
}

//Percorre a 2 transposta da primeira rua e retorna o seu valor
int rua2(int i){

    int resp = 1, v;
    visit[i] = 0;

    for(v::iterator it=trans[i].begin();it!=trans[i].end();it++){

        v = *it;

        if(visit[v]){

            resp += rua2(v);
        }
    }
    return resp;
}