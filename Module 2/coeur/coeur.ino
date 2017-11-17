#include "param.h"

String incomingByte = ""; 


void setup() {

  // Initialisation
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  randomSeed(analogRead(0));
  
  
  
}

// Boucle sans fin
void loop() {
  int mode = parametre();

  switch (mode)

  {

        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        
    case 0: // Allumer une LED au choix
         choix();
         break;
        
    case 1: // Allumer toutes les LEDs
        allled();
        break;
        
    case 2:// Allumer les LEDs en mode chenille
        chenilleune();
        break;
        
    case 3:// Allumer 1 LED sur 2
        unesurdeux();
        break;
      
    case 4:// Allumer 1 LED sur 3
        unesurtrois();
        break;
        
    case 5:// Allumer 1 LED sur 4
        unesurquatre();
        break;
        
    case 6:// Allumer 1 LED sur 5
        unesurcinq();
        break;
      
    case 7:// Allumer 1 LED sur 6
        unesursix();
        break;
      
    case 8:// Allumer 1 LED sur 7
        unesursept();
        break;
      
    case 9:// Allumer 1 LED sur 8
        unesurhuit();
        break;
        
    case 10:// Allumer 1 LED sur 9
        unesurneuf();
        break;
        
    case 11:// Allumer 1 LED sur 10
        unesurdix();
        break;

    case 12: // Mode Escargot
        escargot();
        break; 


    case 13: // Balayage horizontal
        balayagehorizontal();     
        break; 
     
    case 14: // Mode spirale
        spirale();
        break;

    case 15: // Mode barre de chargement
        chargement();
        break; 
        
    case 16: // Chenille de 3 LEDs
        chenilletrois();
        break; 

    case 17: // Chenille de 4 LEDs
        chenillequatre();
        break; 
     
    case 18: // Chenille de 2 LEDs
        chenilledeux();
        break; 


    case 19: // Chenille de 5 LEDs
        chenillecinq();
        break; 

    case 20: // Chenille de 6 LEDs
        chenillesix();
        break; 


    case 21: // Chenille de 7 LEDs
        chenillesept();
        break;


    case 22: // Balayage vertical
        balayagevertical();
        break;


   case 23: // Random
        hasard();
        break;

        
    default :// Erreur
      break;

  }
}
    


    void choix() {
        if (Serial.available()) 
       {
        
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        incomingByte = Serial.readString();
        int valeur = incomingByte.toInt();
        Serial.println((String)valeur);       

          if (valeur > 1 && valeur <= 10) {
            digitalWrite(valeur, HIGH);
          }

          else if (valeur==1){
            digitalWrite(11, HIGH);
          }

          else {
            Serial.println("Mauvaise combinaison");
          }
       }
    }

 
    void allled() {
        int value = analogRead(0);
        if(value > 300){
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        }else{
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        }
    }

    void chenilleune (){
        digitalWrite(11, HIGH); 
        delay(500);
        digitalWrite(11, LOW);
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        delay(500);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(10, LOW);
        }

    void unesurdeux() {    
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
    }

    void unesurtrois() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);  
    }

    void unesurquatre(){
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
    }

    void unesurcinq() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
    }

    void unesursix() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
    }

    void unesursept() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        }

    void unesurhuit() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
    }

    void unesurneuf() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
    }

    void unesurdix() {
        digitalWrite(11, HIGH);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
    }

    void escargot() { 
        digitalWrite(11, HIGH); 
        delay(100);
        digitalWrite(2, HIGH); 
        delay(100);
        digitalWrite(3, HIGH); 
        delay(100);
        digitalWrite(4, HIGH); 
        delay(100);
        digitalWrite(5, HIGH); 
        delay(100);
        digitalWrite(6, HIGH); 
        delay(100);
        digitalWrite(7, HIGH); 
        delay(100);
        digitalWrite(8, HIGH); 
        delay(100);
        digitalWrite(9, HIGH); 
        delay(100);
        digitalWrite(10, HIGH); 
        delay(100);
        
        digitalWrite(10, LOW);
        delay(100);
        digitalWrite(9, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(7, LOW);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(5, LOW);
        delay(100);
        digitalWrite(4, LOW);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(2, LOW);
        delay(100);
        digitalWrite(11, LOW);
        delay(100);
     }

    void balayagehorizontal() {
        digitalWrite(2, HIGH);
        digitalWrite(10, HIGH);
        delay(100);
        digitalWrite(3, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(9, HIGH);
        delay(100);
        digitalWrite(4, HIGH);
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(5, HIGH);
        digitalWrite(7, HIGH);
        delay(100);
        digitalWrite(6, HIGH);
        delay(100);
        digitalWrite(6, LOW);
        delay(100); 
        digitalWrite(5, LOW);
        digitalWrite(7, LOW);
        delay(100);
        digitalWrite(4, LOW);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(3, LOW);
        digitalWrite(11, LOW);
        digitalWrite(9, LOW);
        delay(100);
        digitalWrite(2, LOW);
        digitalWrite(10, LOW);
        delay(100);
     }

     void spirale() {
        digitalWrite(6, HIGH);
        digitalWrite(11, HIGH);
        delay(100);
        digitalWrite(7, HIGH);
        digitalWrite(2, HIGH);
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(9, HIGH);
        digitalWrite(4, HIGH);
        delay(100);
        digitalWrite(10, HIGH);
        digitalWrite(5, HIGH);
        delay(100);
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
        delay(100);
        digitalWrite(9, LOW);
        digitalWrite(4, LOW);
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(7, LOW);
        digitalWrite(2, LOW);
        delay(100);
        digitalWrite(6, LOW);
        digitalWrite(11, LOW);
        delay(100);
    }

    void chargement() {
        digitalWrite(11, HIGH); 
        delay(100);
        digitalWrite(2, HIGH); 
        delay(100);
        digitalWrite(3, HIGH); 
        delay(100);
        digitalWrite(4, HIGH); 
        delay(00);
        digitalWrite(5, HIGH); 
        delay(100);
        digitalWrite(6, HIGH); 
        delay(100);
        digitalWrite(7, HIGH); 
        delay(100);
        digitalWrite(8, HIGH); 
        delay(100);
        digitalWrite(9, HIGH); 
        delay(100);
        digitalWrite(10, HIGH); 
        delay(100);
        
        digitalWrite(10, LOW);
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        digitalWrite(11, LOW);
    }

    void chenilletrois() {       
        digitalWrite(11, HIGH);
        digitalWrite(8, LOW);
        delay(200);
        digitalWrite(9, LOW);
        digitalWrite(2, HIGH);
        delay(200);
        digitalWrite(10, LOW);
        digitalWrite(3, HIGH);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(7, LOW);
        delay(200);
    }

    void chenillequatre() {
        digitalWrite(11, HIGH);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(8, LOW);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(9, LOW);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(10, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(3, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(6, LOW);
        delay(200);
    }

    void chenilledeux() {
        digitalWrite(11, HIGH);
        digitalWrite(9, LOW);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(10, LOW);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(3, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(8, LOW);
    }

    void chenillecinq() {
        digitalWrite(11, HIGH);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(8, LOW);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(9, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(10, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(3, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(5, LOW); 
    }

    void chenillesix() {
        digitalWrite(11, HIGH);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(8, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(9, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(10, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(3, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(4, LOW);
    }

    void chenillesept() {
        digitalWrite(11, HIGH);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(4, HIGH);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(5, HIGH);
        digitalWrite(8, LOW);
        delay(200);
        digitalWrite(6, HIGH);
        digitalWrite(9, LOW);
        delay(200);
        digitalWrite(7, HIGH);
        digitalWrite(10, LOW);
        delay(200);
        digitalWrite(8, HIGH);
        digitalWrite(11, LOW);
        delay(200);
        digitalWrite(9, HIGH);
        digitalWrite(2, LOW);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(3, LOW);
    }

    void balayagevertical() {
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        delay(200);
        digitalWrite(10, HIGH);
        digitalWrite(7, HIGH);
        delay(200);
        digitalWrite(11, HIGH);
        digitalWrite(6, HIGH);
        delay(200);
        digitalWrite(2, HIGH);
        digitalWrite(5, HIGH);
        delay(200);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        delay(200);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        delay(200);
        digitalWrite(2, LOW);
        digitalWrite(5, LOW);
        delay(200);
        digitalWrite(11, LOW);
        digitalWrite(6, LOW);
        delay(200);
        digitalWrite(10, LOW);
        digitalWrite(7, LOW);
        delay(200);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        delay(200);
    }

    void hasard() {
        int randNumber;
        randNumber = random(2,12);
        digitalWrite(randNumber, HIGH);
        delay(100);
        digitalWrite(randNumber, LOW);
   }
