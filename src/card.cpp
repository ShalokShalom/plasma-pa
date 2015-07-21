#include "card.h"

#include <QDebug>

#include "context.h"

namespace QPulseAudio
{

Card::Card(QObject *parent)
    : PulseObject(parent)
{
}

void Card::update(const pa_card_info *info)
{
    updatePulseObject(info);

    QString infoName = QString::fromUtf8(info->name);
    if (m_name != infoName) {
        m_name = infoName;
        emit nameChanged();
    }

    qDeleteAll(m_profiles);
    m_profiles.clear();
#warning more inconsistent api... profiles end with entry with name on null...
#warning profiles2 fixes this
    for (auto *it = info->profiles; it->name != nullptr; ++it) {
        Profile *profile = new Profile(this);
        profile->setInfo(it);
        m_profiles.append(profile);
        if (info->active_profile == it) {
            m_activeProfileIndex = m_profiles.length() - 1;
        }
    }
    emit profilesChanged();
    emit activeProfileIndexChanged();

    qDeleteAll(m_ports);
    m_ports.clear();
    for (auto **it = info->ports; it && *it != nullptr; ++it) {
        CardPort *port = new CardPort(this);
        port->update(*it);
        m_ports.append(port);
    }
    emit portsChanged();
}

void Card::setActiveProfileIndex(quint32 profileIndex)
{
    const Profile *profile = qobject_cast<Profile *>(profiles().at(profileIndex));
    context()->setCardProfile(index(), profile->name());
}

} // QPulseAudio
