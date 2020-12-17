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

private slots:
    void deviceDiscovered(const QBluetoothDeviceInfo &device);

    void socketConnected();
    void socketRead();
    void socketDisconnected();
    void socketError(QBluetoothSocket::SocketError error);
    void socketStateChanged();

private:
    QString m_userName;
    void getLocalDeviceInformation();
    void startDeviceDiscovery();

    QBluetoothSocket *socket;

    int relayAStatus = 0;
    int relayBStatus = 0;
    int relayCStatus = 0;
    int relayDStatus = 0;
};

#endif // BLUETOOTH_H
