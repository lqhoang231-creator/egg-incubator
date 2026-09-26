#define pin 4
unsigned long preMillis = 0;
int Read;
unsigned long prereset = 0;

void setup() {

  Serial.begin(115200);
  pinMode(pin, INPUT_PULLUP);
  Serial.println("........");
}

void loop() {
  unsigned long Millis = millis();
  Read = digitalRead(pin);
  if(Read == LOW){
    if(Millis - preMillis >= 50){
      preMillis = Millis;
      if(Read == LOW){
        unsigned long millisreset = millis();
        if(millisreset - prereset >=3000){
          prereset = millisreset;
          Serial.println("reset");
        }
        else {
          Serial.println("mode changed");
        }
      }
    }
  }

}
