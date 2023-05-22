from sqlite3 import connect, IntegrityError, OperationalError

class create_sqlite:
    def __init__(self, namadb=""):
        # ambil nama database
        self.namadb = namadb
        if (self.namadb == "" or self.namadb == None):
            print("Silahkan isi nama database!");
            return exit();
        
        connect_sql = connect(self.namadb);
        cursor = connect_sql.cursor()
        
        # buat table database jika tidak tersedia
        cursor.execute("""
            CREATE TABLE IF NOT EXISTS data_arduino (
                date TEXT, time TEXT, volt_battery REAL, volt_pv REAL, 
                current_battery REAL, current_pv REAL,
                pzem_voltage_inverter REAL, pzem_voltage_pln REAL, pzem_current_inverter REAL, pzem_current_pln REAL,
                pzem_power_inverter REAL, pzem_power_pln REAL, pzem_energy_inverter REAL,
                pzem_energy_pln REAL, pzem_freq_inverter REAL, pzem_freq_pln REAL,
                pzem_pf_inverter REAL, pzem_pf_pln REAL
            );           
            """)
        
        # commit & close
        connect_sql.commit()
        connect_sql.close()
        