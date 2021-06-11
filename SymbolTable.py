from PyQt5.QtWidgets import QMainWindow, QApplication, QWidget, QAction, QTableWidget,QTableWidgetItem,QVBoxLayout
from PyQt5.QtGui import QIcon
from PyQt5.QtCore import pyqtSlot
import sys

data = {'lexemme':['1','2','3','4'],
        'dataType':['1','2','1','3'],
        'entryType':['1','1','2','1'],
        'functionparamterlist':['1','1','2','1'],
        'parameternumbers':['1','1','2','1'],}
 
class TableView(QTableWidget):
    def __init__(self, data, *args):
        QTableWidget.__init__(self, *args)
        self.data = data
        self.setData()
        self.resizeColumnsToContents()
        self.resizeRowsToContents()
 
    def setData(self): 
        horHeaders = []
        for n, key in enumerate(sorted(self.data.keys())):
            horHeaders.append(key)
            for m, item in enumerate(self.data[key]):
                newitem = QTableWidgetItem(item)
                self.setItem(m, n, newitem)
        self.setHorizontalHeaderLabels(horHeaders)
 
def main(args):
    app = QApplication(args)
    table = TableView(data, 4, 5)
    table.show()
    sys.exit(app.exec_())
 
if __name__=="__main__":
    main(sys.argv)