#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Password.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Password password = Password( "1436" ); //Ubah password

const byte baris = 4; //Baris
const byte kolom = 4; //Kolom
const int alarm= 10;
const int led=11;

char keys[baris][kolom] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte barisPin[baris] = {9,8,7,6};
byte kolomPin[kolom]= {5,4,3,2};

// Buat objek keypad
Keypad keypad = Keypad( makeKeymap(keys), barisPin, kolomPin, baris, kolom );

void setup(){
  pinMode(alarm,OUTPUT);
  pinMode(led,OUTPUT);
  lcd.begin();
  keypad.addEventListener(keypadEvent);
}

void loop(){
  keypad.getKey();

  }

  void keypadEvent(KeypadEvent eKey){
      switch (keypad.getState()){
        case PRESSED:
        lcd.setCursor(0,0);
          lcd.print(eKey);
        
        switch (eKey){
            case 'A': Login(); delay(1); break;
           
            case 'B': password.reset(); delay(1); break;
           
            default: password.append(eKey); delay(1);
          }
       }
    }

      void Login(){
      if (password.evaluate()){
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("masok pa eko");
          digitalWrite(led,HIGH);
          digitalWrite(alarm,LOW);
          delay(5000);
       
      }
      
      else{
          lcd.clear();
          lcd.setCursor(0,1);
          lcd.print("balik ");
          digitalWrite(led,LOW);
          digitalWrite(alarm,HIGH);
          delay(500);
         
        }
      }
