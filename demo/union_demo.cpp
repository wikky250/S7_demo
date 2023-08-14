#include "union_demo.h"
#include <QPushButton>
#include <QLineEdit>


Qtunion_demo::Qtunion_demo(QWidget* parent) : QMainWindow(parent)
{
	this->installEventFilter(this);
	ui.setupUi(this);
	cla = new MyClass();
	CreateConnect();
};

Qtunion_demo::~Qtunion_demo()
{
}

void Qtunion_demo::CreateConnect()
{
	QObject::connect(ui.pB_Connect, &QPushButton::clicked, [=]()
		{
			cla->connect(ui.lE_IP->text(), 102);
		});

	QObject::connect(ui.pB_Read, &QPushButton::clicked, [=]()
		{
			int result = cla->readDB(ui.lE_address->text().toInt());
			ui.lE_Result->setText(QString::number(result));
		});

	QObject::connect(ui.pB_Write, &QPushButton::clicked, [=]()
		{
			int result = cla->writeDB(ui.lE_address->text().toInt(),ui.lE_Result->text().toInt());
		});
}
