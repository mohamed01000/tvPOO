#ifndef IHMHORLOGE_H
#define IHMHORLOGE_H

#include <qglobal.h>
#if QT_VERSION >= 0x050100
#include <QtWidgets> /* tous les widgets de Qt5 */
#else
#include <QtGui> /* tous les widgets de Qt4 */
#endif


QT_BEGIN_NAMESPACE
namespace Ui { class IHMHorloge; }
QT_END_NAMESPACE

class HorlogeDigitale;
class IHMHorloge : public QWidget
{
    Q_OBJECT

public:
    IHMHorloge(QWidget *parent = nullptr);
    ~IHMHorloge();

private:
    Ui::IHMHorloge *ui;
    // les widgets
    QPushButton *boutonReglage;
    HorlogeDigitale *horloge;
    QTimeEdit *editionHeure;

private slots :
       void regler();
       void quitter();

signals:
       void depart(int);
       void arret();

};
#endif // IHMHORLOGE_H
