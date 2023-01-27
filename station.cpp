#include "station.h"

station::station()
{

}

void station::write(QJsonObject &json) const
{
    json["st_no"]=st_no;
    json["st_code"]=st_code;
    json["st_name_en"]=st_name_en;
    json["st_name_hi"]=st_name_hi;
    json["st_name_rl"]=st_name_rl;
    json["rl"]=rl;
    json["dist_km"]=dist_km;
}

void station::read(const QJsonObject &json)
{
    if (json.contains("st_no") && json["st_no"].isDouble())
        st_no  = json["st_no"].toInt();

    if (json.contains("st_code") && json["st_code"].isString())
        st_code  = json["st_code"].toString();

    if (json.contains("st_name_en") && json["st_name_en"].isString())
        st_name_en  = json["st_name_en"].toString();

    if (json.contains("st_name_hi") && json["st_name_hi"].isString())
        st_name_hi  = json["st_name_hi"].toString();

    if (json.contains("st_name_rl") && json["st_name_rl"].isString())
        st_name_rl  = json["st_name_rl"].toString();

    if (json.contains("rl") && json["rl"].isString())
        rl  = json["rl"].toString();

    if (json.contains("dist_km") && json["dist_km"].isDouble())
        dist_km  = json["dist_km"].toDouble();
}
