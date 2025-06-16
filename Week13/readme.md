# 📘 13주차 - 사물인터넷(IoT) 수업 실습 자료

안녕하세요.  
이 폴더에는 **2025학년도 1학기 인하공업전문대학 사물인터넷(IoT)** 수업의 **13주차 실습 자료**가 포함되어 있습니다.

---

## 📅 주차 정보

- **주차**: 13주차  
- **주제**: TinyOS 기반 온습도 센서 모니터링 시스템  
- **내용**:
  - TelosB 센서 노드를 이용한 온습도 수집
  - TinyOS 기반 센서 제어 프로그램 작성
  - InfluxDB + Grafana를 통한 시각화
  - 텔레그램 봇을 통한 알림 연동

---

## 📂 주요 소스파일 설명

| 파일명         | 설명 |
|----------------|------|
| `TestAppC.nc`  | TinyOS 어플리케이션 진입점, 컴포넌트들을 wiring(연결)하는 구성 파일 |
| `Test.h`       | 센서 노드용 상수(센서 ID, 측정 주기 등)를 정의하는 헤더 파일 |
| `TestC.nc`     | 실제 온습도 센서 제어, 데이터 측정 및 송신 기능 구현부 |

---

## 🛠️ 컴파일 및 업로드

- TelosB 노드를 위한 컴파일:
  ```bash
  make telosb
  ```

- 특정 노드 ID(`X`)로 업로드:
  ```bash
  make telosb install.X
  ```

---

## 📡 실시간 센서 데이터 처리

| 항목 | 설명 |
|------|------|
| `oscilloscope.py` | USB 포트로 수신된 센서 데이터를 시각화 (Python GUI 기반) |
| `dustInfluxdb.py` | 수신 데이터를 InfluxDB로 전송하는 미들웨어 역할 |

---

## 📊 InfluxDB + Grafana 설정

- **InfluxDB**: 센서 데이터를 저장하는 시계열 데이터베이스
  - 주소: `localhost:8086`
  - DB 이름: `dust`
  - 사용자: `root`

- **Grafana**: InfluxDB의 센서 데이터를 실시간으로 시각화하는 대시보드 도구

---

## 🤖 Telegram Bot 연동

- Python 스크립트로 텔레그램 봇 생성 및 연동
- 주요 기능:
  - 실시간 센서값 전송
  - 타이머 기반 알림
  - 봇 명령어 응답 처리

---

## 🔁 전체 흐름 요약

```
TinyOS 센서노드 → Python 수신 처리 → InfluxDB 저장 → Grafana 시각화 + Telegram 알림
```
