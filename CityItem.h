#pragma once

#include <QGraphicsEllipseItem>
#include <Player.h>
#include <memory>
#include "City.h"

class CityItem : public QGraphicsEllipseItem {
    string name;
    QColor regionColor;
    shared_ptr<City> city;
    bool toRemove = false;

public:
    CityItem(QPoint topLeft, int width, int height);

    string GetName() const { return name; }
    void SetName(string name) { this->name = name; }

    void SetRegionColor(QColor regionColor);
    QColor GetRegionColor() const { return regionColor; }

    QPoint GetNameLocation(QFont font) const;
    QPoint GetCenter() const;
    QGraphicsSimpleTextItem* GetNameTextItem(QFont font) const;

    QPoint GetHousePosition(int index) const;
    void SetCity(shared_ptr<City> city) { this->city = city; }
    shared_ptr<City> GetCity() const { return city; }
    void SetToRemove(bool toRemove) { this->toRemove = toRemove; }
    bool GetToRemove() const { return toRemove; }
};

