/*
    Copyright 2017 Chris Holland <zrenfire@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

import QtQuick 2.0
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.components 2.0 as PlasmaComponents

PlasmaComponents.ToolButton {
    id: smallToolButton
    property real iconSize: units.iconSizes.small
    property real padding: units.smallSpacing
    property int size: Math.ceil(iconSize + padding * 2)
    implicitWidth: size
    implicitHeight: size
    property alias icon: icon.source

    PlasmaCore.IconItem {
        id: icon
        anchors.fill: parent
        anchors.margins: parent.padding

        // From Plasma's ToolButtonStyle:
        active: parent.hovered
        colorGroup: parent.hovered ? PlasmaCore.Theme.ButtonColorGroup : PlasmaCore.ColorScope.colorGroup
    }
}
