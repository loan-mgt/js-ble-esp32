 #include <ArduinoBLE.h>

BLEService mainService("19B10000-E8F2-537E-4F6C-D104768A1214"); 


BLEByteCharacteristic characteristicRandNb("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
BLECharacteristic characteristicLed("77a57c66-3bc9-463a-bc52-1ee5763b9c0f", BLERead | BLEWrite, 2);


const int ledPin = LED_BUILTIN; 
uint8_t ble_value = 0x0;


void setup() {
  Serial.begin(9600);
  while (!Serial);


  pinMode(ledPin, OUTPUT);


  if (!BLE.begin()) {
    Serial.println("Le démarrage du module Bluetooth® Low Energy a échoué !");
    while (1);
  }

  // définit le nom local annoncé et l'UUID du service :
  BLE.setLocalName("ESP-BLE-N1");
  BLE.setAdvertisedService(mainService);

  // ajoute les caractéristiques au service
  mainService.addCharacteristic(characteristicRandNb);
  mainService.addCharacteristic(characteristicLed);
  


  // ajoute le service
  BLE.addService(mainService);



  // définit la valeur initiale des caractéristiques :
  characteristicRandNb.writeValue(0);
  characteristicLed.writeValue(0);

  BLE.advertise();

  Serial.println("Prêt");
}

void loop() {
  // écoute les périphériques Bluetooth® Low Energy se connecter :
  BLEDevice central = BLE.central();

  // si le central est connecté à un périphérique :
  if (central) {
    Serial.print("Connecté au central : ");
    // affiche l'adresse MAC de la centrale :
    Serial.println(central.address());

    // tant que le central est toujours connecté au périphérique :
    while (central.connected()) {
      
      if (characteristicLed.written()) {
         Serial.println("mise à jour");
        if (characteristicLed.value()[1] == 2) {  
          Serial.println("LED on");
          digitalWrite(ledPin, HIGH);        
        } else {                             
          Serial.println("LED off");
          digitalWrite(ledPin, LOW);         
        }
      }

        ble_value = random(0, 11);
        characteristicRandNb.writeValue(ble_value);
    }


    Serial.print(F("Centrale se déconnecte : "));
    Serial.println(central.address());
  }

  
  
  
}
