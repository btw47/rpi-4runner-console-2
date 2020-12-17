#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QObject>
#include <QtQml>
#include <QString>

#include <QtBluetooth>

class Bluetooth : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit Bluetooth(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
    void getLocalDeviceInformation();
    void startDeviceDiscovery();
    void deviceDiscovered(const QBluetoothDeviceInfo &device);
};

#endif // BLUETOOTH_H
