#include <stdio.h> 
#include <stdlib.h>

#define NUM_MAX_ESTUDANTES 100
#define NUM_MAX_FICHAS 10
#define NUM_MAX_EXERCICIOS 100
#define NUM_MAX_SUBMISSOES 1000

/*FUNÇÕES*/
int lerNumero(int, int);
int menuInicial();
int menuEstudante();
int menuDocente();
int menuDocente_gerirEstudantes();
int menuDocente_gerirFichas();
int menuDocente_regEstudantes(int *contadorEstudantes);
int menuDocente_consEstudantes(int *contadorEstudantes);
int menuDocente_regFichas(int *contadorFichas);
int menuDocente_consFichas(int *contadorFichas);
/*FUNÇÕES - FIM*/

/*VETORES/ESTRUTURAS*/
struct Estudantes{                                                     //STRUCT COMPLETA
    int id_estudante[NUM_MAX_ESTUDANTES]; 
    int numero_de_estudante[NUM_MAX_ESTUDANTES];
    char nome_estudante[NUM_MAX_ESTUDANTES] [80];
    char email_estudante[NUM_MAX_ESTUDANTES] [80];         //STRING, POR ISSO PODE GUARDAR NÚMEROS TAMBÉM!
};

struct Fichas{                                           //STRUCT COMPLETA
    int numero_de_exercicos[NUM_MAX_EXERCICIOS];                                                                       
    char id_ficha[NUM_MAX_FICHAS]; 
    char nome_ficha[NUM_MAX_FICHAS] [20]; 
    char data_publicacao [NUM_MAX_FICHAS] [8]; 
};

typedef struct{
    int id_exercicio[NUM_MAX_EXERCICIOS];
    char nome_exercicio[NUM_MAX_EXERCICIOS] [30];
} Exercicios;
/*VETORES/ESTRUTURAS - FIM*/


/*FICHEIROS*/
FILE *dados_estudantes, *dados_docentes;
/*FICHEIROS - FIM*/

int main() {
    int opcaoA, opcaoB, opcaoC, opcaoD;
    int contadorEstudantes, contadorFichas, contadorExercicios;

    do {                                                    //SAIR DA APLICAÇÃO (DO)
        system("cls");                                   
        opcaoA = menuInicial();
        switch (opcaoA) {
            case 1:
                do {                                      
                system("cls");                        
                opcaoB = menuEstudante();                   
                    switch (opcaoB) {
                        case 1: 
                            system("cls");
                            break;
                    }
                } while (opcaoB != 0); 
                break;
            case 2: 
                do {                                       
                    system("cls");
                    opcaoB = menuDocente();
                    switch (opcaoB) {
                        case 1:
                            system("cls");
                            opcaoC = menuDocente_gerirEstudantes();
                                switch(opcaoC) {
                                    case 1:
                                        system("cls");
                                        menuDocente_regEstudantes(&contadorEstudantes);
                                        getchar();
                                        getchar();
                                        break;
                                    case 2:
                                        system("cls");
                                        menuDocente_consEstudantes(&contadorEstudantes);
                                        getchar();
                                        getchar();
                                        break;
                                }
                                break;
                        case 2:
                            system("cls"); 
                            opcaoC = menuDocente_gerirFichas();
                            break;
                    } 
                } while (opcaoB != 0);                   
                break;
            default:
                break;
        }
    } while(opcaoA != 0);                               //SAIR DA APLICAÇÃO (WHILE)
}




int lerNumero(int numMin, int numMax) {
    int num;
    do {
        printf("\nOpcao --> ");
        scanf("%d", &num);
        if (num > numMax || num < numMin) {
            printf("\nOpcao invalida, escolha um numero entre %d e %d", numMin, numMax);
        }
    } while (num > numMax || num < numMin);

    return(num);
}



int menuInicial() {
    int opcao;
    printf("######### MENU INICIAL #########");
    printf("\n1. Estudante");
    printf("\n2. Docente");
    printf("\n\n0. Sair");

    opcao = lerNumero(0, 2);
    return(opcao);
}



