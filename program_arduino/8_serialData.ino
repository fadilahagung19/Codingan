void serialDataPzem() {
  DynamicJsonDocument data(1024);
  // Data PV & Battery
  data["data_pv"]["volt"] = PV.voltage;
  data["data_pv"]["current"] = PV.current;
  data["data_battery"]["volt"] = Battery.voltage;
  data["data_battery"]["current"] = Battery.current;
  
  // inverter
  data["data_inverter"]["volt"] = Inverter.V;
  data["data_inverter"]["current"] = Inverter.I;
  data["data_inverter"]["power"] = Inverter.P;
  data["data_inverter"]["energy"] = Inverter.E;
  data["data_inverter"]["freq"] = Inverter.Freq;
  data["data_inverter"]["pf"] = Inverter.pF;

  // PLN
  data["data_pln"]["volt"] = PLN.V;
  data["data_pln"]["current"] = PLN.I;
  data["data_pln"]["power"] = PLN.P;
  data["data_pln"]["energy"] = PLN.E;
  data["data_pln"]["freq"] = PLN.Freq;
  data["data_pln"]["pf"] = PLN.pF;

  // kirim data
  serializeJson(data, Serial);
//  delay(500);
}
