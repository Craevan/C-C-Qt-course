#ifndef SUPPORTDIALOG_H
#define SUPPORTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class SupportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupportDialog( QWidget* parent = nullptr);

public slots:
    void on_labelURL_clicked( const QString& url );

protected:
    void paintEvent( QPaintEvent* event );
    QPushButton* okButton;
    QLabel* labelURL;
    QLabel* labelInfo;
    QVBoxLayout* verticalLayout;
};

#endif // SUPPORTDIALOG_H
