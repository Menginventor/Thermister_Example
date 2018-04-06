/*
Thermistor Read Example code
by Dhamdhawach Horsuwan 7/4/2018 Bangkok , Thailand .
*/

/*
  Note : data for 104GT-2 , glass bead NTC thermistor.
  Rated zero-power resistance value at 25°C = 100.0kΩ±3%
  B value = 4267K±2%
  from http://www.atcsemitec.co.uk/gt-2-glass-thermistors.html
*/
/*
  Thermistor equation
  T = 1/( (1/T_0 ) + (1/B)*ln(R/R_0)) 
  T : reading temp (Kelvin)
  R : reading resistant (Ohm)
  T_0 : Thermister base temp (Kelvin)
  R_0 : Thermister base resistant at base temp
  B : Thermister Beta value
  from
  https://learn.adafruit.com/thermistor/using-a-thermistor
*/
#define THERMISTOR_PIN A3
#define THERMISTOR_SR_VAL 100000.0//serie resistor value
#define THERMISTOR_NT_VAL 100000.0 // normal resistant  @ temp 25 °C
#define THERMISTOR_B_VAL 4267.0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc_val = analogRead(THERMISTOR_PIN);//You can change this to another pin
  float voltage = float(adc_val) * 5.0 / 1023.0;
  
  float resistant = (THERMISTOR_SR_VAL * (5.0 - voltage)) / voltage;
  float temp_K  = 1.0/( (1.0/(25+273.15)) + (1.0/THERMISTOR_B_VAL)*log(resistant/THERMISTOR_NT_VAL)) ;
  float temp_C = temp_K-273.15;
  /*
  Serial.print("adc_val = ");
  Serial.println(adc_val);
  Serial.print("voltage = ");
  Serial.println(voltage);
  Serial.print("resistant = ");
  Serial.println(resistant);
  */
  Serial.print("Temp (°C)  = ");
  Serial.println(temp_C,3);
  delay(50);
}

