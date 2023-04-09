// File Program 6 : program_relay.ino
void kondisi(bool kondisi_battery, bool kondisi_pv) 
{
  if (kondisi_battery == false && kondisi_pv == true) 
  {
    digitalWrite(relay_1, MATI);
    digitalWrite(relay_2, HIDUP);
    digitalWrite(relay_3, MATI);
    digitalWrite(relay_4, HIDUP);
  } 
  else if (kondisi_battery == true && kondisi_pv == false) 
  {
    digitalWrite(relay_1, HIDUP);
    digitalWrite(relay_2, MATI);
    digitalWrite(relay_3, MATI);
    digitalWrite(relay_4, HIDUP);
  }
  else if (kondisi_battery == false && kondisi_pv == false) 
  {
    digitalWrite(relay_1, MATI);
    digitalWrite(relay_2, MATI);
    digitalWrite(relay_3, HIDUP);
    digitalWrite(relay_4, MATI);
  }
  else {
    Serial.println(F("Tidak ada kondisi"));
  }
}

void setupRelay(void) 
{
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);
  digitalWrite(relay_1, MATI);
  digitalWrite(relay_2, MATI);
  digitalWrite(relay_3, MATI);
  digitalWrite(relay_4, MATI);
}