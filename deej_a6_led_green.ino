// Linear brightness on the green LED (D6 PWM)
const int NUM_SLIDERS = 7;
const int analogInputs[NUM_SLIDERS] = {A0, A1, A2, A3, A4, A5, A6};
int analogSliderValues[NUM_SLIDERS];

const int LED_GREEN = 6; 

void setup() {
  
  for (int i = 0; i < NUM_SLIDERS; i++) {
    pinMode(analogInputs[i], INPUT);
  }
 
  pinMode(LED_GREEN, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  for (int i = 0; i < NUM_SLIDERS; i++) {
    analogSliderValues[i] = analogRead(analogInputs[i]);
  }


  for (int i = 0; i < NUM_SLIDERS; i++) {
    Serial.print(analogSliderValues[i]);
    if (i < NUM_SLIDERS - 1) Serial.print("|");
  }
  Serial.println();


  int raw   = analogSliderValues[6];
  int pwmV  = map(raw, 0, 1023, 0, 255);
  analogWrite(LED_GREEN, pwmV);

  delay(10);
}