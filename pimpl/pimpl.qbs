import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true
    
    
    files: [
        "src/Library.hpp",
        "src/PIMPL_main.cpp",
        "src/pimpl.hpp",
    ]

    cpp.cxxLanguageVersion : "c++17"

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

