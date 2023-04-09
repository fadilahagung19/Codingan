// File Program 5 : program_pzem.ino
void dataInverter(void) 
{
  Inverter.V = pzem_1.voltage();
  Inverter.I = pzem_1.current();
  Inverter.P = pzem_1.power();
  Inverter.E = pzem_1.energy();
  Inverter.Freq = pzem_1.frequency();
  Inverter.pF = pzem_1.pf();
}

void dataPLN(void) 
{
  PLN.V = pzem_2.voltage();
  PLN.I = pzem_2.current();
  PLN.P = pzem_2.power();
  PLN.E = pzem_2.energy();  
  PLN.Freq = pzem_2.frequency();
  PLN.pF = pzem_2.pf();
}

void resetPzem(int value) 
{
  if (value == 1) {
    pzem_1.resetEnergy();
    pzem_2.resetEnergy();
  } else;
}

void setupButton(void) 
{
  pinMode(ResetButton, INPUT);
}