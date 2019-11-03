#define BUTTON 2
#define BUZZER 8
int tones[] = { 1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976 };
int duration = 800;
bool buttonStat = 1;
bool buttonStatOld = 1;

void setup() {
  Serial.begin(9600);
  for (int pin = 2; pin < 14; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  digitalWrite(13, LOW);
  digitalWrite(2, HIGH);
  playTone(0, duration);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  playTone(1, duration);

  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  playTone(2, duration);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  playTone(3, duration);

  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  playTone(4, duration);

  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  playTone(5, duration);

  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  playTone(6, duration);

  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  playTone(7, duration);

  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  playTone(8, duration);

  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  playTone(9, duration);

  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  playTone(10, duration);

  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  playTone(11, duration);
}

void playTone(int nota, int tempdur) {
  int tone = tones[nota];
  Serial.println("Nota: " + String(nota));

  for (long i = 0; i < tempdur * 1000L; i += tone * 2)   {
    //gestione tasto
    pinMode (BUTTON, INPUT_PULLUP);
    buttonStat = digitalRead(BUTTON);
    pinMode (BUTTON, OUTPUT);
       if (nota>0)   digitalWrite(2, LOW); 
    if  (buttonStat != buttonStatOld)  {
      buttonStatOld = buttonStat;
      if (buttonStat == 0) {
        duration = (duration > 50 ? duration / 2 : 800);
        Serial.println("Durata " + String(duration) + " ms.");
      }
    }
    //tono
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(tone);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(tone);
  }  
 
}
