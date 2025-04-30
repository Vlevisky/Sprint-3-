#include "HX711.h"
#include <ArduinoJson.h>

#define DT 7
#define SCK 6

HX711 scale;
float peso = 0;

void setup() {
  Serial.begin(9600);
  scale.begin(DT, SCK);
  scale.set_scale(420); 
  scale.tare();
}

void loop() {
  if (scale.is_ready()) {
    peso = scale.get_units(10);
    Serial.print("PESO:");
    Serial.println(peso, 2);

    if (peso > 1.0) {
      Serial.println("1"); // sinal para o Node-RED
    }
  } else {
    Serial.println("Balança não pronta");
  }

  if (Serial.available()) {
    char recebido = Serial.read();
    
   
    const char* nome = getNomeBalança(recebido);
    if (nome != "Nenhum") {
      StaticJsonDocument<100> doc;
      doc["nome"] = nome;
      doc["peso"] = peso;

      serializeJson(doc, Serial);
      Serial.println();
    }
  }

  delay(500);
}

const char* getNomeBalança(char codigo) {
  switch (codigo) {
    case '1': return "Dramin";
    case '2': return "Frontal";
    case '3': return "Rivotril";
    default: return "Nenhum";
  }
}
