#ifndef TRANSPORTMODEL_H
#define TRANSPORTMODEL_H

#include <QAbstractListModel>

class TransportModel : public QAbstractListModel {
    Q_OBJECT
public:
    TransportModel( QObject* parent = 0 );

    int rowCount( const QModelIndex& parent ) const;
    int columnCount( const QModelIndex& parent ) const;
    QVariant data( const QModelIndex& index, int role ) const;
    bool setData( const QModelIndex& index, const QVariant& value, int role );

    Qt::ItemFlags flags( const QModelIndex& index ) const;
    QHash<int,QByteArray> roleNames() const;
    void fileappendTransport(const QString& idQ,const QString& typeTrQ,const QString& yearQ, const QString& weightQ,const QString& brandQ,const QString& modelQ);
    enum Roles{
        RoleUniqueIdentificator = Qt::UserRole+1,
        RoleTypeTransport,
        RoleYearManufacture,
        RoleWeight,
        RoleBrand,
        RoleModel,
    };
public slots:
    void appendTransport(const QString& typeTrQ,const QString& weightQ, const QString& yearQ,const QString& brandQ,const QString& modelQ);
    void removeSelected(const QString& deleteUniqueId);
    void printTransportTableInFile();
    void printTranportTableOutFile();


private:
    enum Column {
        uniqueIdentificator = 0,
        typeTransport,
        yearManufacture,
        weight,
        brand,
        model,
        LAST
    };

    typedef QHash< Column, QVariant > TransportData;
    typedef QList<TransportData > Transports;
    Transports tableTransports;

};
#endif // TRANSPORTMODEL_H
