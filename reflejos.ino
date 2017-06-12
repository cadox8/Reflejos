byte white = 6; //Start fkng n00b

byte green = 9; //Player 1
byte pul4 = 4;

byte red = 11; //Player 2
byte pul12 = 12;

String winner;
boolean gameOver;

int csgo; //Ja jaaaaaaaa CounterStrike:GO

void setup() {
  Serial.begin(9600); //Port? Are we boats now?
  
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  pinMode(pul4, INPUT);
  pinMode(pul12, INPUT);

  gameOver = false;
  getReck(5); //We want default message :D
  csgo = 0;
}

void loop() {
  if (!gameOver) {
    Serial.println("COMIENZA EL JUEGO CUANDO SE APAGUE EL LED BLANCO");
    digitalWrite(white, HIGH);
    delay(random(11) * 1000); //Set to 11 to get from 0 to 10
    digitalWrite(white, LOW); 
  }

  switch(digitalRead(pul4)) {
    case HIGH:
      if (gameOver) break;
      digitalWrite(green, HIGH);
      getReck(1);
      break;
  }
  switch(digitalRead(pul12)) {
    case HIGH:
      if (gameOver) break;
      digitalWrite(green, HIGH);
      getReck(2);
      break;
  }

  if (!gameOver) return;
  Serial.println("HAS GANADO " + winner + " en " + csgo / 1000 + " segundos");
  Serial.println("PULSA RESET PARA UN NUEVO JUEGO");
}

void counterStrike(){
  if (gameOver) return;
  csgo++;
}

void getReck(int player){
  gameOver = true;

  switch(player) {
      case 1:
        winner = "VERDE";
        break;
      case 2:
        winner = "ROJO";
        break;
      default:
        winner = "Espera, ¿nadie ha ganado? ¿Tan mancos sois? Peor que WillyRex en el COD, eh";
        break;
  }
}

