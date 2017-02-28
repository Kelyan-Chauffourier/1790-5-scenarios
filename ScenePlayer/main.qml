import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

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
						text: fileDialog.fileUrl
						readOnly: true
						placeholderText: "chemin d'accès"
						Layout.fillWidth: true
					}
					Button {
						id: pbuSCN
						text: qsTr("...")
						Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
						onClicked: fileDialog.open()
					}
					FileDialog {
						id: fileDialog
						title: "Charger un scénario"
						nameFilters: ["Fichiers scénario (*.scn)", "All files (*)"]
						onAccepted: pbuOK.enabled = true
					}
				}

				ListModel {
					id: scnModel
					ListElement {
						action : "A1 description de A1"
						declencheur : "D1 description de D1"
					}
					ListElement {
						action : "A2 description de A2"
						declencheur : "D2 description de D2"
					}
					ListElement {
						action : "A3 description de A3"
						declencheur : "D3 description de D3"
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
					model: scnModel
				}

				WorkerScript {
					id: worker
					source: "dataloader.js"
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
						enabled: false
						onClicked: {
							parser.parse(txtSCN.text) ;
							enabled = false ;
							scnModel.clear() ;
							var i = 0 ;
							for (i = 0 ; i < parser.getSize() ; i++) {
								var msg = {
									'action': 'addEvent',
									'model': scnModel,
									'name': parser.getEventName(i),
									'type': parser.getEventType(i)
								};
								worker.sendMessage(msg) ;
							}
						}
					}
				}
			}
		}
	}
}
