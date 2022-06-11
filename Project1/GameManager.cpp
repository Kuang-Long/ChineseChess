#include "GameManager.h"
GameManager::GameManager() {
    // :P
}
void GameManager::start() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    System::Drawing::Icon^ myIcon = gcnew System::Drawing::Icon("1111.ico");
    Project1::menu form1;
    form1.Text = "Menu";
    form1.Icon = myIcon;
    form1.Width = 243;
    Application::Run(% form1);
A:
    if (startGame) {
        startGame = 0;
        Project1::MyForm form;
        p1Win = 0;
        p2Win = 0;
        Map.clear();
        form.Icon = myIcon;
        System::Drawing::Image^ myImage = gcnew System::Drawing::Bitmap("1.png");
        form.BackgroundImage = myImage;
        form.Text = "ถHดั";
        form.Height = 658;
        form.Width = 673;
        Application::Run(% form);
    }
    if (p1Win) {
        p1Win = 0;
        Project1::EndGame endG;
        System::Drawing::Image^ myImage = gcnew System::Drawing::Bitmap("3.png");
        endG.BackgroundImage = myImage;
        Application::Run(% endG);
    }
    else if (p2Win) {
        p2Win = 0;
        Project1::EndGame endG;
        System::Drawing::Image^ myImage = gcnew System::Drawing::Bitmap("2.png");
        endG.BackgroundImage = myImage;
        endG.Icon = myIcon;
        Application::Run(% endG);
    }
    if (startGame) {
        goto A;
    }
}