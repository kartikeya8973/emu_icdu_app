#ifndef _WIDGETMARQUEELABEL_H_
#define _WIDGETMARQUEELABEL_H_

#include <QLabel>
#include <QTimer>

class WidgetMarqueeLabel : public QLabel
{
	Q_OBJECT

	public: //Member Functions
		WidgetMarqueeLabel(QWidget *parent = 0);
		~WidgetMarqueeLabel();	
		void show();
		void setAlignment(Qt::Alignment);
		int getSpeed();
		
	public slots: //Public Member Slots
		void setSpeed(int s);
		
	protected: //Member Functions
        void paintEvent(QPaintEvent *evt);
        void resizeEvent(QResizeEvent *evt);
		void updateCoordinates();

	private: //Data Members
		int px;
		int py;
		QTimer timer;
		Qt::Alignment m_align;
		int speed;
		int fontPointSize;
        int textLength;

	private slots: //Private Member Slots
		void refreshLabel();
};
#endif /*_WIDGETMARQUEELABEL_H_*/
