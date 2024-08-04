#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void drawFigure(int centerX, int centerY, int handOffsetY) {
    int radius = 100;
    setfillstyle(SOLID_FILL, CYAN);

    // Head Outer Circle
    circle(centerX, centerY - 100, radius);

    // Head Inner Circle
    circle(centerX, centerY - 88, radius - 12);
    floodfill(centerX + 2, centerY - 102, WHITE);
    setfillstyle(SOLID_FILL, CYAN);

    // Body Outer Circle
    circle(centerX, centerY + 100, radius);

    // Body Inner Circle
    circle(centerX, centerY + 88, radius - 12);
    floodfill(centerX + 2, centerY + 98, WHITE);
    setfillstyle(SOLID_FILL, RED);

    // NOSE
    circle(centerX + 2, centerY - 86, 10);
    floodfill(centerX + 4, centerY - 84, WHITE);

    // Eyes
    circle(centerX - 40, centerY - 130, 15);
    circle(centerX + 40, centerY - 130, 15);

    // Mustaches
    line(centerX - 90, centerY - 86, centerX - 140, centerY - 86);
    line(centerX - 90, centerY - 86, centerX - 140, centerY - 104);
    line(centerX - 90, centerY - 86, centerX - 140, centerY - 68);
    
    line(centerX + 90, centerY - 86, centerX + 140, centerY - 86);
    line(centerX + 90, centerY - 86, centerX + 140, centerY - 104);
    line(centerX + 90, centerY - 86, centerX + 140, centerY - 68);

    // Nose-Mouth Connector
    line(centerX + 2, centerY - 76, centerX + 2, centerY - 60);

    // Mouth
    line(centerX - 35, centerY - 60, centerX + 35, centerY - 60);
    line(centerX - 35, centerY - 60, centerX + 2, centerY - 40);
    line(centerX + 2, centerY - 40, centerX + 35, centerY - 60);

    setfillstyle(SOLID_FILL, CYAN);

    // Hands
    line(centerX, centerY + handOffsetY, centerX + 150, centerY + 20 + handOffsetY);
    line(centerX, centerY + handOffsetY, centerX + 150, centerY + 40 + handOffsetY);
    line(centerX + 150, centerY + 20 + handOffsetY, centerX + 150, centerY + 40 + handOffsetY);
    floodfill(centerX + 145, centerY + 30 + handOffsetY, WHITE);
    
    line(centerX, centerY + handOffsetY, centerX - 150, centerY + 20 + handOffsetY);
    line(centerX, centerY + handOffsetY, centerX - 150, centerY + 40 + handOffsetY);
    line(centerX - 150, centerY + 20 + handOffsetY, centerX - 150, centerY + 40 + handOffsetY);
    floodfill(centerX - 145, centerY + 30 + handOffsetY, WHITE);
    circle(centerX + 165, centerY + 30 + handOffsetY, 15);
    circle(centerX - 165, centerY + 30 + handOffsetY, 15);

    // Pocket
    line(centerX - 55, centerY + 80, centerX + 55, centerY + 80);
    line(centerX - 55, centerY + 80, centerX, centerY + 120);
    line(centerX, centerY + 120, centerX + 55, centerY + 80);
    setfillstyle(SOLID_FILL, RED);
    floodfill(centerX, centerY + 100, WHITE);

    // Bell Pad
    line(centerX - 70, centerY - 2, centerX + 70, centerY - 2);
    line(centerX - 70, centerY + 8, centerX + 70, centerY + 8);
    line(centerX - 70, centerY - 2, centerX - 70, centerY + 8);
    line(centerX + 70, centerY - 2, centerX + 70, centerY + 8);
    floodfill(centerX - 68, centerY + 4, WHITE);
    floodfill(centerX + 68, centerY + 4, WHITE);
    floodfill(centerX, centerY + 5, WHITE);

    setfillstyle(SOLID_FILL, YELLOW);
    circle(centerX, centerY + 23, 15);
    floodfill(centerX + 2, centerY + 25, WHITE);

    // Inner Bell
    setcolor(BLACK);
    line(centerX - 15, centerY + 23, centerX + 15, centerY + 23);
    line(centerX - 15, centerY + 28, centerX + 15, centerY + 28);
    setcolor(WHITE);

    // Legs
    line(centerX - 50, centerY + 180, centerX - 50, centerY + 250);
    line(centerX - 30, centerY + 180, centerX - 30, centerY + 250);
    line(centerX + 50, centerY + 180, centerX + 50, centerY + 250);
    line(centerX + 30, centerY + 180, centerX + 30, centerY + 250);

    // Leg Pads
    rectangle(centerX - 60, centerY + 250, centerX - 20, centerY + 270);
    rectangle(centerX + 20, centerY + 250, centerX + 60, centerY + 270);
    
    // Leg Colors
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(centerX - 40, centerY + 200, WHITE);
    floodfill(centerX + 40, centerY + 200, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Play music The music file must be in the .wav format, so if you have an mp3 file, convert it to a .wav file online.
    sndPlaySound(TEXT("C:\\Users\\ashuj\\OneDrive\\Desktop\\CG C++\\Tunak-Tunak-Tun-Daler-Mehndi (mp3cut.net).wav"), SND_ASYNC);

    int winWidth = getmaxx();
    int winHeight = getmaxy();
    int centerX = winWidth / 2;
    int centerY = winHeight / 2;

    for (int i = 0; i < 50; i++) {
        cleardevice();
        int handOffsetY = (i % 2 == 0) ? -10 : 10;
        drawFigure(centerX, centerY, handOffsetY);
        delay(250);
    }

    getch();
    closegraph();
    return 0;
}
