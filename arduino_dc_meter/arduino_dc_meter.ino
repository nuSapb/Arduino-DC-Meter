/*
  DC Voltmeter
  Arduino UNO R3 based on voltage divider
  Anu S.
*/
#define VREF  5.0  //voltage on REF

int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // resistance of R1 (100K)
float R2 = 20000.0; // resistance of R2 (20K)
int value = 0;
void setup() {
  pinMode(analogInput, INPUT);
  Serial.begin(115200);
}
void loop() {
  // read the value at analog input
  value = analogRead(analogInput);
  vout = (value * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));
  if (vin < 0.09) {
    vin = 0.0; //statement to quash undesired reading !
  }
  Serial.print("INPUT V= ");
  Serial.println(vin);
  delay(1000);

}
