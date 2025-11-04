# Goal
*My goal of this project was to develop a mouse-controlled robotic arm, using parts that were exclusively 3D printed, that translate real-time mouse movements and button inputs into precise servo motor motions.* 
*This system allows for an intuitive control of the arm using standard computer input.* 

 ## Pre-Setup intstructions
 - You will need an Arduino UNO, Arduino Leonardo, a USB hostshield, 3 Servo Motors, and some jumper cables. 
 - Once you have procured the aforementioned items you will need to solder 1 3.3V pad and 2 5V pads on the hostshield.

   ## Steup instructions
   **Install necessary files and 3D print the CAD files**
   - Download the .ino files and upload them to the respective arduinos
   - Make sure to import "USB Host Shield Library 2.0" in your Arduino IDE
   - 3D print the CAD files and assemble them
   - Install the Servo Motors, using the m.2 screws to screw them into place
   - Some Notes about construction listed in the "CadFiles" Folder
   - I used the following wiring table, but you are free to do something else :D
  


## ⚙️ Hardware Connections


| Leonardo Pin | Uno Pin | 
|---------------|----------|
| **TX1 (Pin 1)** | **RX (Pin 0)** | 
| **GND** | **GND** |


---

 Uno → Servo Motors

| Servo | Signal Pin | Power | Ground |
|--------|-------------|--------|--------|
| **Servo X** | **D9** | 5 V | GND |
| **Servo Y** | **D10** | 5 V | GND |
| **Servo Z** | **D11** | 5 V | GND |


 **Final Construction Should look like [this](https://imgur.com/a/4Hmcevf)**
     
  
     


   **Demo video**
    https://youtu.be/EMsUd_21su0





