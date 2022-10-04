
// Interrupt information
// 0 on pin 2
// 1 on pin 3

#define encoderI 2
#define encoderQ 3
#define start_button 4 //pin used for button that makes start marker
#define master_button 5 //pin used for the master button
#define end_button 6 //pin used for the end button
// Only use one interrupt in this example

volatile int count;
int start_begin = 0;
void setup()
{
  Serial.begin(115200);
  count=0;
  pinMode(encoderI, INPUT);
  pinMode(encoderQ, INPUT);

  pinMode(master_button, INPUT);
  digitalWrite(master_button, HIGH);
  
  pinMode(start_button, INPUT); //setup for start button
  digitalWrite(start_button, HIGH);

  pinMode(end_button, INPUT);
  digitalWrite(end_button, HIGH);
  digitalWrite(13, LOW);
  
  attachInterrupt(0, handleEncoder, CHANGE);

  
  
}

void loop()
{
  Serial.println(count);
  
  
    if(digitalRead(start_button) == LOW)
      {
          if(start_begin == 0)
          {
          Serial.println('s');
          int start_time = millis();
          start_begin = 1;
          delay(1000);
          }
          else
          {
            Serial.println('e');
            start_begin = 0;
            int end_time = millis();
            delay(1000);
          }
      }

   
  
}

void handleEncoder()
{
  if(digitalRead(encoderI) == digitalRead(encoderQ))
  {
    count++;
  }
  else
  {
    count--;
  }
  
}
