import qbs

CppApplication {
    type: "application" // To suppress bundle generation on Mac
    consoleApplication: true
    
    
    files: "src/main.cpp"

    cpp.cppFlags: {
        if (qbs.toolchain.contains("gcc"))
        {
            return ["-std=c++11"]
        }
    }

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}

