#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Serial.println("MLX90614 Temperature Sensor Test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX90614 sensor. Check wiring.");
    while (1);
  }
}

void loop() {
  double ambientTemp = mlx.readAmbientTempC();
  double objectTemp = mlx.readObjectTempC();

  Serial.print("Ambient Temp: ");
  Serial.print(ambientTemp);
  Serial.print(" °C, Object Temp: ");
  Serial.print(objectTemp);
  Serial.println(" °C");

  delay(2000);  // Wait 2 seconds before next reading
}