int menuEstudante() {
    int opcao;
    printf("######### MENU ESTUDANTE #########");
    printf("\n1. Consultar Dados");
    printf("");
    printf("\n3. Estatisticas");
    printf("\n\n0. Sair");

    opcao = lerNumero(0, 3);
    return(opcao);
}



int menuDocente() {
    int opcao;
    printf("######### MENU DOCENTE #########");
    printf("\n1. Gerir estudantes");
    printf("\n2. Gerir fichas");
    printf("\n3. Gerir exercicios");
    printf("\n4. Gerir submissoes");
    printf("\n5. Estatisticas");
    printf("\n\n0. Sair");
    opcao = lerNumero(0, 5);

    return(opcao);
}



int menuDocente_gerirEstudantes() {
    int opcao;
    printf("######### GERIR ESTUDANTES #########");
    printf("\n1. Registar estudantes");
    printf("\n2. Consultar estudantes");
    printf("\n\n0. Sair");
    opcao = lerNumero(0, 2);

    return(opcao);
}



int menuDocente_gerirFichas() {
    int opcao;

    printf("######### GERIR FICHAS #########");
    printf("\n1. Registar fichas");
    printf("\n2. Consultar fichas");
    printf("\n\n0. Sair");
    opcao = lerNumero(0, 2);

    return(opcao); 
}



int menuDocente_regEstudantes(int *contadorEstudantes) {
    struct Estudantes estruturaEstudantes;
    int indice;
    char opcao:
    do {
        printf("######### REGISTAR ESTUDANTES #########");
        printf("\nInsira o ID do estudante: ");
        scanf("%d", &estruturaEstudantes.id_estudante[*contadorEstudantes]);
        printf("\nInsira número de estudante: ");
        scanf("%d", &estruturaEstudantes.numero_de_estudante[*contadorEstudantes]);
        printf("\nInsira o nome do estudante: ");
        scanf("%s", &estruturaEstudantes.nome_estudante[*contadorEstudantes]);
        printf("\nInsira o email do estudante: ");
        scanf("%s", &estruturaEstudantes.email_estudante[*contadorEstudantes]);

        printf("\nRegistar mais?");
        printf("\n(S)im\n(N)ao");
        scanf(" %c", &opcao);

        contadorEstudantes++;
    } while (opcao != 's' && opcao != 'S');

    return (contadorEstudantes);
}



int menuDocente_consEstudantes(int *contadorEstudantes) {
    struct Estudantes estruturaEstudantes;
    int indice;

    printf("######### CONSULTAR ESTUDANTES #########");
    for (indice = 0; indice < contadorEstudantes; indice++) {
        printf("[%d; %d, %s, %s]", estruturaEstudantes.id_estudante[indice], estruturaEstudantes.numero_de_estudante[indice], estruturaEstudantes.nome_estudante[indice], estruturaEstudantes.email_estudante[indice]);
    }
}



int menuDocente_regFichas(int *contadorFichas) {
    struct Fichas estruturaFichas;
    int indice;
    char opcao:
    do {
        printf("######### REGISTAR FICHAS #########");
        printf("\nInsira o ID do estudante: ");
        scanf("%d", &estruturaFichas.id_estudante[*contadorFichas]);
        printf("\nInsira número de estudante: ");
        scanf("%d", &estruturaFichas.numero_de_estudante[*contadorFichas]);
        printf("\nInsira o nome do estudante: ");
        scanf("%s", &estruturaFichas.nome_estudante[*contadorFichas]);
        printf("\nInsira o email do estudante: ");
        scanf("%s", &estruturaFichas.email_estudante[*contadorFichas]);

        printf("\nRegistar mais?");
        printf("\n(S)im\n(N)ao");
        scanf(" %c", &opcao);

        contadorEstudantes++;
    } while (opcao != 's' && opcao != 'S');

    return (contadorEstudantes);
}



int menuDocente_consFichas(int *contadorFichas) {

}


