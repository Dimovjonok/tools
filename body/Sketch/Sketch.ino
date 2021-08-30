/*
Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru
Create: 28.08.2021
Release:
*/

#define _MODE_DEBUG


void setup() {
    Serial.begin(115200);
    Serial.println("Dmitry Lebedev (Dimovjonok) dmitrylebedev@mail.ru");
    Serial3.begin(115200);
}

void loop() {
    if (Serial3.available()) {
      int c = Serial3.read();
      Serial.write(c);
    }

    if (Serial.available()) {
      int c = Serial.read();
      Serial3.write(c);
    }
}
