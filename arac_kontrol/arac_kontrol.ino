// Açıklama: Joystick ile 4 tekerli basit araç kontrolü
// Description: Simple 4-wheel vehicle control with joystick.
// @author: Hamza Eren Sarpdağ
// Date: 14.09.2004  -  12.14

// Elimizde bir joystick ile sol ve sağ tekerler için birer motor sürücü olduğunu varsayalım.
// Let's assume we have a motor driver for the left and right wheels and have a joystick.
// Joystick ve motor sürücülerin ilgili pinlerini belirtelim.
// Let's specify the relevant pins of the joystick and motor drivers.
const int joy_x = A0;
const int joy_y = A1;

// Deneyap Kart kullanımı için digital pinler D ile belirtilir. ÖR: 7 -> D7 gibi.
// Digital pins for Deneyap Card use should be marked with D. EX: 7 -> D7 etc.
const int RPWM_1 = 7;
const int LPWM_1 = 8;
const int RPWM_2 = 12;
const int LPWM_2 = 13;

void setup() {
  Serial.begin(115200);
  pinMode(RPWM_1, OUTPUT);
  pinMode(LPWM_1, OUTPUT);
  pinMode(RPWM_2, OUTPUT);
  pinMode(LPWM_2, OUTPUT);
}

void loop() {
  /*
  Joystick verisi 1000-2000 aralığına göre ayarlıdır. Eğer sizin elinizdeki
  veri başka bir aralıkta ise ayar yapmanız gerekebilir. Tek tek ayarlamadan önce
  test etmek isterseniz aşağıdaki kodu yorum satırından çıkartıp kendi aralığınızı
  belirtilen kısma girerek test edebilirsiniz.

  Joystick data is set to the range of 1000-2000. If you have If the data is in
  another range, you may need to make adjustments. Before adjusting one by one
  If you want to test it, remove the code below from the comment line and create
  your own range. You can test it by entering the specified section.
  */

  // joy_x = map(joy_x, 1000, 2000, BASLANGIC_DEGERI, BITIS_DEGERI);
  // joy_y = map(joy_y, 1000, 2000, BASLANGIC_DEGERI, BITIS_DEGERI);
  
  
  if (joy_y > 1400 & joy_y < 1600 & joy_x > 1400 & joy_x < 1600) {
    // DUR
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, 0);
  } else if (joy_y > 1600 & joy_x > 1400 & joy_x < 1600) {
    // ILERI
    sp = map(joy_y, 1600, 2000, 100, 255);
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, sp);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, sp);
  } else if (joy_y < 1400 & joy_x > 1400 & joy_x < 1600) {
    // GERI
    sp = map(joy_y, 1400, 1000, 100, 255);
    analogWrite(RPWM_1, sp);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, sp);
    analogWrite(LPWM_2, 0);
  } else if (joy_y > 1400 & joy_y < 1600 & joy_x < 1400) {
    // SOL
    sp = map(joy_x, 1400, 1000, 100, 255);
    analogWrite(RPWM_1, sp);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, sp);
  } else if (joy_y > 1400 & joy_y < 1600 & joy_x > 1600) {
    // SAG
    sp = map(joy_x, 1600, 2000, 100, 255);
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, sp);
    analogWrite(RPWM_2, sp);
    analogWrite(LPWM_2, 0);
  } else if (joy_y > 1600 & joy_y < 2001 & joy_x < 1400 & joy_x > 999) {
    // SOL ILERI
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, 255);
  } else if (joy_y > 1600 & joy_y < 2001 & joy_x > 1600 & joy_x < 2001) {
    // SAG ILERI
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, 255);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, 0);
  } else if (joy_y < 1400 & joy_y > 999 & joy_x < 1400 & joy_x > 999) {
    // SOL GERI
    analogWrite(RPWM_1, 0);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, 255);
    analogWrite(LPWM_2, 0);
  } else if (joy_y < 1400 & joy_y > 999 & joy_x > 1600 & joy_x < 2001) {
    // SAG GERI
    analogWrite(RPWM_1, 255);
    analogWrite(LPWM_1, 0);
    analogWrite(RPWM_2, 0);
    analogWrite(LPWM_2, 0);
  }
}
