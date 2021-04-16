#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionQuit_triggered();

    void on_actionselect_font_triggered();

    void on_actionfont_color_triggered();

    void on_actionfont_background_color_triggered();

    void on_actionAbout_Ot_triggered();

    void on_actionbold_triggered();

    void on_actionitalic_triggered();

    void on_actionunderline_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath;

};
#endif // MAINWINDOW_H
