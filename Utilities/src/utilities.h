#ifndef UTILITIES_H
#define UTILITIES_H

#define __PLACE__ __FILE__ << __LINE__

void printBitsChar(char byte)
{
    QString number;
    number = QString::number(byte) + " as quint8: ";
    for (int i = 0; i < 8; i++) {
          number += QString::number(!!((byte << i) & 0x80));
    }
    qDebug() << number;
};

void printBitsQUint8(quint8 byte)
{
    QString number;
    number = QString::number(byte) + " as quint8: ";
    for (int i = 0; i < 8; i++) {
          number += QString::number(!!((byte << i) & 0x80));
    }
    qDebug() << number;
};

void printBitsQint8(qint8 byte)
{
    QString number;
    number = QString::number(byte) + " as qint8: ";
    for (int i = 0; i < 8; i++) {
          number += QString::number(!!((byte << i) & 0x80));
    }
    qDebug() << number;
};


#endif // UTILITIES_H
