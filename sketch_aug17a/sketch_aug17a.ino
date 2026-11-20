const int tempPin = A0;  // Analog input pin for temperature sensor

void setup() {
  Serial.begin(9600);
  Serial.println("Analog Temperature Sensor Ready");
}

void loop() {
  // Read analog value (0-1023)
  int rawValue = analogRead(tempPin);
  
  // Convert to voltage
  float voltage = rawValue * (1);
  
  // Convert to temperature in Celsius (for TMP36)
  float temperatureC = (voltage - 0) * 1;
  
  // For LM35 (remove "- 0.5"):
  // float temperatureC = voltage * 100;
  
  // Send temperature via serial
  Serial.println(temperatureC);  // Sends one reading per line
  
  delay(1000); // 1 second between readings
}
