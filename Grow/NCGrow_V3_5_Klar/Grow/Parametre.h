// Verdier for vann og fukt (STD verdier før øking til programmer!)
int m_grense = 550;                 //Verdi for fukt grense (endres via modus fra programmer.h)
const int v_niva_grense = 150;      //Grense verdi for vann (Konstant verdi) (legge til funksjon som varsler når nivå er under oppgitt verdi)

//Timer data for hvor hyppig programmet skal innhente info
unsigned long tidligereMillis = 0;   // Siste avlesning av sensor
unsigned long interval = 1200000;    // leser av med 20 min intervall "millis konv(20*60*1000)"
unsigned long aktuellMillis = 0;     // Nåværende tid



