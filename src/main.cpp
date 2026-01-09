#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "NoteModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<NoteModel>("App", 1, 0, "NoteModel");

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/App/content/Main.qml"));
    
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) { QCoreApplication::exit(-1); }
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}