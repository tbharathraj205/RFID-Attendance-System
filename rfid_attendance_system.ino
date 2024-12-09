#include <SPI.h>
#include <MFRC522.h>

// RFID setup
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// Buzzer pin
#define BUZZER_PIN 8

// Database arrays
String knownUIDs[] = {"DEADBEEF", "ABCD1234"};  // Array of known UIDs (RFID tags)
String loggedUIDs[10];  // Array to store UIDs of those who have checked in (max 10 for simplicity)
String timestamps[10];  // Array to store timestamps for each logged UID
int numLoggedUIDs = 0;  // Number of logged UIDs

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  SPI.begin();         // Init SPI bus
  rfid.PCD_Init();     // Init MFRC522

  // Initialize buzzer
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);  // Buzzer off initially

  Serial.println("Place your card on the reader...");
  Serial.println("Attendance Log:");
}

void loop() {
  // Look for new cards
  if (!rfid.PICC_IsNewCardPresent())
    return;

  // Select one of the cards
  if (!rfid.PICC_ReadCardSerial())
    return;

  // Get UID of the scanned card
  String uidStr = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uidStr += String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    uidStr += String(rfid.uid.uidByte[i], HEX);
  }
  uidStr.toUpperCase();
  
  // Check if UID has already been logged
  if (!isUIDLogged(uidStr)) {
    // Log new UID and mark attendance
    loggedUIDs[numLoggedUIDs] = uidStr;
    timestamps[numLoggedUIDs] = getTimestamp();
    numLoggedUIDs++;

    // Display on serial monitor
    Serial.print("New Entry: ");
    Serial.println(uidStr);
    Serial.print("Timestamp: ");
    Serial.println(timestamps[numLoggedUIDs - 1]);
    Serial.println("Attendance marked.");

    // Activate buzzer to confirm card read
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1500);  // Buzzer sound duration
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    // UID already logged, skipping
    Serial.print("Already marked attendance for: ");
    Serial.println(uidStr);
  }

  delay(2000);  // Delay before allowing next scan
}

// Function to check if UID has already been logged
bool isUIDLogged(String uid) {
  for (int i = 0; i < numLoggedUIDs; i++) {
    if (loggedUIDs[i] == uid) {
      return true;      
    }
  }
  return false;
}

// Function to simulate a timestamp (you can add a real-time clock module for actual time)
String getTimestamp() {
  unsigned long time = millis();  // Simulate time using milliseconds since the program started
  int seconds = time / 1000;
  int minutes = seconds / 60;
  int hours = minutes / 60;
  return String(hours) + ":" + String(minutes % 60) + ":" + String(seconds % 60);
}
