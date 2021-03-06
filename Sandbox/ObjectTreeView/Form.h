#ifndef FORM_H
#define FORM_H

// Qt
#include <QWidget>
#include <QObject>
#include <QAction>


// Project
#include "Core/ObjectTreeModel.h"

// Sandbox
#include "ui_Form.h"


class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

protected slots:
    void on__add_clicked();
    void on__remove_clicked();

    void onRemoveLayer();

private:
    Ui_Form * _ui;
    QObject * _mainImage;
    Core::ObjectTreeModel * _model;

    QAction _removeLayer;

};

#endif // FORM_H
