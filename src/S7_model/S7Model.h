#include "snap7.h"
#include<QObject>
class MyClass
{
public:
	MyClass();
	~MyClass();
	void connect(QString _ip,int _port);
	int read(int _address);
private:
	TS7Client* MyClient;
};
