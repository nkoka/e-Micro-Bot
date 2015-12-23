/**************************************/
/** Applicatif de test des moteurs   **/
/** du robot e-Micro-Bot             **/
/**************************************/
#include <Servo.h>
#define PIN_SG		5
#define PIN_SD		4 
#define VITESSE_SD_MAX	35
#define STOP_SD		0
#define PIN_BP		9
Servo Sd;
Servo Sg
int Time0 = 0;
int Time1 = 0;

void setup()
{
	pinMode(Pin_SD,OUTPUT);
	pinMode(pin_SG,OUTPUT);
	pinMode(pin_BP,INPUT);
	/* configuration de la pin du servo moteur */
	Sd.attach(Pin_SD);
	Sg.attach(Pin_SG);
	Serial.begin(9600);
	Serial.println("Applicatif Test Moteur");
	Serial.println("Attente démarrage e-Micro-Bot);
	while(digitRead(Pin_BP))
	{
		Serial.println("BP appuyé");
	}
	while(digitalRead(Pin_BP))
	{
		Serial.println("BP relaché");
	}
}
void loop()
{
	/* Début rotation servomoteur */
	Time0 = millis();
	sd.write(VITESSE_SD);
	sg.write(VITESSE_SD);
	/* attante de la mise à 1 du bit du codeur */
	while(Time1-Time0<1000)
	{
		Time1=millis()
	}
	sd.write(STOP_SD);
	sg.write(STOP_SD);
	Serial.println("Temps écoulé une seonde à 30% de puissance");
	
}
