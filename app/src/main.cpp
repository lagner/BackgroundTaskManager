#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QAbstractItemModel>
#include <QtQml>
#include "context.h"
#include "common.h"

namespace {

const char* APP_DOMAIN = "com.custom";

}

void registerTypes()
{
    // @uri com.custom
    qmlRegisterUncreatableType<QAbstractItemModel>(
                APP_DOMAIN, 1, 0, "AbstractItemModel",
                "AbstractItemModel can not be created from QML");

    qRegisterMetaType<MentionsHashShared>("MentionsHashShared");
}


int main(int argc, char *argv[])
{
    QGuiApplication qtApp(argc, argv);
    QQmlApplicationEngine engine;

    registerTypes();

    Context appContext;

    QQmlContext* qmlContext = engine.rootContext();
    qmlContext->setContextProperty("Context", &appContext);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return qtApp.exec();
}

