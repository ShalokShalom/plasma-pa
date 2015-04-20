#ifndef CARD_H
#define CARD_H

#include <pulse/introspect.h>

#include <QMap>
#include <QVariant>

#include "profile.h"
#include "pulseobject.h"

class Q_DECL_EXPORT Card : public PulseObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QList<QObject *> profiles READ profiles  NOTIFY profilesChanged)
    Q_PROPERTY(quint32 activeProfileIndex READ activeProfileIndex WRITE setActiveProfileIndex NOTIFY activeProfileIndexChanged)
    Q_PROPERTY(QVariantMap properties READ properties NOTIFY propertiesChanged)
public:
    Card(QObject *parent);

    void update(const pa_card_info *info);

    QString name() const { return m_name; }

    QList<QObject *> profiles() const { return m_profiles; }
    quint32 activeProfileIndex() const { return m_activeProfileIndex; }

    void setActiveProfileIndex(quint32 profileIndex);
    QMap<QString, QVariant> properties() const { return m_properties; }

signals:
    void nameChanged();
    void profilesChanged();
    void activeProfileIndexChanged();
    void propertiesChanged();

private:
    QString m_name;

    QList<QObject *> m_profiles;
    quint32 m_activeProfileIndex;

    QVariantMap m_properties;
};

#endif // CARD_H
