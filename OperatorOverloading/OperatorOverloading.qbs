import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true

    // Enable "Modern C++"
    cpp.cxxFlags: {
        if (qbs.targetOS.contains("windows")) {
            if (qbs.toolchain.contains("mingw"))
            {
                print("MinGW: setting compiler options");
                return "-std=c++14"
            }
            else if (qbs.toolchain.contains("msvc"))
            {
                print("MSVC: setting compiler options");
                print("Warning: C++11/14 is enabled by default");
            }
        }
        else if (qbs.targetOS.contains("linux")) {
            if (qbs.toolchain.contains("gcc"))
            {
                print("GCC: setting compiler options");
                return "-std=c++14"
            }
        }
    }

    files: [
        "src/constants/enums.h",
        "src/main.cpp",
        "src/operators/operator.h",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

