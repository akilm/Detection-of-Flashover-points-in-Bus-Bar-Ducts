float val1=0,val2=0,val3=0,his1=0,his2=0,his3=0,i=0,v_flag1=0,v_flag2=0,v_flag3=0;
float x=0,d=0,r=50;
float max1=0,min1=1023,max2=0,min2=1023,max3=0,min3=1023;
float a1=0,a2=0,a3=0;
char a='0';
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
/*function which calculates the approximate distance from the sensor module*/
float distance(float d1,float d2)
{
  x = r/(1+(d1/d2));                            
  return x;  
}
void loop() 
{  while( i<1000 )
  {
    val1 = analogRead(A3);
    val2 = analogRead(A1);
    val3 = analogRead(A2);

    min1=min(val1,min1);
    max1=max(val1,max1);

    min2=min(val2,min2);
    max2=max(val2,max2);

    min3=min(val3,min3);
    max3=max(val3,max3);
    
    i++;
  }
  i=0;
 
 
  
    
    a1=max1-min1;
    a2=max2-min2;
    a3=max3-min3;

   
    max1=max2=max3=0;
    min1=min2=min3=1023;

        
   if(a2>a3 && a2>a1)
   {  if(a1>a3)
         { 
          Serial.println("flashover occured between points 1 and 2");
          d=distance(a1,a2);
          Serial.println("approximate flashover distance from point 1 (cm):  ");
          Serial.println(d);
         }
      if(a3>a1)
        { 
          Serial.println("flashover occured between points 2 and 3");
          d=distance(a2,a3);
          Serial.println("approximate flashover distance from point 2 (cm):  ");
          Serial.println(d);
         }
      
   }
   else
   if(a1>a2 && a1>a3)
   {      
          Serial.println("flashover occured between points 1 and 2");
          d=distance(a1,a2);
          Serial.println("approximate flashover distance from point 1 (cm):  ");
          Serial.println(d);
   
   }
   else
   if(a3>a2 && a3>a1)
   {      
          Serial.println("flashover occured between points 2 and 3");
          d=distance(a2,a3);
          Serial.println("approximate flashover distance from point 2 (cm):  ");
          Serial.println(d);
   }
   
 
  }
 
   
