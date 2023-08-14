#include "S7Model.h"
MyClass::MyClass()
{
	MyClient = new TS7Client();
}

MyClass::~MyClass()
{
	delete MyClient;
}

void MyClass::connect(QString _ip, int _port)
{
	MyClient->ConnectTo(_ip.toStdString().c_str(), 102, 1); //PLC的IP地址，机架号，插槽号
}

int MyClass::readDB(int _address)
{
	unsigned char TestValHex[4];
	MyClient->DBRead(_address, 0, 4, &TestValHex);  //PLC中的DB块编号，起始字节，要读取的字节长度，将要写入本地的变量
	int result,dec;
	result = (int)TestValHex[0]*0x1000000;
	result += (int)TestValHex[1] * 0x10000;
	result += (int)TestValHex[2] * 0x100;
	result += (int)TestValHex[3] * 0x1;
	return result;
}

int MyClass::writeDB(int _address, int value)
{
	unsigned char TestValHex[4];
	TestValHex[0] = value / 0x1000000;
	TestValHex[1] = value % 0x1000000 / 0x10000;
	TestValHex[2] = value % 0x10000 / 0x100;
	TestValHex[3] = value % 0x100 / 0x1;
	MyClient->DBWrite(_address, 0, 4, &TestValHex);  //PLC中的DB块编号，起始字节，要读取的字节长度，将要写入本地的变量
	return 0;
}
