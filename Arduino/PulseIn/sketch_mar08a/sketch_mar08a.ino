#define Ch1 1
#define Ch2 2
#define Ch3 3
#define Ch4 7

volatile long startTimeCh1 = 0;
volatile long currentTimeCh1 = 0;
volatile long PulseCh1 = 0;
int pulseWidthCh1 = 0;

volatile long startTimeCh2 = 0;
volatile long currentTimeCh2 = 0;
volatile long PulseCh2 = 0;
int pulseWidthCh2 = 0;

volatile long startTimeCh3 = 0;
volatile long currentTimeCh3 = 0;
volatile long PulseCh3 = 0;
int pulseWidthCh3 = 0;

volatile long startTimeCh4 = 0;
volatile long currentTimeCh4 = 0;
volatile long PulseCh4 = 0;
int pulseWidthCh4 = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(Ch1, INPUT_PULLUP);
  pinMode(Ch2, INPUT_PULLUP);
  pinMode(Ch3, INPUT_PULLUP);
  pinMode(Ch4, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(Ch1), PulseCalculatorCh1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Ch2), PulseCalculatorCh2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Ch3), PulseCalculatorCh3, CHANGE);
  attachInterrupt(digitalPinToInterrupt(Ch4), PulseCalculatorCh4, CHANGE);
}

void loop() {
  if(PulseCh1 < 2000)
  {
    pulseWidthCh1 = PulseCh1;
  }
  if(PulseCh2 < 2000)
  {
    pulseWidthCh2 = PulseCh2;
  }
  if(PulseCh3 < 2000)
  {
    pulseWidthCh3 = PulseCh3;
  }
  if(PulseCh4 < 2000)
  {
    pulseWidthCh4 = PulseCh4;
  }

  Serial.print(pulseWidthCh1);
  Serial.print("    ");
  Serial.print(pulseWidthCh2);
  Serial.print("    ");
  Serial.print(pulseWidthCh3);
  Serial.print("    ");
  Serial.print(pulseWidthCh4);
  Serial.println();
}

void PulseCalculatorCh1()
{
  currentTimeCh1 = micros();
  if(currentTimeCh1 > startTimeCh1)
  {
    PulseCh1 = currentTimeCh1 - startTimeCh1;
    startTimeCh1 = currentTimeCh1;
  }
}

void PulseCalculatorCh2()
{
  currentTimeCh2 = micros();
  if(currentTimeCh2 > startTimeCh2)
  {
    PulseCh2 = currentTimeCh2 - startTimeCh2;
    startTimeCh2 = currentTimeCh2;
  }
}
void PulseCalculatorCh3()
{
  currentTimeCh3 = micros();
  if(currentTimeCh3 > startTimeCh3)
  {
    PulseCh3 = currentTimeCh3 - startTimeCh3;
    startTimeCh3 = currentTimeCh3;
  }
}
void PulseCalculatorCh4()
{
  currentTimeCh4 = micros();
  if(currentTimeCh4 > startTimeCh4)
  {
    PulseCh4 = currentTimeCh4 - startTimeCh4;
    startTimeCh4 = currentTimeCh4;
  }
}
