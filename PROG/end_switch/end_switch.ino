void setup() {
  Serial.begin(9600);
    Serial.print("test");
    pinMode(13, OUTPUT);
    pinMode(37, INPUT);
    pinMode(38, INPUT);
    pinMode(39, INPUT);
    pinMode(A21, INPUT);
    pinMode(A22, INPUT);

  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  Serial.print("37 -> ");
  Serial.println(digitalRead(37));
    Serial.print("38 -> ");
  Serial.println(digitalRead(38));
    Serial.print("39 -> ");
  Serial.println(digitalRead(A22));
  // put your main code here, to run repeatedly:

}
