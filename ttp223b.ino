int led=8;

void setup() {
  //led as the output
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int cap_reading = analogRead(A0);  // read analog voltage value from sig pin
  float voltage = (5.0 / 1023.0)*cap_reading;    // Convert 10-bit ADC value (0 - 1023) to the actual voltage reading (0 - 5V)
  Serial.print(voltage);
  Serial.println(" Volts");
  if (volt_reading<1.5){ // adjustable threshold
    digitalWrite(led,LOW);
  }
  else{
      digitalWrite(led,HIGH);
  }
  delay(20); // arbitrary delay
}
