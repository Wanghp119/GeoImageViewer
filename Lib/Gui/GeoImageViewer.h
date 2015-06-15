#ifndef GEOIMAGEVIEWER_H
#define GEOIMAGEVIEWER_H

// Project
#include "Core/LibExport.h"
#include "Gui/ShapeViewer.h"

class QProgressDialog;
class QGraphicsItem;

namespace Core {
class ImageOpener;
class ImageWriter;
class ImageDataProvider;
class GeoImageItem;
class GeoImageLayer;
class DrawingsItem;
}

namespace Tools {
class SelectionTool;
}

namespace Filters {
class AbstractFilter;
}

namespace Gui
{

class AbstractRendererView;

//******************************************************************************

class GIV_DLL_EXPORT GeoImageViewer : public ShapeViewer
{
    Q_OBJECT

public:
    explicit GeoImageViewer(QWidget *parent = 0);
    ~GeoImageViewer();

    void loadImage(const QUrl & url);
    virtual void clear();
    void setRendererView(AbstractRendererView * rendererView );

protected slots:
    virtual void onProgressCanceled();

    virtual void onImageOpened(Core::ImageDataProvider *imageDataProvider);
    virtual void onCopyData(const QRectF & selection);
    virtual void onBaseLayerSelected(Core::BaseLayer*);
    virtual void onBaseLayerDestroyed(QObject *);
    virtual void onCreateBaseLayer();

    virtual void onSaveBaseLayer(Core::BaseLayer*);
    virtual void onImageWriteFinished(bool ok);

    virtual void onToolChanged(const QString &);

    virtual void onFilterTriggered();
    virtual void onFilteringFinished(Core::ImageDataProvider *);

    void createScribble(const QString & name, Core::DrawingsItem * item);

protected:

    void writeGeoImageLayer(Core::BaseLayer* layer);
    void filterGeoImageLayer(Core::BaseLayer*);

    const Core::ImageDataProvider *getDataProvider(Core::BaseLayer * layer);
    Core::GeoImageItem * getGeoImageItem(Core::BaseLayer * layer);
    Core::GeoImageItem * createGeoImageItem(Core::ImageDataProvider *, const QPointF &pos=QPointF());
    Core::GeoImageLayer * createGeoImageLayer(const QString & type, Core::ImageDataProvider * provider, const QRect &userPixelExtent = QRect());
//    Core::GeoImageLayer * createEmptyGeoImageLayer(const QString & name, const QRect &extent);

    void prepareSceneAndView(int w, int h);

    bool configureTool(Tools::AbstractTool * tool, Core::BaseLayer * layer);

    void initFilterTools();

    virtual bool onSceneDragAndDrop(const QList<QUrl> & urls);
    void enableOptions(bool v);

    Core::ImageOpener * _imageOpener;
    Core::ImageWriter * _imageWriter;

    AbstractRendererView * _rendererView;

//    Tools::SelectionTool * _selection;

    Core::GeoImageLayer * _processedLayer;
    Filters::AbstractFilter * _appliedFilter;


};

//******************************************************************************

}

#endif // GEOIMAGEVIEWER_H