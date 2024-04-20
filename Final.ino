
// temperature
#include "DHT.h"
// variables
#define DHTPIN1 2
#define DHTPIN2 0
#define DHTTYPE DHT11
DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
// gas
int digitalsensor = 4;
int analogsensor = 35;

void setup() {
  pinMode(digitalsensor, INPUT);
  Serial.begin(9600);

  dht1.begin();
  dht2.begin();

}

void loop() {
  // Temperature
  delay(2000);
  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();
  float f1 = dht1.readTemperature(true);
  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();
  float f2 = dht2.readTemperature(true);

  if (isnan(h1) || isnan(t1) || isnan(f1)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif1 = dht1.computeHeatIndex(f1, h1);
  float hic1 = dht1.computeHeatIndex(t1, h1, false);

  if (isnan(h2) || isnan(t2) || isnan(f2)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  float hif2 = dht2.computeHeatIndex(f2, h2);
  float hic2 = dht2.computeHeatIndex(t2, h2, false);

  Serial.print("Humidity: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t1);
  Serial.print(" *C ");
  Serial.print(f1);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic1);
  Serial.print(" *C ");
  Serial.print(hif1);
  Serial.println(" *F");

  Serial.print("Humidity: ");
  Serial.print(h2);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t2);
  Serial.print(" *C ");
  Serial.print(f2);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic2);
  Serial.print(" *C ");
  Serial.print(hif2);
  Serial.println(" *F");

  int digital = digitalRead(digitalsensor);
  int analog = analogRead(analogsensor);

  Serial.print("Analog Value = ");
  Serial.print(analog);
  Serial.print("\t");
  Serial.print("Digital Value ");
  Serial.print(digital);
  Serial.println("\n");

}
