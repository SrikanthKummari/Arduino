#define LM35 A0
#define unsigned int u32

u32 pre_time = 0; 		// Variable to store the previous time
u32 cur_time = 0;  		// Variable to store the current time
u32 ela_time = 0; 		// Variable to store the elapsed time

// my own delay function
void my_delay(u32 inter_val)
{
  pre_time = millis(); // Get the current time
  
  while (true) {
    cur_time = millis(); // Get the current time
    ela_time = cur_time - pre_time; // Calculate the elapsed time
    
    if (ela_time >= inter_val) { // Check if the elapsed time is greater than or equal to the interval
      break; 
    } 
  }
}


void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

/*void delay_ms(u32 milli_sec){
	u32 t0pr,t0pc,t0tc,t0tcr;
  		t0pr=(16*1000)-1;
  		t0tc=0;
  		t0tcr=1;
  while(1)
  {
    t0tcr = 0;
    t0tc++;
    
    if(t0tc == milli_sec)
      break;
} 
}
*/

void loop() {
  // Read analog value from LM35 temperature sensor
  float lmValue = analogRead(LM35);
  
  // Convert analog value to temperature in Celsius
  float temperature = (lmValue * 3.3) / 1023 * 100; // LM35 sensor output is in mV per degree Celsius

  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Control LED based on temperature
  if (temperature < 30) {
    // If temperature is below 30°C, blink LED every 250ms
    digitalWrite(LED_BUILTIN, HIGH);
    my_delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    my_delay(250);
  } 
     else {
    // If temperature is 30°C or above, blink LED every 500ms
    digitalWrite(LED_BUILTIN, HIGH);
    my_delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    my_delay(500);
  }
}
 