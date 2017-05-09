void Start3Delta()
{
  Run3Delta = 1; // подняли флаг измерений сопротивления
  stepDelta++; // делаем очередной шаг 3 дельта
  
  digitalWrite(Trig, HIGH); //отправляем триггер для Кейтли и Актакома для старта измерений
  
  pinMode(Trig, INPUT); //переводим пин на прием ответного триггреа от Кейтли
  keyAkt = LOW;
  digitalWrite(KeyAktakom, keyAkt); //закрыли Актаком до подачи триггера от Кейтли
  
  while (1)
  {
    if (digitalRead(Trig)==HIGH ) //как только примем триггер от Кетйли, выходим из цикла
    break;
  }
  Serial.println('1'); // говорим PC, что можно читать показания приборов
  pinMode(Trig, OUTPUT); // вернули пин тригера для следующих запусков

  keyAkt = HIGH;
  digitalWrite(KeyAktakom, keyAkt); //подкчлючилиобратно Актаком

  // переключение реле
  if (stepDelta!=3){
  if (relay == LOW)
  {
    relay=HIGH;
    digitalWrite(RelayPin, relay);
  }
  else 
  {
    relay=LOW;
    digitalWrite(RelayPin, relay);
  }
  }
  
  }
