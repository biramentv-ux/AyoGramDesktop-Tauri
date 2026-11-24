#pragma once

#include <QObject>
#include <QVariantMap>

class MK_FuckPaymentsPlugin : public QObject {
    Q_OBJECT
public:
    explicit MK_FuckPaymentsPlugin(QObject *parent = nullptr);
    
public slots:
    void bypassPremium(QVariantMap &data);
};