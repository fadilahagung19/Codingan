// float for ADC voltage & input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;

// float for resistor values in divider (in ohm)
float R1 = 30000.0;
float R2 = 7500.0;

// integer for ADC value
int adc_value = 0;

float get_voltage(int pinSensor, float ref_voltage) 
{
  // Read the Analog Value
  adc_value = analogRead(sensor_voltage_1);

  // Determine voltage at ADC input
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  // Calculate voltage at divider input
  in_voltage = adc_voltage / (R2 / (R1 + R2));

  return in_voltage;
}