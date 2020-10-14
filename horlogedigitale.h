#ifndef HORLOGEDIGITALE_H
#define HORLOGEDIGITALE_H
#include <qglobal.h>
#if QT_VERSION >= 0x050100
#include <QtWidgets/QLCDNumber> /* Qt5 */
#else
#include <QtGui/QLCDNumber> /* Qt4 */
#endif
#include <QTimer>
// réglage au dixième de secondes
#define PERIODE 100

class HorlogeDigitale : public QLCDNumber
{
    Q_OBJECT
    public:
    HorlogeDigitale(QWidget *parent=NULL);
    ~HorlogeDigitale();
    long getMinute();
    long getHeure();
    void fixer(int h, int m);
    private:
    QTimer *m_timer;
    long m_valeur;
    void update();
    private slots:
    void tic();
    public slots:
    void demarrer(int top=PERIODE);
    void arreter();
    };
#endif // IHMHORLOGE_H
