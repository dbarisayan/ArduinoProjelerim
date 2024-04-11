// Arduino UNO
// Kedi Evi projesi
// github.io/dbarisayan
// Uzay Akademi
// davutbarisayan@gmail.com


#include <DHT11.h>
#include <LiquidCrystal_I2C.h>

DHT11 dht11(8);
#define isiklar 7
#define sicaklikSicak 10
#define sicaklikSoguk 11

LiquidCrystal_I2C lcd(0x27,16,2);                 // LCD adresini 0x27 olarak satır sütun sayısını 16, satır sayısını 2 olarak ayarlıyoruz.

void setup() {
  Serial.begin(9600);
  lcd.init();                                     // LCD ekranı başlatıyoruz.
  pinMode(isiklar, OUTPUT);                       // 4'lü beyaz ışıklar
  pinMode(sicaklikSicak, OUTPUT);                 // Kırmızı ışık
  pinMode(sicaklikSoguk, OUTPUT);                 // Mavi ışık

}

void loop() {
  int sicaklik;                                   // Sıcaklık ve Nem
  int nem;                                        // değişkenlerini oluşturuyoruz.
  
  dht11.readTemperatureHumidity(sicaklik, nem);   // DHT11'in veri almasını sağlıyoruz, aldığımız veriler oluşturduğumuz değişkenlere eşitleniyor.
  lcd.backlight();                                // LCD ekranın aydınlatmasını açıyoruz.
  lcd.setCursor(0,0);                             // Ekrandaki imleci 1. Satır, 1. Sütuna alıyoruz.
  lcd.print("SICAKLIK: ");                        //
  lcd.print(sicaklik);                            // Ekranın üst satırına SICAKLIK: 25°C yazdık.
  lcd.print("°C");                                //
  lcd.setCursor(1,0);                             // Ekrandaki imleci 2. Satır, 1. Sütuna alıyoruz.
  lcd.print("NEM: %");                            //
  lcd.print(nem);                                 // Ekranın alt satırına NEM: %23 yazdık.
  
  if(sicaklik>20) {                               // Sıcaklığımız 20°C'den fazlaysa kırmızı ışık azsa mavi ışığı yakacak kodlar.
    digitalWrite(sicaklikSicak, HIGH);
    digitalWrite(sicaklikSoguk, LOW);
  }
  else {
    digitalWrite(sicaklikSicak, LOW);
    digitalWrite(sicaklikSoguk, HIGH);
  }

  delay(1000);
  lcd.clear();

  delay(100);
}
