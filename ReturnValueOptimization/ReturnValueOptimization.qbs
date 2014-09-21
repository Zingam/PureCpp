import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true

    cpp.cxxFlags: "-std=c++11"
//    // Disable "Return Value Optimization" (RVO)
//    cpp.cppFlags: "-fno-elide-constructors"

    files: ["src/main.cpp"]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

