#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "transportmodel.h"

int main(int argc, char *argv[])
{
    /*QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();*/
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

        QGuiApplication app(argc, argv);

        QQmlApplicationEngine engine;
        const QUrl url(QStringLiteral("qrc:/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                         &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
       // TransportModel transportModel;
       // engine.rootContext()->setContextProperty("TransportModel",&transportModel);
        engine.load(url);
        return app.exec();

}
