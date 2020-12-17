#include <QObject>
#include "bluetooth.h"
#include <QDebug>
#include <QtBluetooth>

Bluetooth::Bluetooth(QObject *parent) : QObject(parent)
{
    qDebug() << "INIT??";

    this->getLocalDeviceInformation();
}

QString Bluetooth::userName()
{
    return m_userName;
}

void Bluetooth::setUserName(const QString &userName)
{
    return;
}

void Bluetooth::getLocalDeviceInformation()
{
    qDebug() << "Getting local device information";

    QBluetoothLocalDevice localDevice;
    QString localDeviceName;

    if (localDevice.isValid()) {
        localDevice.powerOn();
    }

    localDeviceName = localDevice.name();

    localDevice.setHostMode(QBluetoothLocalDevice::HostDiscoverable);

    QList<QBluetoothAddress> remotes;
    remotes = localDevice.connectedDevices();
}

void Bluetooth::startDeviceDiscovery()
{
    qDebug() << "starting device discovery";

    QBluetoothDeviceDiscoveryAgent *discoveryAgent = new QBluetoothDeviceDiscoveryAgent(this);
    connect(discoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, SLOT(deviceDiscovered(QBluetoothDeviceInfo)));

    discoveryAgent->start();
}

void Bluetooth::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
    if (device.name() == "4Runner") {
        qDebug() << "Found the 4Runner: " << device.name() << device.rssi() << device.coreConfigurations() << "(" << device.address().toString() << ")";


    }
    else {
        qDebug() << "found other bt device";
    }
}
