#include <string.h>
#include <stdio.h>
#include "conio2.c"


char * leValida_Filme(void);
int leValida_Cadeira(void);
void printf_cinema(char [], int);
int menu (void);

int main(void)
{
int qtde_cadeiras,idade,valor,cadeira, i;
char nome[50], cadeiras[499], opcao, op;

strcpy(nome, leValida_Filme());
qtde_cadeiras = leValida_Cadeira();
for(i=0;i<qtde_cadeiras;i++)
{
cadeiras[i] = 'D';
}
do
{
textcolor(7);
op = menu();
if (op == '1')
{
system("cls");
idade=leValida_idade();
valor=calcula_ingresso(idade);
system("cls");
printf_cinema(cadeiras, qtde_cadeiras);
textcolor(7);
printf("Deseja comprar, reservar ou cancelar alguma cadeira.\n");
printf("Digite 'C' para comprar , 'R' para reservar , 'F' para cancelar.\n");
opcao = getch();
printf("Digite a cadeira que deseja escolher.");
scanf("%d",&cadeira);
switch(opcao)
{
case 'C':
if (cadeiras[cadeira-1] == 'C')
printf("Cadeira indisponivel.");
cadeiras[cadeira-1] = 'C';
break;
case 'R':
if (cadeiras[cadeira-1] == 'C')
printf("Cadeira indisponivel.");
else
cadeiras[cadeira-1] = 'R';
break;
case 'F':
if (cadeiras[cadeira-1] != 'R')
printf("Nao foi possivel cancelar a reserva");
else
cadeiras[cadeira-1] = 'D';
break;
}

printf_cinema(cadeiras, 100);
getch();
}
}while (op != '0');
return 0;
}


char * leValida_Filme(void)
{
static char nome[50];
do{
printf("Digite o nome do filme.\n>");
gets(nome);
if(!(strcmp(nome,"")))
puts("Nome do filme invalido.");

}while(!(strcmp(nome,"")));
return nome;
}

int leValida_Cadeira(void)
{
int qtde;

do{
printf("Digite o numero de cadeiras.(Minimo de 100 e maximo de 500).\n>");
scanf("%i",&qtde);
if(qtde<100||qtde>500)
puts("Quantidade de cadeiras invalida.\n");
}while(qtde<100||qtde>500);
return qtde;
}

int leValida_idade(void)
{
int idade;

do{
printf("Digite a idade.\n>");
scanf("%i",&idade);
if(idade<0)
puts("Idade invalida.\n");
}while(idade<0);
return idade;
}

int leValida_Valor(void)
{
int valor;

do{
printf("Digite o valor do ingresso.\n>");
scanf("%i",&valor);
if(valor<0)
puts("Idade invalida.\n");
}while(valor<0);
return valor;
}

int calcula_ingresso(int idade)
{
int valor;
char opcao;

valor=leValida_Valor();
if(idade>12)
{
printf("Opcoes para meia entrada.\n E - estudantes, P - pessoas com deficiencia, I - idosos, D - doadores de sangue, N - nenhum");
opcao = getch();
}
if(idade < 12  || opcao =='E' || opcao =='P' || opcao =='I' || opcao =='D')
valor = valor/2;

return valor;
}
void printf_cinema(char cadeiras[], int qtde_cadeiras)
{
int i;
for(i=0;i<qtde_cadeiras;i++)
{
if (cadeiras[i] == 'R')
textcolor(RED);
else if (cadeiras[i] == 'C')
textcolor(BLUE);
else
textcolor(GREEN);
printf("%-3i ", i+1);
if(!((i+1) % 10))
putchar('\n');
}
}
int menu (void)
{
int opcao;
system("cls");
printf("[1] comprar\n");
printf("[0] Sair\n");
opcao = getch();
return opcao;
}
