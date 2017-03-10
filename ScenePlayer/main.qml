import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.2

Window {
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
//						onTextChanged: pbuOK.enabled = true
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
						sidebarVisible: false
						nameFilters: [
							"Fichiers scénario (*.scn)",
							"All files (*)"
						]
						onAccepted: pbuOK.enabled = true
					}
				}

				Component {
					id: scnHeader
					Rectangle {
						width: main.width
						height: 40
						border.width: 1
						border.color: "black"
						color: "#808080"
						Row {
							spacing: 10
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtAction
									width: parent.width
									text: "<b>Action</b>"
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtDeclencheur
									width: parent.width
									text: "<b>Declencheur</b>"
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
						}
					}
				}

				Component {
					id: scnDelegate
					Rectangle {
						width: main.width
						height: {
							if (txtDeclencheur.implicitHeight < 40 ) {
								return 40 ;
							}
							else {
								return txtDeclencheur.implicitHeight ;
							}
						}
						border.width: 1
						border.color: "black"
						color: "transparent"

						Row {
							spacing: 10
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtAction
									width: parent.width
									text: action
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
							Column {
								padding: 10
								width: main.width / 2
								Text {
									id: txtDeclencheur
									width: parent.width
									text: declencheur
									horizontalAlignment: Text.AlignHCenter
									verticalAlignment: Text.AlignVCenter
									wrapMode: Text.WordWrap
									elide: Text.ElideRight
								}
							}
						}
						MouseArea {
							anchors.fill: parent
							onClicked: scnListView.currentIndex = index
						}
					}
				}

				ListView {
					id: scnListView
					interactive: false
					Layout.fillWidth: true
					Layout.fillHeight: true
					model: scnModel
					header: scnHeader
					delegate: scnDelegate
					highlight: Rectangle { color: "lightsteelblue"; radius: 5 }
					focus: true
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

//				TableView {
//					id: scnView
//					Layout.fillWidth: true
//					Layout.fillHeight: true
//					TableViewColumn {
//						role: "action"
//						title: "Action"
//						width : scnView.viewport.width / 2
//					}
//					TableViewColumn {
//						role: "declencheur"
//						title: "Déclencheur"
//						width:scnView.viewport.width / 2
//					}
//					model: scnModel
//					onClicked: pbuDeclencher.enabled = true
//				}

				WorkerScript {
					id: worker
					source: "dataloader.js"
				}

				RowLayout {
					id: footer
					Layout.alignment: Qt.AlignRight | Qt.AlignVCenter

					Button {
						id: pbuQuitter
						text: qsTr("Quitter")
						onClicked: messageQuitter.open()
					}

					MessageDialog {
						id: messageQuitter
						title: "Quitter ?"
						icon: StandardIcon.Question
						text: "Voulez vous vraiment quitter ScenePlayer"
						standardButtons: StandardButton.Yes | StandardButton.No
						onYes: sP.close()
					}

					Button {
						id: pbuRestart
						text: qsTr("Recommencer")
						enabled: false
						onClicked: messageRestart.open()
					}

					MessageDialog {
						id: messageRestart
						title: "Recommencer ?"
						icon: StandardIcon.Question
						text: "Voulez vous réinitialiser le scénario courant ?"
						standardButtons: StandardButton.Yes | StandardButton.No
						onYes: {
							loadScn(txtSCN.text);
							pbuRestart.enabled = false;
						}
					}

					Button {
						id: pbuDeclencher
						enabled: {
							if (scnListView.count != 0)
								return true ;
							return false ;
						}

						text: qsTr("Déclencher")
						onClicked: {
							var msg = {
								'action': 'deleteEvent',
								'model': scnModel,
								'index': scnListView.currentIndex
							};
							worker.sendMessage(msg);
							scnListView.remove ;
							pbuRestart.enabled = true ;
							endScn(scnModel.count) ;
						}
					}

					MessageDialog {
						id: messageEnd
						title: "Fin du scénario"
						icon: StandardIcon.Information
						text: "Le scénario est terminé"
						standardButtons: StandardButton.Ok
						onAccepted: close()
					}

					Button {
						id: pbuOK
						text: qsTr("Charger")
						enabled: false
						onClicked: {
							loadScn(txtSCN.text);
							enabled = false;
							pbuRestart.enabled = false;
						}
					}
				}
			}
		}
	}
	function loadScn(file)
	{
		parser.parse(file) ;
		var restart = {
			'action': 'restartScn',
			'model': scnModel
		};
		worker.sendMessage(restart) ;

		var i = 0 ;
		for (i = 0 ; i < parser.getSize() ; i++) {
			var msg = {
				'action': 'addEvent',
				'model': scnModel,
				'name': parser.getEventName(i),
				'type': parser.getEventType(i),
				'index': i
			};
			worker.sendMessage(msg) ;
		}
	}
	function endScn(nbRow)
	{
		if (nbRow == 1) {
			messageEnd.open() ;
		}
	}
}
