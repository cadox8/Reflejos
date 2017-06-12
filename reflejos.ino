byte white = 6; //Start fkng n00b

byte green = 9; //Player 1
byte pul4 = 4;

byte red = 11; //Player 2
byte pul12 = 12;

String winner = "Espera, ¿nadie ha ganado? ¿Tan mancos sois? Peor que WillyRex en el COD, eh";
byte gameOver = 0;

int csgo = 0; //Ja jaaaaaaaa CounterStrike:GO

void setup() {
  Serial.begin(9600); //Port? Are we boats now?
  
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  pinMode(pul4, INPUT);
  pinMode(pul12, INPUT);
}

void loop() {
  counterStrike();
  if (gameOver == 0) {
    Serial.println("COMIENZA EL JUEGO CUANDO SE APAGUE EL LED BLANCO");
    digitalWrite(white, HIGH);
    delay(random(11) * 1000); //Set to 11 to get from 0 to 10
    digitalWrite(white, LOW); 
    delay(500);
  }
 
  if (digitalRead(pul4) == 1 && gameOver == 0) {
      digitalWrite(green, HIGH);
      getReck(1);
  }

  if (digitalRead(pul12) == 1 && gameOver == 0) {
      digitalWrite(red, HIGH);
      getReck(2);
  }

  if (gameOver == 0){
    Serial.println("Nadie ha ganado, ha empezado de nuevo la ronda");
  }
}

void counterStrike(){
  if (gameOver == 1) return;
  csgo++;
}

void getReck(int player){
  gameOver = 1;

  switch(player) {
      case 1:
        winner = "VERDE";
        break;
      case 2:
        winner = "ROJO";
        break;
  }
  Serial.println("HAS GANADO " + winner + " EN " + csgo + " SEGUNDOS");
  Serial.println("PULSA RESET PARA UN NUEVO JUEGO");
}
