//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600); // Création d'une connection avec le premier port parmis ceux disponible
  output = createWriter ("Battements.csv"); // Création/Ouverture du fichier "Battements.csv"
}

  void draw() {
    if (udSerial.available() > 0) { // Si la taille du contenu du fichier est supérieur à 0 bytes
      String SenVal = udSerial.readString(); // Retourne le contenu du fichier, ou null si il n'y a rien
      if (SenVal != null) { // Si SenVal différent de nul
        output.println(SenVal); // Ecriture de SenVal dans "Battements.csv"
      }
    }
  }

  void keyPressed(){
    output.flush(); // Ecriture des données restantes dans le fichier
    output.close(); // Fermeture du fichier
    exit(); // Fermeture du programme
  }
