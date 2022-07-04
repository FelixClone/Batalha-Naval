#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;
void limpaTela(){
    system("clear");
}
void iniciaTabuleiro(char tabuleiro[15][15],char mascara[15][15]){
    for(int linha=0;linha<15;linha++){
        for(int coluna=0;coluna<15;coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}
char turnIntoLyrics(int cont){
    char letter;
    switch(cont){
        case 0:
            letter = 'A';
            break;
        case 1:
            letter = 'B';
            break;
        case 2:
            letter = 'C';
            break;
        case 3:
            letter = 'D';
            break;
        case 4:
            letter = 'E';
            break;
        case 5:
            letter = 'F';
            break;
        case 6:
            letter = 'G';
            break;
        case 7:
            letter = 'H';
            break;
        case 8:
            letter = 'I';
            break;
        case 9:
            letter = 'J';
            break;
        case 10:
            letter = 'K';
            break;
        case 11:
            letter = 'L';
            break;
        case 12:
            letter = 'M';
            break;
        case 13:
            letter = 'N';
            break;
        case 14:
            letter = 'O';
            break;
    }
    return letter;
}
int turnIntoNumber(char letter){
    int number;
    switch(letter){
        case 'a':
            number = 0;
            break;
        case 'b':
            number = 1;
            break;
        case 'c':
            number = 2;
            break;
        case 'd':
            number = 3;
            break;
        case 'e':
            number = 4;
            break;
        case 'f':
            number = 5;
            break;
        case 'g':
            number = 6;
            break;
        case 'h':
            number = 7;
            break;
        case 'i':
            number = 8;
            break;
        case 'j':
            number = 9;
            break;
        case 'k':
            number = 10;
            break;
        case 'l':
            number = 11;
            break;
        case 'm':
            number = 12;
            break;
        case 'n':
            number = 13;
            break;
        case 'o':
            number = 14;
            break;
        default:
            number = 15;
            break;
    }
    return number;
}
void exibeMapa(){
    char normal[] = {0x1b,'[','1',';','3','9','m',0};
    cout<<normal;
    for(int cont=0;cont<15;cont++){
        char letter;
        
        if(cont==0){
            cout<<"      ";
        }
        cout<<turnIntoLyrics(cont)<<" ";
        
    }
    cout<<"\n";
    for(int cont=0;cont<15;cont++){
        if(cont==0){
            cout<<"      ";
        }
        cout<<"| ";
    }
    cout<<"\n";
}
void exibeTabuleiro(char tabuleiro[15][15],char mascara[15][15],bool mostraGabarito){
    char blue[] = {0x1b,'[','1',';','3','4','m',0};
    char green[] = {0x1b,'[','1',';','3','2','m',0};
    char yellow[] = {0x1b,'[','1',';','3','3','m',0};
    char pink[] = {0x1b,'[','1',';','3','5','m',0};
    char gray[] = {0x1b,'[','1',';','3','0','m',0};
    char red[] = {0x1b,'[','1',';','3','1','m',0};
    char normal[] = {0x1b,'[','1',';','3','9','m',0};

    
    cout<<normal;
    for(int linha=0;linha<15;linha++){
        if(linha<10){
            cout<<" "<<linha<<" - ";
        }else{
            cout<<linha<<" - ";
        }
        for(int coluna=0;coluna<15;coluna++){
            switch(mascara[linha][coluna]){
                case 'A':
                    cout<< blue<<" "<<mascara[linha][coluna]<<normal;
                    break;
                case 'S':
                    cout<< green<<" "<<mascara[linha][coluna]<<normal;
                    break;
                case 'E':
                    cout<< yellow<<" "<<mascara[linha][coluna]<<normal;
                    break;
                case 'H':
                    cout<< pink<<" "<<mascara[linha][coluna]<<normal;
                    break;
                case 'P':
                    cout<< gray<<" "<<mascara[linha][coluna]<<normal;
                    break;
                case 'C':
                    cout<< red<<" "<<mascara[linha][coluna]<<normal;
                    break;
                default:
                    cout<<" "<<mascara[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }

    if(mostraGabarito==true){
        for(int linha=0;linha<15;linha++){
            for(int coluna=0;coluna<15;coluna++){
                cout <<" "<<tabuleiro[linha][coluna];
            }
            cout << "\n";
        }
    }
    
    

}
void exibeGabaritoFinal(char tabuleiro[15][15]){
    char red[] = {0x1b,'[','1',';','3','1','m',0};
    char normal[] = {0x1b,'[','1',';','3','9','m',0};
    char blue[] = {0x1b,'[','1',';','3','4','m',0};
    char green[] = {0x1b,'[','1',';','3','2','m',0};
    char yellow[] = {0x1b,'[','1',';','3','3','m',0};
    char pink[] = {0x1b,'[','1',';','3','5','m',0};
    char gray[] = {0x1b,'[','1',';','3','0','m',0};

    for(int linha=0;linha<15;linha++){
        if(linha<10){
            cout<<" "<<linha<<" - ";
        }else{
            cout<<linha<<" - ";
        }
        for(int coluna=0;coluna<15;coluna++){
            switch(tabuleiro[linha][coluna]){
                case 'A':
                    cout<< blue<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                case 'S':
                    cout<< green<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                case 'E':
                    cout<< yellow<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                case 'H':
                    cout<< pink<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                case 'P':
                    cout<< gray<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                case 'C':
                    cout<< red<<" "<<tabuleiro[linha][coluna]<<normal;
                    break;
                default:
                    cout<<" "<<tabuleiro[linha][coluna];
                    break;
            }
        }
        cout << "\n";
    }
}
void posicaoDosBarcos(char tabuleiro[15][15]){
    int quantidadeDeSubMarino = 4, quantidadeDeHidroAviao=3,quantidadeDeEncouracado=2,quantidadeDePortaAviao=1,quantidadeDeCruzadores=3;
    int quantidadePosicionada=0;
    while(quantidadePosicionada < quantidadeDeSubMarino){
        int linhaAleatoria = rand() % 15;
        int colunaAleatoria = rand() % 15;
        if(tabuleiro[linhaAleatoria][colunaAleatoria]=='A'){
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'S';
            quantidadePosicionada++;
        }
        
    }
    quantidadePosicionada=0;

    //Hidro Aviao

    while(quantidadePosicionada<quantidadeDeHidroAviao){
        int linhaAleatoria = rand() % 15;
        int colunaAleatoria = rand() % 15;
        
        if((tabuleiro[linhaAleatoria][colunaAleatoria]=='A')&&(linhaAleatoria>=0 && linhaAleatoria<13)){
            if((tabuleiro[linhaAleatoria][colunaAleatoria+2]=='A')&&(colunaAleatoria>0 && colunaAleatoria<12)){
                if(tabuleiro[linhaAleatoria+1][colunaAleatoria+1]=='A'){
                    tabuleiro[linhaAleatoria][colunaAleatoria] = 'H';
                    tabuleiro[linhaAleatoria][colunaAleatoria+2] = 'H';
                    tabuleiro[linhaAleatoria+1][colunaAleatoria+1] = 'H';
                    quantidadePosicionada++;    

                }
            }
        }    
    }
    quantidadePosicionada=0;

    //Encouraçado

    while(quantidadePosicionada<quantidadeDeEncouracado){
        int linhaAleatoria = rand() % 15;
        int colunaAleatoria = rand() % 15;
        if((tabuleiro[linhaAleatoria][colunaAleatoria]=='A'&&tabuleiro[linhaAleatoria][colunaAleatoria+1]=='A')&&(tabuleiro[linhaAleatoria][colunaAleatoria+2]=='A'&&tabuleiro[linhaAleatoria][colunaAleatoria+3]=='A')){
            if(colunaAleatoria<11){
                tabuleiro[linhaAleatoria][colunaAleatoria] = 'E';
                tabuleiro[linhaAleatoria][colunaAleatoria+1] = 'E';
                tabuleiro[linhaAleatoria][colunaAleatoria+2] = 'E';
                tabuleiro[linhaAleatoria][colunaAleatoria+3] = 'E';
                quantidadePosicionada++;
            }
        }
    }
    quantidadePosicionada=0;

    //Porta-aviões 

    while(quantidadePosicionada<quantidadeDePortaAviao){
        int linhaAleatoria = rand() % 15;
        int colunaAleatoria = rand() % 15;
        if((tabuleiro[linhaAleatoria][colunaAleatoria]=='A'&&tabuleiro[linhaAleatoria][colunaAleatoria+1]=='A')&&(tabuleiro[linhaAleatoria][colunaAleatoria+2]=='A'&&tabuleiro[linhaAleatoria][colunaAleatoria+3]=='A')){
            if(tabuleiro[linhaAleatoria][colunaAleatoria+4]=='A'&&colunaAleatoria<10){
                tabuleiro[linhaAleatoria][colunaAleatoria] = 'P';
                tabuleiro[linhaAleatoria][colunaAleatoria+1] = 'P';
                tabuleiro[linhaAleatoria][colunaAleatoria+2] = 'P';
                tabuleiro[linhaAleatoria][colunaAleatoria+3] = 'P';
                tabuleiro[linhaAleatoria][colunaAleatoria+4] = 'P';
                quantidadePosicionada++;
            }
        }
    }

    quantidadePosicionada=0;

    //Cruzadores

    while(quantidadePosicionada<quantidadeDeCruzadores){
        int linhaAleatoria = rand() % 15;
        int colunaAleatoria = rand() % 15;
        if(tabuleiro[linhaAleatoria][colunaAleatoria]=='A'&&tabuleiro[linhaAleatoria][colunaAleatoria+1]=='A'){
            if(colunaAleatoria<13){
                tabuleiro[linhaAleatoria][colunaAleatoria] = 'C';
                tabuleiro[linhaAleatoria][colunaAleatoria+1] = 'C';
                quantidadePosicionada++;
            }
        }
    }

}
void verificaTiro(char tabuleiro[15][15],int linhaJogada,int colunaJogada,int *pontos,string *msg){
    switch(tabuleiro[linhaJogada][colunaJogada]){
            case 'S':
                *pontos = *pontos + 50;
                *msg = "Belo tiro, vc acertou um Submarino (50 pts)";
                break;
            case 'E':
                *pontos = *pontos + 13;
                *msg = "Belo tiro, vc acertou um Encouraçado (13 pts)";
                break;
            case 'H':
                *pontos = *pontos + 17;
                *msg = "Belo tiro, vc acertou um Hidroavião (17 pts)";
                break;
            case 'P':
                *pontos = *pontos + 10;
                *msg = "Belo tiro, vc acertou um Porta-aviões(10 pts)";
                break;
            case 'C':
                *pontos = *pontos + 25;
                *msg = "Belo tiro, vc acertou um Cruzador (25 pts)";
                break;
            case 'A':
                *msg = "Mais sorte na proxima vez, vc acertou a agua";
                break;
        }  
}
void menuInicial();

void Jogo(string nomeDoJogador){
    char tabuleiro[15][15],mascara[15][15];
    int linhaJogada,colunaReal; // if estado_deJogo == 0, game over
    char colunaJogada;
    char red[] = {0x1b,'[','1',';','3','1','m',0};
    char normal[] = {0x1b,'[','1',';','3','9','m',0};
    int pontos=0,tentativas=0,maximoDeTentativas=15,opcao=1;
    string mensagem = "Bem vindo ao jogo";

    iniciaTabuleiro(tabuleiro,mascara);
    posicaoDosBarcos(tabuleiro);
    while(tentativas<maximoDeTentativas){
        limpaTela();
        exibeMapa();
        exibeTabuleiro(tabuleiro,mascara,false);
        cout << "\nPontos: "<<pontos<<"\n"<<red<<"Bombas restantes: "<<normal<<maximoDeTentativas - tentativas<<"\n";
        cout<<mensagem;
        
        linhaJogada = -1;                        //verificar dados
        colunaReal = -1;

        while((linhaJogada<0||colunaReal<0)||(linhaJogada>14||colunaReal>14)){
            cout <<"\n\n"<<nomeDoJogador<<", digite um "<<red<<"NUMERO"<<normal<<" para "<<red<<"LINHA: "<<normal;
            cin >> linhaJogada;
            cout <<"\n"<<nomeDoJogador<<", digite uma "<<red<<"LETRA"<<normal<<" para "<<red<<"COLUNA: "<<normal;
            cin >> colunaJogada;
            colunaReal = turnIntoNumber(tolower(colunaJogada));
        }

        
        verificaTiro(tabuleiro,linhaJogada,colunaReal,&pontos,&mensagem);

        mascara[linhaJogada][colunaReal] = tabuleiro[linhaJogada][colunaReal];
        tentativas++;
    }
    limpaTela();
    exibeMapa();
    exibeGabaritoFinal(tabuleiro);
    cout<<"\nFim de jogo, o que deseja fazer?";
    cout<<"\n1- Jogar novamente\n2- Ir para o menu inicial\n3- Sair\n";
    cin >> opcao;
    switch(opcao){
        case 1:
            Jogo(nomeDoJogador);
            break;
        case 2:
            menuInicial();
            break;
        case 3:
            limpaTela();
            cout<<red<<"\t  GAMEOVER\n"<<normal;
            cout<<"----------------------------\n";
            cout<<"Nome:\t"<<nomeDoJogador;
            cout<<"\n----------------------------\n";
            cout<<"Pontos:\t"<<pontos;
            cout<<"\n----------------------------\n";
            break;
        }
    


}

void menuInicial(){
    int opcao = 0;
    string nomeDoJogador;
    while(opcao <1 || opcao>3){
        cout << "\tBem vindo ao Batalha Naval\n\n";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER\n";
        cin >> opcao;
        limpaTela();
        switch(opcao){
            case 1:
                cout<<"Qual seu nome?\n";
                cin>>nomeDoJogador;
                Jogo(nomeDoJogador);
                break;
            case 2:
                break;
            case 3:
                cout << "Ate mais U.U\n";
                break;
        }
    }
}
int main(){
    srand((unsigned)time(NULL)); 


    menuInicial();

    return 0;
}