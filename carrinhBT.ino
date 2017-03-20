//Carrinho BT

/*Motor de tras, frente e re*/
#define B1 3
#define B2 5
/*Motor da frente, direita e esquerda*/
#define F1 9
#define F2 6

unsigned char c = 0;
unsigned int power = 0;
void setup() {

  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(F1, OUTPUT);
  pinMode(F2, OUTPUT);

  pinMode(13, OUTPUT);

  delay(500);

  digitalWrite(B1, LOW);
  digitalWrite(B2, LOW);
  digitalWrite(F1, LOW);
  digitalWrite(F2, LOW);

  digitalWrite(13, LOW);

  delay(500);

  Serial.begin(9600);
  delay(1000);

}

void loop() {

  if (Serial.available() > 0 ) {
    c = Serial.read();
    switch (c) {
      case 'F':
        analogWrite(B1, map(power, 0, 9, 0, 255));
        digitalWrite(B2, LOW);
        break;
      case 'B':
        analogWrite(B2, map(power, 0, 9, 0, 255));
        digitalWrite(B1, LOW);
        break;
      case 'R':
        digitalWrite(F2, HIGH);
        digitalWrite(F1, LOW);
        break;
      case 'L':
        digitalWrite(F1, HIGH);
        digitalWrite(F2, LOW);
        break;
      case 'S':
        digitalWrite(B1, LOW);
        digitalWrite(B2, LOW);
        digitalWrite(F1, LOW);
        digitalWrite(F2, LOW);
        break;
      case '0':
        power = 0;
        break;
      case '1':
        power = 1;
        break;
      case '2':
        power = 2;
        break;
      case '3':
        power = 3;
        break;
      case '4':
        power = 4;
        break;
      case '5':
        power = 5;
        break;
      case '6':
        power = 6;
        break;
      case '7':
        power = 7;
        break;
      case '8':
        power = 8;
        break;
      case '9':
        power = 9;
        break;
    }
  }
  delay(1);
}
