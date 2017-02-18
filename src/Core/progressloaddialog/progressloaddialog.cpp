#include "progressloaddialog.h"

ProgressLoadDialog::ProgressLoadDialog(QWidget *parent) :
    QWidget(parent), progressAnimation( ":/processloaddialog/gfx/loading.gif")
{
    configWidget();
}

ProgressLoadDialog::~ProgressLoadDialog()
{
    progressAnimation.stop();
    delete animationLabel;
    delete outLabel;
    delete staticTextLabel;
}

void ProgressLoadDialog::setNameLoadFile(const QString &FileName)
{
    outLabel->setText("Load file: "+FileName);
}

void ProgressLoadDialog::configWidget()
{
    setWindowTitle("Open project ...");
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    setFixedSize(300,100);
    createLabel();
    configAnimation();
}

void ProgressLoadDialog::createLabel()
{
    animationLabel = new QLabel(this);
    outLabel = new QLabel(this);
    staticTextLabel = new QLabel(this);
    configLabel();
}

void ProgressLoadDialog::configLabel()
{
    animationLabel->setGeometry(25,0,100,100);
    outLabel->setGeometry(100,35,200,50);
    staticTextLabel->setGeometry(100,10,200,50);
    staticTextLabel->setText("Please wait ...");
}

void ProgressLoadDialog::configAnimation()
{
    animationLabel->setMovie(&progressAnimation);
    progressAnimation.start();
}
