#include <stdio.h> /* padrão */
#include <stdlib.h>/* padrão */
#include <string.h> /* Essa biblioteca serve para usar os structs e manipulação de strings */
#include <locale.h> /* biblioteca para definir para brasil*/

/* Empresa SJU Informatica*/
/*Programa de cadastro de pacientes de COVID19*/
/* Alunas: Juliana Silva e Sumaya Távora Costa */
/* Universidade Paulista - UNIP */
/* Data:17/11/2020*/

#define SIZE 200
char nome[SIZE][50];
int cpf[SIZE][25];
int telefone[SIZE][50];
char endereco[SIZE][100];
int datanascimento[SIZE][50];
char email[SIZE][100];
int datadiagnostico[SIZE][50];
char comorbi[SIZE][100];
int fichapaciente;


typedef struct{
    char login[30];  /* vetor login da struct pessoa */
    char senha[30];  /* vetor senha da struct pessoa*/
} pessoa; pessoa p[1];  /* diminuindo o nome da struct para "p" e o "[1]" é o máximo de pessoas com logins e senhas*/


int login(){

    char login[30]; /* responsável por armazenar a senha inserida pelo usuário*/
    char senha[30]; /*responsável por armazenar a senha inserida pelo usuário*/
    int valida;
    strcpy(p[0].login,"brasil");  /*Definindo o login "brasil" na struct*/
    strcpy(p[0].senha,"prafrente");  /* Definindo a senha "prafrente"  na struct*/
    do {
    system("cls");
    printf("\nlogin: ");
    scanf("%s", login);  /* armazenando os dados inseridos pelo usuário para o vetor login que está dentro da função main*/
    printf("\nsenha: ");
    scanf("%s", senha); /* armazenando os dados inseridos pelo usuário para o vetor senha que está dentro da função main*/
    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ /*A função strcmp é responsável por comparar string com string*/
        printf("Usuário logado");  /*se os vetores de dentro da struct tiver os mesmos dados do vetor interno da função main, usuário será logado.*/
        valida = 1;
    }else{
        printf("Login e/ou senha incorretos");  /* senão, login ou senha incorreta.*/
        valida = 0;
    }
    } while (valida == 0);
}

int idade(){
    int nasc, idade;
    printf("informe seu ano de nascimento: ");
    scanf("%d", &nasc);
    idade = 2020 - nasc;
    if(idade < 65) {
        printf("fora da area de risco");
    } else {
        printf ("grupo de risco");
    }
}

void validacao() {
    int dia, mes, ano;
    char nome [20];
    printf ("qual o seu nome: ");
    gets(nome);
    do {
    printf("em que ano voce nasceu: ");
    scanf("d%", &ano);
    }while ("ano < 1900 || ano 2020" ) ;
    printf("em que mes voce nasceu: ");
    scanf ("%d", &mes);
    ("mes < 1 || mes 12" );
    printf("em que dia voce nasceu: ");
    scanf("%d", &dia);
    ("dia < 1 || dia 31" );
    printf("ola %s, voce nasceu em %d / %d / %d \n", nome, dia, mes, ano );
}



 void cadastro(){ /* função para cadastrar o paciente*/
    static char paciente;
    FILE *pont; // já deixa esse ponteiro aqui, para já enviar o paciente para arquivo
    pont = fopen("Cadastro.txt", "a"); // neste arquivo todas as informações do paciente serão inseridas, independente de serem do grupo de risco ou não.
    do{
        printf("\nDigite o nome: ");
        scanf("%s", &nome[paciente]);
        printf("Seu nome é %s", nome);
        fflush(stdin);
        printf("\nDigite seu cpf: ");
        scanf("%d", &cpf[paciente]);
        fflush(stdin);
        printf("\nDigite seu telefone: ");
        scanf("%d", &telefone[paciente]);
        fflush(stdin);
        printf("\nDigite seu endereco: ");
        scanf("%s", &endereco[paciente]);
        fflush(stdin);
        printf("\nDigite sua data de nascimento: ");
        scanf("%d", &datanascimento[paciente]);
        fflush(stdin);
        printf("\nDigite seu email: ");
        scanf("%s", &email[paciente]);
        fflush(stdin);
        printf("\nData do diagnostico: ");
        scanf("%d", &datadiagnostico[paciente]);
        fflush(stdin);
        printf("\nAlguma comorbidade: ");
        scanf("%s", &comorbi[paciente]);
        idade();
        do {
        printf("\nDigite 1 para continuar ou 0 sair:");
        scanf("%d", &fichapaciente);
        fflush(stdin);
        } while (fichapaciente != 0 && fichapaciente != 1);
        paciente++;
        // iremos inserir as informações no arquivo de texto agora:
        fprintf(pont, "Nome: %s\n", nome);
        fprintf(pont, "CPF: %d\n", cpf);
        fprintf(pont, "Telefone: %d\n", telefone);
        fprintf(pont, "Endereço: %s\n", endereco);
        fprintf(pont, "Data de nascimento: %d\n", datanascimento);
        fprintf(pont, "E-mail: %s\n", email);
        fprintf(pont, "Data do diagnóstico: %d\n", datadiagnostico);
        fprintf(pont, "Comorbidade: %s\n", comorbi);
        fprintf(pont, "---------------------------\n"); // essa linha é para dividir cada cadastro que é inserido
        fclose(pont); // caso o usuário desejar sair, o arquivo criado é fechado.
        if (fichapaciente == 0){
            break;
        }
} while(fichapaciente==1);
 }

//-------------PROGRAMA PRINCIPAL-------------
void main () {
 setlocale(LC_ALL, "Portuguese" );
 login(); // CHAMA A FUNÇÃO LOGIN
 cadastro(); // CHAMA A FUNÇÃO CADASTRO
}
