#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <conio.c>
/*para colocar acento: #include <locale.h> e logo apois o main setlocale(LC_ALL,"Portuges")*/
typedef struct logins LOGIN;

struct logins{
    char nome[40];
    char login[40];
    char password[40];
    char categoria;
};

typedef struct dadospalestra PALESTRA; // aq o cdtros é tipo um apelido para CADASTRAMENTO
struct dadospalestra{
    char palestrante[40];
    int vagas;
    char sala[15];
    float  horario;
    char tema[40];
    float cargaHoraria;
    int codPalestra;/// O CODIGO DE PALESTRA É 111
};

typedef struct congressitas CONGRE;
struct congressitas{ // para armazena dados de congressionistas no caso apenas nome e matricula
    int matricula;
    char nome[30];
    int idUsuarios[20][4];
    int nEventos;
};

typedef struct mesaredonda MESA;
struct mesaredonda{ // para armazena dados de congressionistas no caso apenas nome e matricula
    char nome[40];
    int vagas;
    float cargahoraria;
    float horario;
    char sala[20];
    char tema[30];
    char membros[80];
    int codMesa; /// O CODIGO DE MESA É 222
    int nEventos;
};

typedef struct cursos CURSO;
struct cursos{ // para armazena dados de congressionistas no caso apenas nome e matricula
    int vagas;
    float cargahoraria;
    float horario;
    char sala[20];
    char tema[30];
    char professor[30];
    int codCurso; /// O CODIGO DE CURSOS É 333
     int nEventos;
};

typedef struct oficinas OFICINA;
struct oficinas{ // para armazena dados de congressionistas no caso apenas nome e matricula
    int vagas;
    float cargahoraria;
    float horario;
    char sala[20];
    char tema[30];
    char professor[30];
    int codOficinas; /// O CODIGO DE OFICINAS É 444
    int nEventos;
};


void inicio();
void quadradoLogin();
void quadradoCadastro();
void linha(int n);
void senha(char senha[9]);
void telaLogin();
void verificadorDelogin(char loginParamento[10],char nomeparametro[40]);
void cadastro();

void palestra(char nome[40]);
void congressitas(char nome[40]);
void mesaredonda(char nome[40]);
void cursos(char nome[40]);
void oficina(char nome[40]);

void organizadores();

void imprimirUsuarios();
int verificar(char nome[40]);
void printcongrecionistas();
void imprimirPalestra();

// MATRICULA


int main(){
    inicio();

}

void inicio(){
    system("cls");
    system("color 17");
    textcolor(15);
    char opcao;
    printf("\n\t\t\tWELCOME TO THE EVENT\n\n");
    printf("\t\t============================================");
    printf("\n\n\t\tCADASTRO: [1]\n\n\t\t   LOGIN: [2]\n\n \t   ORGANIZADORES: [3]\n\n");
    printf("\t\t============================================");
    putchar('\n');
    opcao = getch();
    switch (opcao){
       case '1':
           cadastro();
           getch();
           inicio();
           break;
       case '2':
           telaLogin();
           inicio();
           break;
       case '3':
         organizadores();
       default:
            printf("Opcao invalida");
       }
       system("cls");


}
// função do quadrado da tela de logim
void quadradoLogin(){




  int i;
  // rodapé de cima
  for(i = 0;i < 30;i++){ // 188 _| // 205 =
        if(i == 0){
            printf("\t\t%c",201);
        }
        if(i == 29){
            printf("%c",187);
        }
        else{
        printf("%c",205);}
  }

  putchar('\n');

  for(i = 0;i < 10;i++){ // laterais
       printf("\t\t\t%c                             %c\n",186,186);

       }

  for(i = 0;i < 30;i++){ // rodapé de baixo
    if(i == 0){
        printf("\t\t\t%c",200);}
    if(i == 29){
        printf("%c",188);
    }else{
        printf("%c",205);
        }
    }
}
void quadradoCadastro(){
  int i;
  // rodapé de cima
  for(i = 0;i < 45;i++){ // 188 _| // 205 =
        if(i == 0){
            printf("\t%c",201);
        }
        if(i == 44){
            printf("%c",187);
        }
        else{
        printf("%c",205);}
  }

  putchar('\n');

  for(i = 0;i < 19;i++){ // laterais
       printf("\t\t%c                                            %c\n",186,186);

       }

  for(i = 0;i < 45;i++){ // rodapé de baixo
    if(i == 0){
        printf("\t\t%c",200);}
    if(i == 44){
        printf("%c",188);
    }else{
        printf("%c",205);
        }
    }
}

void linha(int n){

    int i;
    for(i = 0; i < n;i++){
        printf("%c",196);
    }

}

void senha(char senha[15]){ /// mascarando a senha
  int i;
  fflush(stdin);
  for (i = 0; i < 15; i++){
    senha[i] = getch();
     if(senha[i] == 13){
        break;
        }
    putchar('*');
    }
}

