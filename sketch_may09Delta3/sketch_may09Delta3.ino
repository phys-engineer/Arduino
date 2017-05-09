/*
 * TO DO
 * - функция опроса температуры и передачи сведений по порту в комп - для тестового наблюдения без элементов Пельтье
 * - программа на компе для общения с Ардуино
 * - Новые команды для Кейтли и Актакома для настройки триггера, фильтра (со сбросом старых значений) 
 * и триггера ответа от Кейтли о финише измерения.
 * 
 */

#define Trig  13      //ПИН для подачи и считывания триггера
#define RelayPin 12   //пин управления реле
#define KeyAktakom 8  // пин отключения и подключения Актакома (иначе он сработает от ответа Кейтли)

long TempPrev_ms = 0; // время крайнего опроса температуры
long TempInterval_ms = 1000; // период опроса температуры
int relay = LOW;
int keyAkt = HIGH; //изначально ключ Актакома открыт, чтобы он услышал триггер от Ардуино
int stepDelta = 0;

bool Run3Delta = 0; //флаг для контроля проведения измерения, чтобы не прервать его измерением температуры

void setup() {
  // put your setup code here, to run once:
pinMode(Trig, OUTPUT);
digitalWrite(Trig, LOW);

pinMode(RelayPin, OUTPUT);
digitalWrite(RelayPin, relay);

pinMode(KeyAktakom, OUTPUT);
digitalWrite(KeyAktakom, keyAkt);

Serial.begin(9600);
Serial.println("время\tнапряжение");
}
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis(); // текущее время в миллисекундах
  
  if((currentMillis - TempPrev_ms > TempInterval_ms) && !Run3Delta) //проверяем, что прошло 1000 мс и не идет опрос 3 дельта
  {
    // обновляем время опроса температуры
    Serial.println(currentMillis - TempPrev_ms);
    TempPrev_ms = currentMillis;
    TempControl();
    
  }
  if (Serial.available()>0)
  { String st =Serial.readString() ;
    if (st ==  "start")  
    Start3Delta(); 
    else if ( st ==  "readOK") 
    ReadOK(); 
    else if  ( st ==  "error")        
    Error(); 
    else Serial.println("Invalid comand");  
      }  
    
  
  //delay(500);
  /*
  String st;
  
  while (Serial.available()<0)
  st=Serial.readString();  
  Serial.println(st);
  */
 
}
