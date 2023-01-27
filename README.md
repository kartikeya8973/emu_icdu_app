# emu_icdu_app
Source Code of the ICDU application for the MYS-6ULX


Directory cross compilation toolchain -
/home/csemi/kartikeya/MYS-6ULX/03-Tools/mys_qtToolchain

Directory for ICDU Source Code
/home/csemi/MYS-6ULX_ICDU_App/Split_cli_compile/lcd_pis_24

To Cross Compile application
Export environment in a terminal for the above toolchain.
Open the source of qt application in the same terminal.
# qmake
# make
These steps will successfully compile the application.

Name of application
lcd_pis_24


ON ICDU (MYS-6ULX) 
Location of ICDU application - /home/root/

To run the application
# ./lcd_pis_24 -platform linuxfb
