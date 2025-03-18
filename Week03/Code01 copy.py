import serial
from influxdb_client import InfluxDBClient
import time

serial_port = '/dev/cu/usbserial-1110'  # 포트명 수정
baud_rate = 9600
timeout = 2

# InfluxDB v2 설정
influxdb_url = "http://localhost:8086"
influxdb_token = "bY1bNi_1GuDu_sn2s3vND27LuO5LF8JdNmrkJ--VUNGwXmLybmlFnfa0NjQiA42XNVfNeDUbCnsa15nO32wdvg=="  # 오타 수정
influxdb_org = "test"  # InfluxDB 조직
influxdb_bucket = "dust"  # 데이터가 저장될 버킷 이름

# InfluxDB 클라이언트 초기화
client = InfluxDBClient(url=influxdb_url, token=influxdb_token, org=influxdb_org)
write_api = client.write_api()  # 오타 수정

# 시리얼 포트 열기
try:
    ser = serial.Serial(serial_port, baud_rate, timeout=timeout)  # 공백 및 파라미터 수정
    print(f"Connected to {serial_port} at {baud_rate} baud")
except serial.SerialException as e:
    print(f"Failed to connect to serial port: {e}")
    exit()

try:
    while True:
        if ser.in_waiting > 0:
            # 아두이노로부터 시리얼 데이터를 읽음
            line = ser.readline().decode('utf-8').strip()  # 변수명 및 함수 오타 수정

            # 데이터가 유효한 경우 InfluxDB에 기록
            if "=" in line:
                key, value = line.split("=")
                try:
                    value = float(value)
                    data = f"sensor_data,device=arduino {key}={value}"  # 오타 수정
                    write_api.write(bucket=influxdb_bucket, record=data)
                    print(f"Data written to InfluxDB: {key}={value}")
                except ValueError:
                    print("Invalid data format")

        time.sleep(1)
except KeyboardInterrupt:
    print("프로그램이 종료되었습니다.")
finally:
    ser.close()

