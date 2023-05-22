// File Program 3 : program_main.ino
void funcMain() {
  // deklarasi variabel millis waktu sekarang jalannya program
  unsigned long waktuSekarang = millis();

  // jalankan program 1 : untuk PV
  if ((unsigned long) (waktuSekarang - waktuSebelum_1) >= interval_1) {
    waktuSebelum_1 = waktuSekarang;
    // get voltage and current value PV
    PV.voltage = get_voltage(sensor_voltage_pv, ref_voltage_system);
    PV.current = get_current("pv");
    PV.power = PV.voltage * PV.current;

    // get voltage and current value Battery
    Battery.voltage = get_voltage(sensor_voltage_battery, ref_voltage_system);
    Battery.current = get_current("battery");
    Battery.power = Battery.voltage * Battery.current;

    //print result to serial monitor to 2 decimal places
    Serial.println("\n");
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA DAYA BATTERY"));
    Serial.print(F("Voltage BATTERY  : ")); Serial.print(Battery.voltage, 2); Serial.println(F(" V"));
    Serial.print(F("Current BATTERY  : ")); Serial.print(Battery.current); Serial.println(F(" mA"));
    Serial.print(F("Power BATTERY    : ")); Serial.print(Battery.power); Serial.println(F(" W"));
    Serial.println("==================================================================\n");

    // print result to serial monitor to 2 decimal places
    Serial.println("\n");
    Serial.println(F("=================================================================="));
    Serial.println(F("DATA DAYA PV"));
    Serial.print(F("Voltage PV  : ")); Serial.print(PV.voltage, 2); Serial.println(F(" V"));
    Serial.print(F("Current PV  : ")); Serial.print(PV.current); Serial.println(F(" mA"));
    Serial.print(F("Power PV    : ")); Serial.print(PV.power); Serial.println(F(" W"));
    Serial.println("==================================================================\n");

    // Short delay
    delay(500);
  }

  // Jalankan program pzem
  if ((unsigned long) (waktuSekarang - waktuSebelum_3) >= interval_3) {
    waktuSebelum_3 = waktuSekarang;
    // Ambil data Daya Inverter dan PLN
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
    Serial.println();

    delay(500);
  }

  // program in relay
  /* kondisi(kondisi_battery, kondisi_pv);
   * jika tegangan tidak ada = false
   * jika tegangan ada       = true
   */

  if ((unsigned long) (waktuSekarang - waktuSebelum_4) >= interval_4) {
    waktuSebelum_4 = waktuSekarang;
    // jika tegangan battery lemah, maka relay PV Hidup
    if (Battery.voltage <= cutoff) {
      kondisi(false, true);
      Serial.println(F("Mode PV"));
    }
    
    // jika tegangan PV lemah, maka relay battery Hidup
    if (Battery.voltage >= cutoff) {      
      kondisi(true, false);
      Serial.println(F("Mode Battery"));
    }
    
    // jika tegangan battery dan PV lemah, maka relay PLN Hidup
    if (Battery.voltage <= cutoff && PV.voltage <= cutoff) 
    {
      kondisi(false, false);
      Serial.println(F("Mode PLN"));
    }
    
  }
}

void funcTester() {
  // TODO
}
