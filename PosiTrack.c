int forceSensorPin = A0; 
int tempSensorPin = A1;

int irSensorLeftPin = 2; // Sol IR 
int irSensorRightPin = 3; // Sağ IR 

int trigPin = 5; // Ultrasonik sensör Trig
int echoPin = 4; // Ultrasonik sensör Echo

int flexSensorPin = A2; // Esneklik sensörü

int buzzerPin = 9;

int redLEDPin = 13; // RGB LED'in kırmızı
int greenLEDPin = 11; // RGB LED'in yeşil
int blueLEDPin = 12; // RGB LED'in mavi

long duration; // süre 
int distance; // mesafe

void setup() {
  pinMode(forceSensorPin, INPUT);
  pinMode(tempSensorPin, INPUT);
  pinMode(irSensorLeftPin, INPUT);
  pinMode(irSensorRightPin, INPUT);
  pinMode(flexSensorPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tone(buzzerPin, 150, 100);
  delay(500);
  tone(buzzerPin, 200, 100);
  delay(500);
  tone(buzzerPin, 200, 100);
  delay(500);
  
  int forceValue = analogRead(forceSensorPin); // Kuvvet sensörü değeri
  int tempValue = analogRead(tempSensorPin); // Sıcaklık sensörü değeri
  int irLeftValue = digitalRead(irSensorLeftPin); // IR sol 1-0
  int irRightValue = digitalRead(irSensorRightPin); // IR sağ 1-0
  int flexValue = analogRead(flexSensorPin); // Esneklik sensörü değeri

  // Ultrasonik sensör ile mesafe ölçümü
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  bool irDetected = (irLeftValue == LOW || irRightValue == LOW); // ir ilk değerleri false ayarla
  bool seated = (forceValue > 300) || (tempValue > 25) && irDetected; // oturuyor mu
  bool correctPosture = (flexValue > 995); // Esneklik ve mesafe kontrolü

  // Seri monitöre sensör değerlerini yazdır
  Serial.print("Kuvvet Sensoru (N): "); Serial.println(map(forceValue, 0, 358, 0, 10));
  Serial.print("Sıcaklık Sensoru (C): "); Serial.println(map(tempValue, 20, 358, -40, 125));
  Serial.print("IR Sol Sensor: "); Serial.println(irLeftValue);
  Serial.print("IR Sag Sensor: "); Serial.println(irRightValue);
  Serial.print("Esneklik Sensoru: "); Serial.println(flexValue);
  Serial.print("Mesafe (cm): "); Serial.println(distance);
  Serial.print("Oturma Durumu: "); Serial.println(seated ? "Oturuyor" : "Oturmuyor");
  Serial.print("Dogru Pozisyon: "); Serial.println(correctPosture ? "Evet" : "Hayir");
  Serial.println("-----");

  if (seated) {
    setColor(0, 0, 255); // Mavi
    delay(30000); // 30 saniye bekle

    setColor(128, 0, 128); // Mor
    delay(30000); // 30 saniye bekle

    setColor(255, 0, 0); // Kırmızı
    tone(buzzerPin, 150, 100);
    delay(500);
    tone(buzzerPin, 200, 100);
    delay(500);
    tone(buzzerPin, 200, 100);
    delay(500);
  } else {
    setColor(0, 255, 0); // Kullanıcı kalktığında LED yeşil olur
  }

  if (!correctPosture) {
    tone(buzzerPin, 150, 100);
    delay(500);
    tone(buzzerPin, 200, 100);
    delay(500);
    tone(buzzerPin, 200, 100);
    delay(500); 
  }

  // 10 saniyede bir sensör değerlerini yazdırma
  delay(10000);
}

void setColor(int red, int green, int blue) {
  analogWrite(redLEDPin, red);
  analogWrite(greenLEDPin, green);
  analogWrite(blueLEDPin, blue);
}
