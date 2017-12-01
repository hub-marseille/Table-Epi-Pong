#include <IRremote.h>

int RECV_PIN = 32;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define CH1 0xFFA25D 
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD

void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn(); 
}

void loop() {
 if (irrecv.decode(&results)) 
 {
 if (results.value == CH1) 
 {
 Serial.println("CH-"); 
 }
 if (results.value == CH) 
 {
 Serial.println("CH"); 
 }
 if (results.value == CH2) 
 {
 Serial.println("CH+"); 
 }
 if (results.value == PREV) 
 {
 Serial.println("PREV");
 }
 if (results.value == NEXT) 
 {
 Serial.println("NEXT");
 }
 if (results.value == PLAYPAUSE) 
 {
   Serial.println("PLAY/PAUSE");
 }
 if (results.value == VOL1) 
 {
 Serial.println("VOL-");
 }
 if (results.value == VOL2) 
 {
   Serial.println("VOL+")
 }
 if (results.value == EQ) 
 {
 Serial.println("EQ"); 
 }
 if (results.value == BUTON0) 
 {
 Serial.println("BUTON0"); 
 }
 if (results.value == BUTON100) 
 {
 Serial.println("BUTON100+"); 
 }
 if (results.value == BUTON200) 
 {
 Serial.println("BUTON200+"); 
 }
 if (results.value == BUTON1) 
 {
 Serial.println("BUTON1"); 
 }
 if (results.value == BUTON2) 
 {
 Serial.println("BUTON2"); 
 }
 if (results.value == BUTON3) 
 {
 Serial.println("BUTON3"); 
 }
 if (results.value == BUTON4) 
 {
 Serial.println("BUTON4"); 
 }
 if (results.value == BUTON5) 
 {
 Serial.println("BUTON5"); 
 }
 if (results.value == BUTON6) 
 {
 Serial.println("BUTON6"); 
 }
 if (results.value == BUTON7) 
 {
 Serial.println("BUTON7"); 
 }
 if (results.value == BUTON8) 
 {
 Serial.println("BUTON8"); 
 }
if (results.value == BUTON9) 
 {
 Serial.println("BUTON9"); 
 }
 irrecv.resume();
 }
}
