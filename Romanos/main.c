#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

//Declaración de Funciones:
void titulo();
char *Unidad(int u);
char *Decena(int d);
char *Centena(int c);
char *Mil(int m);
//-------------------------

void main(){
/*Programa que convierte números naturales a números romanos desde el 1 hasta 4.294.967.295(Cuatro mil doscientos noventa y cuatro millones novecientos sesenta y siete mil doscientos noventa y cinco).
  Por que es el valor máximo para un entero sin signo de 32 bits en informática. Por lo tanto, es el valor máximo para una variable declarada como un entero sin signo.*/
system("mode con cols=100 lines=25");
system("title Números Natutrales a Números Romanos");
unsigned long int estado, copia, contador=0, x=65, unidades, decenas, centenas, mil, decenasmil, centenasmil, millon, diezmillones, cienmillones, milmillones;
double numero;
char opcion='1';
textcolor(WHITE);//Color del texto.
while((opcion=='1') || (opcion=='2'))//Este ciclo mantiene al usuario en el menú mientras no digite el 2.
	   {
      fflush(stdin);
      clrscr();
      titulo();
      gotoxy(48,10); cprintf("Men"); cprintf("%c",163);
      gotoxy(39,13); cprintf("1. Convertir un N"); cprintf("%c",163); cprintf("mero");
		gotoxy(39,15); cprintf("2. Cerrar");
		gotoxy(39,17); cprintf("Digite Opci"); cprintf("%c",162); cprintf("n: ");
		opcion=getche();
      if((opcion!='1') && (opcion!='2'))//Condicional que valida la opción que digita el usuario.
        {
        gotoxy(39,20); cprintf("%c",173); cprintf("Opci"); cprintf("%c",162); cprintf("n Incorrecta!");
        opcion='1';
        gotoxy(29,23); cprintf("Presione cualquier tecla para continuar...");
        getche();
        }
        else if(opcion=='1')//Condicional para la opción 1 del menú
        			{
               estado=1;
               while(estado==1)
               	  {
                    /*En este ciclo se muestra el error las veces que sea necesario, pero una vez el usuario digite un número válido se muestra dicho
                      número convertido en número romano, un mensaje que le indica: "Presione cualquier tecla para continuar..." y este ciclo se "rompe",
                      lo que lleva al usuario al menú principal.*/
                    clrscr();
   	              titulo();
		              gotoxy(27,12); cprintf("Digite un N"); cprintf("%c",163); cprintf("mero: ");
	                 cin>>numero;
                    copia=numero;
                    if((numero<1) || (numero-copia>0))//Condicional para validar los números menores que 1 y los números decimales
                    	 {
                      clrscr();
          	          titulo();
                      gotoxy(27,11); cprintf("%g",numero); cprintf(" no se puede convertir a n"); cprintf("%c",163); cprintf("mero romano");
                      gotoxy(27,16); cprintf("Presione cualquier tecla para continuar...");
                      estado=0;
                      getche();
                      }
                    else
                      {
                      milmillones=copia/1000000000;
                      cienmillones=copia/100000000;
                      diezmillones=copia/10000000;
                      millon=copia/1000000;
                      centenasmil=copia/100000;
                      decenasmil=copia/10000;
                      mil=copia/1000;
                      centenas=(copia%1000)/100;
                      decenas=(copia%100)/10;
                      unidades=copia%10;
                      /*Para imprimir por pantalla los números mayores a 3.999(Tres mil novecientos noventa y nueve), se debe separar por "bloques"
                        dicha impresión ya que estos números se representan con una o mas líneas en la parte superior. Para efectos de este
                        programa solo se utilizan 3 lineas.*/
                      if((copia>999999999) && (copia<4000000000))//Condicional para los números entre 1.000.000.000(Mil millones) y 10.000.000.000(Diez mil millones).
                        {
                        clrscr();
		                  titulo();
	     		            gotoxy(18,13); cprintf("%u",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Mil(milmillones%10)); cprintf("%s",Centena(cienmillones%10)); cprintf("%s",Decena(diezmillones%10)); cprintf("%s",Unidad(millon%10)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                        x-=3;
                        while(contador<strlen(Mil(milmillones)))
         		              {
                             gotoxy(x,11); cprintf("%c",196);
		                       gotoxy(x,12); cprintf("%c",196);
		                       x++;
		                       contador++;
		                       }
                             contador=0;
                             while(contador<strlen(Centena(cienmillones%10)))
         		                   {
                                  gotoxy(x,11); cprintf("%c",196);
		                            gotoxy(x,12); cprintf("%c",196);
		                            x++;
		                            contador++;
		                            }
                                  contador=0;
                                  while(contador<strlen(Decena(diezmillones%10)))
         		                        {
                                       gotoxy(x,11); cprintf("%c",196);
		                                 gotoxy(x,12); cprintf("%c",196);
		                                 x++;
		                                 contador++;
		                                 }
                                       contador=0;
                                       while(contador<strlen(Unidad(millon%10)))
         		                             {
                                            gotoxy(x,11); cprintf("%c",196);
		                                      gotoxy(x,12); cprintf("%c",196);
                                            x++;
		                                      contador++;
		                                      }
                                            contador=0;
                                            while(contador<strlen(Centena(centenasmil%10)))
         		              	                   {
		                       	                   gotoxy(x,12); cprintf("%c",196);
                                                 x++;
		                                           contador++;
		                                           }
                                                 contador=0;
		                                           while(contador<strlen(Decena(decenasmil%10)))
         		              	       	               {
		                       	                        gotoxy(x,12); cprintf("%c",196);
                                                      x++;
		                                                contador++;
		                                                }
                                                      contador=0;
		                                                while(contador<strlen(Unidad(mil%10)))
         		              	       	                    {
		                       	                             gotoxy(x,12); cprintf("%c",196);
                                                           x++;
		                                                     contador++;
		                                                     }
                                                           gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                               estado=0;
            		                                         x=65;
                  		                                   contador=0;
                                                           getche();
                        }
                        else if((copia>3999999999) && (copia<4294967296))
                               {
                               clrscr();
		                         titulo();
	     		                   gotoxy(18,13); cprintf("%u",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Unidad(milmillones%10)); cprintf("%s",Centena(cienmillones%10)); cprintf("%s",Decena(diezmillones%10)); cprintf("%s",Unidad(millon%10)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                               x-=3;
                               while(contador<strlen(Unidad(milmillones)))
         		                     {
                                    gotoxy(x,10); cprintf("%c",196);
                                    gotoxy(x,11); cprintf("%c",196);
		                              gotoxy(x,12); cprintf("%c",196);
		                              x++;
		                              contador++;
		                              }
                                    contador=0;
                                    while(contador<strlen(Centena(cienmillones%10)))
         		                          {
                                         gotoxy(x,11); cprintf("%c",196);
		                                   gotoxy(x,12); cprintf("%c",196);
		                                   x++;
		                                   contador++;
		                                   }
                                         contador=0;
                                         while(contador<strlen(Decena(diezmillones%10)))
         		                               {
                                              gotoxy(x,11); cprintf("%c",196);
		                                        gotoxy(x,12); cprintf("%c",196);
                                              x++;
		                                        contador++;
		                                        }
                                              contador=0;
                                              while(contador<strlen(Unidad(millon%10)))
         		                                    {
                                                   gotoxy(x,11); cprintf("%c",196);
		                                             gotoxy(x,12); cprintf("%c",196);
		                                             x++;
		                                             contador++;
                                                   }
                                                   contador=0;
                                                   while(contador<strlen(Centena(centenasmil%10)))
         		              	                          {
		                       	                          gotoxy(x,12); cprintf("%c",196);
                                                        x++;
		                                                  contador++;
		                                                  }
                                                        contador=0;
		                                                  while(contador<strlen(Decena(decenasmil%10)))
         		              	       	                      {
		                       	                               gotoxy(x,12); cprintf("%c",196);
                                                             x++;
		                                                       contador++;
		                                                       }
                                                             contador=0;
		                                                       while(contador<strlen(Unidad(mil%10)))
         		              	       	                           {
		                       	                                    gotoxy(x,12); cprintf("%c",196);
                                                                  x++;
		                                                            contador++;
		                                                            }
                                                                  gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                      estado=0;
            		                                                x=65;
                  		                                          contador=0;
                        	                                       getche();
                               }
                               else if((copia>99999999) && (copia<1000000000))//Condicional para los números entre 100.000.000(Cien millones) y 999.999.999(Novecientos noventa y nueve millones novecientos noventa y nueve mil novecientos noventa y nueve).
                                      {
                                      clrscr();
		                                titulo();
	     		                          gotoxy(20,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Centena(cienmillones)); cprintf("%s",Decena(diezmillones%10)); cprintf("%s",Unidad(millon%10)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                      x=63;
                                      while(contador<strlen(Centena(cienmillones)))
         		                            {
                                           gotoxy(x,11); cprintf("%c",95);
		                                     gotoxy(x,12); cprintf("%c",196);
		                                     x++;
		                                     contador++;
		                                     }
                                           contador=0;
                                           while(contador<strlen(Decena(diezmillones%10)))
                                                {
                                                gotoxy(x,11); cprintf("%c",95);
		                                          gotoxy(x,12); cprintf("%c",196);
		                                          x++;
		                                          contador++;
		                                          }
                                                contador=0;
                                                while(contador<strlen(Unidad(millon%10)))
         		                                      {
                                                     gotoxy(x,11); cprintf("%c",95);
		                                               gotoxy(x,12); cprintf("%c",196);
		                                               x++;
		                                               contador++;
		                                               }
                                                     contador=0;
                                                     while(contador<strlen(Centena(centenasmil%10)))
         		              	                            {
		                       	                            gotoxy(x,12); cprintf("%c",196);
                                                          x++;
		                                                    contador++;
		                                                    }
                                                          contador=0;
		                                                    while(contador<strlen(Decena(decenasmil%10)))
         		              	       	                        {
		                       	                                 gotoxy(x,12); cprintf("%c",196);
                                                               x++;
		                                                         contador++;
		                                                         }
                                                               contador=0;
		                                                         while(contador<strlen(Unidad(mil%10)))
         		              	       	                             {
		                       	                                      gotoxy(x,12); cprintf("%c",196);
                                                                    x++;
		                                                              contador++;
		                                                              }
                                                                    gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                        estado=0;
            		                                                  x=65;
                  		                                            contador=0;
                        	                                         getche();
                                      }
                                      else if((copia>9999999) && (copia<100000000))//Condicional para los números entre 10.000.000(Diez millones) y 99.999.999(Noventa y nueve millones novecientos noventa y nueve mil novecientos noventa y nueve).
                                             {
                                             clrscr();
		                                       titulo();
	     		                                 gotoxy(20,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Decena(diezmillones)); cprintf("%s",Unidad(millon%10)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                             x=62;
                                             while(contador<strlen(Decena(diezmillones)))
         		                                   {
                                                  gotoxy(x,11); cprintf("%c",95);
		                                            gotoxy(x,12); cprintf("%c",196);
		                                            x++;
		                                            contador++;
		                                            }
                                                  contador=0;
                                                  while(contador<strlen(Unidad(millon%10)))
         		                                        {
                                                       gotoxy(x,11); cprintf("%c",95);
		                                                 gotoxy(x,12); cprintf("%c",196);
		                                                 x++;
		                                                 contador++;
		                                                 }
                                                       contador=0;
                                                       while(contador<strlen(Centena(centenasmil%10)))
         		              	                              {
		                       	                              gotoxy(x,12); cprintf("%c",196);
                                                            x++;
		                                                      contador++;
		                                                      }
                                                            contador=0;
		                                                      while(contador<strlen(Decena(decenasmil%10)))
         		              	       	                          {
		                       	                                   gotoxy(x,12); cprintf("%c",196);
                                                                 x++;
		                                                           contador++;
		                                                           }
                                                                 contador=0;
		                                                           while(contador<strlen(Unidad(mil%10)))
         		              	       	                               {
		                       	                                        gotoxy(x,12); cprintf("%c",196);
                                                                      x++;
		                                                                contador++;
		                                                                }
                                                                      gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                          estado=0;
            		                                                    x=65;
                  		                                              contador=0;
                        	                                           getche();
                                             }
                      								else if((copia>999999) && (copia<10000000))//Condicional para los números entre 1.000.000(Un millón) y 9.999.999(Nueve millones novecientos noventa y nueve mil novecientos noventa y nueve).
                        									 {
                        									 if(copia<4000000)
                          										{
                          										clrscr();
		                    										titulo();
	     		              										gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Mil(millon)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                          										x+=3;
                          										while(contador<strlen(Mil(millon)))
         		                									  {
		                         									  gotoxy(x,12); cprintf("%c",196);
		                         									  x++;
		                         									  contador++;
		                         									  }
                                                           contador=0;
                                                           while(contador<strlen(Centena(centenasmil%10)))
         		                                                 {
		                                                          gotoxy(x,12); cprintf("%c",196);
		                                                          x++;
		                                                          contador++;
		                                                          }
                                                                contador=0;
                                                                while(contador<strlen(Decena(decenasmil%10)))
         		              	                                       {
		                       	                                       gotoxy(x,12); cprintf("%c",196);
                                                                     x++;
		                                                               contador++;
		                                                               }
                                                                     contador=0;
		                                                               while(contador<strlen(Unidad(mil%10)))
         		              	       	                                   {
		                       	                                            gotoxy(x,12); cprintf("%c",196);
                                                                          x++;
		                                                                    contador++;
		                                                                    }
                                                                          gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                              estado=0;
            		                                                        x=65;
                  		                                                  contador=0;
                        	                                               getche();
                                                    }
                                                    /*Esta parte del condicional se cumple cuando el número es mayor a 3.999.999(Tres millones novecientos noventa y nueve mil novecientos noventa y nueve),
									                           ya que en este punto el número se representa con su respectivo caracter pero con 2 lineas encima.*/
                                                    else
                                                       {
                                                       clrscr();
		                                                 titulo();
	     		                                           gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Unidad(millon)); cprintf("%s",Centena(centenasmil%10)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                                       x+=3;
                                                       while(contador<strlen(Unidad(millon)))
         		                                             {
                                                            gotoxy(x,11); cprintf("%c",95);
		                                                      gotoxy(x,12); cprintf("%c",196);
		                                                      x++;
		                                                      contador++;
		                                                      }
                                                            contador=0;
                                                            while(contador<strlen(Centena(centenasmil%10)))
         		                                                  {
		                                                           gotoxy(x,12); cprintf("%c",196);
		                                                           x++;
		                                                           contador++;
		                                                           }
                                                                 contador=0;
                                                                 while(contador<strlen(Decena(decenasmil%10)))
         		              	                                        {
		                       	                                        gotoxy(x,12); cprintf("%c",196);
                                                                      x++;
		                                                                contador++;
		                                                                }
                                                                      contador=0;
		                                                                while(contador<strlen(Unidad(mil%10)))
         		              	       	                                    {
		                       	                                             gotoxy(x,12); cprintf("%c",196);
                                                                           x++;
		                                                                     contador++;
		                                                                     }
                                                                           gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                               estado=0;
            		                                                         x=65;
                  		                                                   contador=0;
                        	                                                getche();
                           }
                                                       }
                                                       else if((copia>99999) && (copia<1000000))//Condicional para los números entre 100.000(Cien mil) y 999.999(Novecientos noventa y nueve mil novecientos noventa y nueve).
                      	                                      {
                                                              clrscr();
		                                                        titulo();
	     		                                                  gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Centena(centenasmil)); cprintf("%s",Decena(decenasmil%10)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                                              x+=2;
                                                              while(contador<strlen(Centena(centenasmil)))
         		                                                    {
		                                                             gotoxy(x,12); cprintf("%c",196);
		                                                             x++;
		                                                             contador++;
		                                                             }
                                                                   contador=0;
                                                                   while(contador<strlen(Decena(decenasmil%10)))
         		              	                                          {
		                       	                                          gotoxy(x,12); cprintf("%c",196);
                                                                        x++;
		                                                                  contador++;
		                                                                  }
                                                                        contador=0;
		                                                                  while(contador<strlen(Unidad(mil%10)))
         		              	       	                                      {
		                       	                                               gotoxy(x,12); cprintf("%c",196);
                                                                             x++;
		                                                                       contador++;
		                                                                       }
                                                                             gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                                 estado=0;
            		                                                           x=65;
                  		                                                     contador=0;
                        	                                                  getche();
                                                              }
                                                              else if((copia>9999) && (copia<100000))//Condicional para los números entre 10.000(Diez mil) y 99.999(Noventa y nueve mil novecientos noventa y nueve).
                      	                                             {
                                                                     clrscr();
		                                                               titulo();
	     		                                                         gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Decena(decenasmil)); cprintf("%s",Unidad(mil%10)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                                                     x++;
                                                                     while(contador<strlen(Decena(decenasmil)))
         		                                                           {
		                                                                    gotoxy(x,12); cprintf("%c",196);
		                                                                    x++;
		                                                                    contador++;
		                                                                    }
                                                                          contador=0;
                                                                          while(contador<strlen(Unidad(mil%10)))
         		                                                                {
		                       	                                                 gotoxy(x,12); cprintf("%c",196);
                                                                               x++;
		                                                                         contador++;
		                                                                         }
			            		                                                    gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                                   estado=0;
            		                                                             x=65;
                  		                                                       contador=0;
                        	                                                    getche();
                                                                     }
                      	                                             else if((copia>3999) && (copia<10000))//Condicional para los números entre 4.000(Cuatro mil) y 9.999(Nueve mil novecientos noventa y nueve).
                      		                                                 {
		                                                                      clrscr();
		                                                                      titulo();
                                                                            gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Unidad(mil)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
                                                                            while(contador<strlen(Unidad(mil)))
     									                                                   {
										                                                   gotoxy(x,12); cprintf("%c",196);
										                                                   x++;
										                                                   contador++;
										                                                   }
                                                                                 gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
      		                                                                     estado=0;
            		                                                               x=65;
                                                                                 contador=0;
                                                                                 getche();
	                                                                         }
                      	                                                    else if(copia<4000)//Esta parte del condicional se cumple cuando el número es menor a 4.000(Cuatro mil).
                      		                                                        {
	                      																			  clrscr();
   	                       																		  titulo();
      	                  																		  gotoxy(27,13); cprintf("%d",copia); cprintf(" en n"); cprintf("%c",163); cprintf("mero romano se escribe as"); cprintf("%c",161); cprintf(": "); cprintf("%s",Mil(mil)); cprintf("%s",Centena(centenas)); cprintf("%s",Decena(decenas)); cprintf("%s",Unidad(unidades));
         	                																	     estado=0;
                           																		  gotoxy(27,20); cprintf("Presione cualquier tecla para continuar...");
            	            																		  getche();
               	                                                                 }
                      }
               	  }
               }
      			else//Esta parte del condicional se cumple cuando el usuario elige la opción 2
             	   exit(0);
      }
}

//Definición de Funciones:

void titulo(){
gotoxy(27,6); cprintf("Convertir N"); cprintf("%c",163); cprintf("meros Naturales a N"); cprintf("%c",163); cprintf("meros Romanos");
}

char *Unidad(int u){//Función para las unidades
char *unidades[10], *uni[1];
unidades[0]="";
unidades[1]="I";
unidades[2]="II";
unidades[3]="III";
unidades[4]="IV";
unidades[5]="V";
unidades[6]="VI";
unidades[7]="VII";
unidades[8]="VIII";
unidades[9]="IX";
strcpy(uni[0], unidades[u]);
return uni[0];
}

char *Decena(int d){//Función para los múltiplos de 10 hasta 90
char *decenas[10], *dec[1];
decenas[0]="";
decenas[1]="X";
decenas[2]="XX";
decenas[3]="XXX";
decenas[4]="XL";
decenas[5]="L";
decenas[6]="LX";
decenas[7]="LXX";
decenas[8]="LXXX";
decenas[9]="XC";
strcpy(dec[0], decenas[d]);
return dec[0];
}

char *Centena(int c){//Función para los múltiplos de 100 hasta 900
char *centenas[10], *cen[1];
centenas[0]="";
centenas[1]="C";
centenas[2]="CC";
centenas[3]="CCC";
centenas[4]="CD";
centenas[5]="D";
centenas[6]="DC";
centenas[7]="DCC";
centenas[8]="DCCC";
centenas[9]="CM";
strcpy(cen[0], centenas[c]);
return cen[0];
}

char *Mil(int m){//Función para los múltiplos de 1.000(Mil) hasta 3.000(Tres mil)
char *multiplosmil[4], *m1000[1];
multiplosmil[0]="";
multiplosmil[1]="M";
multiplosmil[2]="MM";
multiplosmil[3]="MMM";
strcpy(m1000[0], multiplosmil[m]);
return m1000[0];
}