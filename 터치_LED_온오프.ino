#include <CapacitiveSensor.h>
CapacitiveSensor cs_6_7 = CapacitiveSensor(6, 7);

int led = 11;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  CSread();

}

void CSread() {
  unsigned long cs = cs_6_7.capacitiveSensor(50);
  cs_6_7.set_CS_AutocaL_Millis(50);
  cs_6_7.set_CS_Timeout_Millis(50);


  Serial.print("CDS = ");
  Serial.println(cs);


  //if(cs > 500){
  //analogWrite(led, 70);
  //}

  //if(cs < 1){
  //analogWrite(led, 0);
  //}



  //if(cs < 1)
  //{
  //if(analogRead(led) == 0)
  //analogWrite(led, 70);

  //if(analogRead(led) == 70)
  //analogWrite(led, 0);
  //}

  //아날로그 값으로는 실패

  if (cs < 1)
  {
    if (digitalRead(led) == 0)
      digitalWrite(led, HIGH);

    else if (digitalRead(led) == 1)
      digitalWrite(led, LOW);
  }

  delay(1000);

  //delay를 1000 이하로 하면 반응이 빨라져서
  //인간기준 터치가 불가하다.


}
