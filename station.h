#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QTime>
#include <QJsonArray>
#include <QJsonObject>

class station
{
public:
    station();

    int st_no;
    QString st_code="";
    QString st_name_en="";
    QString st_name_hi="";
    QString st_name_rl="";
    QString rl="";
    double dist_km;

   void read(const QJsonObject &json);
   void write(QJsonObject &json) const;
};

#endif // STATION_H
