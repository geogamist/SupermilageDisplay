#pragma once

#include <string>
#include <thread>
#include <mutex>

#if defined (_WIN32) || defined( _WIN64)
constexpr char const* PORT = "COM7";
#endif
#if defined (__linux__)
constexpr char const* PORT = "ttyUSB0"; //"/dev/ttyUSB0"
#endif
constexpr int BAUDRATE = 115200; //9600

class SerialClient {
public:
	SerialClient(Delegate* handle);
	~SerialClient();
	bool Initalize(std::string port = PORT, int BaudRate = BAUDRATE);

private:
	void polSerialPort(std::string port, int BaudRate);
	SensorData ConvertPayload(std::string& Temp_Input);

	Delegate* p_updateHandler;
	bool _EndRead = false;
	std::thread _AsyncSerial;
};