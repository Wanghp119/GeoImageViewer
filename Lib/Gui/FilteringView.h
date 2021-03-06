#ifndef FILTERINGVIEW_H
#define FILTERINGVIEW_H

// Qt
#include <QObject>


// Project
#include "Core/Global.h"

class QProgressDialog;

namespace Filters {
class AbstractFilter;
}

namespace Core {
class GeoImageLayer;
}

namespace Gui
{

class BaseFilterDialog;

//******************************************************************************

class FilteringView : public QObject
{
    Q_OBJECT
    PTR_PROPERTY_GETACCESSOR(Filters::AbstractFilter, filter, getFilter)
    PTR_PROPERTY_GETACCESSOR(Core::GeoImageLayer, srcLayer, getSrcLayer)
    PTR_PROPERTY_ACCESSORS(Core::GeoImageLayer, dstLayer, getDstLayer, setDstLayer)

public:
    explicit FilteringView(QProgressDialog * progress, QObject * parent = 0);
    virtual ~FilteringView();
    void setup(Filters::AbstractFilter * f);
    void reset();
    void setSrcLayer(Core::GeoImageLayer * layer);


protected slots:
    void onApplyFilter();

protected:

    bool eventFilter(QObject * object, QEvent * event);

    BaseFilterDialog * _filterDialog;
    QProgressDialog * _progressDialog;

};

//******************************************************************************

}

#endif // FILTERINGVIEW_H
