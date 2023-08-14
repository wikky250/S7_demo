#include "snap7.h"
#include<QObject>
class MyClass
{
public:
	MyClass();
	~MyClass();
	void connect(QString _ip,int _port);
	int readDB(int _address);
	int writeDB(int _address, int value);
private:
	TS7Client* MyClient;
};
