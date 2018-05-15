import qbs

Project {
    minimumQbsVersion: "1.7.1"

    CppApplication {
        cpp.cxxLanguageVersion: "c++17"

        consoleApplication: true
        files: [
            "src/main.cpp",
            "src/UUID.cpp",
            "src/UUID.hpp",
        ]

        Group {     // Properties for the produced executable
            fileTagsFilter: "application"
            qbs.install: true
        }
    }
}
