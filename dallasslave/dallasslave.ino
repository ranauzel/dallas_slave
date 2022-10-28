#include <Wire.h> // Wire kütüphanemizi projemize dahil ediyoruz

String  endChar = String(char(0xff)) + String(char(0xff)) + String(char(0xff));

/*int motor1=5;
int motor2=6;
int onsagled=13;
int onsolled=12;*/

int deger=255;
int state="0";
int buzzer=7; 
int gosterge;
byte alinan[2]; // Alınan veriyi hafızada tutmak için 2 indisli dizemiz 
byte alinan1[2];
byte alinan2[2];
byte akim[2];
byte hiz[2];


void setup() {
  Wire.begin(); // Wire haberleşmeyi Master olarak başlat
  Serial.begin(9600); // Seri haberleşmeyi 9600 baud rate ile başlat
  Serial2.begin(9600); // Seri haberleşmeyi 9600 baud rate ile başlat

  //pinMode(motor1, OUTPUT);
  //pinMode(motor2, OUTPUT);
 // pinMode(onsagled, OUTPUT);
  //pinMode(onsolled, OUTPUT);
}
 
void loop() {
  /*Wire.requestFrom(1,2); // 1 numaralı slave cihaza 2 byte okuma isteği gönder.Sıcaklık verisini okur.
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
    word sonuc = word(alinan[0], alinan[1]); // okunan 2 byte veriyi bir word veriye dönüştür
    Serial.print("Sicaklik : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.println(sonuc); // sonucu seri porta yaz
    delay(1000); // 1 saniye bekle

      if(sonuc>60){ //gelen veri 60'dan büyükse
    digitalWrite(buzzer,HIGH);
    Serial.print("MOTOR SICAKLIGI KRiTiK");
  }
  else{ //değilse
    digitalWrite(buzzer,LOW);
    Serial.print("            ");
  }
  delay(100);

    Serial.print("Max.val="); //nextion ekran motor sıcaklığı progress bar kodları
    Serial.println(sonuc);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  } 
  
  Wire.requestFrom(2,2); // 1 numaralı slave cihaza 2 byte okuma isteği gönder.Şarj verisini okur.
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen1 = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen1; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan1[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
    word sonuc1 = word(alinan1[0], alinan1[1]); // okunan 2 byte veriyi bir word veriye dönüştür
    Wire.beginTransmission(6); // 6 numaralı aktarma başlat
    Wire.write(sonuc1); // sonuc verisini aktar
    Wire.endTransmission(); // Altarmayı tamamla
    delay(1000);
    Serial.print("Şarj Yüzdesi : ");  // Seri porta Okunan yaz aynı satırdan devam et
    Serial.println(sonuc1); //şarj değerini seri porta yazdır.
    delay(1000); // 1 saniye bekle
    
    if(sonuc1<=20) {
   
    Serial.println("Sarj Seviyesi Az");
    digitalWrite(buzzer,HIGH);
    delay(100);
    digitalWrite(buzzer,LOW);
    delay(10);
     }

    Serial.print("Full.val=");   //nextion ekran şarj progress bar kodları
    Serial.println(sonuc1);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  } */
 
  Wire.requestFrom(3,2); // 1 numaralı slave cihaza 2 byte okuma isteği gönder.Pil sıcaklık verisini okur.
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen2 = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen2; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      alinan[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
    word sonuc2 = word(alinan[0], alinan[1]); // okunan 2 byte veriyi bir word veriye dönüştür
    ////Serial.print("Sicaklik : ");  // Seri porta Okunan yaz aynı satırdan devam et
   // Serial.println(sonuc2); // sonucu seri porta yaz
    delay(500); // 1 saniye bekle

  if (sonuc2>80)sonuc2=80;
  gosterge= map(abs(sonuc2),0,80,0,100);

    Serial.print("Hiz.txt=");
     //nextion ekran batarya sıcaklığı text kodları
    Serial.write(0x22);
    Serial.println(sonuc2);
    Serial.write(0x22);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    
    Serial.print("Full.val=");   //nextion ekran şarj progress bar kodları
    Serial.print(gosterge);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    
      if(sonuc2>60){ //gelen veri 60'dan büyükse
    digitalWrite(buzzer,HIGH);
    Serial.print("PİL SICAKLIGI KRiTiK");
    
   
  }
  else{ //değilse
    digitalWrite(buzzer,LOW);
    Serial.print("            ");
  }
  delay(100);
  
    Wire.beginTransmission(7); // 7 numaralı aktarma başlat
    Wire.write(sonuc2); // sonuc verisini aktar
    Wire.endTransmission(); // Altarmayı tamamla
    delay(1000); 
}
  
 /* Wire.requestFrom(4,2); // 1 numaralı slave cihaza 2 byte okuma isteği gönder.Pil akım / gerilim okur.
  
  if(Wire.available()){ // eğer gelen veri var ise
    int gelen3 = Wire.available();// Gelen byte sayısını gelen değişkenine aktar
    for(int i = 0; i<gelen3; i++){ // gelen byte sayısı kadar döngüyü devam ettir
      akim[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar
    }
    word sonuc3=word(akim[0],akim[1]);
    Wire.beginTransmission(6); // 6 numaralı aktarma başlat
    Wire.write(sonuc3); // sonuc verisini aktar
    Wire.endTransmission(); // Altarmayı tamamla
    delay(1000);
    Serial.print("Bataryadan geçen akım= " );
    Serial.println(sonuc3); //akım değerini seri porta yazdır.
    delay(1000);

    Serial.print("t1.txt="); //nextion ekran batarya akım text kodları
    Serial.write(0x22);
    Serial.println(sonuc3);
    Serial.write(0x22);
    Serial.write(0xff); 
    Serial.write(0xff);
    Serial.write(0xff);
  }
  Wire.requestFrom(5,2); // 1 numaralı slave cihaza 2 byte okuma isteği gönder.Hız verisini okur.
  
  if(Wire.available()){ // eğer gelen veri var ise;
  int gelen4 =Wire.available(); // Gelen byte sayısını gelen değişkenine aktar.
  for(int i=0; i<gelen4; i++){ // gelen byte sayısı kadar döngüyü devam ettir.
      hiz[i] = Wire.read(); // her döngüde 1 byte oku ve alinan dizisine aktar.
}
  word sonuc4=word(hiz[0], hiz[1]);
  Wire.beginTransmission(8); // 6 numaralı aktarma başlat
  Wire.write(sonuc4); // sonuc verisini aktar
  Wire.endTransmission(); // Altarmayı tamamla
  delay(1000);
  Serial.print("Arac Hizi km/h : ");
  Serial.println(sonuc4); //hız değerini seri porta yazdır.
  delay(1000); // 1 sn bekle

    Serial.print("hiz.val="); //nextion ekran gauge çubuğu kodları
    Serial.write(0x22);   
    Serial.println(sonuc4);
    Serial.write(0x22);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
    
  delay(100);
  
  }*/
}

/*void sinyal(){
  if(Serial.available()>0){
    state= Serial.read();
  }
  
  //sağ taraf
  if(state=="s") {
    Serial.println(state);
    digitalWrite(onsagled, HIGH);
    digitalWrite(onsolled, LOW);
    analogWrite(motor1, deger);
    analogWrite(motor2, 0);

  }
  // sol taraf
    Serial.println(state);
    digitalWrite(onsagled, LOW);
    digitalWrite(onsolled, HIGH);
    analogWrite(motor1, 0);
    analogWrite(motor2, deger);
}*/
