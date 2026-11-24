#pragma once

#include <QObject>
#include <QVariantMap>

class UnlockStarsContentPlugin : public QObject {
    Q_OBJECT
public:
    explicit UnlockStarsContentPlugin(QObject *parent = nullptr);
    
public slots:
    void unlockStarsContent(QVariantMap &data);
};