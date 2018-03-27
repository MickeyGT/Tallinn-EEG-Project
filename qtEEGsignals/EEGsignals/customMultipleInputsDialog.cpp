#include "customMultipleInputsDialog.h"

customMultipleInputsDialog::customMultipleInputsDialog()
{
	QDialog dialog(this);
	// Use a layout allowing to have a label next to each field
	QFormLayout form(&dialog);

	// Add the lineEdits with their respective labels

	QLineEdit *lineEdit = new QLineEdit(&dialog);
	QString label1 = QString("Ip Address:");
	form.addRow(label1, lineEdit);

	QLineEdit *lineEdit2 = new QLineEdit(&dialog);
	QString label2 = QString("Port:");
	form.addRow(label2, lineEdit2);

	// Add some standard buttons (Cancel/Ok) at the bottom of the dialog
	QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
		Qt::Horizontal, &dialog);
	form.addRow(&buttonBox);
	QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
	QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

	// Show the dialog as modal
	if (dialog.exec() == QDialog::Accepted) 
	{
		mIp = lineEdit->text();
		mPort = lineEdit2->text();
	}
}

customMultipleInputsDialog::~customMultipleInputsDialog()
{
}

QString customMultipleInputsDialog::getIp()
{
	return mIp;
}

QString customMultipleInputsDialog::getPort()
{
	return mPort;
}