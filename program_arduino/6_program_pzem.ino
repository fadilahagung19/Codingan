// File Program 6 : program_pzem.ino
void dataInverter(void) 
{
  if (!isnan(pzem_1.voltage())) {
    Inverter.V = pzem_1.voltage();
    Inverter.I = pzem_1.current();
    Inverter.P = pzem_1.power();
    Inverter.E = pzem_1.energy();
    Inverter.Freq = pzem_1.frequency();
    Inverter.pF = pzem_1.pf();
  } else {
    Inverter.V = 0.0;
    Inverter.I = 0.0;
    Inverter.P = 0.0;
    Inverter.E = 0.0;
    Inverter.Freq = 0.0;
    Inverter.pF = 0.0;
  }
}

void dataPLN(void) 
{
  if (!isnan(pzem_2.voltage())){
    PLN.V = pzem_2.voltage();
    PLN.I = pzem_2.current();
    PLN.P = pzem_2.power();
    PLN.E = pzem_2.energy();  
    PLN.Freq = pzem_2.frequency();
    PLN.pF = pzem_2.pf(); 
  } else {
    PLN.V = 0.0;
    PLN.I = 0.0;
    PLN.P = 0.0;
    PLN.E = 0.0;
    PLN.Freq = 0.0;
    PLN.pF = 0.0;
  }
}

void resetPzem(int value) 
{
  if (value == 1) {
    pzem_1.resetEnergy();
    pzem_2.resetEnergy();
    Serial.println(F("Reset Energy PZEM"));
  } else;
}

void setupButton(void) 
{
  pinMode(ResetButton, INPUT);
}
