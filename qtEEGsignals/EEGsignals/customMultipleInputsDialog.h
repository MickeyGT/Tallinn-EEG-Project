/*
Custom QT dialog used to obtain 2 user inputs that represend an ip address and a port
Warning : corner cases such as invalid ip address MUST be added
*/
#ifndef CUSTOMMULTIPLEINPUTSDIALOG_H
#define CUSTOMMULTIPLEINPUTSDIALOG_H
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include <QDebug>
class customMultipleInputsDialog : public QDialog
{
public:
	QString mIp;
	QString mPort;
	customMultipleInputsDialog();
	~customMultipleInputsDialog();
	QString getIp();
	QString getPort();
};
#endif