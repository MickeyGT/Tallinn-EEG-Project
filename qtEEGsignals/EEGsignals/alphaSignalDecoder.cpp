#include "alphaSignalDecoder.h"



AlphaSignalDecoder::AlphaSignalDecoder()
{
}


AlphaSignalDecoder::~AlphaSignalDecoder()
{
}

long long AlphaSignalDecoder::decodeSignal(const QByteArray &datagram)
{	
	bool ok;

	QString auxstring(datagram.toHex());

	std::string current_locale_text = auxstring.toLocal8Bit().constData();

	double a = hexstr2double(current_locale_text);

	QString* completeSignal = new QString(datagram.toHex());

	QString string(datagram.toHex());
	QString firstvalue = string.toUpper().left(16);
	
	unsigned long long asdasda = firstvalue.toULongLong(&ok , 16);


	QStringRef ref(completeSignal, 0, 16);
	long long asdf = ref.toLongLong();

	long long alpha1213 = QStringRef(completeSignal, 0, 16).toLongLong();
	long long alpha1112 = QStringRef(completeSignal, 16, 16).toLongLong();
	long long alpha1011 = QStringRef(completeSignal, 32, 16).toLongLong();
	long long alpha910 = QStringRef(completeSignal, 48, 16).toLongLong();
	long long alpha89 = QStringRef(completeSignal, 64, 16).toLongLong();

	return (-(alpha1213 * alpha1213) - alpha1112 + alpha910 + (alpha89 * alpha89));
}
//00 00 00 00 00 dc 46 3f

double AlphaSignalDecoder::hexstr2double(const std::string& hexstr)
{
	union
	{
		long long i;
		double    d;
	} value;

	value.i = std::stoll(hexstr, nullptr, 16);

	return value.d;
}