#include <iostream>
using namespace std;
int backcolor=0;
void gotoxy(int x, int y)
{
	HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X= x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void setCColor( int color)
{
        static HANDLE hConsole;

        hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

        SetConsoleTextAttribute( hConsole, color | (backcolor * 0x10 + 0x100) );
}
int color[7] = {
      0x009, //azul 0
      0x00E, //amarillo 1
       //amarillo2
      0x00C, //rojo 2
      0x002, // verde oscuro
      0x00B, //turquesa
      0x005, //morado
      0x00F //blanco
     };
char tituloPrincipal[300][300]={

	"\t ____________    ____________    ____________    ___        ___    ______________ ",
	"\t|            |  |            |  |            |  |   |      |   |  |              |",
	"\t|    ________|  |    ____    |  |    ________|  |   |      |   |  |    ______    |",
	"\t|   |           |   |    |   |  |   |           |   |______|   |  |   |      |   |",
	"\t|   |           |   |____|   |  |   |           |              |  |   |      |   |",
	"\t|   |           |            |  |   |           |    ______    |  |   |      |   |",
	"\t|   |________   |    ____    |  |   |________   |   |      |   |  |   |______|   |",
	"\t|            |  |   |    |   |  |            |  |   |      |   |  |              |",
	"\t|____________|  |___|    |___|  |____________|  |___|      |___|  |______________|",
};
void pintar_titulo()
{
	for(int i=0;i<150; i++){
		for(int j=0; j<30; j++){
			gotoxy(i,j);
			if(tituloPrincipal[j][i] == '|') {setCColor(color[1]);printf("%c",190);}
            if(tituloPrincipal[j][i] == '_') {setCColor(color[1]); printf("%c",190);}
		}
	}
}
void menuopc()
{	cout<<" _______________________ \n";
	cout<<"|      MENÚ DE JUEGO    |\n";
	cout<<"|_______________________| \n";
	cout<<"| 1.- Nuevo juego       |\n";
	cout<<"| 2.- Reglas del juego  |\n";
	cout<<"| 3.- Creditos          |\n";
	cout<<"| 4.- SALIR             |\n";
	cout<<"|_______________________| \n";
}

void reglas()
{
	cout<<endl;
	cout<<"°°°°°°°°°°°°°°°°°°°°°°°°°°°° REGLAS °°°°°°°°°°°°°°°°°°°°°°°°°°°°\n";
	cout<<endl<<"INTRODUCCIÓN:"<<endl;
	cout<<"El cacho es un juego muy interesante, porque se pone en práctica"<<endl;
	cout<<"la astucia y la destreza al momento de buscar grupos de números,"<<endl;
	cout<<"este juego necesita de 6 dados, que se lanzan aleatoriamente, en"<<endl;
	cout<<"este caso, los datos estarán representados por 6 números  que"<<endl;
	cout<<"serán generados aleatoriamente por el programa, en este juego to-"<<endl;
	cout<<"mamos y sabemos que los dados solo tienen números del 1 al 6, en"<<endl;
	cout<<"el cacho estos números cambian de 'nombre' y tienen un diferente"<<endl;
	cout<<"puntaja por cada unidad,estos nombres y sus puntajes respectivos"<<endl;
	cout<<"son:\n";
	cout<<endl;
	cout<<"     1 ->  balas  ->  1 punto (cada uno)"<<endl;
	cout<<"     2 ->  tontos  ->  2 puntos (cada uno)"<<endl;
	cout<<"     3 ->  trenes  ->  3 puntos (cada uno)"<<endl;
	cout<<"     4 ->  cuadras  ->  4 puntos (cada uno)"<<endl;
	cout<<"     5 ->  quinas  ->  5 puntos (cada uno)"<<endl;
	cout<<"     6 ->  senas  ->  6 puntos (cada uno)"<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	cout<<endl;
	cout<<"JUGADORES:"<<endl;
	cout<<"El juego va de 2 a 5 jugadores, opción que muestra el menú al mo-"<<endl;
	cout<<"mento de iniciar el juego, selecciona 'juego nuevo', e ingresa el"<<endl;
	cout<<"número de jugadores."<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	cout<<endl;
	cout<<"PUNTAJES:"<<endl;
	cout<<"El puntaje se califica de la siguiente forma:"<<endl;
	cout<<endl;
	cout<<"          |          |          "<<endl;   
	cout<<"          |          |          "<<endl;
	cout<<"    1     | Escalera |     4    "<<endl;
	cout<<"  balas   |          |  cuadras "<<endl;
	cout<<"__________|__________|__________"<<endl;  
	cout<<"          |          |          "<<endl;   
	cout<<"          |          |          "<<endl;
	cout<<"    2     |   Full   |     5    "<<endl;
	cout<<"  tontos  |          |  quinas  "<<endl;
	cout<<"__________|__________|__________"<<endl;
	cout<<"          |          |          "<<endl;   
	cout<<"          |          |          "<<endl;
	cout<<"    3     |   Poker  |     6    "<<endl;
	cout<<"  trenes  |          |   senas  "<<endl;
	cout<<"          |          |          "<<endl;
	cout<<"Grande: (Todos iguales al segundo tiro vale 50 puntos)."<<endl;
	cout<<"Dormida: (Todos iguales al primer tiro, gana automaticamente)."<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	cout<<endl;
	cout<<"EN EL ESPACIO DE LAS BALAS:"<<endl;
	cout<<"Se anota la cantidad de unos multiplicado por 1, siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 5)."<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DE LOS TONTOS:"<<endl;
	cout<<"Se anota la cantidad de dos multiplicado por 2 , siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 10)."<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DE LOS TRENES:"<<endl;
	cout<<"Se anota la cantidad de tres multiplicado por 3, siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 15)."<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DE LAS CUADRAS:"<<endl;
	cout<<"Se anota la cantidad de cuatros multiplicado por 4, siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 20)."<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DE LAS QUINAS:"<<endl;
	cout<<"Se anota la cantidad de cincos multiplicado por 5, siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 25)."<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DE LAS SENAS:"<<endl;
	cout<<"Se anota la cantidad de seis multiplicado por 6, siendo este el"<<endl;
	cout<<"puntaje obtenido, (puntaje máximo 30)."<<endl;
	cout<<endl;
	cout<<"Cabe aclarar que en estos espacios de los costados, se toman en"<<endl;
	cout<<"cuenta dados del 1 al 5."<<endl<<endl;
	cout<<"EN EL ESPACIO DE LA ESCALERA:"<<endl;
	cout<<"Cuando los dados van en forma de escalera, es decir:"<<endl;
	cout<<"1,2,3,4,5  o  2,3,4,5,6  o  3,4,5,6,1"<<endl;
	cout<<"Se anota el puntaje obtenido directamente que es de 20 puntos"<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DEL FULL:"<<endl;
	cout<<"Cuando 2 dados se repiten y los otros 3 tambien son los mismos, es decir:"<<endl;
	cout<<"1,1,2,2,2  o 2,2,3,3,3  o  2,2,4,4,4  etc."<<endl;
	cout<<"Se anota el puntaje obtenido directamente que es de 30 puntos"<<endl;
	cout<<endl;
	cout<<"EN EL ESPACIO DEL POKER:"<<endl;
	cout<<"Cuando un dado se repite 4 veces:"<<endl;
	cout<<"1,2,2,2,2  o 2,3,3,3,3  o  2,4,4,4,4  etc."<<endl;
	cout<<"Se anota el puntaje obtenido directamente que es de 40 puntos"<<endl;
	cout<<endl;
	cout<<"APARTE SE ANOTA EL PUNTAJE DE LA GRANDE, O EN TODO CASO DE LA DORMIDA"<<endl;
	cout<<"Que tendrá un espacio reservado por cada jugador."<<endl;
	cout<<"(JUGADAS CON PUNTAJE MENSIONADAS ANTERIORMENTE)."<<endl;
	cout<<endl;
	system("pause");
	system("cls");
	cout<<endl;
	cout<<"LA PARTIDA:"<<endl;
	cout<<"Cada jugador contará con 2 intentos, contará con un pimer  tiro, del cual tendrá"<<endl;
	cout<<"que escoger primero la base de la jugada, es decir a por qué tipo de jugada irá,"<<endl;
	cout<<"(Tontos, Trenes, Poker, Full, etc)y seguidammente, un segundo tiro opcional, si "<<endl;
	cout<<"quiere volver a tirar los dados que seleccione, es decir volver a lanzar solo los"<<endl;
	cout<<"dados que el jugador escoja (podrían ser todos si así lo quiere), despues el juga-"<<endl;
	cout<<"dor deberá voltear el dado que quiera para concretar su jugada, (esto de voltear"<<endl;
	cout<<"un dado la primera vez es obligatorio), y luego un seundo volteo opcional; el pun-"<<endl;
	cout<<"tage que se va acumulando se irá anotando en el espacio y con el valor que corres-"<<endl;
	cout<<"ponda; el juego termina cuando se dan las siguientes condiciones:"<<endl<<endl;
	cout<<"1. Ya nadie tenga que anotar"<<endl;
	cout<<"2. Algún jugador haya sacado la jugada 'dormida'"<<endl;
	cout<<"3. Si algún jugador tiene llena la 'panza de oro', es decir sacó Poker, Full y Escalera"<<endl;
	cout<<"   de mano."<<endl;
	cout<<"4. Si un jugador tiene la grande, llenos todos los espacios numéricos al máximo, y mínimo"<<endl;
	cout<<"   un Poker."<<endl;
	
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	system("pause");
	system("cls");
}
void creditos(){
	cout<<"*EQUIPO DE PROGRAMACIÓN TUTUMITAS*\n";
	cout<<"\tJefe de grupo: Pablo Sanabria Becerra\n";
	cout<<"\tAnalista de Sistemas: Ingridh Mahovani Coaquira Molina\n";
	cout<<"\tProgramadores: \n";
	cout<<"\t-Oscar Andres Gutierrez Andrade\n";
	cout<<"\t-Mateo Espinoza Rodríguez \n";
	cout<<"\t-Pablo Sanabria Becerra\n";
	cout<<"\tDesigner: Yara Osnayo Vilca\n";
	cout<<"\tAGRADECIMIENTOS ESPECIALES <3: \n";
	cout<<"\t\tLic. Ana Marlene Ticona Flores\n";
	cout<<"\t\tEst. Fabricio Lojhan Balderrama\n";
}
void reiniciarjugador(int &jugador)
{
	jugador++;
	if (jugador>2) jugador=1;
}

int random()
{	int x;
	x=1+rand()%(6+1-1);
	return x;
}


void lanzardados(int v[])
{
	for (int i=0; i<5;i++)
	{
		v[i]=random();
	}

}
void copiatiro(int v[],int c[])
{
	for (int i=0;i<5;i++){
		c[i]=v[i];
	}
}

void volteardados(int v[], int volt1, int volt2)
{
	v[volt1-1]=7-v[volt1-1];
	if(volt2>0)
	{
		v[volt2-1]=7-v[volt2-1];
	}
}

void impresion(int v[])
{
	setCColor(color[2]);
	cout<<"\nEL VALOR DE LOS DADOS DE SU LANZAMIENTO ES:"<<endl;
	for (int i=0; i<5;i++)
	{
		setCColor(color[6]);
		cout<<"El valor del dado "<<i+1<<" es: "<<v[i]<<endl;
	}
}
void mostrarpuntaje(int a[])
{
	setCColor(color[1]);
	cout<<"          |          |          "<<endl;   
	cout<<"          |   "<<a[6]<<"      |          "<<endl;
	cout<<"    "<<a[0]<<"     | Escalera |     "<<a[3]<<"    "<<endl;
	cout<<"  balas   |          |    cuadras     "<<endl;
	cout<<"__________|__________|__________"<<endl;  
	cout<<"          |          |          "<<endl;   
	cout<<"          |     "<<a[7]<<"    |          "<<endl;
	cout<<"    "<<a[1]<<"     |   Full   |     "<<a[4]<<"    "<<endl;
	cout<<"  tontos  |          |  quinas  "<<endl;
	cout<<"__________|__________|__________"<<endl;
	cout<<"          |          |          "<<endl;   
	cout<<"          |     "<<a[8]<<"    |          "<<endl;
	cout<<"     "<<a[2]<<"    |   Poker  |     "<<a[5]<<"    "<<endl;
	cout<<"  trenes  |          |   senas  "<<endl;
	cout<<"          |          |          "<<endl;
	cout<<"__________|__________|__________"<<endl;
	cout<<"          |          |          "<<endl;
	cout<<"          |   "<<a[9]<<"      |   "<<a[10]<<"           "<<endl;
	cout<<"          |          |          "<<endl;	
}
void opcionestiro()
{	
	setCColor(color[2]);
	cout<<"\nSELECCIONE  SU JUGADA :D\n";
	setCColor(color[6]);
	cout<<"1)BALAS    \t2)TONTOS \t3)TRENES \n";
	cout<<"4)CUADRAS  \t5)QUINAS \t6)SENAS \n";
	cout<<"7)ESCALERA \t8)FULL   \t9)POKER \n          \t10/11)LA GRANDE"<<endl;
}
void ordenado (int v[])
{
	int aux;
	for(int e=0;e<5;e++)
	{
		for(int i=e+1;i<e;i++)
		{
			if(v[e]>v[i])
			{
				aux=v[e];
				v[e]=v[i];
				v[i]=aux;
			}
		}
	}
}
int comprobar(int vec[],int &p){
	int i=0,j;
	int aux;
	
	for(i=1;i<=4;i++){
		for(j=0;j<=3;j++){
			if(vec[j]>vec[j+1]){
				aux=vec[j];
				vec[j]=vec[j+1];
				vec[j+1]=aux;
			}
		}
	}
	i=0;
	//DORMIDA
	if(vec[i]==vec[i+1] && vec[i]==vec[i+2] && vec[i]==vec[i+3] && vec[i]==vec[i+4]){ p=11;
	return 20000;}     
	
	//ESCALERA
	if(vec[i]==1 && vec[i+1]==2 && vec[i+2]==3 && vec[i+3]==4 && vec[i+4]==5 ){p=7;
	return 25;}
    if(vec[i]==2 && vec[i+1]==3 && vec[i+2]==4 && vec[i+3]==5 && vec[i+4]==6 ){p=7;
	return 25;}
   	if(vec[i]==1 && vec[i+1]==3 && vec[i+2]==4 && vec[i+3]==5 && vec[i+4]==6 ){p=7;
	return 25;}   
	   
	//FULL
	if(vec[i]==vec[i+1] && vec[i]==vec[i+2] && vec[i+3]==vec[i+4]){p=8;
	return 35;} 
	if(vec[i]==vec[i+1] && vec[i+2]==vec[i+3] && vec[i+2]==vec[i+4]){p=8;
	return 35;}  
	
   //POKER
   for(i=0;i<2;i++){ 
		if(vec[i]==vec[i+1] && vec[i]==vec[i+2] && vec[i]==vec[i+3] ){p=9;
			return 45;}     
   }
   return 0;
}


int puntajadejugada(int jug, int vr[])
{
	int con=0, aux,v[5],i,j;
	copiatiro(vr,v);
	for(i=1;i<=4;i++){
	for(j=0;j<=3;j++){
			if(v[j]>v[j+1]){
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
	//ALLEGRO PARA PONER MUSIQUITA
	switch(jug)
	{
	case 1: 
		for(i=0;i<5;i++)
		{
			if(v[i]==1) con++;
		}
		return con;
	break;
	case 2:
		for(i=0;i<5;i++)
		{
			if(v[i]==2) con++;
		}
		return con*2;
	break;
	case 3: 
		for(i=0;i<5;i++)
		{
			if(v[i]==3) con++;
		}
		return con*3;
	break;
	case 4: 
		for(i=0;i<5;i++)
		{
			if(v[i]==4) con++;
		}
		return con*4;
	break;
	case 5:
		for(i=0;i<5;i++)
		{
			if(v[i]==5) con++;
		}
		return con*5;
	break;
	case 6: 
		for(i=0;i<5;i++)
		{
			if(v[i]==6) con++;
		}
		return con*6;
	break;
	case 7:
		i=0;
		if(v[i]==1 && v[i+1]==2 && v[i+2]==3 && v[i+3]==4 && v[i+4]==5 ) return 20;
    	if(v[i]==2 && v[i+1]==3 && v[i+2]==4 && v[i+3]==5 && v[i+4]==6 ) return 20;
   		if(v[i]==1 && v[i+1]==3 && v[i+2]==4 && v[i+3]==5 && v[i+4]==6 ) return 20; 
	break;
	case 8: 
		i=0;
	    if(v[i]==v[i+1] && v[i]==v[i+2] && v[i+3]==v[i+4])	return 30;
		if(v[i]==v[i+1] && v[i+2]==v[i+3] && v[i+2]==v[i+4]) return 30;  
	break;
	case 9:
		for(i=0;i<2;i++){ 
		if(v[i]==v[i+1] && v[i]==v[i+2] && v[i]==v[i+3] ) return 40;     
   		}
	break;
	case 10: 
		i=0;
		if(v[i]==v[i+1] && v[i]==v[i+2] && v[i]==v[i+3] && v[i]==v[i+4]) return 45;
	break;
	case 11: 
		i=0;
		if(v[i]==v[i+1] && v[i]==v[i+2] && v[i]==v[i+3] && v[i]==v[i+4]) return 45;
	break;
	}
	return 0;
}
int sumarpuntos(int v[])
{	int acu=0;
	for (int i=0;i<=11;i++){
		acu=acu+v[i];
	}
	return acu;
}
bool panza(int v[],int pos)
{
	if (v[pos]!=0) return true;
	else return false;
}
