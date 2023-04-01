#include <chrono>
#include <iostream>
#include <stdio.h>
#include <thread>
#include <Windows.h>

// SPECS

#define LEFT_MONITOR_HEIGHT 2560
#define LEFT_MONITOR_WIDTH 1080

#define RIGHT_MONITOR_HEIGHT 1440
#define RIGHT_MONITOR_WIDTH 3440

#define HEIGHT_OFFSET 1863

// UI

#define ACTION_OFFSET_X 464
#define ACTION_OFFSET_Y 478

#define ADD_KEYBIND_OFFSET_X 800
#define ADD_KEYBIND_OFFSET_Y 742

#define ESC_OFFSET_X 890
#define ESC_OFFSET_Y 780

#define KEYBINDS_OFFSET_X 200
#define KEYBINDS_OFFSET_Y 264

#define RECORD_KEYBIND_OFFSET_X 790
#define RECORD_KEYBIND_OFFSET_Y 480

#define SETTINGS_OFFSET_X 216
#define SETTINGS_OFFSET_Y 22

#define TOGGLE_MUTE_OFFSET_X 402
#define TOGGLE_MUTE_OFFSET_Y 324

#define BASE_X -LEFT_MONITOR_WIDTH
#define BASE_Y HEIGHT_OFFSET

void click()
{
  INPUT Inputs[2] = {0};

  Inputs[0].type = INPUT_MOUSE;
  Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

  Inputs[1].type = INPUT_MOUSE;
  Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

  SendInput(2, Inputs, sizeof(INPUT));
}

void move(int x, int y)
{
  SetCursorPos(BASE_X + x, BASE_Y - y);
}

void sleep(int time)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void clickAction(int x, int y)
{
  move(x, y);
  click();
  sleep(1000);
}

int main()
{
  clickAction(SETTINGS_OFFSET_X, SETTINGS_OFFSET_Y);

  clickAction(KEYBINDS_OFFSET_X, KEYBINDS_OFFSET_Y);

  clickAction(ADD_KEYBIND_OFFSET_X, ADD_KEYBIND_OFFSET_Y);

  clickAction(ACTION_OFFSET_X, ACTION_OFFSET_Y);

  clickAction(TOGGLE_MUTE_OFFSET_X, TOGGLE_MUTE_OFFSET_Y);

  clickAction(RECORD_KEYBIND_OFFSET_X, RECORD_KEYBIND_OFFSET_Y);

  return 0;
}