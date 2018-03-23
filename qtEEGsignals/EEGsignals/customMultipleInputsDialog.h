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
	QString ip;
	QString port;
	customMultipleInputsDialog();
	~customMultipleInputsDialog();
	QString getIp();
	QString getPort();
};
#endif