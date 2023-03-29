#define COIN 19  // coin
#define money 5  // หยอดเหรียญแล้วให้ขึ้นกี่บาท 1บาท = 60วิ (วินาทีเริ่มต้น 60 ลง 0 ไป -1 คือ 1บาท)

int x_money = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(COIN, INPUT_PULLUP);  // คุม ที่หยอดเหรียญ
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!digitalRead(COIN)) {
    if (readCoin()) {
      x_money += money;
    }
  }
}

bool readCoin() {
  long duration = millis();
  while (!digitalRead(COIN)) {
    delay(2);
  }
  if (millis() - duration >= 20) {
    return true;
  } else
    return false;
}
