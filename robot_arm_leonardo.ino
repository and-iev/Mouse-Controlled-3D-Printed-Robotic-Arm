#include <usbhub.h>
#include <SPI.h>
#include <hidboot.h>

USB Usb;
HIDBoot<USB_HID_PROTOCOL_MOUSE> HidMouse(&Usb);

int lmb = 0;
int rmb = 0;

class MouseRptParser : public MouseReportParser {
  void OnMouseMove(MOUSEINFO *mi) {
    Serial1.print(mi->dX);
    Serial1.print(",");
    Serial1.print(mi->dY);
    Serial1.print(",");
    Serial1.print(lmb);
    Serial1.print(",");
    Serial1.println(rmb);
  }

  void OnLeftButtonDown(MOUSEINFO *mi) { lmb = 1; }
  void OnLeftButtonUp(MOUSEINFO *mi)   { lmb = 0; }
  void OnRightButtonDown(MOUSEINFO *mi){ rmb = 1; }
  void OnRightButtonUp(MOUSEINFO *mi)  { rmb = 0; }
};

MouseRptParser Prs;

void setup() {
  Serial.begin(115200);   // debug
  Serial1.begin(115200);  // UART to Uno

  if (Usb.Init() == -1) {
    Serial.println("USB Host Shield not detected");
    while (1);
  }

  HidMouse.SetReportParser(0, &Prs);
  Serial.println("Leonardo ready. Waiting for mouse input...");
}

void loop() {
  Usb.Task();
}
