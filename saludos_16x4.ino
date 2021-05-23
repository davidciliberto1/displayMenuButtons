#include <Wire.h>

// incluimos libreria
#include <LiquidCrystal.h>

// inicializamos display con sus pines
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// variables de botones
int btnUp = 10;
int btnDown = 9;
int btnSelect = 7;
int menu = 1;

void setup() {
  lcd.begin(16, 4);
  pinMode(btnUp, INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnSelect, INPUT_PULLUP);
}

void loop() {
  if (!digitalRead(btnUp)) {
    menu++;
    updateMenu();
    delay(300);
    while (!digitalRead(btnUp));
  }
  if (!digitalRead(btnDown)) {
    menu--;
    updateMenu();
    delay(300);
    while (!digitalRead(btnDown));
  }
  if (!digitalRead(btnSelect)) {
    executeAction();
    updateMenu();
    delay(300);
    while (!digitalRead(btnSelect));
  }
}
void updateMenu() {
  switch (menu) {
    case 0:
      menu = 1;
      break;
    case 1: lcd.setCursor(0, 0);
      lcd.print(">Item menu1");
      lcd.setCursor(0, 1);
      lcd.print(" Item menu2");
      lcd.setCursor(0, 2);
      lcd.print(" Item menu3");
      lcd.setCursor(0, 3);
      lcd.print(" Item menu4");
      break;
    case 2: lcd.setCursor(0, 0);
      lcd.print(" Item menu1");
      lcd.setCursor(0, 1);
      lcd.print(">Item menu2");
      lcd.setCursor(0, 2);
      lcd.print(" Item menu3");
      lcd.setCursor(0, 3);
      lcd.print(" Item menu4");
      break;
    case 3: lcd.setCursor(0, 0);
      lcd.print(" Item menu1");
      lcd.setCursor(0, 1);
      lcd.print(" Item menu2");
      lcd.setCursor(0, 2);
      lcd.print(">Item menu3");
      lcd.setCursor(0, 3);
      lcd.print(" Item menu4");
      break;
    case 4: lcd.setCursor(0, 0);
      lcd.print(" Item menu1");
      lcd.setCursor(0, 1);
      lcd.print(" Item menu2");
      lcd.setCursor(0, 2);
      lcd.print(" Item menu3");
      lcd.setCursor(0, 3);
      lcd.print(">Item menu4");
      break;
    case 5:
      menu = 4;
      break;
  }

}
void executeAction() {
  switch (menu) {
    case 1:
      action1();
      break;
    case 2:
      action2();
      break;
    case 3:
      action3();
      break;
    case 4:
      action4();
      break;

  }
}
void action1() {
  lcd.clear();
  lcd.print("Holaa benny!!");
  delay(1500);
    lcd.clear();

}
void action2() {
  lcd.clear();
  lcd.print(">Epa panaaa!");
  delay(1500);
    lcd.clear();

}
void action3() {
  lcd.clear();
  lcd.print(">Armate eseee!");
  delay(1500);
    lcd.clear();

}
void action4() {
  lcd.clear();
  lcd.print(">Hablaaaaa");
  delay(1500);
  lcd.clear();
}
