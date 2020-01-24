#include <QPushButton>
#include <QPainter>
#include "AboutDialog.h"

AboutDialog::AboutDialog(QWidget* parent):
    QDialog(parent),
    okButton(new QPushButton(this)),
    labelInfo(new QLabel(this)),
    verticalLayout(new QVBoxLayout(this))
{
    const int BUTTON_W = 120;
    const int BUTTON_H = 24;

    okButton->setText("Ok");
    okButton->resize(BUTTON_W, BUTTON_H);
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    labelInfo->setText(tr("Sea-Battle \nalpha-beta version RC 0.1"));

    const QString& labelStyle("QLabel {color : #00157f; font-weight: bold; }");
    labelInfo->setStyleSheet(labelStyle);

    labelInfo->setAlignment(Qt::AlignCenter);

    verticalLayout->addStretch();
    verticalLayout->addWidget(labelInfo);
    verticalLayout->addSpacing(BUTTON_H);
    verticalLayout->addWidget(okButton);
    setMinimumSize(200, 100);
}

void AboutDialog::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)
    QPainter painter(this);
}
