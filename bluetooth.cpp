#include <QObject>
#include "bluetooth.h"
#include <QDebug>
#include <QtBluetooth>

Bluetooth::Bluetooth(QObject *parent) : QObject(parent)
{
    qDebug() << "INIT??";

    this->getLocalDeviceInformation();
    this->startDeviceDiscovery();
}

QString Bluetooth::userName()
{
    return m_userName;
}

void Bluetooth::setUserName(const QString &userName)
{
    qDebug() << "Set user name: " << &userName;
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
    if (device.name() == "4RUNNER") {
        qDebug() << "Found the 4Runner: " << device.name() << device.rssi() << device.coreConfigurations() << "(" << device.address().toString() << ")";

        socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
        socket->connectToService(QBluetoothAddress(device.address()), QBluetoothUuid(QBluetoothUuid::SerialPort));
        connect(socket, SIGNAL(error(QBluetoothSocket::SocketError)), this, SLOT(socketError(QBluetoothSocket::SocketError)));
        connect(socket,SIGNAL(connected()), this, SLOT(socketConnected()));
        connect(socket, SIGNAL(readyRead()), this, SLOT(socketRead()));
        connect(socket, SIGNAL(stateChanged(QBluetoothSocket::SocketState)), this, SLOT(socketStateChanged()));
    }
    else {
        qDebug() << "found other bt device";
    }
}

void Bluetooth::socketRead()
{

}

void Bluetooth::socketDisconnected()
{
    qDebug() << "Socket disconnected";
    socket -> deleteLater();
}

void Bluetooth::socketError(QBluetoothSocket::SocketError error)
{
    qDebug() << "Socket error: " << error;
}

void Bluetooth::socketStateChanged()
{
    int socketState = socket->state();
    qDebug() << "Socket state changed: " << socketState;

    if (socketState == QAbstractSocket::UnconnectedState) {
        qDebug() << "UNCONNNECTED";
    }
    else if (socketState == QAbstractSocket::HostLookupState) {
        qDebug() << "HOST LOOKUP";
    }
    else if (socketState == QAbstractSocket::ConnectingState) {
        qDebug() << "CONNECTING";
    }
    else if (socketState == QAbstractSocket::ConnectedState) {
        qDebug() << "CONNECTED!!";
    }
    else if (socketState == QAbstractSocket::BoundState) {
        qDebug() << "BOUND";
    }
    else if (socketState == QAbstractSocket::ClosingState) {
        qDebug() << "CLOSING";
    }
    else if (socketState == QAbstractSocket::ListeningState) {
        qDebug() << "LISTENING";
    }
}

void Bluetooth::socketConnected()
{
    qDebug() << "Socket has been connected!! it's what you want really";
}

void Bluetooth::toggleRelayA()
{
    relayAStatus = !relayAStatus;
    qDebug() << "sending relay A a status of: " << relayAStatus;

    if (relayAStatus) {
        socket->write("a");
    }
    else {
        socket->write("b");
    }
}

void Bluetooth::toggleRelayB()
{
    relayBStatus = !relayBStatus;
    qDebug() << "sending relay B a status of: " << relayBStatus;

    if (relayBStatus) {
        socket->write("c");
    }
    else {
        socket->write("d");
    }
}

void Bluetooth::toggleRelayC()
{
    relayCStatus = !relayCStatus ;
    qDebug() << "sending relay C a status of: " << relayCStatus ;

    if (relayCStatus) {
        socket->write("e");
    }
    else {
        socket->write("f");
    }
}

void Bluetooth::toggleRelayD()
{
    relayDStatus = !relayDStatus;
    qDebug() << "sending relay D a status of: " << relayDStatus;

    if (relayDStatus) {
        socket->write("g");
    }
    else {
        socket->write("h");
    }
}
