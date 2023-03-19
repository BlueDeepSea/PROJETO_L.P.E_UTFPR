#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int idade;
    char sexo;
};

int main(void) {
  printf("\nCRIADO POR: VITOR PALADINI\n\nGHS\n\nCom o GHS (Gestão Hospitalar Simplifica), você pode facilmente organizar e gerenciar o seu hospital de forma mais eficiente. Desfrute de uma plataforma intuitiva e funcional que ajudará a simplificar processos e melhorar a qualidade do atendimento aos pacientes.\n\n\n");

  printf("Por favor, informe a capacidade total da sala de triagem, ou seja, o número máximo de pessoas que podem ser acomodadas no local:\n\nWARNING: LIMITE MIN 3 PESSOAS, MÁX.5 PESSOAS\n");

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


while(menu!=5){
  
  printf("\n\nMENU\n1 - Cadastrar interessado\n2 - Confirmar imunização\n3 - Exibir fila em triagem\n4 - Relatórios\n5 - Encerrar\n\n");
  scanf("%d", &menu);

  switch (menu) {

    case 1:
    
    struct Pessoa pessoas[5];

    for (int i = 0; i < total_triagem; i++) {

      int continuar=1;

        printf("Informe o nome da pessoa: ", i+1);
        scanf("%s", pessoas[i].nome);

        printf("Informe a idade da pessoa: ", i+1);
        scanf("%d", &pessoas[i].idade);

        printf("Informe o sexo da pessoa (M/F): ", i+1);
        scanf(" %c", &pessoas[i].sexo);

        printf("Quer cadastrar outro interessado? (1-S/2-N)");
        scanf(" %d", &continuar);

        if(continuar==2){
          break;
        }
        
    }
    
      break;
    
    
    case 2:
      break;
    
    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    }
  }    
}