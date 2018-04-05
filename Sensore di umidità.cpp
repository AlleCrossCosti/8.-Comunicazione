#include <DHT.h>

// Pin a cui è connesso il sensore
#define DHTPIN 2
// Modello di sensore
#define DHTTYPE DHT11

DHT dht (DHTPIN, DHTTYPE);

void setup () {
    Serial.begin (9600);
    // Il sensore è acceso
    dht.begin () ;

    // Pausa per attendere che il sensore "vada a regime"
    delay (2000);
 }
 void loop ()  {
     float umidita  = dht.readHumidity ();
     float temperatura =  dht.readTemperature ();

     // Si controlla che i due valori siano validi
     if (isnan (umidita) || isnan (temperatura))  {
         Serial.print ("Lettura˽del˽sensore˽fallita");
         return; // Interrompe il loop e lo ricomincia

  }
  Serial.print ("Umidità:˽");
  Serial.print (umidita);
  Serial.print ("%˽˽˽");
  Serial.print ("Temperatura:˽");
  Serial.print (temperatura);
  Serial.print ("˽°C˽");
  Serial.println ();

  // Pausa fra una misura e l'altra
  delay (1000);

   }         