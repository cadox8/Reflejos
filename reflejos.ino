byte white = 6; //Start fkng n00b

byte green = 9; //Player 1
byte pul4 = 4;

byte red = 11; //Player 2
byte pul12 = 12;

String winner = "Espera, ¿nadie ha ganado? ¿Tan mancos sois? Peor que WillyRex en el COD, eh";
byte gameOver = 0;

int csgo = 0; //Ja jaaaaaaaa CounterStrike:GO

// Sleep when we're dead (ty mcgough6101)
byte speakerPin = 2;

int length = 10;
char notes[] = "fefeca a#a "; // El espacio es una parada
int beats[] = { 4, 1, 1, 1, 1, 1, 1, 2, };
int tempo = 300;

void setup() {
  Serial.begin(9600); //Port? Are we boats now?
  
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  
  pinMode(pul4, INPUT);
  pinMode(pul12, INPUT);

  pinMode(speakerPin, OUTPUT);
}

void loop() {
  counterStrike();
  if (gameOver == 0) {
    Serial.println("COMIENZA EL JUEGO CUANDO SE APAGUE EL LED BLANCO");
    digitalWrite(white, HIGH);
    //delay(random(11) * 1000); //Set to 11 to get from 0 to 10
    delay(1000); //Tests
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
    for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // rest
    } else {
      playNote(notes[i], beats[i] * tempo);
    }
    
    delay(tempo / 2); //Delay!
  }
}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'd#', 'e', 'f', 'g', 'g#', 'a', 'a#' };
  int tones[] = { 1915, 1700, 1608, 1519, 1432, 1275, 1205, 1136, 1073 };

  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