void telaLogin(){



    system("cls");

    system("color 17");
    char login[10],senhas[15];
    gotoxy(10,5); quadradoLogin();

    gotoxy(27,8);printf("LOGIM: ");
    gotoxy(27,9);linha(25);

    gotoxy(27,11);printf("SENHA: ");
    gotoxy(27,12);linha(25);

    gotoxy(37,13);linha(5);
    gotoxy(27,14);printf("\t   %cENTER%c",179,179);
    gotoxy(37,15);linha(5);

    textcolor(4);
    fflush(stdin);
    gotoxy(34,8);gets(login);
    gotoxy(34,11);senha(senhas); // funcao para mudar caractere por '*'
    gotoxy(43,14);getch();

    //----------------------------------------------------------------------------
    int cont = 0;
    FILE *filelogin;
    LOGIN cdt;
    filelogin = fopen("login.txt","rb");
    if(filelogin == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
     while( fread(&cdt,sizeof(LOGIN),1,filelogin) == 1 ){
        if(strcmp(login,cdt.login) == 0 ){
            cont += 1;
            verificadorDelogin(login,cdt.nome);
            }
        }
    if(cont == 0){
            printf("\n\n\n\t\t\tUsuario nao cadastrado\n\n\n");
            textcolor(15);
            getch();
            inicio();
            }
    }
void cadastro(){

    FILE *filelogin;
    LOGIN lgn; //
    PALESTRA cdt;

    filelogin = fopen("login.txt","ab");

    if(filelogin == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    system("cls");
    system("color 17");
   // system("color e0");

    gotoxy(10,5);quadradoCadastro();
    gotoxy(19,7);printf("======>TELA DE CADASTRAMENTOS<======\n\n\n\n\n");
    gotoxy(20,10);printf("NOME: \n\n");
    gotoxy(20,12);printf("LOGIN: \n\n");
    gotoxy(20,14);printf("SENHA: \n\n");
    gotoxy(20,16);printf("[1]- PALESTRAS    [2]- CONGRESSISTAS");
    gotoxy(20,18);printf("[3]- MESA REDONDA [4]- CURSOS        ");
    gotoxy(19,20);printf("           [5]- OFICINAS            ");

    gotoxy(36,22);linha(5);
    gotoxy(35,23);printf("%cENTER%c",179,179);
    gotoxy(36,24);linha(5);

    //------------------------------------------------------------------------
    fflush(stdin);
    textcolor(15);
    gotoxy(26,10);gets(lgn.nome); // usando a variavel temporaria para armazena dados a minha struct
    gotoxy(27,12);gets(lgn.login);
    gotoxy(27,14);senha(lgn.password);
    gotoxy(44,20);lgn.categoria = getch();
    /*while(lgn.categoria <= 0 || lgn.categoria > 5){
        textcolor(4);gotoxy(30,23);printf("\7ERRO! DIGITE NOVAMENTE!");
        gotoxy(44,20);lgn.categoria = getch();
        textcolor(15);gotoxy(30,23);printf("                         ");
    }*/
    fwrite(&lgn,sizeof(LOGIN),1,filelogin);

    fclose(filelogin);

    filelogin = fopen("login.txt","ab"); // aberto novamente para o caso de ser preciso usar novamente

    if(lgn.categoria == '1'){ /// PALESTRAS CAPACIDADE DE 50 A 150 PESSOAS , CADA PALESTRA VAI RECEBE UM CODIGO 111
             FILE *palestr;
             palestr = fopen("palestra.txt","ab");
             system("cls");
             gotoxy(10,5);quadradoCadastro();
             gotoxy(19,6);printf("======>Bem vindo %s<======",lgn.nome);
             gotoxy(19,8);printf(" PALESTRANTE: ");
             gotoxy(20,10);printf("TEMA: ");
             gotoxy(20,12);printf("CARGA HORARIA: ");
             gotoxy(20,14);printf("VAGAS: ");
             gotoxy(20,16);printf("SALA: ");
             gotoxy(20,18);printf("HORARIO: ");
             gotoxy(36,19);linha(5);
             gotoxy(35,20);printf("%cENTER%c",179,179);
             gotoxy(36,21);linha(5);
             textcolor(15);

             fflush(stdin);
             gotoxy(32,8);gets(cdt.palestrante);
             gotoxy(25,10);gets(cdt.tema);
             gotoxy(35,12);scanf("%f",&cdt.cargaHoraria);
             while(cdt.cargaHoraria > 2){
                 gotoxy(30,23);textcolor(4);printf("\7[Carga horaria indisponivel]");
                 gotoxy(35,12);textcolor(15);scanf("%f",&cdt.cargaHoraria);
                 }
             textcolor(15);
             gotoxy(27,14);scanf("%i",&cdt.vagas);
             while(cdt.vagas > 150){
                 gotoxy(25,23);textcolor(4);printf("\7DIMINUA O NUMBERO DE VAGAS        ");
                 gotoxy(27,14);textcolor(15);scanf("%i",&cdt.vagas);
             }
             fflush(stdin);
             gotoxy(25,23);textcolor(4);printf("SALAS DISPONIVEIS: [AUDITORIO 1,2,3]");
             gotoxy(26,16);gets(cdt.sala);

             gotoxy(25,23);textcolor(4);printf(" Horarios disponeiveis: entre 7 e 12");
             gotoxy(29,18);scanf("%f",&cdt.horario);

             gotoxy(25,23);textcolor(4);printf("                                    ");

             while(cdt.horario < 7 || cdt.cargaHoraria > 12){
                 gotoxy(25,23);textcolor(4);printf("HORARIO INDISPONIVEL");
                 gotoxy(29,18);scanf("%f",&cdt.horario);
             }
             gotoxy(26,23);textcolor(4);printf("                                    ");

             if((cdt.cargaHoraria + cdt.horario) > 12 ){
                    gotoxy(25,23);printf("Tempo limite utrapassado");
                    gotoxy(25,24);printf("DIMINUA O SEU HORARIO");
                    gotoxy(29,18);scanf("%f",&cdt.horario);
             }

            cdt.codPalestra = 111;

            gotoxy(25,23);printf("                        ");
            gotoxy(25,24);printf("                        ");
            fwrite(&cdt,sizeof(PALESTRA),1,palestr); // aq estou salvando os aruqivos em forma binaria

            textcolor(4);gotoxy(23,22);printf("\t     Usuario cadastrado");
            textcolor(15);

            gotoxy(21,22);getch();

            fclose(palestr);
            fclose(filelogin);

    }
    else if(lgn.categoria == '2'){ // ENTRANDO AQ EU ABRO O ARQUIVO DE CONGRECIONISTAS
             system("cls");
             int contEventos;
             char inscricao,opcao,opc = 's';
             FILE *congre;
             congre = fopen("congrecionistas.txt","ab"); // salvar dados de congrecionistas

             CONGRE cng;
             LOGIN  cng1; // isso aq foi criado com o intuito de pegar os dados do usuario para mostrar na tela

             gotoxy(10,5);quadradoCadastro();


             gotoxy(19,7);printf("======>Bem vindo %s<======",lgn.nome);

          ///   gotoxy(20,9);printf("SUA MATRICULA: %i",matriculaglobal);

            while(opc == 's'){              ///=========================================INICIO DO WHILE PRINCIPAL==========
             system("cls");
             gotoxy(19,6);printf("======>Bem vindo %s<======",lgn.nome);
             gotoxy(10,5);quadradoCadastro();
             gotoxy(20,11);printf("VEJA OS EVENTOS DISPONIVEIS");
             gotoxy(20,13);printf("[1] - PALESTRAS [2]- MESA REDONDA \n");
             gotoxy(20,15);printf("[3] - CURSOS    [4] - OFICINAS");
             gotoxy(60,15);opcao = getch();
             system("cls");


             if(opcao == '1'){ /// OPCAO DE CONGRESSISTAS
                    FILE *palestr;
                    palestr = fopen("palestra.txt","rb");
                    PALESTRA cdt;
                    gotoxy(10,5);quadradoCadastro();
                    gotoxy(24,7);printf("PALESTRAS DISPONIVEIS");
                    while( fread(&cdt,sizeof(PALESTRA),1,palestr) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                         gotoxy(24,8);linha(22);
                        //DADOS DOS PALESTRANTES
                         gotoxy(20,9);printf("Sala: %s",cdt.sala);
                         gotoxy(20,11);printf("Horario: %.1f horas",cdt.horario); // tds os cdt esta sendo salvo no txt palestra
                         gotoxy(20,13);printf("Tema: %s",cdt.tema);
                         gotoxy(20,15);printf("Carga Horaria:%.1f",cdt.cargaHoraria);
                         gotoxy(24,16);linha(22);
                         gotoxy(20,17);printf("DESEJA SE INSCREVER [s/n]? ");
                         gotoxy(46,17);scanf("%s",&inscricao);
                        if(inscricao == 's'){ /// N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE
                            contEventos = 1;
                            cng.nEventos = contEventos;
                            contEventos += 1;
                            cng.idUsuarios[cng.nEventos][1] = cdt.codPalestra;

                            gotoxy(20,19);printf("DIGITE SEU NOME: ");
                            fflush(stdin);
                            gets(cng.nome);
                            fwrite(&cng,sizeof(CONGRE),1,congre); /// salvando os dados em em congressitas

                            fclose(congre);
                            fclose(filelogin);
                            fclose(palestr);
                            gotoxy(29,22);printf("USUARIO MATRICULADO!");
                            getch();
                            break;
                            }
                        }
                        gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                        opc = getch();
                        if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                            gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                            textcolor(15);
                            getch();
                            inicio();
                        }
                        continue; /// ESSE CARINHA AQ VAI FAZER VOLTAR PARA O INICIO DO WHILE E ASSIM EU POSSO ESCOLHER OUTRA CATEGODRIA
                }

                else if(opcao == '2'){ /// OPCAO DE CONGRESSISTAS MESA REDONDA

                       FILE *filemesas;
                       filemesas = fopen("mesa.txt","rb"); // salvar dados dos cursos
                       MESA msa;

                    gotoxy(10,5);quadradoCadastro();
                    gotoxy(24,7);printf("CURSOS DISPONIVEIS");
                    while( fread(&msa,sizeof(CURSO),1,filemesas) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                         gotoxy(24,8);linha(22);
                        //DADOS DOS PALESTRANTES
                         gotoxy(20,9);printf("Sala: %s",msa.sala);
                         gotoxy(20,11);printf("Horario: %.1f horas",msa.horario); // tds os msa esta sendo salvo no txt palestra
                         gotoxy(20,13);printf("Tema: %s",msa.tema);
                         gotoxy(20,15);printf("Carga Horaria:%.1f",msa.cargahoraria);
                         gotoxy(24,16);linha(22);
                         gotoxy(19,17);printf("DESEJA SE INSCREVER [s/n]? ");
                         gotoxy(46,17);scanf("%s",&inscricao);
                        if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE

                            contEventos = 1;
                            cng.nEventos = contEventos;
                            contEventos += 1;
                            cng.idUsuarios[cng.nEventos][1] = msa.codMesa;
                            printf("%i",cng.idUsuarios[cng.nEventos][1]);
                            gotoxy(20,19);printf("DIGITE SEU NOME: ");
                            fflush(stdin);
                            gets(cng.nome);
                            fwrite(&cng,sizeof(CONGRE),1,congre); /// salvando os dados em em congressitas

                            fclose(congre);
                            fclose(filelogin);
                            fclose(filemesas);
                            gotoxy(29,22);printf("USUARIO MATRICULADO!");
                            getch();
                            break;
                            }
                        }
                        gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                        opc = getch();
                        if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                            gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                            textcolor(15);
                            getch();
                            inicio();
                        }
                        continue;
                }

                else if(opcao == '3'){ /// OPCAO DE CONGRESSISTAS CURSOS

                    FILE *filecursos;
                    filecursos = fopen("cursos.txt","rb"); // salvar dados dos cursos
                    CURSO crs;

                    gotoxy(10,5);quadradoCadastro();
                    gotoxy(24,7);printf("CURSOS DISPONIVEIS");
                    while( fread(&crs,sizeof(CURSO),1,filecursos) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                         gotoxy(24,8);linha(22);
                        //DADOS DOS PALESTRANTES
                         gotoxy(20,9);printf("Sala: %s",crs.sala);
                         gotoxy(20,11);printf("Horario: %.1f horas",crs.horario); // tds os crs esta sendo salvo no txt palestra
                         gotoxy(20,13);printf("Tema: %s",crs.tema);
                         gotoxy(20,15);printf("Carga Horaria:%.1f",crs.cargahoraria);
                         gotoxy(24,16);linha(22);
                         gotoxy(19,17);printf("DESEJA SE INSCREVER [s/n]? ");
                         gotoxy(46,17);scanf("%s",&inscricao);
                        if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE

                            contEventos = 1;
                            cng.nEventos = contEventos;
                            contEventos += 1;
                            cng.idUsuarios[cng.nEventos][1] = crs.codCurso;

                            gotoxy(20,19);printf("DIGITE SEU NOME: ");
                            fflush(stdin);
                            gets(cng.nome);
                            fwrite(&cng,sizeof(CONGRE),1,congre); /// salvando os dados em em congressitas

                            fclose(congre);
                            fclose(filelogin);
                            fclose(filecursos);
                            gotoxy(29,22);printf("USUARIO MATRICULADO!");
                            getch();
                            break;
                            }
                        }
                        gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                        opc = getch();
                        if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                            gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                            textcolor(15);
                            getch();
                            inicio();
                        }
                        continue;
                }
                else if(opcao == '4'){ /// OPCAO DE CONGRESSISTAS OFCINAS


                    FILE *fileoficina;
                    fileoficina = fopen("oficinas.txt","rb"); // salvar dados dos cursos

                    OFICINA ofc;

                    gotoxy(10,5);quadradoCadastro();
                    gotoxy(24,7);printf("OFICINAS DISPONIVEIS");
                    while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                         gotoxy(24,8);linha(22);
                        //DADOS DOS PALESTRANTES
                         gotoxy(20,9);printf("Sala: %s",ofc.sala);
                         gotoxy(20,11);printf("Horario: %.1f horas",ofc.horario); // tds os ofc esta sendo salvo no txt palestra
                         gotoxy(20,13);printf("Tema: %s",ofc.tema);
                         gotoxy(20,15);printf("Carga Horaria:%.1f",ofc.cargahoraria);
                         gotoxy(24,16);linha(22);
                         gotoxy(20,17);printf("DESEJA SE INSCREVER [s/n]? ");
                         gotoxy(46,17);scanf("%s",&inscricao);
                        if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE
                            contEventos = 1;
                            cng.nEventos = contEventos;
                            contEventos += 1;
                            cng.idUsuarios[cng.nEventos][1] = ofc.codOficinas;
                            gotoxy(20,19);printf("DIGITE SEU NOME: ");
                            fflush(stdin);
                            gets(cng.nome);
                            fwrite(&cng,sizeof(CONGRE),1,congre); /// salvando os dados em em congressitas

                            fclose(congre);
                            fclose(filelogin);
                            fclose(fileoficina);
                            gotoxy(29,22);printf("USUARIO MATRICULADO!");
                            getch();
                            break;
                            }
                        }
                        gotoxy(29,22);printf("DESEJA CONTINUAR[s/n] ? ");
                        opc = getch();
                        if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                            gotoxy(29,23);textcolor(4);printf("APROVEITE O EVENTO");
                            textcolor(15);
                            getch();
                            inicio();
                        }
                        continue;
        /// DEPOIS DO IF ELE VOLTA PARA O INICIO

                }
            fclose(congre); // salvando dpois de escolher uma opcao
            fclose(filelogin);

            }///================================FIM DO WHILE Q VAI FAZER O USUARIO SE CADASTRA EM MAIS DE UM EVENTO
        }

    else if(lgn.categoria == '3'){ /// MESA REDONDA CAPACIDADE DE 30 A 50 PESSOAS
            system("cls");
             char opcao;
             FILE *filemesa;

             filemesa = fopen("mesa.txt","ab");

             MESA msa;

             gotoxy(10,5);quadradoCadastro();
             gotoxy(19,7);printf("\t======>Bem vindo %s<======",lgn.nome);
             gotoxy(20,8);printf("NOME: ");
             gotoxy(20,10);printf("VAGAS: ");
             gotoxy(20,12);printf("CARGA HORARIA: ");
             gotoxy(20,14);printf("HORARIO: ");
             gotoxy(20,16);printf("SALA: \n\n");
             gotoxy(20,18);printf("TEMA: \n\n");
             gotoxy(20,20);printf("MEMBROS: ");
             gotoxy(41,11);linha(5);
             gotoxy(40,12);printf("%cENTER%c",179,179);
             gotoxy(41,13);linha(5);
             textcolor(15);
             textcolor(15);
             gotoxy(25,8);gets(msa.nome);
             gotoxy(26,10);scanf("%i",&msa.vagas);
             while(msa.vagas > 50){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CAPACIDADE MAXIMA DE 50 PESSOAS");
                gotoxy(26,10);textcolor(15);scanf("%i",&msa.vagas);

             }
             gotoxy(29,10);printf(" ");

             gotoxy(23,23);printf("                                       ");

             textcolor(15);
             gotoxy(34,12);scanf("%f",&msa.cargahoraria);
             while(msa.cargahoraria > 2){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                gotoxy(34,12);textcolor(15);scanf("%f",&msa.cargahoraria);

             }
             gotoxy(23,23);printf("                                       ");
             textcolor(15);

             gotoxy(28,14);scanf("%f",&msa.horario);
             while(msa.horario > 18 || msa.horario < 13){
                gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                gotoxy(28,14);textcolor(15);scanf("%f",&msa.horario);
             }

             gotoxy(18,23);textcolor(4);printf("                                            ");

             textcolor(15);
             fflush(stdin);
             gotoxy(18,23);textcolor(4);printf("SALAS DISPONIVEIS: SALA 1,SALA 2,SALA 3");
             textcolor(15);

             gotoxy(25,16);gets(msa.sala);
             gotoxy(25,18);gets(msa.tema);
             gotoxy(18,23);textcolor(4);printf("                                       ");
             gotoxy(28,20);gets(msa.membros);

            msa.codMesa = 222; /// CODIGO DE MESAS-----------------

            fwrite(&msa,sizeof(MESA),1,filemesa);
            gotoxy(47,12);getch();
            fclose(filemesa);
            fclose(filelogin);
    }

    else if(lgn.categoria == '4'){ /// CURSOS CAPACIDADE DE 40 PESSOAS
           system("cls");
            char opcao;
             FILE *filecursos;

             filecursos = fopen("cursos.txt","ab"); // salvar dados dos cursos

             CURSO crs;
             //LOGIN  cng1; // isso aq foi criado com o intuito de pegar os dados do usuario para mostrar na tela


             gotoxy(10,5);quadradoCadastro();
             gotoxy(19,7);printf("\t======>Bem vindo %s<======",lgn.nome);
             gotoxy(20,10);printf("VAGAS: ");
             gotoxy(20,12);printf("CARGA HORARIA: ");
             gotoxy(20,14);printf("HORARIO: ");
             gotoxy(20,16);printf("SALA: \n\n");
             gotoxy(20,18);printf("TEMA: \n\n");
             gotoxy(20,20);printf("PROFESSOR: \n\n");
             gotoxy(42,19);linha(5);
             gotoxy(41,20);printf("%cENTER%c",179,179);
             gotoxy(42,21);linha(5);
              textcolor(15);
             gotoxy(26,10);scanf("%i",&crs.vagas);
             while(crs.vagas > 40){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CAPACIDADE MAXIMA DE 40 PESSOAS");
                gotoxy(26,10);textcolor(15);scanf("%i",&crs.vagas);

             }
             gotoxy(23,23);printf("                                       ");

             textcolor(15);
             gotoxy(34,12);scanf("%f",&crs.cargahoraria);
             while(crs.cargahoraria > 2){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                gotoxy(34,12);textcolor(15);scanf("%f",&crs.cargahoraria);

             }
             gotoxy(23,23);printf("                                       ");
             textcolor(15);

             gotoxy(28,14);scanf("%f",&crs.horario);
             while(crs.horario > 18 || crs.horario < 13){
                gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                gotoxy(28,14);textcolor(15);scanf("%f",&crs.horario);
             }

             gotoxy(18,23);textcolor(4);printf("                                            ");

             textcolor(15);
             fflush(stdin);
             gotoxy(18,23);textcolor(4);printf("SALAS DISPONIVEIS: AUDITORIO3,SALA 1,SALA 2");
             textcolor(15);

             gotoxy(25,16);gets(crs.sala);
             gotoxy(25,18);gets(crs.tema);
             gotoxy(30,20);gets(crs.professor);

             crs.codCurso = 333; /// CODIGO DE CURSOS-----------------

             fwrite(&crs,sizeof(CURSO),1,filecursos);
             fclose(filecursos);
             fclose(filelogin);
             gotoxy(49,20);getch();
    }

    /// AS OFICINAS JA ESTAO QSE 100% DO ESPERADO

    else if(lgn.categoria == '5'){ /// OFICINAS CAPACIDADE DE 20 PESSOAS
           system("cls");
            char opcao;
             FILE *fileoficinas;

             fileoficinas = fopen("oficinas.txt","ab"); // salvar dados dos cursos

             OFICINA ofc;
             //LOGIN  cng1; // isso aq foi criado com o intuito de pegar os dados do usuario para mostrar na tela

             gotoxy(10,5);quadradoCadastro();
             gotoxy(19,7);printf("\t======>Bem vindo %s<======",lgn.nome);
             gotoxy(20,10);printf("VAGAS: ");
             gotoxy(20,12);printf("CARGA HORARIA: ");
             gotoxy(20,14);printf("HORARIO: ");
             gotoxy(20,16);printf("SALA: \n\n");
             gotoxy(20,18);printf("TEMA: \n\n");
             gotoxy(20,20);printf("PROFESSOR: \n\n");
             gotoxy(41,19);linha(5);
             gotoxy(40,20);printf("%cENTER%c",179,179);
             gotoxy(41,21);linha(5);

             textcolor(15);
             gotoxy(26,10);scanf("%i",&ofc.vagas);
             while(ofc.vagas > 20){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CAPACIDADE MAXIMA DE 20 PESSOAS");
                gotoxy(26,10);textcolor(15);scanf("%i",&ofc.vagas);

             }
             gotoxy(23,23);printf("                                       ");

             textcolor(15);
             gotoxy(34,12);scanf("%f",&ofc.cargahoraria);
             while(ofc.cargahoraria > 2){
                gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                gotoxy(34,12);textcolor(15);scanf("%f",&ofc.cargahoraria);

             }
             gotoxy(23,23);printf("                                       ");
             textcolor(15);

             gotoxy(28,14);scanf("%f",&ofc.horario);
             while(ofc.horario > 18 || ofc.horario < 13){
                gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                gotoxy(28,14);textcolor(15);scanf("%f",&ofc.horario);
             }

             gotoxy(18,23);textcolor(4);printf("                                            ");

             textcolor(15);
             fflush(stdin);
             gotoxy(23,23);textcolor(4);printf("SALAS DISPONIVEIS: LAB1 OU LAB 2");
             textcolor(15);

             gotoxy(25,16);gets(ofc.sala);
             gotoxy(25,18);gets(ofc.tema);
             gotoxy(30,20);gets(ofc.professor);

             ofc.codOficinas = 444; ///------------------------------------------------------

             fwrite(&ofc,sizeof(OFICINA),1,fileoficinas);
             fclose(fileoficinas);
             fclose(filelogin);
             gotoxy(47,20);getch();
    }

}

