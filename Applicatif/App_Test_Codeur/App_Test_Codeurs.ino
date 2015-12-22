/**************************************/
/** Applicatif de test des moteurs   **/
/** du robot e-Micro-Bot             **/
/** et de validation des capteurs    **/ 
/** incrémentaux                     **/
/**************************************/
#include <Servo.h>
#define PIN_CODEUR	2
#define PIN_SD	5
#define VITESSE_SD_MAX	35
#define STOP_SD			0
Servo Sd;
int Time0 = 0;
int Time1 = 0;
void ISR_Codeur()
{
	Time1=millis();
	sd.write(STOP_SD);
}
void setup()
{
	/* configuration de la pin du servo moteur */
	Sd.attach(Pin_SD);
	/* configuration de l'entrée du codeur incrémental */
	pinMode(PIN_CODEUR,INPUT);
	attachInterrupt(digitalPinToInterrupt(PIN_CODEUR),ISR_Codeur,CHANGE);
	Serial.begin(9600);
}
void loop()
{
	/* Début rotation servomoteur */
	Time0 = millis();
	sd.write(VITESSE_SD);
	/* attante de la mise à 1 du bit du codeur */
	while(0!=Time1){};
	Serial.println("Temps pour un quart de tour:");
	Serial.println(Time1-Time0,"DEC");
	Serial.println(" en ms");
	
}