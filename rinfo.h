#ifndef RINFO_H
#define RINFO_H

#include <QString>
#include <QJsonObject>
#include <QJsonObject>
#include <QJsonArray>
#include "route.h"
#include "station.h"

class rinfo
{
public:
    rinfo();

    int     sno;
    QString tr_no_en="";
    QString tr_nm_en="";
    QString tr_route_en="";
    QString tr_via_en="";
    QList <station> st_list;
    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;
};

#endif // RINFO_H
