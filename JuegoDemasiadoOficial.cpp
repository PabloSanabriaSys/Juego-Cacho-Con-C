#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#include "libreriasjuego.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	PlaySound(TEXT("intro.wav"), NULL, SND_ASYNC);
	srand(time(NULL));
	int opc,tiro[5],copia[5],jugada,reciclada,i,posc,jugador=1,demano,total1,total2;
	int volteo1, volteo2;
	int puntaje_1[12]={NULL},puntaje_2[12]={NULL};
	bool panzaa;
	char j1[20 ],j2[20];
	string sino;
	setlocale(LC_ALL, "spanish");
	pintar_titulo();
	system("color 09");
	system("pause");
	do{
		menuopc();
		cout<<"Elija una opción: ";
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
				setCColor(color[1]);
				cout<<"\tSELECCIONO UN NUEVO JUEGO DE DOS JUGADORES :D\n";
				cout<<"\tINGRESE EL NOMBRE DEL JUGADOR 1: "; fflush(stdin);gets(j1);fflush(stdin);
				cout<<"\tINGRESE EL NOMBRE DEL JUGADOR 2: "; fflush(stdin);gets(j2);fflush(stdin);
				for (int j=1;j<=22;j++)
				{ 	volteo1=-1, volteo2=-1;	
					panzaa=false;
					cout<<"\n\t JUGADOR "<<jugador<<endl;
					if (jugador==1) cout<<"\t"<<j1<<endl;
					else cout<<"\t"<<j2<<endl;
					PlaySound(TEXT("cubilete.wav"), NULL, SND_ASYNC);
					cout<<" \tLance el cubilete: \n";
					system("pause");
					lanzardados(tiro);
					copiatiro(tiro,copia);
					impresion(tiro);
					demano=comprobar(copia,jugada);
					if (jugador==1) panzaa=panza(puntaje_1,jugada-1);
					else panzaa=panza(puntaje_2,jugada-1);
					if (demano==0 || panzaa==true)
					{
						if (jugador==1) {
							mostrarpuntaje(puntaje_1);
						}
						else mostrarpuntaje(puntaje_2);
						opcionestiro(); cin>>jugada;
						cout<<"Seleccione la cantidad de dados que desea volver a lanzar: "; cin>>reciclada;
						for (i=1;i<=reciclada;i++)
						{	cout<<"Seleccione la posicion del dado (1 - 5): "; cin>>posc;
							tiro[posc-1]=random();
						}
						PlaySound(TEXT("cubilete.wav"), NULL, SND_ASYNC);
						impresion(tiro);
						if(reciclada>0)
						{
							cout<<endl<<"Seleccione la posición del dado que desea voltear (1 - 5): "; cin>>volteo1;
							cout<<"¿Desea voltear un segundo dado? (Indique si o no): "; cin>>sino;
							if(sino=="si") {
							cout<<"Seleccione la posición del dado que desea voltear (1 - 5): "; 
							cin>>volteo2;}
							volteardados(tiro, volteo1, volteo2);
						}
						impresion(tiro);
						if (jugador==1) 
						{
							puntaje_1[jugada-1]=puntajadejugada(jugada, tiro);
							mostrarpuntaje(puntaje_1);
						
						}
						else
						{
							puntaje_2[jugada-1]=puntajadejugada(jugada, tiro);
							mostrarpuntaje(puntaje_2);
					
						}
					}
				else 
				{
					if (jugador==1) 
					{	puntaje_1[jugada-1]=demano;
						if (demano>1000) break;
						mostrarpuntaje(puntaje_1);
					}
					else
					{	puntaje_2[jugada-1]=demano;
						mostrarpuntaje(puntaje_2);
					}	
					
				}
				j=23;
				reiniciarjugador(jugador);
				system("pause");
				system("cls");
				
				}
				total1=sumarpuntos(puntaje_1);
				total2=sumarpuntos(puntaje_2);
				PlaySound(TEXT("win.wav"), NULL, SND_ASYNC);
				if (total1>total2) cout<<"EL GANADOR ES EL JUGADOR 1"<<endl;
				else cout<<"EL GANADOR ES EL JUGADOR 2"<<endl;
				
				if (total1>1000 || total2>1000) {PlaySound(TEXT("winner.wav"), NULL, SND_ASYNC);
				 cout<<"Usted gano con la dormida USTED TIENE MUCHA SUERTE :)"<<endl;
				}
				else cout<<"El jugador 1 tiene "<<total1<<" puntos\n"<<"El jugador 2 tiene "<<total2<<" puntos";
				system("pause");
				break;
			case 2:
				PlaySound(TEXT("reglas.wav"), NULL, SND_ASYNC);
				gotoxy(10,10); reglas();
			break;
			case 3:
				PlaySound(TEXT("creditos.wav"), NULL, SND_ASYNC);
				creditos();
				system("pause");
				system("cls");
				break;
			case 4:
				PlaySound(TEXT("ysemarchoaudio.wav"), NULL, SND_ASYNC);
				cout<<"Usted esta saliendo del juego :)\n";
				system("pause");
				break;
			default: 
				cout<<"INGRESE LA OPCION CORRECTA :D"<<endl;
				break;
		}
		
	}while(opc!=4);
	return 0;
}