void verificadorDelogin(char loginParamento[10],char nomeparametro[40]){

    FILE *filelogin;
    LOGIN lgn;
    filelogin = fopen("login.txt","rb");

    if(filelogin == NULL){
        printf("Nao foi possivel abrir o arquivo filelogin");
    }
   /* if(usuarios == NULL){
        printf("Nao foi possivel abrir o arquivo usuarios = palestra");}*/

    else{
        while( fread(&lgn,sizeof(LOGIN),1,filelogin) == 1 ){ // aq vai ler todos os dados armazenados

                if(strcmp(loginParamento,lgn.login) == 0 ){// se o login digitado for igual a algum login armazenado ele printa logado

                    printf("  [Logado]\n\n\n");

                    getch();
                    if(lgn.categoria == '1'){// se for igual os login ele verifica a categoria e chama uma função de acordo com a categoria
                        palestra(nomeparametro);

                        }
                    else if(lgn.categoria == '2'){
                        congressitas(nomeparametro);
                        printf("---");

                    }
                    else if(lgn.categoria == '3'){
                        mesaredonda(nomeparametro);
                    }
                    else if(lgn.categoria == '4'){
                        cursos(nomeparametro);
                    }
                    else if(lgn.categoria == '5'){
                        oficina(nomeparametro);
                    }
                    getch();
                    break;
                    }
                }
        }
        fclose(filelogin);
    }

