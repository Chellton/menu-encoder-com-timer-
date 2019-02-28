#include <LiquidCrystal.h>

#include <RotaryEncoder.h>

#define potPin  A0 // potenciometro

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//teste

RotaryEncoder encoder(A2, A3); // encoder

const long maxTime = 1000000;// time maximo
const int minTime = 1000; // time minimo

float duration;
int potValue;
float tempo;
int valor = LOW;
static int pos = 1;
int newPos = 0;
int lock = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(7, INPUT);
  lcd.begin(16, 2);
}


void loop()
{

  valor = digitalRead(7); // leitura buton central do encoder

  Serial.println(valor); // Debug na serial

  encoder.tick();

  newPos = encoder.getPosition();

  potValue = analogRead(potPin);

  duration = map(potValue, 0, 1023, minTime, maxTime);

  tempo = ((duration / 1000) / 60);

  //-------------------- menu 01 ---------------------------

  while (valor == 0 && lock == 1) {

    lcd.clear();
    lcd.setCursor(0, 0);
    delay(200);
    lcd.print("> > SET TIME < < ");


    lock = 11;
    delay (200);

    valor = digitalRead(7);

  }

// --------------------------------------------------------------
  if (valor == 0 && lock == 11) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ATIVADO");
    delay(300);

    while ((tempo * 1000) >= 0 ) {


      int pos;
      
      if (tempo > 11) {
        pos = 9;
      } else {
        pos = 10;
        
        lcd.setCursor(9, 0);
        lcd.print(" ");
      }

      lcd.setCursor(pos, 0);

      tempo = (tempo - 1);
      lcd.print(tempo);

      lcd.setCursor(11, 0);
      lcd.print(":");

      if (tempo >= 0 ) {

        for (int i = 60; i >= 0; i--) {
          lcd.setCursor(12, 0);
          lcd.print(i);
          delay(100);

        }
      }



      if (tempo < 1) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> > TERMINOU < <");


      }

    }




  }

  // ------------------------------------------------------------------------

  //-------------------------- menu 02 ---------------------

  while (valor == 0 && lock == 2) {

    lcd.clear();
    lcd.setCursor(0, 0);
    delay(200);
    lcd.print("> > SET TIME < < ");


    lock = 22;
    delay (200);

    valor = digitalRead(7);

  }

// --------------------------------------------------------------
  if (valor == 0 && lock == 22) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ATIVADO");
    delay(300);

    while ((tempo * 1000) >= 0 ) {


      int pos;
      
      if (tempo > 11) {
        pos = 9;
      } else {
        pos = 10;
        
        lcd.setCursor(9, 0);
        lcd.print(" ");
      }

      lcd.setCursor(pos, 0);

      tempo = (tempo - 1);
      lcd.print(tempo);

      lcd.setCursor(11, 0);
      lcd.print(":");

      if (tempo >= 0 ) {

        for (int i = 60; i >= 0; i--) {
          lcd.setCursor(12, 0);
          lcd.print(i);
          delay(100);

        }
      }



      if (tempo < 1) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(">LUZ.UV. TERMIN<");


      }

    }




  }

  // --------------------------------------------------------------------

  //-------------------------- menu 03 ---------------------

  while (valor == 0 && lock == 3) {

    lcd.clear();
    lcd.setCursor(0, 0);
    delay(200);
    lcd.print("> > SET TIME < < ");


    lock = 33;
    delay (200);

    valor = digitalRead(7);

  }

// --------------------------------------------------------------
  if (valor == 0 && lock == 33) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ATIVADO");
    delay(300);

    while ((tempo * 1000) >= 0 ) {


      int pos;
      
      if (tempo > 11) {
        pos = 9;
      } else {
        pos = 10;
        
        lcd.setCursor(9, 0);
        lcd.print(" ");
      }

      lcd.setCursor(pos, 0);

      tempo = (tempo - 1);
      lcd.print(tempo);

      lcd.setCursor(11, 0);
      lcd.print(":");

      if (tempo >= 0 ) {

        for (int i = 60; i >= 0; i--) {
          lcd.setCursor(12, 0);
          lcd.print(i);
          delay(100);

        }
      }



      if (tempo < 1) {

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> AQUEC. TERMINOU <");


      }

    }




  }

  // --------------------------------------------------------------------
  
  if (pos != newPos)
  {
    //Limite maximo menu
    if (newPos > 6)
    {
      encoder.setPosition(6);
      newPos = 6;
    }
    //Limite minimo menu
    if (newPos < 1)
    {
      encoder.setPosition(1);
      newPos = 1;
    }

    pos = newPos;


    // -------------------------------------------

    switch (pos) {

      case 1:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("GIR. MOTOR.    ");
        lock = 1;
        break;


      case 2:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("LUZ UV.       ");
        lock = 2;
        break;

      case 3:
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("AQUECER.       ");
        lock = 3;
        break;

    }


  }


}

