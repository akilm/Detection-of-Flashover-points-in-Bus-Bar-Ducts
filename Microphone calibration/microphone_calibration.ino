int val1,val2,val3,
float k1=1,k2=1,k3=1;
void setup() 
{  
  Serial.begin(9600);
  
  /*power supply for the Microphone sensor modules*/
  
  pinMode(6,OUTPUT);
  digitalWrite(6,HIGH);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  
}

void loop() 
{  
  /*monitor the values of all the sensors in the serial plotter in arduino IDE*/
  for(i<1000)
   {  
      val1 = k1*analogRead(A0);
      val2 = k2*analogRead(A1);
      val3 = k3*analogRead(A2);
      Serial.print(val1);
      Serial.print(",");
      Serial.print(val2);
      Serial.print(",");
      Serial.println(val3);
      i++;
   }

  /*monitor these values in a noiseless environment and tweak the values of k1,k2 and k3 and also
   * the gain of the microphone continuously till all the three lines nearly coincide. the value of 
   * k1,k2 and k3 can be varied in steps of 0.1 ex. try adjusting in terms of 1.1,1.2...or 0.9,0.8...
   * in addition to turning the knob of the microphone sensor gain.
   */
   
}
 
   
