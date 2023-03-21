#include <stdio.h>
#include <string.h>

//DEFININDO O TIPO STRUCT PARA ARMANEZAR AS PESSOAS
struct Pessoa {
    char nome[100];
    int idade;
    char sexo;
    int imunizado;
};

struct Pessoa pessoas[5];

//CRIANDO O ARRAY FILA PARA ORDENAR AS PESSOAS À SEREM IMUNIZADAS
char fila[5][100];
int fim_fila = 1;

#define TAMANHO_FILA 5

//CRIANDO VOIDS PARA ADICIONAR E REMOVER PESSOAS DA FILA
void adicionar_pessoa_na_fila() {
  
    if (fim_fila <= TAMANHO_FILA) {
        strcpy(fila[fim_fila], pessoas[fim_fila].nome);
        fim_fila++;
    }
}

void remover_pessoa_da_fila() {
    if (fim_fila > 0) {
        for (int i = 1; i < fim_fila - 1; i++) {
            strcpy(fila[i], fila[i+1]);
      }
        fim_fila--;
    }
}

void imprimir_fila() {
    for (int i = 1; i <= fim_fila; i++) {
        printf("%d - %s\n", i, fila[i]);
    }
}

//APRESENTANDO O PROGRAMA
int main(void) {
  printf("\nCRIADO POR: VITOR PALADINI\n\nGHS\n\nCom o GHS (Gestão Hospitalar Simplifica), você pode facilmente organizar e gerenciar o seu hospital de forma mais eficiente. Desfrute de uma plataforma intuitiva e funcional que ajudará a simplificar processos e melhorar a qualidade do atendimento aos pacientes.\n\n\n");

  printf("Por favor, informe a capacidade total da sala de triagem, ou seja, o número máximo de pessoas que podem ser acomodadas no local:\n\nWARNING: LIMITE MIN 3 PESSOAS, MÁX.5 PESSOAS\n");

//SCANF DO MÁXIMO DA FILA DE TRIAGEM E DOSES
  int total_triagem;

  scanf("%d", &total_triagem);

  while((total_triagem < 3) || (total_triagem > 5)){
    
    printf("\nWARNING: CAPACIDADE NÃO ATENDE OS REQUISITOS, LIMITE MIN 3 PESSOAS, MÁX.5 PESSOAS\n\n");

     printf("Por favor, informe a capacidade total da sala de triagem, ou seja, o número máximo de pessoas que podem ser acomodadas no local:\nWARNING: LIMITE MIN 3 PESSOAS, MÁX.5 PESSOAS\n");

  scanf("%d", &total_triagem);
    }

  int doses;
  printf("\nQuantas doses o seu hospital dispõe?\n");
  scanf("%d", &doses);

int menu=0;
int interessados=1;

while(menu!=5){
  
  printf("\n\nMENU\n1 - Cadastrar interessado\n2 - Confirmar imunização\n3 - Exibir fila em triagem\n4 - Relatórios\n5 - Encerrar\n\n");
  scanf("%d", &menu);

int continuar=1;
int fila=1;


  switch (menu) {

//CADASTRAR INTERESSADO
    case 1:

    for (int i=1; i <= total_triagem; i++) {

        printf("\nInforme o nome da pessoa:\n");
        scanf("%s", &pessoas[i].nome);

        printf("\nInforme a idade da pessoa:\n");
        scanf("%d", &pessoas[i].idade);

        printf("\nInforme o sexo da pessoa (M/F):\n");
        scanf("%s", &pessoas[i].sexo);

        adicionar_pessoa_na_fila();

        printf("\nGostaria de cadastrar outro interessado? (1-S/2-N):\n");
        scanf("%d", &continuar);
        pessoas[i].imunizado=0;

        if(continuar==2){
          break;
        }
    }
    
      break;
    
    
    case 2:

    int j=1;
    if(doses>0){

        for (int i=fila; i < total_triagem; i++){

          if(pessoas[i].imunizado==0){

            printf("\nSeguindo a fila, %s foi imunizado(a)!\n", pessoas[i].nome);

            remover_pessoa_da_fila();
            doses--;

              if (doses <= 0){

                printf("As doses do seu hospital, acabaram!");

                break;

              }

            printf("\nGostaria de continuar a fila de imunização?(1-S/2-N)\n");
            scanf("%d", &continuar);

            if(continuar==2){

              break;

            }
            
          }
          else{

            printf("Essa pessoa já foi imunizada!\n");
            printf("Gostaria de continuar a fila de imunização?(1-S/2-N)\n");
            scanf("%d", &continuar);

            if(continuar==2){

              break;

            }
          }
        }
      }
      else{

      printf("Não há doses disponíveis!\n");

    }
      break;
    
    case 3:

      printf("Imprimindo fila de interessados:\n\n");

        imprimir_fila();

      break;

    case 4:
      break;

    case 5:
      break;

    }
  }    
}