#include <QPushButton>
#include <QPainter>
#include <QUrl>
#include <QDesktopServices>
#include "Images.h"
#include "AboutDialog.h"
#include "SupportDialog.h"

SupportDialog::SupportDialog(QWidget* parent):
    QDialog(parent),
    okButton(new QPushButton(this)),
    labelURL(new QLabel(this)),
    labelInfo(new QLabel(this)),
    verticalLayout(new QVBoxLayout(this))
{
    const int BUTTON_W = 120;
    const int BUTTON_H = 24;

    okButton->setText("Ok");
    okButton->resize(BUTTON_W, BUTTON_H);
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    labelURL->setText(tr("<a href=\"https://money.yandex.ru/to/410011232719535\"> Support Us </a>"));
    labelInfo->setText(tr("It's a joke"));

    const QString& labelStyle("QLabel { color : #00157f; font-weight: bold; }");
    labelURL->setStyleSheet(labelStyle);
    labelInfo->setStyleSheet(labelStyle);

    labelURL->setAlignment(Qt::AlignCenter);
    labelInfo->setAlignment(Qt::AlignCenter);

    verticalLayout->addStretch();
    verticalLayout->addWidget( labelInfo );
    verticalLayout->addWidget( labelURL );
    verticalLayout->addSpacing( BUTTON_H );
    verticalLayout->addWidget( okButton );
    setMinimumSize(200, 100);

    connect(labelURL,SIGNAL(linkActivated(QString)),this,
                     SLOT(on_labelURL_clicked(QString)));
    }

    void SupportDialog::paintEvent(QPaintEvent* event)
    {
        Q_UNUSED(event)
        QPainter painter(this);
    }

    void SupportDialog::on_labelURL_clicked(const QString& url)
    {
        QDesktopServices::openUrl(QUrl(url));
    }
