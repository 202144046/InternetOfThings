# 📘 11주차 - 사물인터넷(IoT) 수업 실습 자료

안녕하세요.  
이 폴더에는 **2025학년도 1학기 인하공업전문대학 사물인터넷(IoT)** 수업의 **11주차 실습 자료**가 포함되어 있습니다.

---

## 📅 주차 정보

- **주차** : 11주차  
- **주제** : 라즈베리파이 기반 OpenCV + USB 카메라 + 텔레그램 봇 연동 실습  
- **내용** :
  - 라즈베리파이 환경에서 OpenCV 설치 및 카메라 테스트
  - Python으로 USB 카메라 영상 처리 실습
  - Telegram API를 활용한 이미지 전송 자동화 봇 제작

---

## 🛠️ 실습 환경 준비

### 1. OpenCV 설치

1. **pip 오류 해결 전처리**
   ```bash
   sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED
   ```

2. **스왑 메모리 증가 (설치 중 오류 방지용)**
   ```bash
   sudo vim /etc/dphys-swapfile
   # CONF_SWAPSIZE=200 → 2048로 수정
   sudo /etc/init.d/dphys-swapfile restart
   ```

3. **OpenCV 설치**
   ```bash
   pip install opencv-contrib-python
   sudo apt-get install python3-opencv
   ```

4. **설치 후 스왑 복원**
   ```bash
   CONF_SWAPSIZE=2048 → 200으로 다시 변경
   ```

---

### 2. USB 카메라 테스트

- Python 코드로 USB 카메라에서 영상 캡처 테스트
- `cv2.VideoCapture()`를 통해 카메라 스트림 읽기
- 이미지 저장 또는 실시간 화면 출력 가능

---

### 3. 텔레그램 봇 연동

#### 🔹 봇 생성 절차

1. 텔레그램 앱에서 **botfather** 검색
2. `/start`, `/newbot` 명령어 입력
3. **봇 이름** 설정 (`예 : myiot_bot`)
4. 생성 후 **토큰(Token)** 확인

#### 🔹 Python 텔레그램 API 설치

```bash
pip install python-telegram-bot --upgrade
```

#### 🔹 GitHub 예제 클론 및 수정

```bash
git clone https://github.com/python-telegram-bot/python-telegram-bot --recursive
```

- `TimerBot.py` 수정
  - 이미지 전송, 타이머 실행 등 `context.job_queue.run_once()` 또는 `run_repeating()` 활용

---

## 📌 참고 사항

- USB 카메라는 라즈베리파이에 직접 연결해야 정상 작동합니다.
- 텔레그램 봇은 토큰 보안에 주의해야 하며, 실습 중 노출되지 않도록 합니다.
- 실습 중 오류가 발생하면 **스왑 메모리 설정**을 우선 점검하세요.
- Python 버전은 3.10 이상 권장됩니다.
