Created:  11/ 2/2006
Modified:  4/ 4/2012


The Source ("src") directory contains the actual program source code, partitioned into various levels of functionality.  

The architecture and partitioning of embedded software can minimize adverse interactions between the hardware implementation and the desired observable functionality.  "Layered" software architectures with "abstraction" layers between the layers of code is one such organization. Here are a few related links for reference:
http://www.autosar.org/download/AUTOSAR_LayeredSoftwareArchitecture.pdf
http://fox.wikis.com/wc.dll?Wiki~LayeredArchitecture~SoftwareEng
http://en.wikipedia.org/wiki/OSI_model ; http://www.webopedia.com/quick_ref/OSI_Layers.asp


Organization of the project's directory structure can facilitate maintenance of the layered software architecture. Please feel free to adopt and adapt this proposed folder structure in your projects.

Proposal:
The root of the source directory contains the architectural partitioning of the overall program.  The deeper levels of subdirectories contain "packages" of source code to fulfill a specific function in the overall program.

Each "package" of source code (self contained in a subdirectory) should contain a standard set of files along with any additional files necessary.  Some representative files for an example package "ABC" might be:

Directory: abc.dir
* abc.c - definitions of functions, static variables, etc., related to the "ABC" package.
* abc.h - declares any functions and variables, macro definitions, etc. that will be used by external functions.
* abc_api.h - This file is #included by any external file that will use the resources of the "ABC" package.  Any necessary resource files for "ABC" should be #included in this file.
* abc_cfg.h - symbol definitions (#defines) for modifying the behavior of the ABC functions should be defined in this file.  This allows reconfiguring of the function behavior without modifying the actual function source code.
* abc_make.mak - or something like that, if the project uses "make-files" or "build scripts" to compile the program.


Source-Level Directory Tree with Definitions:

.\prj                 - Project "Root" Directory
    .\src             - Project source code file "tree"
        .\app         - "Application" layer - main "observable" features, 
                        hardware independent
            .\...       - Subdirectories as appropriate for the project
        .\bld         - Project "Build" or "Make" files to automate the 
                        compile and link process
            .\...       - Subdirectories as appropriate for the project
        .\drv         - "Driver" layer - hardware specific configuration files 
                        for microcontroller configuration and control
            .\adc       - Analog to Digital Converter driver
            .\dio       - Digital Input/Output driver
            .\mcu       - MicroController Unit configuration files
            .\pwm       - Pulse-Width Modulator driver
            .\rti       - Real-Time Interrupt driver
            .\spi       - Serial Peripheral Interface driver
            .\...       - Additional subdirectories as necessary
        .\itf         - Interfaces - Abstractions of Input and Output Interface devices.
            .\kpd       - Keypad - alpha-numeric keypad
            .\lcd       - LCD - Liquid Crystal Display 
            .\SevenSeg  - Seven Segment LED Display
        .\os          - Operating System - program "task" management

        .\sim         - Simulation components - Simulations for interfaces and other system components.
            .\KeySim    - KeySim - Keyboard and Monitor simulation for various input and output devices.
        .\svc         - "Service" layer - interface between Application and 
                        Driver layers (if necessary) for input and output 
                        filtering, conversion, and other processing
            .\Debounce  - Digital Input Debounce service and configuration
            .\IoMgr     - Input/Output Manager
            .\tmr       - TiMeR service and configuration files
        .\tsk         - Periodic Tasks -  


~Ben Sweet
