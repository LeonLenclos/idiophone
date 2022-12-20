const int SOLENOID_PIN[4] =  {9,10,11,12};
const int PIEZZO_PIN = A0;
const int SOLENOID_DELAY = 80; //ms

const int BOUNCE_DELAY = 10; //ms
const int KEYS_PINS[4] = {0, 1, 2, 3};
  
void setup() { 
  
    for (int i = 0; i < 4; i++) {
    pinMode(KEYS_PINS[i], INPUT_PULLUP);
    pinMode(SOLENOID_PIN[i], OUTPUT); 
  }    
  Serial.begin(9600);    
}

void hit(int i){
  digitalWrite(SOLENOID_PIN[i], HIGH);
  delay(SOLENOID_DELAY);
  digitalWrite(SOLENOID_PIN[i], LOW);
  


}

// Renvoie l'index du premier piezzo frappé
int readKeys(){
  while(true){
    for (int i = 0; i < 4; i++) {
      int state = digitalRead(KEYS_PINS[i]);
      if(state == LOW){
        return i;
      }
    }
  }
}


void loop()
{
  //int hittedKey = readKeys();
  //Serial.println('key: ' + hittedKey);
  for (int i = 0; i < 4; i++) {
    hit(i);
    delay(1000);
  }
}
