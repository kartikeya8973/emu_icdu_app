#include "rinfo.h"

rinfo::rinfo()
{

}

void rinfo::read(const QJsonObject &json)
{
    if(json.contains("info"))
    {
        QJsonObject i_json;
        i_json = json["info"].toObject();
        if(i_json.contains("route"))
        {
            QJsonObject r_json;
            r_json = i_json["route"].toObject();

            if (r_json.contains("sno") && r_json["sno"].isDouble())
                sno = r_json["sno"].toInt();

            if (r_json.contains("tr_no_en") && r_json["tr_no_en"].isString())
                tr_no_en = r_json["tr_no_en"].toString();

            if (r_json.contains("tr_nm_en") && r_json["tr_nm_en"].isString())
                tr_nm_en = r_json["tr_nm_en"].toString();

            if (r_json.contains("tr_route_en") && r_json["tr_route_en"].isString())
                tr_route_en = r_json["tr_route_en"].toString();

            if (r_json.contains("tr_via_en") && r_json["tr_via_en"].isString())
                tr_via_en = r_json["tr_via_en"].toString();
        }
    }

    if(json.contains("data"))
    {
        QJsonObject d_json;
        d_json = json["data"].toObject();
        if (d_json.contains("st_list") && d_json["st_list"].isArray())
        {
            QJsonArray sArray = d_json["st_list"].toArray();
            st_list.clear();
            st_list.reserve(sArray.size());

            for(int sIdx=0;sIdx<sArray.size();sIdx++)
            {
                QJsonObject sObject = sArray[sIdx].toObject();
                station station;
                station.read(sObject);
                st_list.append(station);
            }
        }
    }
}

void rinfo::write(QJsonObject &json) const
{
    json["sno"]=sno;
    json["tr_no_en"]=tr_no_en;
    json["tr_nm_en"]=tr_nm_en;
    json["tr_route_en"]=tr_route_en;
    json["tr_via_en"]=tr_via_en;
}
