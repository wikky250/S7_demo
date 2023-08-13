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
	MyClient->ConnectTo(_ip.toStdString().c_str(), 102, 1); //PLC��IP��ַ�����ܺţ���ۺ�
}

int MyClass::read(int _address)
{
	unsigned char TestValHex[4];
	MyClient->DBRead(_address, 0, 4, &TestValHex);  //PLC�е�DB���ţ���ʼ�ֽڣ�Ҫ��ȡ���ֽڳ��ȣ���Ҫд�뱾�صı���
	int result,dec;
	result = (int)TestValHex[0]*0x1000000;
	result += (int)TestValHex[1] * 0x10000;
	result += (int)TestValHex[2] * 0x100;
	result += (int)TestValHex[3] * 0x1;
	return result;
}