void palestra(char nome[40]){



    system("cls");
    char opcao,opc;
    int cont;
    FILE *filelogin;
    FILE *novoarquivo;
    FILE *filepalestra;
    LOGIN lgn; //
    PALESTRA cdt;
    filelogin = fopen("login.txt","rb");
    novoarquivo = fopen("temp.txt","ab");
    filepalestra = fopen("palestra.txt","rb");

    if(novoarquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }


    system("color 17");
    gotoxy(10,5);quadradoCadastro();

    gotoxy(22,6);printf("\tAJUSTE OS DADOS DE SUA PALESTRA");

    gotoxy(27,11);linha(12);
    gotoxy(22,12);printf("1 - %cListar dados%c",179,179);
    gotoxy(27,13);linha(12);

    gotoxy(27,14);linha (6);
    gotoxy(22,15);printf("2 - %cEditar%c",179,179);
    gotoxy(27,16);linha (6);
    gotoxy(27,17);linha (7);
    gotoxy(22,18);printf("3 - %cRemover%c",179,179);
    gotoxy(27,19);linha (7);
    fflush(stdin);
    opcao = getch();
    switch(opcao){
            case '1':
                      while( fread(&cdt,sizeof(PALESTRA),1,filepalestra) == 1 ){
                              if(strcmp(cdt.palestrante,nome) == 0){
                                    system("cls");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>BEM VINDO<==========");
                                    gotoxy(20,10);printf("SALA: %s\n",cdt.sala);
                                    gotoxy(20,12);printf("HORARIO: %.1f horas\n",cdt.horario);
                                    gotoxy(20,14); printf("TEMA: %s\n",cdt.tema);
                                    gotoxy(20,16); printf("PALESTRANTE: %s\n",cdt.palestrante);
                                    gotoxy(20,18); printf("CARGA HORARIA: %.1f\n",cdt.cargaHoraria);
                                    fclose(novoarquivo);
                                    fclose(filelogin);
                                    fclose(filepalestra);
                                    break;
                                    }
                             }
                    ;break;

          case '2':
                      while(  fread(&cdt,sizeof(PALESTRA),1,filepalestra) == 1  ){
                           if(strcmp(cdt.palestrante,nome) == 0){
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>ALTERAR DADOS<==========");

                                    gotoxy(20,10);printf("Sala: ");
                                    gotoxy(20,12);printf("Tema: ");
                                    gotoxy(20,14);printf("horario: ");
                                    gotoxy(20,16);printf("Carga Horaria: ");
                                    fflush(stdin);
                                    gotoxy(25,23);textcolor(4);printf("SALAS DISPONIVEIS: [AUDITORIO 1,2,3]");
                                    gotoxy(26,10);gets(cdt.sala);
                                    gotoxy(26,12);gets(cdt.tema);
                                    gotoxy(25,23);textcolor(4);printf("HORARIOS DISPONIVEIS: ENTRE 7 E 12  ");
                                    gotoxy(29,14);scanf("%f",&cdt.horario);

                                    gotoxy(25,23);textcolor(4);printf("                                    ");

                                    while(cdt.horario < 7 || cdt.horario > 12){
                                         gotoxy(25,23);textcolor(4);printf("HORARIO INDISPONIVEL");
                                         gotoxy(29,14);scanf("%f",&cdt.horario);
                                     }

                                     gotoxy(25,23);textcolor(4);printf("                                    ");
                                     gotoxy(35,16);scanf("%f",&cdt.cargaHoraria);
                                     while(cdt.cargaHoraria > 2){
                                          gotoxy(25,23);textcolor(4);printf("\7 DIMINUA SUA CARGA HORARIA");
                                          gotoxy(35,16);scanf("%f",&cdt.cargaHoraria);
                                     }
                                     if((cdt.cargaHoraria + cdt.horario) > 12 ){
                                            gotoxy(25,23);printf("\7TEMPO LIMITE UTRAPASSADO");
                                            gotoxy(25,24);printf("DIMINUA O SEU HORARIO");
                                            gotoxy(29,18);scanf("%f",&cdt.horario);
                                     }
                                       gotoxy(25,24);textcolor(4);printf("                                    ");

                                    fwrite(&cdt,sizeof(PALESTRA),1,novoarquivo);
                                    textcolor(4);gotoxy(30,22); printf("DADOS ALTERADO COM SUCESSO!");
                                    getch();
                                    textcolor(15);
                                    break;
                                    }
                            else{
                                fwrite(&cdt,sizeof(PALESTRA),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filepalestra);
                      remove("palestra.txt");//remove o original
                      rename("temp.txt","palestra.txt");//renomeia o aux com nome do orinial

                      getch();
                      inicio();

          ;break;
           case '3':
               gotoxy(10,5);quadradoCadastro();
               gotoxy(22,6);printf("====>REMOVER DADOS<====");
               gotoxy(22,8);printf("DESEJA REMOVER OS DADOS DE SEU CURSO[s/n]?");
               opc = getch();
               if(opc == 's'){
                   while( fread(&cdt,sizeof(PALESTRA),1,filepalestra) == 1  ){

                           if(strcmp(cdt.palestrante,nome) == 0){
                                continue;
                           }
                            else{
                                fwrite(&cdt,sizeof(PALESTRA),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filepalestra);

                      remove("palestra.txt");

                      rename("temp.txt","palestra.txt");//renomeia o aux com nome do orinial
                      printf("USUARIO REMOVIDO COM SUCESSO!");
                      gotoxy(50,23);getch();
                      inicio();
               }
               else{
                gotoxy(22,8);textcolor(4);printf("BOA ESCOLHA APROVEITE O EVENTO");
                textcolor(15);
                getch();
                inicio();
               }

          ;break;
          default:
            printf("OPCAO INVALIDA");
            }
        }
void congressitas(char nome[40]){


    system("cls");

    char opcao,opc,inscricao;
    int cont,contEventos;
    FILE *filelogin;
    FILE *novoarquivo;
    FILE *filecongre;
    LOGIN lgn; //
    CONGRE cng;
    filelogin = fopen("login.txt","rb");
    novoarquivo = fopen("temp.txt","ab");
    filecongre = fopen("congrecionistas.txt","rb");

    if(novoarquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
        }

    system("color 17");
    gotoxy(10,5);quadradoCadastro();

    gotoxy(22,6);printf("\tAJUSTE OS DADOS DE SUA PALESTRA");

    gotoxy(27,11);linha(12);
    gotoxy(22,12);printf("1 - %cListar dados%c",179,179);
    gotoxy(27,13);linha(12);

    gotoxy(27,14);linha (6);
    gotoxy(22,15);printf("2 - %cEditar%c",179,179);
    gotoxy(27,16);linha (6);
    fflush(stdin);
    opcao = getch();

    switch(opcao){
            case '1':
                      while( fread(&lgn,sizeof(LOGIN),1,filelogin) == 1 ){
                              fread(&cng,sizeof(CONGRE),1,filecongre);
                              if(strcmp(lgn.nome,nome) == 0){
                                     printf("%s",nome);
                                     printf("%s",lgn.nome);
                                    system("cls");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>BEM VINDO<==========");
                                    gotoxy(20,10); printf("NOME: %s\n",cng.nome);
                                    gotoxy(20,12); printf("NUMERO EVENTOS MATRICULADOS: %i\n",cng.nEventos);
                                    gotoxy(20,14); printf("MATRICULADO: %i\n",cng.idUsuarios[cng.nEventos][1]);
                                    getch();
                                    fclose(filelogin);
                                    fclose(novoarquivo);
                                    fclose(filecongre);
                                    inicio();
                                    break;
                                    }
                             }
                             break;

          case '2':
                      while( fread(&cng,sizeof(CONGRE),1,filecongre) == 1  ){

                           if(strcmp(cng.nome,nome) == 0){
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>ALTERAR DADOS<==========");

                                    gotoxy(20,10);printf("NOME: ");
                                    gotoxy(26,10);gets(cng.nome);
                                    system("cls");
                                    gotoxy(22,6);printf("====>ALTERA EVENTO MATRICULADO<====");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(20,8);printf("VEJA OS EVENTOS DISPONIVEIS");
                                    gotoxy(20,10);printf("[1] - PALESTRAS [2]- MESA REDONDA \n");
                                    gotoxy(20,12);printf("[3] - CURSOS    [4] - OFICINAS");
                                    gotoxy(50,12);opcao = getch();
                                        if(opcao == '1'){ ///USUARIO ESCOLHANDO UMA NOVA PALESTRA
                                                FILE *palestr;
                                                palestr = fopen("palestra.txt","rb");
                                                PALESTRA cdt;
                                                system("cls");
                                                gotoxy(10,5);quadradoCadastro();
                                                gotoxy(24,7);printf("PALESTRAS DISPONIVEIS");
                                                while( fread(&cdt,sizeof(PALESTRA),1,palestr) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                                                     gotoxy(24,8);linha(22);
                                                    //DADOS DOS PALESTRANTES
                                                     gotoxy(20,9);printf("Sala: %s",cdt.sala);
                                                     gotoxy(20,11);printf("Horario: %.1f horas",cdt.horario); // tds os cdt esta sendo salvo no txt palestra
                                                     gotoxy(20,13);printf("Tema: %s",cdt.tema);
                                                     gotoxy(20,15);printf("Carga Horaria:%.1f",cdt.cargaHoraria);
                                                     gotoxy(24,16);linha(22);
                                                     gotoxy(20,17);printf("DESEJA SE INSCREVER [s/n]? ");
                                                     gotoxy(46,17);scanf("%s",&inscricao);
                                                    if(inscricao == 's'){ /// N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE
                                                        contEventos = 1;
                                                        cng.nEventos = contEventos;
                                                        contEventos += 1;
                                                        cng.idUsuarios[cng.nEventos][1] = cdt.codPalestra;

                                                        gotoxy(20,19);printf("DIGITE SEU NOME: ");
                                                        fflush(stdin);
                                                        gets(cng.nome);
                                                        fwrite(&cng,sizeof(CONGRE),1,novoarquivo); /// salvando os dados em em congressitas

                                                        fclose(filecongre);
                                                        fclose(filelogin);
                                                        fclose(palestr);
                                                        fclose(novoarquivo);
                                                        remove("temp.txt");
                                                        rename("temp.txt","congrecionistas.txt");
                                                        gotoxy(29,22);printf("USUARIO MATRICULADO!");
                                                        getch();
                                                        break;
                                                        }
                                                    }
                                                    gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                                                    opc = getch();
                                                    if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                                                        gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                                                        textcolor(15);
                                                        getch();
                                                        inicio();
                                                    }

                                                }
                             else if(opcao == '2'){ /// OPCAO DE CONGRESSISTAS MESA REDONDA ---------------------------------

                                           FILE *filemesas;
                                           FILE *temp;
                                           filemesas = fopen("mesa.txt","rb"); // salvar dados dos cursos
                                           temp = fopen("temp.txt","ab");
                                           MESA msa;

                                            gotoxy(10,5);quadradoCadastro();
                                            gotoxy(24,7);printf("CURSOS DISPONIVEIS");
                                            while( fread(&msa,sizeof(CURSO),1,filemesas) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                                                 gotoxy(24,8);linha(22);
                                                //DADOS DOS PALESTRANTES
                                                 gotoxy(20,9);printf("Sala: %s",msa.sala);
                                                 gotoxy(20,11);printf("Horario: %.1f horas",msa.horario); // tds os msa esta sendo salvo no txt palestra
                                                 gotoxy(20,13);printf("Tema: %s",msa.tema);
                                                 gotoxy(20,15);printf("Carga Horaria:%.1f",msa.cargahoraria);
                                                 gotoxy(24,16);linha(22);
                                                 gotoxy(19,17);printf("DESEJA SE INSCREVER [s/n]? ");
                                                 gotoxy(46,17);scanf("%s",&inscricao);
                                                if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE

                                                    contEventos = 1;
                                                    cng.nEventos = contEventos;
                                                    contEventos += 1;
                                                    cng.idUsuarios[cng.nEventos][1] = msa.codMesa;

                                                    gotoxy(20,19);printf("DIGITE SEU NOME: ");
                                                    fflush(stdin);
                                                    gets(cng.nome);
                                                    fwrite(&cng,sizeof(CONGRE),1,novoarquivo); /// salvando os dados em em congressitas

                                                    fclose(filecongre);
                                                    fclose(filelogin);
                                                    fclose(filemesas);
                                                    fclose(novoarquivo);
                                                    remove("congrecionistas.txt");
                                                    rename("temp.txt","congrecionistas.txt");
                                                    gotoxy(29,22);printf("USUARIO MATRICULADO!");
                                                    getch();
                                                    break;
                                                    }
                                                }
                                                gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                                                opc = getch();
                                                if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                                                    gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                                                    textcolor(15);
                                                    getch();
                                                    inicio();
                                                }

                                        }
                                        else if(opcao == '3'){ /// OPCAO DE CONGRESSISTAS CURSOS

                                            FILE *filecursos;
                                            filecursos = fopen("cursos.txt","rb"); // salvar dados dos cursos
                                            CURSO crs;

                                            gotoxy(10,5);quadradoCadastro();
                                            gotoxy(24,7);printf("CURSOS DISPONIVEIS");
                                            while( fread(&crs,sizeof(CURSO),1,filecursos) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                                                 gotoxy(24,8);linha(22);
                                                //DADOS DOS PALESTRANTES
                                                 gotoxy(20,9);printf("Sala: %s",crs.sala);
                                                 gotoxy(20,11);printf("Horario: %.1f horas",crs.horario); // tds os crs esta sendo salvo no txt palestra
                                                 gotoxy(20,13);printf("Tema: %s",crs.tema);
                                                 gotoxy(20,15);printf("Carga Horaria:%.1f",crs.cargahoraria);
                                                 gotoxy(24,16);linha(22);
                                                 gotoxy(19,17);printf("DESEJA SE INSCREVER [s/n]? ");
                                                 gotoxy(46,17);scanf("%s",&inscricao);
                                                if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE

                                                    contEventos = 1;
                                                    cng.nEventos = contEventos;
                                                    contEventos += 1;
                                                    cng.idUsuarios[cng.nEventos][1] = crs.codCurso;

                                                    gotoxy(20,19);printf("DIGITE SEU NOME: ");
                                                    fflush(stdin);
                                                    gets(cng.nome);
                                                    fwrite(&cng,sizeof(CONGRE),1,novoarquivo); /// salvando os dados em em congressitas

                                                    fclose(filecongre);
                                                    fclose(filelogin);
                                                    fclose(filecursos);
                                                    gotoxy(29,22);printf("USUARIO MATRICULADO!");

                                                    fclose(novoarquivo);
                                                    remove("congrecionistas.txt");
                                                    rename("temp.txt","congrecionistas.txt");
                                                    getch();
                                                    break;
                                                    }
                                                }
                                                gotoxy(29,23);printf("DESEJA CONTINUAR[s/n] ? ");
                                                opc = getch();
                                                if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                                                    gotoxy(29,24);textcolor(4);printf("APROVEITE O EVENTO");
                                                    textcolor(15);
                                                    getch();
                                                    inicio();
                                                }
                                                continue;
                                        }
                                        else if(opcao == '4'){ /// OPCAO DE CONGRESSISTAS OFCINAS


                                            FILE *fileoficina;
                                            fileoficina = fopen("oficinas.txt","rb"); // salvar dados dos cursos

                                            OFICINA ofc;

                                            gotoxy(10,5);quadradoCadastro();
                                            gotoxy(24,7);printf("OFICINAS DISPONIVEIS");
                                            while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
                                                 gotoxy(24,8);linha(22);
                                                //DADOS DOS PALESTRANTES
                                                 gotoxy(20,9);printf("Sala: %s",ofc.sala);
                                                 gotoxy(20,11);printf("Horario: %.1f horas",ofc.horario); // tds os ofc esta sendo salvo no txt palestra
                                                 gotoxy(20,13);printf("Tema: %s",ofc.tema);
                                                 gotoxy(20,15);printf("Carga Horaria:%.1f",ofc.cargahoraria);
                                                 gotoxy(24,16);linha(22);
                                                 gotoxy(20,17);printf("DESEJA SE INSCREVER [s/n]? ");
                                                 gotoxy(46,17);scanf("%s",&inscricao);
                                                if(inscricao == 's'){ // N PRECISO BOTAR ELSE PQ SE FOR N ELE VOLTTA PARA O INICIO DO WHILE
                                                    contEventos = 1;
                                                    cng.nEventos = contEventos;
                                                    contEventos += 1;
                                                    cng.idUsuarios[cng.nEventos][1] = ofc.codOficinas;
                                                    gotoxy(20,19);printf("DIGITE SEU NOME: ");
                                                    fflush(stdin);
                                                    gets(cng.nome);
                                                    fwrite(&cng,sizeof(CONGRE),1,novoarquivo); /// salvando os dados em em congressitas

                                                    fclose(filecongre);
                                                    fclose(filelogin);
                                                    fclose(fileoficina);
                                                    fclose(novoarquivo);
                                                    gotoxy(29,22);printf("USUARIO MATRICULADO!");
                                                    remove("congrecionistas.txt");
                                                    rename("temp.txt","congrecionistas.txt");
                                                    getch();
                                                    break;
                                                    }
                                                }
                                                gotoxy(29,22);printf("DESEJA CONTINUAR[s/n] ? ");
                                                opc = getch();
                                                if(opc == 'n'){ /// CONDIÇÃO PARA SAIR DO WHILEE PRINCIPAL OQ RODA TODO O EVENTO
                                                    gotoxy(29,23);textcolor(4);printf("APROVEITE O EVENTO");
                                                    textcolor(15);
                                                    getch();
                                                    inicio();
                                                    }


                                                fwrite(&cng,sizeof(CONGRE),1,novoarquivo);
                                                textcolor(4);gotoxy(30,22); printf("Dados alterado com Sucesso!");
                                                getch();
                                                textcolor(15);
                                                break;
                                                }
                                    else{
                                        fwrite(&cng,sizeof(CONGRE),1,novoarquivo);
                                        }

                           }                   ///-------------------------------------------------------------

                      }
                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filecongre);
                      remove("congrecionistas.txt");//remove o original
                      rename("temp.txt","congrecionistas.txt");//renomeia o aux com nome do orinial

                      getch();
                           ;break;

                          default:
                            printf("OPCAO INVALIDA");
                        }
                        inicio();
            }
