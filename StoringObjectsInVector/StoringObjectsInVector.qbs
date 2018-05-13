import qbs

CppApplication {
    consoleApplication: true
    files: "src/main.cpp"

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
    }
}
