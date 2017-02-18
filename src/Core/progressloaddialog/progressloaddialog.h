#ifndef PROGRESSLOADDIALOG_H
#define PROGRESSLOADDIALOG_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QMovie>

class ProgressLoadDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressLoadDialog(QWidget *parent = 0);
    ~ProgressLoadDialog();
    void setNameLoadFile(const QString &FileName);

private:
    QMovie progressAnimation;
    QLabel *animationLabel;
    QLabel *outLabel;
    QLabel *staticTextLabel;

    void configWidget();

    void createLabel();
    void configLabel();
    void configAnimation();

};

#endif // PROGRESSLOADDIALOG_H
