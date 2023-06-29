 #include <SoftwareSerial.h>
 int x_initial;
 int y_initial;
 int x;
 int y;
 int pin_x= 9;
void setup() {
  Serial.begin(9600);  
 
  pinMode(pin_x,OUTPUT);
  

}
int m=0;
int power_x=0;
void loop() {
  if (Serial.available()) {
    // Read the incoming data from Python
    String data = Serial.readStringUntil('\n');
    
    // Parse the coordinates
    int commaIndex = data.indexOf(',');
    if (commaIndex != -1) {
      String xStr = data.substring(0, commaIndex);
      String yStr = data.substring(commaIndex + 1);
      
       x = xStr.toInt();
       y = yStr.toInt();
      
      // Use the coordinates as desired
      // Example: Print the coordinates
      Serial.print("X=");
      Serial.print(x);
      Serial.print(", Y=");
      Serial.println(y);
     
    }
    if(m==0){
      x_initial=x;
      y_initial=y;
      m++;
    } 
    if(x - x_initial >=5){
      
         String data = Serial.readStringUntil('\n');
       // Parse the coordinates
       int commaIndex = data.indexOf(',');
       if (commaIndex != -1) {
         String xStr = data.substring(0, commaIndex);
      
         int x = xStr.toInt();
         }
         power_x=power_x+10;
         analogWrite(pin_x,power_x);
        delay(1000);
       Serial.print("output=");
      Serial.print(power_x);
      }
    
    

    if(x - x_initial <= -5){
    
         String data = Serial.readStringUntil('\n');
       // Parse the coordinates
       int commaIndex = data.indexOf(',');
       if (commaIndex != -1) {
         String xStr = data.substring(0, commaIndex);
      
         int x = xStr.toInt();
         }
         power_x=power_x-10;
         analogWrite(pin_x,power_x);
         
      }
      delay(10);
    
  
  
  
  }
}
