//declaring pin no. to the variables.
int gled = 13;
int yled = 12;
int rled = 11;
int button = 7;
unsigned long prevMillis=0; 
const long interval=1000; //time interval between blinking of two consecutive LEDS in ms
int led=0;



void setup(){
  pinMode(gled,OUTPUT);
  pinMode(yled,OUTPUT);
  pinMode(rled,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}
void loop(){
  if(digitalRead(button) == HIGH){ //when button is switched on
    digitalWrite(rled, HIGH);
    digitalWrite(yled, LOW);
    digitalWrite(gled, LOW);
  }
  else{
    unsigned long presentMillis = millis();

    if(presentMillis- prevMillis >=1000){
      prevMillis = presentMillis; //reassigning the timer

      if(led==0){
        digitalWrite(gled,HIGH); //green light starts to
        digitalWrite(yled,LOW);
        digitalWrite(rled,LOW);
        Serial.println("green");
      }else if(led==1){
        digitalWrite(gled,LOW);
        digitalWrite(yled,HIGH); //yellow light starts here 
        digitalWrite(rled,LOW);
        Serial.println("yellow");
      }else if(led==2){
        digitalWrite(gled,LOW);
        digitalWrite(yled,LOW);
        digitalWrite(rled,HIGH); //red light starts here
        Serial.println("red");

      }
      led = (led +1)%3;
    }
  }
}
