import sys, os

for arg in sys.argv[1:]:
    if arg.endswith((".hpp", ".h")):
        filename, extension = os.path.splitext(arg)
        #with open(filename + ".cpp", "w") as f:
            #escrever para cpp
        with open(arg, "w") as f:
            #header
            f.write("#ifndef " + filename.upper() + "_" + extension.lstrip(".").upper() + "\n")
            f.write("#define " + filename.upper() + "_" + extension.lstrip(".").upper() + "\n\n\n")

            #class
            f.write("class " + filename + "\n" + "{\n")
            #TODO:
            #constructor
            #copy constructor
            #assignment operator
            #destructor

            #end
            f.write("#endif /*" + filename.upper() + "_" + extension.lstrip(".").upper() + "*/\n")
            #escrever para hpp

