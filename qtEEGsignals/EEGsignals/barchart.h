#ifndef BARCHART_H
#define BARCHART_H

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>

QT_CHARTS_USE_NAMESPACE

class Barchart : public QObject
{
	

public:

	Barchart();
	~Barchart();
	QChartView* createChart();
};


#endif
