#include <Keypad.h>
#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1);

unsigned long delaytime1 = 500;
unsigned long delaytime2 = 50;

int middle_x = 515;
int middle_y = 503;

#define blue_led 2
#define green_led 4

const int SW_pin = 6; // digital pin connected to switch output
const int X_pin = 0;  // analog pin connected to X output
const int Y_pin = 1;  // analog pin connected to Y output

int x = 0;
int y = 0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {30, 33, 34, 37}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {38, 41, 42, 45}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

int led_status = 0;

int l = 0;
int c = 0;

void vline(int l1)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setLed(0, i, l1, true);
  }
}

void hline(int l1)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setLed(0, l1, i, true);
  }
}

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  lc.shutdown(0, false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0, 8);
  /* and clear the display */
  lc.clearDisplay(0);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  int l = 0;
  int c = 0;
}

void loop()
{
  char customKey = customKeypad.getKey();

  if (customKey == '2')
  {
    digitalWrite(blue_led, HIGH);
  }
  if (customKey == '4')
  {
    digitalWrite(green_led, HIGH);
  }

  if (customKey == '5')
  {
    if (led_status == 0)
    {
      led_status = 1;
      digitalWrite(green_led, HIGH);
      digitalWrite(blue_led, HIGH);
    }
    else
    {
      led_status = 0;
      digitalWrite(green_led, LOW);
      digitalWrite(blue_led, LOW);
    }
  }
  if (customKey == '6')
  {
    digitalWrite(blue_led, LOW);
  }
  if (customKey == '8')
  {
    digitalWrite(green_led, LOW);
  }

  if (customKey == '1')
  {
    lc.setLed(0, c, l, false);
    if (c > 0)
    {
      c -= 1;
    }

    //lc.setColumn(0,1,B1111111);
  }
  if (customKey == '3')
  {
    lc.setLed(0, c, l, true);
    if (c < 8)
    {
      c += 1;
    }

    //lc.setColumn(0,1,B00100000);
  }
  if (customKey == '7')
  {
    lc.setLed(0, c, l, false);
    if (l > 0)
    {
      l -= 1;
    }

    //lc.setColumn(0,1,B00100000);
  }
  if (customKey == '9')
  {
    lc.setLed(0, c, l, true);
    if (l < 8)
    {
      l += 1;
    }

    //lc.setColumn(0,1,B00100000);
  }

  if (customKey == '0')
  {
    vline(l);
    hline(l);
    if (l < 8)
    {
      l += 1;
    }

    //lc.setColumn(0,1,B00100000);
  }

  if (customKey)
  {
    Serial.println(customKey);
  }
  if (digitalRead(SW_pin) == 0)
  {
    Serial.print("swtich pressed\n\n");
    l = 0;
    c = 0;
    lc.clearDisplay(0);
    if (led_status == 0)
    {
      digitalWrite(green_led, HIGH);
      digitalWrite(blue_led, HIGH);
      led_status = 1;
    }
    else
    {
      digitalWrite(green_led, LOW);
      digitalWrite(blue_led, LOW);
      led_status = 0;
    }
  }
  x = analogRead(X_pin);
  y = analogRead(Y_pin);
  //if ( x < y ) {
  //digitalWrite(green_led, HIGH);
  if (int(x) > 900)
  {
    digitalWrite(green_led, HIGH);
    lc.setLed(0, c++, l, true);
    //      if ( c < 8 ) {
    //        lc.setLed(0,c,l,true);
    //        c++;
    //        delay(500);
    //      }
  }
  else if (int(x) < 123)
  {
    digitalWrite(green_led, LOW);
    lc.setLed(0, c--, l, false);
    //      if ( c > 0 ) {
    //        lc.setLed(0,c,l,true);
    //        c--;
    //        delay(500);
    //      }
  }
  // } else {
  //digitalWrite(blue_led, HIGH);
  if (int(y) > 900)
  {
    digitalWrite(blue_led, HIGH);
    lc.setLed(0, c, l++, true);
    //      if ( l < 8 ) {
    //        lc.setLed(0,c,l,true);
    //        l++;
    //        delay(500);
    //      }
  }
  else if (int(y) < 123)
  {
    digitalWrite(blue_led, LOW);
    lc.setLed(0, c, l--, false);
    //      if ( l > 0 ) {
    //        lc.setLed(0,c,l,true);
    //        l--;
    //        delay(500);
    //      }
  }
  //  }
  //  if (int(x) > 900) {
  //  	vline(l);
  //  	l++;
  //  }
  //  if (int(y) > 900) {
  //  	hline(c);
  //  	c++;
  //  }
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(y);
  Serial.print("\n\n");
  delay(500);
}
