from DatabaseSQLite import *
from datetime import datetime

import serial, json, os

board_com = dict()
namadb = "data_arduino.db"

def input_data(board_com):
    board = str(input("Masukan tipe arduino(ex : uno) : "));
    for i in board_com.keys():
        if board == i:
            print("Coba lagi!")
            return 0
            break
    seri = int(input("Serial port COM(angka saja, ex: 3) : "));
    board_com[board]=[seri];
    return 1

def show_data(board_com):
    # show data
    try:
        board = str(input("Masukan tiper arduino : "));
        for i in board_com.keys():
            if board == i:
                seri = board_com[board][0]
                print(f"\nSerial port : COM{seri}")
                print("Result Data : ");
                
        seri = board_com[board][0]
        arduino = serial.Serial(f"com{seri}", 115200);
        data_arduino = arduino.readline();
        decode_values = str(data_arduino[0:len(data_arduino)].decode("utf-8"))
        data = json.loads(decode_values);
        print(data);
        
        # ambil tanggal dan waktu jalannya program
        now = datetime.now()
        time = now.strftime("%H:%M:%S")
        date = f"{now.day}/{now.month}/{now.year}"
        
        # ambil data sensor analog
        volt_battery = data['data_battery']['volt']
        current_battery = data['data_analog']['current']
        volt_pv = data['data_pv']['volt']
        current_pv = data['data_pv']['current']
        
        # ambil data pzem inverter
        pzem_voltage_inverter = data['data_inverter']['volt']
        pzem_current_inverter = data['data_inverter']['current']
        pzem_power_inverter = data['data_inverter']['power']
        pzem_energy_inverter = data['data_inverter']['energy']
        pzem_freq_inverter = data['data_inverter']['freq']
        pzem_pf_inverter = data['data_inverter']['pf']
        
        # ambil data pzem pln
        pzem_voltage_pln = data['data_pln']['volt']
        pzem_current_pln = data['data_pln']['current']
        pzem_power_pln = data['data_pln']['power']
        pzem_energy_pln = data['data_pln']['energy']
        pzem_freq_pln = data['data_pln']['freq']
        pzem_pf_pln = data['data_pln']['pf']
        
        # masukan data ke dalam database
        create_sqlite(namadb);
        insertdb(namadb=namadb, date=date, time=time, 
            voltage_battery=volt_battery, voltage_pv=volt_pv, 
            current_battery=current_battery, current_pv=current_pv, 
            pzem_voltage_inverter=pzem_voltage_inverter, pzem_voltage_pln=pzem_voltage_pln, 
            pzem_current_inverter=pzem_current_inverter, pzem_current_pln=pzem_current_pln, 
            pzem_power_inverter=pzem_power_inverter, pzem_power_pln=pzem_power_pln, 
            pzem_energy_inverter=pzem_energy_inverter, pzem_energy_pln=pzem_energy_pln, 
            pzem_freq_inverter=pzem_freq_inverter, pzem_freq_pln=pzem_freq_pln, 
            pzem_pf_inverter=pzem_pf_inverter, pzem_pf_pln=pzem_pf_pln
        )
        
        # tampilkan data di terminal
        print(f"""
Tanggal : {date} ({time})
==================================================================
DATA DAYA BATTERY
Voltage Battery\t: {volt_battery}V
Current Battery\t: {current_battery}A
Power Battery\t: {float(volt_battery*current_battery)}W
==================================================================
DATA DAYA PV
Voltage PV\t: {volt_pv}V
Current PV\t: {current_pv}A
Power PV\t: {float(volt_pv*current_pv)}W
==================================================================

Tanggal : {date} ({time})
==================================================================
DATA PZEM INVERTER
Voltage Inverter\t: {pzem_voltage_inverter}V
Current Inverter\t: {pzem_current_inverter}A
Power Inverter\t: {pzem_power_inverter}W
Energy Inverter\t: {pzem_energy_inverter}Wh
Frequency Inverter\t: {pzem_freq_inverter}Hz
PF Inverter\t: {pzem_pf_inverter}%
==================================================================
DATA PZEM PLN
Voltage PLN\t: {pzem_voltage_pln}V
Current PLN\t: {pzem_current_pln}A
Power PLN\t: {pzem_power_pln}W
Energy PLN\t: {pzem_energy_pln}Wh
Frequency PLN\t: {pzem_freq_pln}Hz
PF PLN\t: {pzem_pf_pln}%
==================================================================
""")
        # hapus serial data arduino
        #arduino.flush();
        
    except:
        print("\nTerjadi kesalahan.. silahkan coba lagi");
        print("\n1. Pastikan serial port sama di aplikasi arduino ide.")
        print("2. Pastikan board sudah");
        
if os.name == 'nt': os.system('cls');
else: os.system('clear')
    
while True:
    try:
        print("\nProgram include data arduino to python")
        print("Versi : 1.0")
        print("1. Masukan data\n2. Ambil data\n3. Keluar");
        select = int(input("Select : "));
        
        if (select == 1):
            input_data(board_com);
        elif (select == 2):
            show_data(board_com);
        elif (select == 3):
            break
        
    except:
        print("Pastikan masukan angka saja 1-3")
