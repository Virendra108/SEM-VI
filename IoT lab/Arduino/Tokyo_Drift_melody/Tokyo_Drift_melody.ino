#define BUZZER_PIN 9  // Connect buzzer to pin 9

// Define musical notes (frequency in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

// Twinkle Twinkle Little Star melody
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,
  4, 4, 4, 4, 4, 4, 2
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 14; i++) {
    int noteDuration = 1000 / noteDurations[i];  // Calculate duration
    tone(BUZZER_PIN, melody[i], noteDuration);   // Play note
    delay(noteDuration * 1.3);  // Delay between notes
  }
  delay(2000);  // Pause before repeating melody
}