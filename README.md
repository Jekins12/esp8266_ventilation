
# ESP8266 Ventilation Controller

This project is a simple ventilation control system using the ESP8266 microcontroller. It allows the control of a ventilation system via HTTP requests to open or close the ventilation. The system also provides discovery information, including the device name, IP address, and MAC address.

## Features
- **Discover Endpoint:** Provides device information such as name, IP address, and MAC address along with available endpoints.
- **Open Endpoint:** Opens the ventilation by rotating the servo motor.
- **Close Endpoint:** Closes the ventilation by rotating the servo motor.

## Requirements
- ESP8266 microcontroller (e.g., NodeMCU)
- Servo motor
- LED (optional, for indication)
- [ArduinoJson Library](https://github.com/bblanchon/ArduinoJson) - Used for JSON formatting.
- [Servo Library](https://www.arduino.cc/en/Reference/Servo)

## Setup

1. **Connect Components:**
   - Connect the servo motor to a designated pin on the ESP8266 (configured as `servoPin` in `config.h`).
   - Optionally, connect an LED to an output pin.

2. **Wi-Fi Configuration:**
   - Set up your Wi-Fi SSID and password in the `config.h` file.

3. **Endpoints:** The following HTTP endpoints are available:
   - `/discover`: Returns JSON with device details and endpoints.
   - `/open`: Opens the ventilation.
   - `/close`: Closes the ventilation.

## Usage
After powering on and connecting to Wi-Fi, the ESP8266 will serve an HTTP server at its IP address.

- **Discover Device:** Navigate to `http://<device_ip>/discover` to get device information in JSON format.
- **Open Ventilation:** Navigate to `http://<device_ip>/open` to open the ventilation.
- **Close Ventilation:** Navigate to `http://<device_ip>/close` to close the ventilation.

## Example Response for `/discover`
```json
{
  "name": "ESP8266 Ventilation",
  "ip_address": "192.168.1.50",
  "mac_address": "XX:XX:XX:XX:XX:XX",
  "endpoints": ["/close", "/open"]
}
```


## Acknowledgments
- The [ESP8266WebServer Library](https://github.com/esp8266/Arduino) for managing HTTP requests.
- The [Servo Library](https://www.arduino.cc/en/Reference/Servo) for controlling the servo motor.
