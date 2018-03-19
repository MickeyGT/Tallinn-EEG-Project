#ifndef BARCHART_H
#define BARCHART_H
#include <QChart>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

class Barchart : public QObject
{
	

public:

	Barchart();
	~Barchart();
	QChartView* createChart();
};


#endif
