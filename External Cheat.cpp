#include <Windows.h>
#include <iostrream>

using namespace std;

int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d){
  int value = 2000;
  int value2 = 2000;
  HWND p = FindWindowA(NULL, "ac_client.exe");
  if(p == NULL){
    cout << "Couldn't find." << endl;
    Sleep(5000);
    exit(0);
  } else {
    DWORD proc;
    GetWindowThreadProcessId(p, &proc);
    HANDLE b = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proc);
    if(proc == NULL){
      cout << "Couldn't get process." << endl;
      Sleep(5000);
      exit(0);
    } else {
      cout << "Press SPACE for health." << endl;
      cout << "Press BACKSPACE for ammo." << endl;
      if(GetAsyncKeyState(VK_SPACE)){
        WriteProcessMemory(b, (LPVOID)000DF73C, &value, sizeof(value), 0);
        cout << "Health: " << value << endl;
        value++;
      } else if(GetAsyncKeyState(VK_END)){
        WriteProcessMemory(b, (LPVOID)000DF73C, &value2, sizeof(value2), 0);
        cout << "Ammo: " << value2 << endl;
        value2++;
      }
    }
  }
  return 0;
}
