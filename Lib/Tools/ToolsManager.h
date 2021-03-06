#ifndef TOOLSMANAGER_H
#define TOOLSMANAGER_H

// Qt
#include <QString>
#include <QHash>
#include <QObject>

// Project
#include "Core/LibExport.h"
#include "AbstractTool.h"

namespace Tools
{

//******************************************************************************


class GIV_DLL_EXPORT ToolsManager : public QObject
{
    Q_OBJECT
public:

    void loadPlugins(const QString & path);

    static ToolsManager * get()
    {
        if (!_instance)
            _instance = new ToolsManager();
        return _instance;
    }

    static void destroy()
    {
        if (_instance) {
            delete _instance;
        }
    }

    AbstractTool* getTool(const QString & name)
    { return _tools.value(name, 0); }

    QList<AbstractTool*> getTools()
    { return _list; }

    void insertTool(AbstractTool * tool);

private:
    ToolsManager();
    ~ToolsManager();
    static ToolsManager * _instance;

    bool loadPlugin(QObject *plugin);

    QHash<QString, AbstractTool*> _tools;
    QList<AbstractTool*> _list;

};


class NavigationTool : public AbstractTool
{
    Q_OBJECT
public:
    NavigationTool(QObject * parent=0) :
        AbstractTool(parent)
    {
        setObjectName("navigation");
        _name=tr("Navigation");
        _description=tr("Tool to pan, zoom on image");
        _icon = QIcon(":/icons/hand");
        _cursor = QCursor(Qt::ArrowCursor);
    }
    virtual bool dispatch(QEvent*, QGraphicsScene *){ return false; }
    virtual void clear(QGraphicsScene *) {}
};

//******************************************************************************

}

#endif // TOOLSMANAGER_H
