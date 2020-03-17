#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
//    QTranslator tr_en;
//    {
//        QLocale::setDefault( QLocale{ QStringLiteral("en_GB") } );
//        tr_en.load("l10n/qml-l10n-idbased-example_en_GB");
//        app.installTranslator(&tr_en);
//    }

    QTranslator tr_fr;
    {
        QLocale::setDefault( QLocale{ QStringLiteral("fr_FR") } );
        tr_fr.load("l10n/qml-l10n-idbased-example_fr_FR");
        app.installTranslator(&tr_fr);
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
