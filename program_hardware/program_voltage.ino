// float for resistor values in divider (in ohm)
float R1 = 30000.0;
float R2 = 7500.0;

float get_voltage(int pinSensor, float ref_voltage) 
{
  // Read the Analog Value
<<<<<<< HEAD
  int adc_value = analogRead(pinSensor);
=======
  adc_value = analogRead(pinSensor);
>>>>>>> 4852d52d55e09dbaa2dd35fcd175edfc76e5767d

  // Determine voltage at ADC input
  float adc_voltage = (adc_value * ref_voltage) / 1024.0;
  // Calculate voltage at divider input
  float in_voltage = adc_voltage / (R2 / (R1 + R2));

  return in_voltage;
}
