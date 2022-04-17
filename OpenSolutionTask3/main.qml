import QtQuick.Window 2.3
import QtQuick 2.9
import QtQuick.Controls 1.4 as QC1
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
Window{
    visible: true
    width: 1600
    height: 1000
    title:"Table of Transports"
    ColumnLayout{
        anchors.fill:parent
        QC1.TableView {
            id: view
            Layout.fillHeight: true
            Layout.fillWidth: true

            QC1.TableViewColumn{ role: "RoleUniqueIdentificator" ; title: "Уникальный идентификатор" }
            QC1.TableViewColumn{ role: "RoleTypeTransport" ; title: "Тип транспорта" }
            QC1.TableViewColumn{ role: "RoleYearManufacture" ; title: "Год выпуска" }
            QC1.TableViewColumn{ role: "RoleWeight" ; title: "Вес" }
            QC1.TableViewColumn{ role: "RoleBrand" ; title: "Марка" }
            QC1.TableViewColumn{ role: "RoleModel" ; title: "Модель" }
            model: TransportModel
    }
    GridLayout{
        Layout.fillHeight: true
        Layout.fillWidth: true
        Label{
            Layout.column: 0
            Layout.row: 0
            text: "Введите уникальный идентификатор транспорта, который хотите удалить"
        }
       TextField{
           id:uniqueIdForDelete
           Layout.column: 1
           Layout.row: 0
       }
       Button{
           Layout.column: 2
           Layout.row: 0
           text: "Удалить"
       }
       Label{
           Layout.column: 0

           Layout.row: 1
           text: "Тип транспорта"
       }
       TextField{
           id:typeTransportEdit
           Layout.column: 1
           Layout.row: 1
       }
       Label{

           Layout.column: 2

           Layout.row: 1
           text: "Год выпуска"
       }
       TextField{
           id:yearManufactureEdit
           Layout.column: 3
           Layout.row: 1
       }
       Label{
           Layout.column: 4

           Layout.row: 1
           text: "Вес"
       }
       TextField{
           id:weightEdit
           Layout.column: 5
           Layout.row: 1
       }
       Label{
           Layout.column: 6

           Layout.row: 1
           text: "Марка"
       }
       TextField{
           id:brandEdit
           Layout.column: 7
           Layout.row: 1

       }
       Label{

           Layout.column: 8

           Layout.row: 1
           text: "Модель"
       }
       TextField{
            id:modelEdit
           Layout.column: 9
           Layout.row: 1
       }
       Button{
           Layout.column: 10
           Layout.row: 1
           text: "Добавить"

           onClicked:TransportModel.appendTransport(typeTransportEdit.text,yearManufactureEdit.text,
                                                    weightEdit.text,brandEdit.text,modelEdit.text);
          // onClicked:console.log(typeTransportEdit.text);
       }
       Button{
           Layout.column: 3
           Layout.row: 0
           text: "Добавить данные в файл"
       }
       Button{
           Layout.column: 4
           Layout.row: 0
           text: "Добавить данные из файла"
       }



    }
   }
}
/*
TransportWidget::TransportWidget( QWidget* parent ) : QWidget( parent ) {

    QPushButton* removeButton = new QPushButton("Удалить");
    connect( removeButton, SIGNAL( clicked()), SLOT( deleteTransport()));
    panelLayout->addWidget( removeButton, 0, 2 );


    QPushButton* createButton = new QPushButton("Добавить");
    connect( createButton, SIGNAL( clicked() ), SLOT( onAppend() ) );
    panelLayout->addWidget( createButton, 1, 10 );

    QPushButton* dataInFileButton = new QPushButton("Добавить данные в файл");
    connect(dataInFileButton,SIGNAL(clicked()),ModelTransport,SLOT(printTransportTableInFile()));
    panelLayout->addWidget( dataInFileButton, 0, 3 );

    QPushButton* dataOutFileButton = new QPushButton("Добавить данные из файла");
    connect( dataOutFileButton, SIGNAL( clicked() ),ModelTransport,SLOT(printTranportTableOutFile()) );
    panelLayout->addWidget( dataOutFileButton, 0, 4 );


}

TransportWidget::~TransportWidget() {
}
void TransportWidget::deleteTransport(){
    ModelTransport->removeSelected(deleteTransportEdit->text());
    deleteTransportEdit->clear();
}
void TransportWidget::onAppend() {
    ModelTransport->appendTransport(
        typeTransportEdit->text(),
        weightEdit->text(),
        yearManufactureEdit->text(),
        brandEdit->text(),
        modelEdit->text()
    );
    typeTransportEdit->clear();
    weightEdit->clear();
    yearManufactureEdit->clear();
    typeTransportEdit->clear();
    brandEdit->clear();
    modelEdit->clear();
}



____________________________

private slots:
    void onAppend();
    void deleteTransport();

private:
    QTableView* TransportView;
    TransportModel* ModelTransport;

    QLineEdit* typeTransportEdit;
    QLineEdit* yearManufactureEdit;
    QLineEdit* brandEdit;
    QLineEdit* modelEdit;
    QLineEdit* weightEdit;
    QLineEdit* deleteTransportEdit;
};

#endif // TRANSPORTWIDGET_H




*/


