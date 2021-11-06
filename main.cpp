#include <iostream>
#include <string>

using namespace std;

int modo;

//FUNÇÃO PARA O USUÁRIO INICIAR A INTERAÇÃO COM A MÁQUINA INSERINDO VALOR DINHEIRO
void FunctionStart(){
  cout<<"Qual Modo deseja acessar?\n";
  cout<<"\n";
  cout<<"(1) - Cliente\n(2) - Administrador\n";
  cout<<"\n";
  cin>>modo;
}

int main() {

  //FIZ UMA MATRIZ PARA CADA TIPO DE VARIÁVEL
  int mat_opcao[6][4]={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16},
    {17,18,19,20},
    {21,22,23,24}
  };
  string mat_nome[6][4]={
    {"Salgadinho A", "Salgadinho B", "Salgadinho C", "Salgadinho D"},
    {"Chocolate A", "Chocolate B", "Chocolate C", "Chocolate D"},
    {"Sorvete A", "Sorvete B", "Sorvete C", "Sorvete D"},
    {"Lanche A", "Lanche B", "Lanche C", "Lanche D"},
    {"Refrigerante A", "Refrigerante B", "Refrigerante C", "Refrigerante D"},
    {"Suco A", "Suco B", "Suco C", "Suco D"}
  };
  int mat_quantidade[6][4]={0};
  int mat_qtd_vendida[6][4]={0};
  float mat_preco[6][4]={
    {2,2,2,2},
    {3,3,3,3},
    {4,4,4,4},
    {5.5,5.5,5.5,5.5},
    {6,6,6,6},
    {7,7,7,7},
  };
  
  float qtd_reposicao=0, qtd_vendida=0, dinheiro =0, troco=0;
  float fat_atual=0, fat_futuro=0;
  int opcao_adm;
  int opcao, i=0, j=0;
  //FIM DA DECLARAÇÃO DE VARIÁVEIS

  for(i=0;i<6;i++){
    for(j=0;j<4;j++){
      mat_quantidade[i][j]=5;
    }
  }

  FunctionStart();

  while (modo==1||modo==2){
    //OPERANDO MODO CLIENTE
    if (modo==1){
      
      while (modo==1){ 
        
        cout<<"Insira o dinheiro.\n";
        cin>>dinheiro;

        //SE DINHEIRO FOR MENOR QUE MÍNIMO ESIPULADO
        if (dinheiro<2){
          cout<<"Dinheiro insuficiente. Impossível realizar esta operação.\n"<<endl;
          cout<<"------Próxima Venda------\n";
          cout<<"\n";
          FunctionStart();
          continue;
        }
        if (dinheiro>=2){
          cout<<"Pressione o botão correspondente ao item desejado: ";
          cin>>opcao;
          if (opcao<=0 || opcao>24){
            cout<<"Por favor, refaça a operação e digite uma opção válida.\n"<<endl;
            continue;
          }
        }

        for (i=0; i<6; i++){
          for (j=0; j<4; j++){

            if (mat_opcao[i][j]==opcao) {
              if (dinheiro<mat_preco[i][j]){
                cout<<"Dinheiro insuficiente para este item.\npor favor refaça a operação."<<endl;
                cout<<"\n";
                continue;
              }   
              if (mat_quantidade[i][j]<1){
                cout<<"Pedimos desculpas, produto esgotado. Refaça a operação."<<endl;
                continue;
              }
              else {
                mat_qtd_vendida[i][j]++;
                mat_quantidade[i][j]--;
                troco=dinheiro-mat_preco[i][j];
                cout<<"Seu troco é de R$ "<<troco<<"\n"<<endl;
                cout<<"------Próxima Venda------"<<"\n";
                cout<<"\n";
                FunctionStart(); 
                continue;
              }
            }
          }
        }
      }
    }
    //OPERANDO MODO ADMINISTRADOR
    if (modo==2){
      cout<<"\nDigite o número correspondente à operação desejada:\n(1) - Reposição de Produtos\n(2) - Listagem de Estoque Atual\n(3) - Relatório Faturamento\n";
      cin>>opcao_adm;

      if (opcao_adm==2){
        cout<<"Produto"<<" | "<<"Quantidade\n";
      }
      if (opcao_adm==3){
        cout<<"Produto"<<" | "<<"Faturamento Atual"<<" | "<< "Faturamento Possível\n"; 
      }
      for(i=0;i<6;i++){
        for(j=0;j<4;j++){

          switch (opcao_adm){
            case 1: 
              cout<<"Qual produto gostaria de repor?\n";
              cin>>mat_opcao[i][j];
              if (mat_opcao[i][j]<=0 || mat_opcao[i][j]>24){
                cout<<"Por favor, refaça a operação e digite uma opção válida.\n"<<endl;
                continue;
              }
              else
                cout<<"Quantas unidades gostaria de repor?\n";
                cin>>qtd_reposicao;

                mat_quantidade[i][j]+=qtd_reposicao;
                      
                if (mat_quantidade[i][j]>5){
                  cout<<"Capacidade excedida. Refaça a operação.\n"<<endl;
                  FunctionStart();
                }
              break;

            case 2: 
              cout<<mat_nome[i][j]<<" | "<<mat_quantidade[i][j]<<endl;
              break;

            case 3: 
              cout<<mat_nome[i][j]<<" | "<<mat_qtd_vendida[i][j]*mat_preco[i][j]<<" | "<<(mat_quantidade[i][j]-mat_qtd_vendida[i][j])*mat_preco[i][j]<<endl;
              break;
          }
        }
      }
    }
    FunctionStart();
}         
return 0;
}