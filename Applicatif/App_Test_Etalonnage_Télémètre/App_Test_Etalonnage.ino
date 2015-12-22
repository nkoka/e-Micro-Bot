/**************************************/
/** Applicatif de test des moteurs   **/
/** du robot e-Micro-Bot             **/
/** et de validation des capteurs    **/ 
/** incrémentaux                     **/
/**************************************/
#define PIN_TELEMETRE	A0
#define PIN_LED	4
#define PIN_BP	5
#define NEXT_STEP	2000
void setup()
{
	/* configuration de la sortie de la LED */
	pinMode(PIN_LED,OUTPUT);
	pinMode(PIN_TELEMETRE,INPUT);
	pinMode(PIN_BP,INPUT);
	Time0 = millis();
	DigitalWrite(PIN_LED,LOW);
}
void loop()
{
	int nbDiv = 0;
	int valMoy = 0;
	/* Début clignotement LED */
	Time0 = Time1;
	while( (Time1-Time0) < NEXT_STEP)
	{
		valMoy+=analogRead(A0);
		nbDiv++;
		valMoy/=nbDiv;
		Time1 = millis();
	}
	DigitalWrite(PIN_LED,HIGH);
	Serial.println("Valeur numérique :");
	Serial.println(valMoy);
	while(STATE_HIGH!=DigitalRead(PIN_BP));
	while(STATE_LOW!=DigitalRead(PIN_BP));
	DigitalWrite(PIN_LED,LOW);
	
}