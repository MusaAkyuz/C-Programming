#define RCPin 2
int value;

void setup() {
  Serial.begin(9600);
  pinMode(RCPin, INPUT);
}

void loop() {
  value = pulseIn(RCPin, HIGH);
  Serial.println(value);
}
