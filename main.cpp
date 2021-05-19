#include <windows.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <time.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Variaveis
    int digito1, digito2, digito3, digito4, digito5;
    int senha, senha1, senha2, senha3, senha4, senha5, qtd_digitos;
    int tecla, tentativas, i, i2, posicao_certa, posicao_errada, y, x;
    char menu, voltar;
    string dificuldade;
    dificuldade="Normal";
    qtd_digitos=4;
    tentativas=8;

    //Menu Inicial
    inicio:
    system ("clear||cls");

    voltar=0;
    y=3;

    cout<<"\nMenu Inicial:" ;
    cout<<"\n\n(j) Jogar";
    cout<<"\n(d) Dificuldade";
    cout<<"\n(s) Sobre";
    cout<<"\n\n(f) Fim";

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(out, &cursorInfo);

    menu=getche();

    if (dificuldade=="Facil") {
        tentativas=8;
    } else if (dificuldade=="Normal") {
        tentativas=10;
    } else if (dificuldade=="Dificil") {
        tentativas=12;
    }

    //Dificuldade
    if (menu=='d') {
        while (voltar !='v') {
            system ("clear||cls");

            cout<<"\nEscolha a dificuldade: "<<dificuldade;
            cout<<"\n\n(f) Facil";
            cout<<"\n(n) Normal";
            cout<<"\n(d) Dificil";
            cout<<"\n\n(v) Voltar";

            tecla=getche();

            switch (tecla) {
            case 102:
                dificuldade="Facil";
                qtd_digitos=3;
            break;
            case 110:
                dificuldade="Normal";
                qtd_digitos=4;
            break;
            case 100:
                dificuldade="Dificil";
                qtd_digitos=5;
            break;
            case 118:
                voltar='v';
            break;
            }
        }
        goto inicio;
    }

    //Sobre
    if (menu=='s') {
        while (voltar !='v') {
            system ("clear||cls");

            cout<<"\nSobre";
            cout<<"\n\nEquipe de Desenvolvimento:";
            cout<<"\n-Lucas Oliveira Prado";
            cout<<"\n-Gabriel Libório ";
            cout<<"\n\nProfessor: Thiago Felski Pereira";
            cout<<"\nDisciplina: Algoritimos e Programação";
            cout<<"\n\nData: Maio/2021";
            cout<<"\n\n(v) Voltar";

            voltar=getche();
        }
        goto inicio;
    }

    //Inicio do jogo dificuldade dificil
    if (menu=='j') {

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = true;
        SetConsoleCursorInfo(out, &cursorInfo);

        // Geração da digito de forma randomica
        system ("clear || cls");

        digito1=0;
        digito2=0;
        digito3=0;
        digito4=0;
        digito5=0;

        srand (time(NULL));
        while (digito1==0) {digito1= rand()%7;}
        while (digito2==0 or digito2==digito1) {digito2= rand()%7;}
        while (digito3==0 or digito3==digito1 or digito3==digito2) {digito3= rand()%7;}

        if (dificuldade=="Normal" || dificuldade=="Dificil") {
            while (digito4==0 or digito4==digito1 or digito4==digito2 or digito4==digito3) {digito4= rand()%7;}
        }
        if (dificuldade=="Dificil") {
            while (digito5==0 or digito5==digito1 or digito5==digito2 or digito5==digito3 or digito5==digito4) {digito5= rand()%7;}
        }

        //Respostas do usuario
            cout<<"\nExiste uma senha de "<<qtd_digitos<<" digitos que voce pecisa descobrir,\ncada numero da senha vai de 1 a 6\n\n(v) Voltar";

        while (tentativas!=0) {
            tentativas=tentativas-1;
            senha1=0;
            senha2=0;
            senha3=0;
            senha4=0;
            senha5=0;
            i2=0;
            posicao_certa=0;
            posicao_errada=0;
            y=y+5;
            x=8;
            COORD coord;
            coord.X = 1;
            coord.Y = y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

            if (dificuldade=="Facil") {
                cout<<"Senha:  -*-*";
            } else if (dificuldade=="Normal") {
                cout<<"Senha:  -*-*-*";
            } else if (dificuldade=="Dificil") {
                cout<<"Senha:  -*-*-*-*";
            }

            //Reconhecimento do Teclado
            while(i2<qtd_digitos) {
                i=0;

                COORD coord;
                coord.X = x;
                coord.Y = y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                tecla=getche();

                switch(tecla) {
                case 49:
                    tecla=1, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 50:
                    tecla=2, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 51:
                    tecla=3, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 52:
                    tecla=4, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 53:
                    tecla=5, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 54:
                    tecla=6, i=1, i2++, x=x+2;
                    if(senha5==0 && senha4!=0 && senha3!=0 && senha2!=0 && senha1!=0) {senha5=tecla;}
                    if(senha4==0 && senha3!=0 && senha2!=0 && senha1!=0) {senha4=tecla;}
                    if(senha3==0 && senha2!=0 && senha1!=0) {senha3=tecla;}
                    if(senha2==0 && senha1!=0) {senha2=tecla;}
                    if(senha1==0) {senha1=tecla;}
                break;

                case 118:
                    goto inicio;
                break;
                }

                if(i==0) {
                    cout<<"\nVoce pode digitar apenas de 1 a 6!!!";
                    Beep(500, 100);
                }

                coord.X = 0;
                coord.Y = y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

                if(i2==1) {
                    cout<<" Senha: "<<senha1<<"-";
                } else if(i2==2) {
                    cout<<" Senha: "<<senha1<<"-"<<senha2<<"-";
                } else if(i2==3) {
                    cout<<" Senha: "<<senha1<<"-"<<senha2<<"-";
                } else if(i2==4 && dificuldade=="Normal" || i2==5 && dificuldade=="Dificil") {
                    cout<<" Senha: "<<senha1<<"-"<<senha2<<"-"<<senha3<<"-";
                } else if(i2==5 && dificuldade=="Dificil") {
                    cout<<" Senha: "<<senha1<<"-"<<senha2<<"-"<<senha3<<"-"<<senha4<<"-"<<senha5;
                }
            }

            //Quando todas as respostas estão corretas
            if (senha1==digito1 && senha2==digito2 && senha3==digito3 && senha4==digito4 && senha5==digito5) {
                cout<<"\n\n\nPARABENS VOCE ACERTOU A SENHA!!! \nAGORA VOCE PODE ENTRAR NO INCRIVEL MUNDO DE FELSKI!!!\n\n";
                system ("pause");
                goto inicio;
            }

            //calculo numeros ceertos nas posiçao certa
            if (senha1==digito1) {
                posicao_certa++;
            } else if (senha1==digito2 || senha1==digito3 || senha1==digito4 || senha1==digito5) {
                posicao_errada++;
            }
            if (senha2==digito2) {
                posicao_certa++;
            } else if (senha2==digito1 || senha2==digito3 || senha2==digito4 || senha2==digito5) {
                posicao_errada++;
            }
            if (senha3==digito3) {
                posicao_certa++;
            } else if (senha3==digito1 || senha3==digito2 || senha3==digito4 || senha3==digito5) {
                posicao_errada++;
            }

            if(dificuldade=="Normal" || dificuldade=="Dificil"){
                if (senha4==digito4) {
                    posicao_certa++;
                } else if (senha4==digito1 || senha4==digito2 || senha4==digito3 || senha4==digito5) {
                    posicao_errada++;
                }
            }
            if(dificuldade=="Dificil"){
                if (senha5==digito5) {
                    posicao_certa++;
                } else if (senha5==digito1 || senha5==digito2 || senha5==digito3 || senha5==digito4) {
                    posicao_errada++;
                }
            }

            cout<<"\n";
            cout<<posicao_certa<<" numeros estão certo e na posicao certa";
            cout<<"\n";
            cout<<posicao_errada<<" numeros estão certo e na posicao errada";
            cout<<"\nTentativas restantes: "<<tentativas;
        }

        cout<<"\n\n\nVOCE PERDEU!!! :( \n\n";

        if(dificuldade=="Dificil") {
            cout<<"A senha era: "<<digito1<<"-"<<digito2<<"-"<<digito3<<"-"<<digito4<<"-"<<digito5<<"\n\n";
        } else if(dificuldade=="Normal") {
            cout<<"A senha era: "<<digito1<<"-"<<digito2<<"-"<<digito3<<"-"<<digito4<<"\n\n";
        } else if(dificuldade=="Facil") {
            cout<<"A senha era: "<<digito1<<"-"<<digito2<<"-"<<digito3<<"\n\n";
        }

        system ("pause");
    }

    //Encerrar o jogo
    if (menu=='f') {
        return 0;
    }

    goto inicio;
    return 0;
}
