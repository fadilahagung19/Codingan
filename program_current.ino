void acs_autoMidPoin(void) 
{
  acs_sensor_1.autoMidPoint();
  acs_sensor_2.autoMidPoint();
}

int get_current(String data)
{
  if(data == "plts") {
    int value_1 = acs_sensor_1.mA_DC();
    return value_1;
  }

  if(data == "battery") {
    int value_2 = acs_sensor_2.mA_DC();
    return value_2;
  }
}