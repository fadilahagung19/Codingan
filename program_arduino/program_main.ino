// File Program 3 : program_main.ino
void funcMain() {
  // deklarasi variabel millis waktu sekarang jalannya program
  unsigned long waktuSekarang = millis();

  // jalankan program 1 : untuk Battery
  if ((unsigned long) (waktuSekarang - waktuSebelum_1) >= interval_1) {
    waktuSebelum_1 = waktuSekarang;
    // get voltage and current value battery
    PV.voltage = get_voltage(sensor_voltage_1, 12.0);
    PV.current = get_current("pv");
    PV.power = PV.voltage * PV.current;

    // print result to serial monitor to 2 decimal places
    Serial.println("\n");
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA DAYA PV"));
    Serial.print(F("Voltage PV  : ")); Serial.print(PV.voltage, 2); Serial.println(F(" V"));
    Serial.print(F("Current PV  : ")); Serial.print(PV.current); Serial.println(F(" A"));
    Serial.print(F("Power PV    : ")); Serial.print(PV.power); Serial.println(F(" W"));
    Serial.println("==================================================================\n");

    // Short delay
    delay(500);
  }

  // jalankan program 2 : untuk PV
  if ((unsigned long) (waktuSekarang - waktuSebelum_2) >= interval_2) {
    waktuSebelum_2 = waktuSekarang;
    // get voltage and current value PV
    Battery.voltage = get_voltage(sensor_voltage_2, 12.0);
    Battery.current = get_current("battery");
    Battery.power = Battery.voltage * Battery.current;

    // print result to serial monitor to 2 decimal places
    Serial.println("\n");
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA DAYA BATTERY"));
    Serial.print(F("Voltage BATTERY  : ")); Serial.print(Battery.voltage, 2); Serial.println(F(" V"));
    Serial.print(F("Current BATTERY  : ")); Serial.print(Battery.current); Serial.println(F(" A"));
    Serial.print(F("Power BATTERY    : ")); Serial.print(Battery.power); Serial.println(F(" W"));
    Serial.println("==================================================================\n");

    // Short delay
    delay(500);
  }

  if ((unsigned long) (waktuSekarang - waktuSebelum_3) >= interval_3) {
    waktuSebelum_3 = waktuSekarang;
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
  /* kondisi(kondisi_battery, kondisi_pv);
   * jika tegangan tidak ada = false
   * jika tegangan ada       = true
   */
  // jika tegangan battery lemah, maka relay PV Hidup
  if (Battery.voltage <= 10.5) {
    kondisi(false, true);
  }
  
  // jika tegangan PV lemah, maka relay battery Hidup
  else if (PV.voltage <= 10.5) {      
    kondisi(true, false);
  }
  
  // jika tegangan battery dan PV lemah, maka relay PLN Hidup
  else if (PV.voltage <= 10.5 && Battery.voltage <= 10.5) 
  {
    kondisi(false, false);
  }
}

void funcTester() {
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