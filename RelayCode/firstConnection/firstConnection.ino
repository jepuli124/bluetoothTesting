#include "BluetoothSerial.h"  // Include the Bluetooth Serial library

BluetoothSerial SerialBT;  // Create a Bluetooth Serial object

// Define relay pins
#define RELAY1_PIN 2
#define RELAY2_PIN 4
#define RELAY3_PIN 16
#define RELAY4_PIN 17
#define RELAY5_PIN 18
#define RELAY6_PIN 19
#define RELAY7_PIN 21
#define RELAY8_PIN 22

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);
  
  // Initialize Bluetooth Serial
  SerialBT.begin("LilyGO_T_Relay_8");  // Set the Bluetooth device name
  Serial.println("Bluetooth is ready. Waiting for connections...");

  // Set relay pins as OUTPUT
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);
  pinMode(RELAY5_PIN, OUTPUT);
  pinMode(RELAY6_PIN, OUTPUT);
  pinMode(RELAY7_PIN, OUTPUT);
  pinMode(RELAY8_PIN, OUTPUT);

  // Turn off all relays initially
  digitalWrite(RELAY1_PIN, LOW);
  digitalWrite(RELAY2_PIN, LOW);
  digitalWrite(RELAY3_PIN, LOW);
  digitalWrite(RELAY4_PIN, LOW);
  digitalWrite(RELAY5_PIN, LOW);
  digitalWrite(RELAY6_PIN, LOW);
  digitalWrite(RELAY7_PIN, LOW);
  digitalWrite(RELAY8_PIN, LOW);
}

void loop() {
  // Check if data is available from Bluetooth
  if (SerialBT.available()) {
    String command = SerialBT.readString();  // Read the incoming command
    Serial.println("Received: " + command);  // Print it for debugging

    // Control Relay 1
    if (command == "ON1") {
      digitalWrite(RELAY1_PIN, HIGH);
      Serial.println("Relay 1 turned ON");
    } else if (command == "OFF1") {
      digitalWrite(RELAY1_PIN, LOW);
      Serial.println("Relay 1 turned OFF");
    }
    
    // Control Relay 2
    else if (command == "ON2") {
      digitalWrite(RELAY2_PIN, HIGH);
      Serial.println("Relay 2 turned ON");
    } else if (command == "OFF2") {
      digitalWrite(RELAY2_PIN, LOW);
      Serial.println("Relay 2 turned OFF");
    }

    // Add similar blocks for Relay 3 to Relay 8
  }
}
