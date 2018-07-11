#include <CapacitiveSensor.h>
#define greater(X, Y) ((X) > (Y) ? true : false)
#define timeout(X, Y) ((X) == (Y) ? true : false)
const byte connect0 = A15;
const byte maglock = 22;
const byte buzzer = 23;
const byte unlock = 25;
const byte led0 = 2;
const byte led1 = 3; //Swan
const byte led2 = 4; //Alligator
const byte led3 = 5;
int threshold0 = 300;
int threshold1 = 300;
int threshold2 = 50; 
int threshold3 = 500;
int threshold4 = 500;
int threshold5 = 50;
int threshold6 = 3000;
int threshold7 = 500;
int threshold8 = 100;
int threshold9 = 500;
int threshold10 = 500;
int threshold11 = 500;
int humanThreshold = 500;
int timeoutValue = -2;
CapacitiveSensor  cs_30_26 = CapacitiveSensor(30, 26);
CapacitiveSensor  cs_30_27 = CapacitiveSensor(30, 27);
CapacitiveSensor  cs_30_28 = CapacitiveSensor(30, 28);
CapacitiveSensor  cs_30_29 = CapacitiveSensor(30, 29);
CapacitiveSensor  cs_45_42 = CapacitiveSensor(45, 42);
CapacitiveSensor  cs_45_43 = CapacitiveSensor(45, 43);
//CapacitiveSensor  cs_45_41 = CapacitiveSensor(45 ,41);
CapacitiveSensor  cs_45_44 = CapacitiveSensor(45, 44);
CapacitiveSensor  cs_50_49 = CapacitiveSensor(50, 49);
CapacitiveSensor  cs_50_51 = CapacitiveSensor(50, 51);
CapacitiveSensor  cs_50_52 = CapacitiveSensor(50, 52);
CapacitiveSensor  cs_50_53 = CapacitiveSensor(50, 53);

bool flag0 = false;
bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool win = false;
long total0;
long total1;
long total2;
long total3;
long total4;
long total5;
long total6;
long total7;
long total8;
long total9;
long total10;
long total11;
long total12;
int value0;
bool gate0 = false;
bool gate1 = false;

void setup() {
  Serial.begin(9600);
  pinMode(maglock, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(unlock, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(buzzer, HIGH);
  digitalWrite(maglock, HIGH);
}

void loop() {
  //gate0 = true;
  while (!gate0) {
    if (!digitalRead(unlock)) {
      gate0 = true;
    }
    Serial.println(digitalRead(unlock));
  }
  long total0 =  cs_30_26.capacitiveSensor(30);
  long total1 =  cs_30_27.capacitiveSensor(30);
  long total2 =  cs_30_28.capacitiveSensor(30);
  long total3 =  cs_30_29.capacitiveSensor(30);
  long total4 =  cs_45_42.capacitiveSensor(30);
  long total5 =  cs_45_43.capacitiveSensor(30);
  //long total6 =  cs_45_41.capacitiveSensor(30);
  long total7 =  cs_45_44.capacitiveSensor(30);
  long total8 =  cs_50_49.capacitiveSensor(30);
  long total9 =  cs_50_51.capacitiveSensor(30);
  long total10 =  cs_50_52.capacitiveSensor(30);
  long total11 =  cs_50_53.capacitiveSensor(30);
  int value0 = analogRead(connect0);
  Serial.print("Totals: ");
  Serial.print(total0);
  Serial.print("\t");
  Serial.print(total1);
  Serial.print("\t");
  Serial.print(total2);
  Serial.print("\t");
  Serial.print(total3);
  Serial.print("\t");
  Serial.print(total4);
  Serial.print("\t");
  Serial.print(total5);
  Serial.print("\t");
  Serial.print(total6);
  Serial.print("\t");
  Serial.print(total7);
  Serial.print("\t");
  Serial.print(total8);
  Serial.print("\t");
  Serial.print(total9);
  Serial.print("\t");
  Serial.print(total10);
  Serial.print("\t");
  Serial.print(total11);
  Serial.print("\t");
  Serial.println(value0);

  bool check0 = greater(total0, threshold0) || timeout(total0, timeoutValue);
  bool check1 = greater(total1, threshold1) || timeout(total1, timeoutValue);
  bool check2 = greater(total2, threshold2) || timeout(total2, timeoutValue);
  bool check3 = greater(total3, threshold3) || timeout(total3, timeoutValue);
  bool check4 = greater(total4, threshold4) || timeout(total4, timeoutValue);
  bool check5 = greater(total5, threshold5) || timeout(total5, timeoutValue);
  bool check6 = greater(total6, threshold6) || timeout(total6, timeoutValue);
  bool check7 = greater(total7, threshold7) || timeout(total7, timeoutValue);
  bool check8 = greater(total8, threshold8) || timeout(total8, timeoutValue);
  bool check9 = greater(total9, threshold9) || timeout(total9, timeoutValue);
  bool check10 = greater(total10, threshold10) || timeout(total10, timeoutValue);
  bool check11 = greater(total11, threshold11) || timeout(total11, timeoutValue);
  bool test = timeout(total3, timeoutValue);
  //Serial.println(test);

  if (check0 && check1 && check2 && !check3 && !check4 && check5 && !check6 && !check7 && !check8 && !check9 && !check10 && !check11) {
    flag0 = true;
    digitalWrite(led0, HIGH);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
  }

  if (check3 && check4 && check7) {
    flag1 = true;
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    //Serial.println("Flag1!");
  }

  if (!check0 && !check1 && !check2 && !check3 && !check4 && !check5 && !check6 && !check7 && check8 && check9 && check10 && !check11) {
    flag2 = true;
    digitalWrite(led2, HIGH);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
  }

  if (value0 <= humanThreshold && check11) {
    flag3 = true;
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
  }

  if (flag0 && flag1 && flag2 && flag3) {
    digitalWrite(maglock, LOW);
    Serial.println("Win!");
    win = true;
  }
  else {
    digitalWrite(maglock, HIGH);
  }

  if (win && !check0 && !check1 && !check2 && !check3 && check4 && !check5 && !check6 && !check7 && !check8 && !check9 && !check10 && check11) {
    win = false;
    flag0 = false;
    flag1 = false;
    flag2 = false;
    flag3 = false;
    gate0 = false;
    gate1 = false;
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(maglock, HIGH);
  }
}
