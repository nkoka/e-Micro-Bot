/**************************************/
/** Applicatif de test des moteurs   **/
/** du robot e-Micro-Bot             **/
/** et de validation des capteurs    **/ 
/** incrémentaux                     **/
/**************************************/
#define PIN_LED	2
#define CHG_STAT_LED_MS	500
int state_Led = 0;
void setup()
{
	/* configuration de la sortie de la LED */
	pinMode(PIN_LED,OUTPUT);
	Time0 = millis();
}
void loop()
{
	/* Début clignotement LED */
	Time1 = millis();
	if( (Time1-Time0) > CHG_STAT_LED_MS)
	{
		Time0 = Time1;
		DigitalWrite(PIN_LED,(~state_Led)&0x1);
	}
}