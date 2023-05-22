from sqlite3 import connect, IntegrityError, OperationalError

class insertdb:
    def __init__(self, namadb, date, time, voltage_battery, voltage_pv, current_battery, current_pv, 
        pzem_voltage_inverter, pzem_voltage_pln, pzem_current_inverter, pzem_current_pln,
        pzem_power_inverter, pzem_power_pln, pzem_energy_inverter, pzem_energy_pln,
        pzem_freq_inverter, pzem_freq_pln, pzem_pf_inverter, pzem_pf_pln):
        
        # ambil nama database
        self.namadb = namadb
        if (self.namadb == None or self.namadb == ""):
            print("Silahkan isi nama database!");
            return exit();
        
        connect_sql = connect(self.namadb)
        cursor = connect_sql.cursor()
        
        # masukan data ke dalam database
        cursor.execute(f"""
            INSERT INTO data_arduino VALUES (
                :date, :time, 
                :volt_battery, :volt_pv, 
                :current_battery, :current_pv, 
                :pzem_voltage_inverter, :pzem_voltage_pln,
                :pzem_current_inverter, :pzem_current_pln, 
                :pzem_power_inverter, :pzem_power_pln,
                :pzem_energy_inverter, :pzem_energy_pln, 
                :pzem_freq_inverter, :pzem_freq_pln,
                :pzem_pf_inverter, :pzem_pf_pln
            )
            """, {
              "date": date, "time": time, "volt_battery": voltage_battery, "volt_pv": voltage_pv,
              "current_battery": current_battery, "current_pv": current_pv,
              "pzem_voltage_inverter": pzem_voltage_inverter, "pzem_voltage_pln": pzem_voltage_pln,
              "pzem_current_inverter": pzem_current_inverter, "pzem_current_pln": pzem_current_pln,
              "pzem_energy_inverter": pzem_energy_inverter, "pzem_energy_pln": pzem_energy_pln,
              "pzem_power_inverter": pzem_power_inverter, "pzem_power_pln": pzem_power_pln,
              "pzem_freq_inverter": pzem_freq_inverter, "pzem_freq_pln": pzem_freq_pln,
              "pzem_pf_inverter": pzem_pf_inverter, "pzem_pf_pln": pzem_pf_pln
            })
        
        # commit and close
        connect_sql.commit();
        connect_sql.close();