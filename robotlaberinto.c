
#include "simpletools.h"                      
#include "abdrive.h"                        
#include "ping.h"                          

// Declaración de variables

int sensorFrontal, sensorDerecho; //dos sensores                               
int laberinto[50][50]; //matriz con la posicion del robot
int spd, ejeX, ejeY, orientacion; //Variables de funcionamiento del programa
int i,j; //Contadores
int giro = 34;


// Programa principal

int main()                              
{
  pause(1000);

  ejeX = 0;
  ejeY = 0;
  orientacion = 0;
  
  while(1)
  {                       
    sensorFrontal = ping_cm(8);
    sensorDerecho = ping_cm(10);
    i = 0;
    
    
    while(sensorFrontal >= 10 && sensorDerecho < 25) // el robot camina hacia enfrente 
    {
      sensorFrontal = ping_cm(8);
      sensorDerecho = ping_cm(10); 
      
      drive_ramp(50,50);
     
      if(i == 50){       
        coordenadas();
        contador();
        i = 0;
      }else{
        i++;
      }   
      
      pause(5);            
    }
   
  
    if(sensorDerecho < 25) //el robot gira a la izquierda
    {
      drive_speed(-giro,giro);
      j = 0;
      while(j < 97)
      {
        j++;  
        pause(5);
      }        
      
      orientacion = orientacion + 3;
      orientacion = orientacion % 4;             
        
    }else{  // el robot gira a la derecha
            // los siguientes tres while solo hacen que el giro no sea tan abrupto
      j = 0;
      while(j < 160)
      {
        drive_ramp(30,30);
        j++;  
        pause(5);
      }
      
      
      drive_speed(giro,-giro);
      j = 0;
      while(j < 148)
      {
        j++;  
        pause(5);
      }
      
      
      drive_speed(50,50);  
      j = 0;
      while(j < 180)
      {
        j++;  
        pause(5);
      }    
      
      orientacion++;
      orientacion = orientacion % 4;
    }      
 
  }  
                         
}

// METODOS

void contador(){
  laberinto[ejeX][ejeY]= laberinto[ejeX][ejeY]+1;
}  

int coordenadas(){
  if(orientacion == 0){
    ejeY++;
  }    
  if(orientacion == 1){
    ejeX++;
  }
  if(orientacion == 2){
    ejeY--;
  }
  if(orientacion == 3){
    ejeX--;
  }  
} 

