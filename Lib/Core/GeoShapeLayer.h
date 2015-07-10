#ifndef GEOSHAPELAYER_H
#define GEOSHAPELAYER_H

// Qt
#include <QObject>
#include <QString>
#include <QRect>
#include <QRectF>
#include <QPolygonF>

// Project
#include "Global.h"
#include "BaseLayer.h"

namespace Core
{

//******************************************************************************
/*!
  \class GeoShapeLayer
  \brief derived from BaseLayer and represents geographic layers
  It has properties :
  - geographic extent
  - geographic bounding box

 */

//******************************************************************************

class GeoShapeLayer : public BaseLayer
{

    Q_OBJECT

    // Geo info
    // !!! SHOULD BE IN GeoImageLayer
//    Q_PROPERTY(QRect pixelExtent READ getPixelExtent)
//    PROPERTY_ACCESSORS(QRect, pixelExtent, getPixelExtent, setPixelExtent)
    Q_PROPERTY(QPolygonF geoExtent READ getGeoExtent)
    PROPERTY_ACCESSORS(QPolygonF, geoExtent, getGeoExtent, setGeoExtent)
    Q_PROPERTY(QRectF geoBBox READ getGeoBBox)
    PROPERTY_ACCESSORS(QRectF, geoBBox, getGeoBBox, setGeoBBox)

//    Q_CLASSINFO("pixelExtent","label:Pixel extent")
    Q_CLASSINFO("geoExtent","label:Geo extent")
    Q_CLASSINFO("geoBBox","label:Geo bounding box")

public:
    GeoShapeLayer(QObject * parent = 0) :
        BaseLayer(parent)
    {
        _type = "Geo Shape";
    }

    virtual bool canSave()
    { return true; }
};

//******************************************************************************

}


#endif // GEOSHAPELAYER_H
