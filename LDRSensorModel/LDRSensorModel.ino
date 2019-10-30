#define LDR A1 //Define LDR as A1
#define relay 8 //Define led as 8

//============================ Defining variebles============================//

float luminosity; //varieble to storage the valor of the LDR sensor
float percentage; //variebles to storage the light porcentage 
int button = 7; // button on pin 7
int funcaoa = 0; // valor recived by the button
int funcaob = 0; // valor storaged
int state=0; // stores the valor 0 or 1 (HIGH or LOW)

void setup()
{   
//=============================comunication with arduino==============================//
Serial.begin(9600); //Initialize the serial of Arduino   
pinMode(relay, OUTPUT); //configure pin 8 as output   
digitalWrite(relay, LOW); //power off LED
pinMode(button,INPUT); //Define the button as input
digitalWrite(relay, LOW);//Define relay as off
}

//==========================ldr ==============================//
void loop()
{   

percentage = 0;  

for(int i=0; i < 100 ; i++)   
{     
luminosity = analogRead(LDR); //Stores the valor of LDR     
luminosity = (luminosity / 1024) * 100; //convert the valor into a percentage
percentage = percentage + luminosity; //stores the percentage   
}   

percentage = percentage/100;
Serial.print("luminosity = "); //print on serial "luminosity = "   
Serial.print(percentage, 0); //print the percentage whithout decimals   
Serial.println("%");  
if(percentage < 30) //If luminosity under 30%  

{    
delay(1500);     
digitalWrite(relay,HIGH); //power on LED   
delay(1500);
}   
else
{     

funcaoa=digitalRead(button);
 if ((funcaoa == HIGH) && (funcaob == LOW)) {
 state = 1 - state;
delay(1); 
 }
 funcaob=funcaoa;
 if (state == 1) {
 digitalWrite(relay, HIGH); // power on the led
 } else {
 digitalWrite(relay, LOW); // power off the led
 } 

}
}

 
