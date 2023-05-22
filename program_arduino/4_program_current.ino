// File Program 4 : program_current.ino
void acs_autoMidPoin(String data) 
{
  if (data == "pv") {
    acs_sensor_pv.autoMidPoint();
  }
  
  if (data == "battery") {
    acs_sensor_battery.autoMidPoint();
  }

  if (data == "both") {
    acs_sensor_pv.autoMidPoint();
    acs_sensor_battery.autoMidPoint();
  }
}

int get_current(String data)
{
  if(data == "pv") {
    int value_1 = acs_sensor_pv.mA_DC();
    return value_1;
  }

  if(data == "battery") {
    int value_2 = acs_sensor_battery.mA_DC();
    return value_2;
  }
}
