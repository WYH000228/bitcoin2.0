#ifndef BITCOIN2PUSHBUTTON_H
#define BITCOIN2PUSHBUTTON_H
#include <QPushButton>
#include <QStyleOptionButton>
#include <QIcon>

class BITCOIN2PushButton : public QPushButton
{
public:
    explicit BITCOIN2PushButton(QWidget * parent = Q_NULLPTR);
    explicit BITCOIN2PushButton(const QString &text, QWidget *parent = Q_NULLPTR);

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    void updateIcon(QStyleOptionButton &pushbutton);

private:
    bool m_iconCached;
    QIcon m_downIcon;
};

#endif // BITCOIN2PUSHBUTTON_H