void mesaredonda(char nome[40]){
     system("cls");
    char opcao,opc;
    int cont;
    FILE *filelogin;
    FILE *novoarquivo;
    FILE *filemesaredonda;
    LOGIN lgn; //
    MESA msa;
    filelogin = fopen("login.txt","rb");
    novoarquivo = fopen("temp.txt","ab");
    filemesaredonda = fopen("mesa.txt","rb");

    if(novoarquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }


    system("color 17");
    gotoxy(10,5);quadradoCadastro();

    gotoxy(20,6);printf("AJUSTE OS DADOS DE SEU GRUPO DE DISCURCOES");

    gotoxy(27,11);linha(12);
    gotoxy(22,12);printf("1 - %cListar dados%c",179,179);
    gotoxy(27,13);linha(12);

    gotoxy(27,14);linha (6);
    gotoxy(22,15);printf("2 - %cEditar%c",179,179);
    gotoxy(27,16);linha (6);

    gotoxy(27,17);linha (7);
    gotoxy(22,18);printf("3 - %cRemover%c",179,179);
    gotoxy(27,19);linha (7);
    opcao = getch();
    switch(opcao){
            case '1':
                      while( fread(&msa,sizeof(MESA),1,filemesaredonda) == 1 ){
                              if(strcmp(msa.nome,nome) == 0){
                                    system("cls");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>BEM VINDO<==========");
                                    gotoxy(20,10);printf("SALA: %s\n",msa.sala);
                                    gotoxy(20,12);printf("HORARIO: %.1f horas\n",msa.horario);
                                    gotoxy(20,14);printf("TEMA: %s\n",msa.tema);
                                    gotoxy(20,16);printf("NOME: %s\n",msa.nome);
                                    gotoxy(20,18);printf("CARGA HORARIA: %.1f\n",msa.cargahoraria);
                                    gotoxy(20,18);printf("MEMBROS: %s\n",msa.membros);
                                    break;
                                    }
                             }
                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filemesaredonda);
                    ;break;

          case '2':
                      while(fread(&msa,sizeof(MESA),1,filemesaredonda) == 1  ){
                           if(strcmp(msa.nome,nome) == 0){
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("====>ALTERAR DADOS<====");

                                    gotoxy(20,10);printf("Sala: ");
                                    gotoxy(20,12);printf("Tema: ");
                                    gotoxy(20,14);printf("horario: ");
                                    gotoxy(20,16);printf("Carga Horaria: ");

                                    gotoxy(18,23);textcolor(4);printf("SALAS DISPONIVEIS: SALA 1,SALA 2,SALA 3");
                                    textcolor(15);
                                    gotoxy(26,10);gets(msa.sala);
                                    gotoxy(18,23);textcolor(4);printf("                                            ");
                                    textcolor(15);
                                    gotoxy(25,12);gets(msa.tema);

                                    gotoxy(28,14);scanf("%f",&msa.horario);
                                    while(msa.horario > 18 || msa.horario < 13){
                                        gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                                        gotoxy(28,14);textcolor(15);scanf("%f",&msa.horario);
                                        }

                                    gotoxy(18,23);textcolor(4);printf("                                            ");

                                    textcolor(15);
                                    gotoxy(34,16);scanf("%f",&msa.cargahoraria);
                                     while(msa.cargahoraria > 2){
                                        gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                                        gotoxy(34,16);textcolor(15);scanf("%f",&msa.cargahoraria);

                                     }
                                     gotoxy(23,23);printf("                                       ");
                                     textcolor(15);
                                     gotoxy(23,23);textcolor(4);printf("DADOS ALTERADO COM SUCESSO!");
                                     textcolor(15);
                                     fwrite(&msa,sizeof(MESA),1,novoarquivo);
                                    break;
                           }
                            else{
                                fwrite(&msa,sizeof(CURSO),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filemesaredonda);
                      remove("mesa.txt");//remove o original
                      rename("temp.txt","mesa.txt");//renomeia o aux com nome do orinial

                      getch();
                      inicio();

          ;break;
          case '3':
               gotoxy(10,5);quadradoCadastro();
               gotoxy(22,6);printf("====>REMOVER DADOS<====");
               gotoxy(19,8);printf("DESEJA REMOVER OS DADOS DE SUA OFICINAS[s/n]?");
               opc = getch();
               if(opc == 's'){
                   while( fread(&msa,sizeof(MESA),1,filemesaredonda) == 1  ){
                           if(strcmp(msa.nome,nome) == 0){
                                continue;
                           }
                            else{
                                fwrite(&msa,sizeof(MESA),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filemesaredonda);
                      remove("mesa.txt");//remove o original
                      rename("temp.txt","mesa.txt");//renomeia o aux com nome do orinial
                      gotoxy(19,12);textcolor(4);printf("DADOS ALTERADO COM SUCESSO!");
                      gotoxy(50,23);getch();
                      inicio();
               }
               else{
                    gotoxy(22,8);textcolor(4);printf("BOA ESCOLHA APROVEITE O EVENTO");
                    textcolor(15);
                    getch();
                    inicio();
                   }
          ;break;
          default:
            printf("OPCAO INVALIDA");
            }
}

void cursos(char nome[40]){
    system("cls");
    char opcao,opc;
    int cont;
    FILE *filelogin;
    FILE *novoarquivo;
    FILE *filecursos;
    LOGIN lgn; //
    CURSO crs;
    filelogin = fopen("login.txt","rb");
    novoarquivo = fopen("temp.txt","ab");
    filecursos = fopen("cursos.txt","rb");

    if(novoarquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }


    system("color 17");
    gotoxy(10,5);quadradoCadastro();

    gotoxy(21,6);printf("AJUSTE OS DADOS DE SEU CURSO");

    gotoxy(27,11);linha(12);
    gotoxy(22,12);printf("1 - %cListar dados%c",179,179);
    gotoxy(27,13);linha(12);

    gotoxy(27,14);linha (6);
    gotoxy(22,15);printf("2 - %cEditar%c",179,179);
    gotoxy(27,16);linha (6);

    gotoxy(27,17);linha (7);
    gotoxy(22,18);printf("3 - %cRemover%c",179,179);
    gotoxy(27,19);linha (7);
    opcao = getch();
    switch(opcao){
            case '1':
                      while(  fread(&crs,sizeof(CURSO),1,filecursos) == 1 ){

                              if(strcmp(crs.professor,nome) == 0){
                                    system("cls");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>BEM VINDO<==========");
                                    gotoxy(20,10);printf("SALA: %s\n",crs.sala);
                                    gotoxy(20,12);printf("HORARIO: %.1f horas\n",crs.horario);
                                    gotoxy(20,14);printf("TEMA: %s\n",crs.tema);
                                    gotoxy(20,16);printf("PROFESSOR: %s\n",crs.professor);
                                    gotoxy(20,18);printf("CARGA HORARIA: %.1f\n",crs.cargahoraria);
                                    break;
                                    }
                             }
                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filecursos);
                    ;break;

          case '2':
                      while( fread(&crs,sizeof(CURSO),1,filecursos) == 1  ){

                           if(strcmp(crs.professor,nome) == 0){
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("====>ALTERAR DADOS<====");

                                    gotoxy(20,10);printf("Sala: ");
                                    gotoxy(20,12);printf("Tema: ");
                                    gotoxy(20,14);printf("horario: ");
                                    gotoxy(20,16);printf("Carga Horaria: ");

                                    gotoxy(18,23);textcolor(4);printf("SALAS DISPONIVEIS: AUDITORIO3,SALA 1,SALA 2");
                                    textcolor(15);
                                    gotoxy(26,10);gets(crs.sala);
                                    gotoxy(18,23);textcolor(4);printf("                                            ");
                                    textcolor(15);
                                    gotoxy(25,12);gets(crs.tema);

                                    gotoxy(28,14);scanf("%f",&crs.horario);
                                    while(crs.horario > 18 || crs.horario < 13){
                                        gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                                        gotoxy(28,14);textcolor(15);scanf("%f",&crs.horario);
                                        }

                                    gotoxy(18,23);textcolor(4);printf("                                            ");

                                     textcolor(15);
                                    gotoxy(34,16);scanf("%f",&crs.cargahoraria);
                                     while(crs.cargahoraria > 2){
                                        gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                                        gotoxy(34,16);textcolor(15);scanf("%f",&crs.cargahoraria);

                                     }
                                     gotoxy(23,23);printf("                                       ");
                                     textcolor(15);
                                     gotoxy(23,23);textcolor(4);printf("DADOS ALTERADO COM SUCESSO!");
                                     textcolor(4);
                                     fwrite(&crs,sizeof(CURSO),1,novoarquivo);
                                     break;
                                    }
                            else{
                                fwrite(&crs,sizeof(CURSO),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filecursos);
                      remove("cursos.txt");//remove o original
                      rename("temp.txt","cursos.txt");//renomeia o aux com nome do orinial

                      getch();
                      inicio();

          ;break;
          case '3':
               gotoxy(10,5);quadradoCadastro();
               gotoxy(22,6);printf("====>REMOVER DADOS<====");
               gotoxy(22,8);printf("DESEJA REMOVER OS DADOS DE SEU CURSO[s/n]?");
               opc = getch();
               if(opc == 's'){
                   while( fread(&crs,sizeof(CURSO),1,filecursos) == 1  ){

                           if(strcmp(crs.professor,nome) == 0){
                                continue;
                           }
                            else{
                                fwrite(&crs,sizeof(CURSO),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(filecursos);
                      remove("cursos.txt");//remove o original
                      rename("temp.txt","cursos.txt");//renomeia o aux com nome do orinial
                      gotoxy(22,10);printf("DADOS REMOVIDOS COM SUCESSO!");
                      gotoxy(50,23);getch();
                      inicio();
               }
               else{
                gotoxy(22,8);textcolor(4);printf("BOA ESCOLHA APROVEITE O EVENTO");
                textcolor(15);
                getch();
                inicio();
               }

          ;break;
          default:
            printf("OPCAO INVALIDA");
            }
}

void oficina(char nome[40]){
    system("cls");
    char opcao,opc;
    int cont;
    FILE *filelogin;
    FILE *novoarquivo;
    FILE *fileoficina;
    LOGIN lgn; //
    OFICINA ofc;
    filelogin = fopen("login.txt","rb");
    novoarquivo = fopen("temp.txt","ab");
    fileoficina = fopen("oficinas.txt","rb");

    if(novoarquivo == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }


    system("color 17");
    gotoxy(10,5);quadradoCadastro();

    gotoxy(22,6);printf("\tAJUSTE OS DADOS DE SUA OFICINAS");

    gotoxy(27,11);linha(12);
    gotoxy(22,12);printf("1 - %cListar dados%c",179,179);
    gotoxy(27,13);linha(12);

    gotoxy(27,14);linha (6);
    gotoxy(22,15);printf("2 - %cEditar%c",179,179);
    gotoxy(27,16);linha(6);

    gotoxy(27,17);linha(7);
    gotoxy(22,18);printf("3 - %cRemover%c",179,179);
    gotoxy(27,19);linha(7);
    fflush(stdin);
    opcao = getch();

    switch(opcao){
            case '1':
                      while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1 ){

                              if(strcmp(ofc.professor,nome) == 0){
                                    system("cls");
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("==========>BEM VINDO<==========");
                                    gotoxy(20,10);printf("SALA: %s\n",ofc.sala);
                                    gotoxy(20,12);printf("HORARIO: %.1f horas\n",ofc.horario);
                                    gotoxy(20,14);printf("TEMA: %s\n",ofc.tema);
                                    gotoxy(20,16);printf("PROFESSOR: %s\n",ofc.professor);
                                    gotoxy(20,18);printf("CARGA HORARIA: %.1f\n",ofc.cargahoraria);
                                    gotoxy(20,18);printf("MEMBROS: %.1f\n",ofc.cargahoraria);
                                    break;
                                    }
                             }
                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(fileoficina);

                    ;break;

          case '2':
                      while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1  ){

                           if(strcmp(ofc.professor,nome) == 0){
                                    gotoxy(10,5);quadradoCadastro();
                                    gotoxy(22,6);printf("====>ALTERAR DADOS<====");

                                    gotoxy(20,10);printf("SALA: ");
                                    gotoxy(20,12);printf("TEMA: ");
                                    gotoxy(20,14);printf("HORARIO: ");
                                    gotoxy(20,16);printf("CARGA HORARIA: ");
                                    gotoxy(20,18);printf("PROFESSOR: ");

                                    gotoxy(18,23);textcolor(4);printf("SALAS DISPONIVEIS: LAB1,LAB2");
                                    textcolor(15);
                                    gotoxy(26,10);gets(ofc.sala);
                                    gotoxy(18,23);textcolor(4);printf("                                            ");
                                    textcolor(15);
                                    gotoxy(25,12);gets(ofc.tema);

                                    gotoxy(28,14);scanf("%f",&ofc.horario);
                                    while(ofc.horario > 18 || ofc.horario < 13){
                                        gotoxy(18,23);textcolor(4);printf("\7HORARIOS DISPONIVEIS: ENTRE AS 13 E 18 HORAS");
                                        gotoxy(28,14);textcolor(15);scanf("%f",&ofc.horario);
                                        }

                                    gotoxy(18,23);textcolor(4);printf("                                            ");

                                     textcolor(15);
                                    gotoxy(34,16);scanf("%f",&ofc.cargahoraria);
                                     while(ofc.cargahoraria > 2){
                                        gotoxy(23,23);textcolor(4);printf("\7[ERRO]- CARGA HORARIA MAXIMA DE 2 HORAS");
                                        gotoxy(34,16);textcolor(15);scanf("%f",&ofc.cargahoraria);

                                     }
                                     fflush(stdin);
                                     gotoxy(31,18);gets(ofc.professor);
                                     gotoxy(23,23);printf("                                       ");

                                     textcolor(15);

                                     gotoxy(23,23);printf("DADOS ALTERADO COM SUCESSO!");

                                     fwrite(&ofc,sizeof(OFICINA),1,novoarquivo);
                                     break;
                           }
                            else{
                                fwrite(&ofc,sizeof(OFICINA),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(fileoficina);
                      remove("oficinas.txt");//remove o original
                      rename("temp.txt","oficinas.txt");//renomeia o aux com nome do orinial

                      gotoxy(50,23);getch();
                      inicio();
                      ;break;
          case '3':
               gotoxy(10,5);quadradoCadastro();
               gotoxy(22,6);printf("====>REMOVER DADOS<====");
               gotoxy(18,10);printf("DESEJA REMOVER OS DADOS DE SUA OFICINA[s/n]?\n");
               opc = getch();
               if(opc == 's'){
                   while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1  ){

                           if(strcmp(ofc.professor,nome) == 0){
                                continue;
                           }
                            else{
                                fwrite(&ofc,sizeof(OFICINA),1,novoarquivo);
                                }

                           }

                      fclose(novoarquivo);
                      fclose(filelogin);
                      fclose(fileoficina);
                      remove("oficinas.txt");//remove o original
                      rename("temp.txt","oficinas.txt");//renomeia o aux com nome do orinial
                      gotoxy(22,12);textcolor(4);printf("DADOS REMOVIDO COM SUCESSO");
                      gotoxy(50,23);getch();
                      inicio();
               }
               else{
                gotoxy(22,8);textcolor(4);printf("BOA ESCOLHA APROVEITE O EVENTO");
                textcolor(15);
                getch();
                inicio();
               }

          ;break;
          default:
            printf("OPCAO INVALIDA");
            }
}

void imprimirPalestra(){ /// dados apois ser alterado
    FILE *filepalestra;
    PALESTRA cdt;
    filepalestra = fopen("palestra.txt","rb");
    if(filepalestra == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{
            printf("PALESTRAS AGENDADAS\n");
        while( fread(&cdt,sizeof(PALESTRA),1,filepalestra) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");
            printf("Sala: %s\n",cdt.sala);
            printf("Horario: %.1f horas\n",cdt.horario);
            printf("Tema: %s\n",cdt.tema);
            printf("Carga Horaria:%.1f \n",cdt.cargaHoraria);

        }


    }
    fclose(filepalestra);

    getch();
}

void imprimirUsuarios(){ /// USAUARIOS LOGADOS AO SEU SISTEMA
    FILE *filelogin;
    LOGIN lgn;
    filelogin = fopen("login.txt","rb");
    if(filelogin == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{
            printf("USUARIOS CADASTRADOS\n");
        while( fread(&lgn,sizeof(LOGIN),1,filelogin) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");
            printf("Nome: %s\n",lgn.nome);
            printf("Login: %s\n",lgn.login);
            printf("Senha: %s\n",lgn.password);
        }


    }
    fclose(filelogin);

    getch();
}

void printcongrecionistas(){
    FILE *filecongre;
    CONGRE cng;
    filecongre = fopen("congrecionistas.txt","rb");
    if(filecongre == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{
            printf("PARTICIPANTES DO EVENTO\n");
        while( fread(&cng,sizeof(CONGRE),1,filecongre) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");

            printf("NUMERO DE EVENTOS: %i \n",cng.nEventos);
            printf("NOME: %s \n",cng.nome);
            printf("EVENTOS DISPONIVEIS : %i  \n",cng.idUsuarios[cng.nEventos][1]); /// PARA FAZER APARECER OS OUTROS BASTA APENAS USAR MAIS 3 %I E COLOCAR AS OUTRAS POSIÇÕES
        }
    }
    fclose(filecongre);

    getch();
}

void printcursos(){
    FILE *filecurso;
    CURSO crs;
    filecurso = fopen("cursos.txt","rb");
    if(filecurso == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{

            printf("CURSOS QUE SERAO MINISTRADOS\n");
        while( fread(&crs,sizeof(CURSO),1,filecurso) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");
            printf("VAGAS: %i\n",crs.vagas);
            printf("CARGA HORARIA: %.2f\n",crs.cargahoraria);
            printf("HORARIO: %.2f\n",crs.horario);
            printf("SALA: %s\n",crs.sala);
            printf("TEMA: %s\n",crs.tema);
            printf("PROFESSOR: %s\n",crs.professor);
        }


    }
    fclose(filecurso);

    getch();
}

void printmesaredonda(){
    FILE *filemesaredonda;
    MESA msa;
    filemesaredonda = fopen("mesa.txt","rb");
    if(filemesaredonda == NULL){
        printf("Nao foi possivel abrir o arquivo");
    }
    else{
              printf("MESAS REDONDA\n");
        while( fread(&msa,sizeof(MESA),1,filemesaredonda) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");
            printf("VAGAS: %i\n",msa.vagas);
            printf("CARGA HORARIA: %.1f\n",msa.cargahoraria);
            printf("HORARIO: %.1f\n",msa.horario);
            printf("SALA: %s\n",msa.sala);
            printf("TEMA: %s\n",msa.tema);
            printf("MEMBROS: %s\n",msa.membros);
        }

    }
    fclose(filemesaredonda);
    getch();
}

void printOfinas(){

    FILE *fileoficina;
    OFICINA ofc;
    fileoficina = fopen("oficinas.txt","rb");
    if(fileoficina == NULL){
        printf("Nao foi possivel abrir o arquivo");
        }
    else{
              printf("OFICINAS\n");
        while( fread(&ofc,sizeof(OFICINA),1,fileoficina) == 1 ){ // enquanto ele estiver retornando um é pq ainda n chegou no fim do arq txt
            printf("--------------------\n");
            printf("VAGAS: %i\n",ofc.vagas);
            printf("CARGA HORARIA: %.2f\n",ofc.cargahoraria);
            printf("HORARIO: %.2f\n",ofc.horario);
            printf("SALA: %s\n",ofc.sala);
            printf("TEMA: %s\n",ofc.tema);
            printf("PROFESSOR: %s\n",ofc.professor);
            }
        }

    fclose(fileoficina);

    getch();
}

void organizadores(){

    system("cls");
    char opcao;

    gotoxy(10,5);quadradoCadastro();
    gotoxy(18,7);printf("\t======>Bem vindo <======");
    gotoxy(19,9);printf ("LISTAR USUARIOS     - [1]");
    gotoxy(19,11);printf("LISTAR PALESTRAS    - [2]");
    gotoxy(19,13);printf("LISTAS CURSOS       - [3]");
    gotoxy(19,15);printf("LISTAS MESA REDONDA - [4]");
    gotoxy(19,17);printf("LISTAS OFICINAS     - [5]");
    gotoxy(19,19);printf("LISTAS CONGRESSITAS - [6]");
    gotoxy(19,21);printf("VOLTAR AO O INICIO  - [7]");
    opcao = getch();
    switch(opcao){
        case '1':
                system("cls");
                imprimirUsuarios();
                organizadores();
                break;
        case '2':
                system("cls");
                imprimirPalestra();
                organizadores();
                ;break;
        case '3':
                system("cls");
                printcursos();
                organizadores();
                break;
        case '4':
                system("cls");
                printmesaredonda();
                organizadores();
                break;
        case '5':
                system("cls");
                printOfinas();
                organizadores();
                break;
        case '6':
            system("cls");
            printcongrecionistas();
            organizadores();
            break;
        case '7':
            inicio();
            break;
        default:
            printf("OPCAO INVALIDA!");
    }
    inicio();
}

int verificar(char nome[40]){

    ///ESSA FUNÇÃO FOI CRIADA COM O INTUITO DE VEFICAR ALGO COM BASE NO NOME

    FILE *usuarios;
    PALESTRA cdt;
    FILE *filelogin;
    LOGIN lgn;
    int cont = 0;
    usuarios = fopen("dadosnovos.txt","rb");
    filelogin = fopen("login.txt","rb");
     while( fread(&cdt,sizeof(PALESTRA),1,usuarios) == 1 ){
             cont = cont + 1;
           if(strcmp(lgn.nome,nome) == 0){
                break;
                }
            }
    return cont;


}
