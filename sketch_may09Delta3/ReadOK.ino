void ReadOK()
{  
  if (stepDelta==3){ //условие последнего шага
    Run3Delta = 0; // опустили флаг измерений сопротивления
    stepDelta =0; //сбросили счетчик шага
    return;
  }
  Start3Delta();
}

