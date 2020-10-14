#include <QApplication>
#include <QTextCodec>
#include "ihmhorloge.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Choix de l’encodage des caractères
    #if QT_VERSION >= 0x050000
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); /* Qt5 */
    #else
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); /* Qt4 */
    #endif
    IHMHorloge w;
    w.show();
    return a.exec();
}
