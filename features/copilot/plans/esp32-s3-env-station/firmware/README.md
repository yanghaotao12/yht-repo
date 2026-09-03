# firmware/README.md

Expanded instructions and environment variables for the ESP-IDF firmware.

1. Install ESP-IDF (for esp32-s3) as per Espressif docs.
2. Set IDF_PATH and run . ./export.sh
3. cd firmware
4. idf.py set-target esp32s3
5. idf.py menuconfig
   - Configure Wi-Fi provisioning & MQTT broker URI/credentials
   - If using TLS, set path to CA certificate in menuconfig or provide via partition
6. idf.py build
7. idf.py -p <PORT> flash monitor

Notes:
- This repo contains component skeletons. Sensor drivers provided are minimal stubs—replace with production-grade drivers from vendor or upstream libs.
