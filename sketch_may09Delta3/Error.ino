void Error()
{
  Run3Delta = 0; // опустили флаг измерений сопротивления
  stepDelta =0;
  relay=LOW;
  digitalWrite(RelayPin, relay);
}

