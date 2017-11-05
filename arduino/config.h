
/******************************** Thing Speak GET Connection ********************************/
char TS_connect[] = "AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80";
char TS_size[] = "AT+CIPSEND=74";
char TS_payload[] = "GET https://api.thingspeak.com/update?api_key=D4SUXF8GPW96TGD8&field1=";



/************************************** Initial Delay **************************************/
#define INIT_DELAY 10000


/************************************** Interval Delay **************************************/
#define INTERVAL 10000
