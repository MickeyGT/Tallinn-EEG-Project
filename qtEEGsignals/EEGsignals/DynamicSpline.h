#ifndef DYNAMICSPLINE_H
#define DYNAMICSPLINE_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class DynamicSpline : public QChart
{
	Q_OBJECT
public:
	qreal mSignalYValue;

	DynamicSpline(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
	virtual ~DynamicSpline();

	void setSignalYValue(const qreal &signalYValue);

	public slots:
	void handleTimeout();

private:
	QTimer m_timer;
	QSplineSeries *m_series;
	QStringList m_titles;
	QValueAxis *m_axis;
	qreal m_step;
	qreal m_x;
	qreal m_y;

};

#endif DYNAMICSPLINE_H