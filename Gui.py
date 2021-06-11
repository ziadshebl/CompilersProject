import sys
import subprocess
from PyQt5 import QtCore
from PyQt5 import QtGui
from PyQt5.QtGui import QFont, QIcon, QPixmap
from PyQt5.QtWidgets import (
    QApplication,
    QFileDialog,
    QFrame,
    QGridLayout,
    QLabel,
    QPlainTextEdit,
    QPushButton,
    QTabWidget,
    QWidget,
)


class Window(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Msh Visual Studio Code")
        self.setMinimumSize(500,500)
        self.setStyleSheet("background-color: #252526")
        
        self.build_button=QPushButton(self)
        build_icon = QtGui.QIcon()
        build_icon.addPixmap(QtGui.QPixmap("./settings.ico"),
                       QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.build_button.setIcon(build_icon)
        self.build_button.clicked.connect(self.build_button_handler)
        self.build_button.setStyleSheet("background-color: #1e1e1e")
        
        self.run_button=QPushButton(self)
        run_icon = QtGui.QIcon()
        run_icon.addPixmap(QtGui.QPixmap("./run.ico"),
                       QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.run_button.setIcon(run_icon)
        #self.browse_file.clicked.connect(self.run_button_handler)
        self.run_button.setStyleSheet("background-color: #1e1e1e")

        self.input_code_text_area = QPlainTextEdit(self)
        self.input_code_text_area.insertPlainText("Add your code here\n")
        self.input_code_text_area.setFont(QFont('Arial', 15))
        self.input_code_text_area.setStyleSheet("color: #128ead;  background-color: #1e1e1e")


        self.output_quadruples_text_area = QPlainTextEdit(self)
        self.output_quadruples_text_area.setReadOnly(True)
        self.output_quadruples_text_area.setStyleSheet("color: #128ead;  background-color: #1e1e1e")


        self.debug_console_text_area = QPlainTextEdit(self)
        self.debug_console_text_area.setReadOnly(True)
        self.debug_console_text_area.setStyleSheet("color: #128ead;  background-color: #1e1e1e")


        self.debug_console_label=QLabel("Debug console",self)
        self.debug_console_label.setStyleSheet("color:white")

        self.browse_file=QPushButton("Import code",self)
        self.browse_file.setStyleSheet("color: white;  background-color: #1e1e1e")
        self.browse_file.clicked.connect(self.browse_file_handler)


        self.save_file=QPushButton("Export quadruples",self)
        self.save_file.setStyleSheet("color: white;  background-color: #1e1e1e")
        self.save_file.clicked.connect(self.save_file_handler)


        self.show_symbol_tables=QPushButton("Show symbol tables",self)
        self.show_symbol_tables.setStyleSheet("color: white;  background-color: #1e1e1e")
        self.show_symbol_tables.clicked.connect(self.show_symbol_tables_handler)

        
        
        layout = QGridLayout()
        layout.addWidget(self.build_button,0,0)
        layout.addWidget(self.run_button,0,1)
        layout.addWidget(self.input_code_text_area,1,0)
        layout.addWidget(self.output_quadruples_text_area,1,1)
        layout.addWidget(self.browse_file,2,0)
        layout.addWidget(self.save_file,2,1)
        layout.addWidget(self.show_symbol_tables,3,0,1,2)
        layout.addWidget(self.debug_console_label,4,0,1,2)
        layout.addWidget(self.debug_console_text_area,5,0,1,2)

        self.setLayout(layout)

    def browse_file_handler(self):
      file_name=None
      file_name = QFileDialog.getOpenFileName(self, 'Open file')
      if file_name is not None:
        file=open(file_name[0],"r")
        self.input_code_text_area.setPlainText(file.read())

    def save_file_handler(self):
      file_name=None
      file_name = QFileDialog.getOpenFileName(self, 'Open file')
      if file_name is not None:
        file=open(file_name[0],"w")
        file.write( self.output_quadruples_text_area.toPlainText())
    def show_symbol_tables_handler(self):
        None
        
    def build_button_handler(self):
        with open("D:/Spring 2021/Languages and compilers/Project/Project/CompilersProject/code.txt", "w") as code_file:
            code_file.write(str(self.input_code_text_area.toPlainText()))
        subprocess.call([r'D:/Spring 2021/Languages and compilers/Project/Project/CompilersProject/run.bat'])
        error_file =open("D:/Spring 2021/Languages and compilers/Project/Project/CompilersProject/error.txt","r")
        quadruples_file=open("D:/Spring 2021/Languages and compilers/Project/Project/CompilersProject/output.txt","r")
        error_file=error_file.read()
        self.debug_console_text_area.setPlainText(error_file)
        quadruples_file=quadruples_file.read()
        self.output_quadruples_text_area.setPlainText(quadruples_file)
        
        


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Window()
    window.show()
    sys.exit(app.exec_())




