#include "ihmhorloge.h"
#include "horlogedigitale.h"
#include <QPushButton>
#include <QDebug>

IHMHorloge::IHMHorloge(QWidget *parent) : QWidget(parent)
{
// Les widgets
    horloge = new HorlogeDigitale(this);
    editionHeure = new QTimeEdit(QTime::currentTime(), this);
    editionHeure->setDisplayFormat("HH:mm");
    boutonReglage = new QPushButton("Régler");
    boutonReglage->setDefault(true);
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setShortcut(QKeySequence(QKeySequence::Quit)); // Ctrl+Q
    addAction(actionQuitter);
// Le positionnement
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(horloge);
    layoutPrincipal->addWidget(editionHeure);
    layoutPrincipal->addWidget(boutonReglage);
//layoutPrincipal->addStretch();
    setLayout(layoutPrincipal);
// Les signaux/slots
    connect(this, SIGNAL(depart(int)), horloge, SLOT(demarrer(int)));
    connect(this, SIGNAL(arret()), horloge, SLOT(arreter()));
    connect(boutonReglage, SIGNAL(clicked()), this, SLOT(regler()));
    connect(actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
// La fenêtre
    setWindowTitle("Horloge digitale");
//setFixedHeight(sizeHint().height());
//setFixedWidth(sizeHint().width());
// reste en avant plan sans la barre de titre (déplacer avec Alt+clic gauche)
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
// le menu contextuel
    setContextMenuPolicy(Qt::ActionsContextMenu);

// Initialisation
    horloge->fixer(editionHeure->time().hour(), editionHeure->time().minute());
    emit depart(PERIODE); // démarrage de l’horloge
}

IHMHorloge::~IHMHorloge()
{
// arrêt de l’horloge
    emit arret();
    qDebug() << "~IHMHorloge()";
}
void IHMHorloge::regler()
{
// arrêt de l’horloge
    emit arret();
// paramétrage de l’horloge
    int minutes = editionHeure->time().minute();
    int heures = editionHeure->time().hour();
    horloge->fixer(heures, minutes);
// redémarrage de l’horloge
    emit depart(PERIODE);
}

void IHMHorloge::quitter()
{
    // on ferme la fenêtre
    close();
}
