import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0

ApplicationWindow {
	id: sP
	visible: true
	width: 640
	height: 480
	title: qsTr("ScenePlayer")

	Rectangle {
		id: main
		color: "#ffffff"
		anchors.fill: parent
		ColumnLayout {
			anchors.fill: parent

			Text {
				id: appName
				text: "ScenePlayer"
				Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				font.pointSize: 15
			}

			ColumnLayout {
				id: columnLayout

				RowLayout {
					id: header
					Layout.fillWidth: true

					Label {
						id: labSCN
						text: qsTr("Fichier SCN : ")
					}

					TextField {
						id: txtSCN
						placeholderText: "chemin d'accès"
						Layout.fillWidth: true
					}
					Button {
						id: pbuSCN
						text: qsTr("...")
						Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
					}
				}

				TableView {
					Layout.fillWidth: true
					Layout.fillHeight: true
					TableViewColumn {
						role: "action"
						title: "Action"
						width : main.width / 2
					}
					TableViewColumn {
						role: "declencheur"
						title: "Déclencheur"
						width: main.width / 2
					}
					model: ScnModel {}
				}

				RowLayout {
					id: footer
					Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

					Button {
						id: pbuDeclencher
						text: qsTr("Déclencher")
					}

					Button {
						id: pbuOK
						text: qsTr("Valider")
					}
				}
			}
		}
	}
}
