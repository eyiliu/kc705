# kc705
Kintex-7 FPGA KC705

### Main library, executables and GUI

#### Windows
* CMake: download and execute the [CMake Win32 Installer](http://www.cmake.org/download/). Make sure to set the PATH variable during installation
* Visual Studio 2017 community: download and install [vs studio 2017](https://www.visualstudio.com/downloads/). 
* Swig

#### OS X

* Clang

  Clang (at least version 4.21)

* Qt

  Install Qt5, ```brew install qt ```  

* Pyqt

  Install pyqt5, ```brew install pyqt ```

* Swig

  Install swig3, ```brew install swig```

* CMake
  Install cmake3.6 or later, ```brew install cmake```


### Setup

#### Windows
See the document in doc

#### OS X

* Config and compile

```shell
mkdir build
cd build 
cmake -DCAMKE_INSTALL_PREFIX=where you want to install ..
make
```

* Install
```shell
make install # Install the dynamic libraries
make install-python # Install the python module to ${PYTHON_LIB}/site-packages/
```

* Clean
```shell
make clean
```


![Alt text](https://g.gravizo.com/source/custom_mark10?https%3A%2F%2Fraw.githubusercontent.com%2FTLmaK0%2Fgravizo%2Fmaster%2FREADME.md)
<details> 
<summary></summary>
custom_mark10
digraph G {
    label = "Diagram of JadePix DAQ setup"
    node [shape=box];
    rankdir=LR;
    subgraph cluster0 {
        label = "hardware";
        Sensor -> FE[dir=both, arrowhead=none, arrowtail=none];
        FE -> PC [dir=both,arrowhead=none, arrowtail=none,
                    label="PCIe \n connection"];
    }
    
    subgraph cluster1 {
        label = "DAQ software";
        Factory;
        JsonConf;
        subgraph cluster2 {
            label = "";
            Manager ;
            PC:reg -> RegCtrl [label="retrive status"];
            RegCtrl ->  PC:reg [label="configure"];
            PC:data -> Reader [label="raw stream"];
            Reader -> Decoder [label="raw frame"];
            Decoder -> Filter [label="data frame"];
            Filter -> Monitor [label="CDS data frame"];
            Filter -> Writer [label="CDS data frame"];
        }
        
        RegCtrl -> Manager;
        Manager -> GUI;
        Monitor -> GUI [label="Message \n graph"];
    }
    Writer -> File;
    JsonFile -> JsonConf;
    
    Sensor [label="JadePix \n Sensor"]
    FE [label="Front end \n electronic \n FPGA"];
    PC [shape=record, label="{kernel space: \n XilBus \n stack|{<reg>userspace devfile:\n register map|<data>userspace devfile: \n high speed data}}" ];
    Reader [];
    RegCtrl [];
    Decoder [];
    Filter [];
    Writer [];
    File [label="File or \n TCP socket"];
    GUI [label="user \n interface"]
    Factory [label="Objects Factory"]
    JsonConf [label="Json configuration"]
}
custom_mark10
</details>



![Alt text](https://g.gravizo.com/svg?
  digraph G {
    aize ="4,4";
    main [shape=box];
    main -> parse [weight=8];
    parse -> execute;
    main -> init [style=dotted];
    main -> cleanup;
    execute -> { make_string; printf}
    init -> make_string;
    edge [color=red];
    main -> printf [style=bold,label="100 times"];
    make_string [label="make a string"];
    node [shape=box,style=filled,color=".7 .3 1.0"];
    execute -> compare;
  }
)
