void programMain() {
  // deklarasi variabel millis waktu sekarang jalannya program
  unsigned long waktuSekarang_1 = millis();
  unsigned long waktuSekarang_2 = millis();
  unsigned long waktuSekarang_3 = millis();

  // jalankan program 1 : untuk Battery
  if ((unsigned long) (waktuSekarang_1 - waktuSebelum_1) >= pending_1) {
    waktuSebelum_1 = waktuSekarang_1;
    // get voltage and current value battery
    Plts.voltage = get_voltage(sensor_voltage_1, 12.0);
    Plts.current = get_current("plts");

    // print result to serial monitor to 2 decimal places
    Serial.print(F("Voltage 1 : "));
    Serial.print(Plts.voltage, 2);
    Serial.print(F(" V | Current 1 : "));
    Serial.print(Plts.current);
    Serial.println(F(" A|"));

    // Short delay
    delay(500);
  }

  // jalankan program 2 : untuk PV
  if ((unsigned long) (waktuSekarang_2 - waktuSebelum_2) >= pending_2) {
    waktuSebelum_2 = waktuSekarang_2;
    // get voltage and current value PV
    Battery.voltage = get_voltage(sensor_voltage_2, 12.0);
    Battery.current = get_current("battery");

    // print result to serial monitor to 2 decimal places
    Serial.print(F("Voltage 2 : "));
    Serial.print(Battery.voltage, 2);
    Serial.print(F(" V | Current 2 : "));
    Serial.print(Battery.current);
    Serial.println(F(" A|"));

    // Short delay
    delay(500);
  }

  if ((unsigned long) (waktuSekarang_3 - waktuSebelum_3) >= pending_3) {
    waktuSebelum_3 = waktuSekarang_3;
    // Jalankan program pzem
    dataInverter();
    dataPLN();
    // Jalankan program Reset sensor pzem jika ditekan tombol
    nilaiReset = digitalRead(ResetButton);
    resetPzem(nilaiReset);

    Serial.println("\n");    
    // Tampilkan data voltage, current, energy, power, pF dari Inverter
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA PZEM INVERTER"));
    Serial.print(F("Voltage      : ")); Serial.print(Inverter.V); Serial.println(F(" V"));
    Serial.print(F("Current      : ")); Serial.print(Inverter.I); Serial.println(F(" A"));
    Serial.print(F("Power        : ")); Serial.print(Inverter.P); Serial.println(F(" W"));
    Serial.print(F("Energy       : ")); Serial.print(Inverter.E); Serial.println(F(" Wh"));
    Serial.print(F("Frequency    : ")); Serial.print(Inverter.Freq); Serial.println(F(" Hz"));
    Serial.print(F("Power Factor : ")); Serial.println(Inverter.pF);
    Serial.println("==================================================================\n");

    // Tampilkan data voltage, current, energy, power, pF dari PLN
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA PZEM PLN"));
    Serial.print(F("Voltage      : ")); Serial.print(PLN.V); Serial.println(F(" V"));
    Serial.print(F("Current      : ")); Serial.print(PLN.I); Serial.println(F(" A"));
    Serial.print(F("Power        : ")); Serial.print(PLN.P); Serial.println(F(" W"));
    Serial.print(F("Energy       : ")); Serial.print(PLN.E); Serial.println(F(" Wh"));
    Serial.print(F("Frequency    : ")); Serial.print(PLN.Freq); Serial.println(F(" Hz"));
    Serial.print(F("Power Factor : ")); Serial.println(PLN.pF);
    Serial.println("==================================================================\n");

    delay(500);
  }

  // program in relay
  /* kondisi(kondisi_battery, kondisi_plts);
  *  jika tegangan tidak ada = false
  *  jika tegangan ada       = true
  */

  // jika tegangan battery lemah, maka relay PV Hidup
  if (Battery.voltage <= 10.5) {
    kondisi(false, true);
  }
  
  // jika tegangan PV lemah, maka relay battery Hidup
  else if (Plts.voltage <= 10.5) {      
    kondisi(true, false);
  }
  
  // jika tegangan battery dan PV lemah, maka relay PLN Hidup
  else if (Plts.voltage <= 10.5 && Battery.voltage <= 10.5) 
  {
    kondisi(false, false);
  }
}

void programTester() {
  // dataInverter();
  // Serial.println("TEST PZEM 1");
  // Serial.print("Voltage : ");
  // Serial.println(Inverter.V);
  // Serial.print("Current : ");
  // Serial.println(Inverter.I);
  // Serial.print("Power : ");
  // Serial.println(Inverter.P);
  // Serial.print("Energy : ");
  // Serial.println(Inverter.E);
  // Serial.print("Frequency : ");
  // Serial.println(Inverter.Freq);
  // Serial.print("pF : ");
  // Serial.println(Inverter.pF);
  // Serial.println();
  // delay(1000);

  // dataPLN();
  // keadaan(3);
  // Serial.println("TEST PZEM 2");
  // Serial.print("Voltage : ");
  // Serial.println(PLN.V);
  // Serial.print("Current : ");
  // Serial.println(PLN.I);
  // Serial.print("Power : ");
  // Serial.println(PLN.P);
  // Serial.print("Energy : ");
  // Serial.println(PLN.E);
  // Serial.print("Frequency : ");
  // Serial.println(PLN.Freq);
  // Serial.print("pF : ");
  // Serial.println(PLN.pF);
  // Serial.println();

  // delay(1000);

  kondisi(true,false);
  delay(3500);
  kondisi(false,true);
  delay(3500);
  kondisi(false,false);
  delay(3500);
}