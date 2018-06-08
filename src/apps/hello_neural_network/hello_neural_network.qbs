import qbs
import qbs.File

CppApplication {
    consoleApplication: true
    files: [
        "include/hello_neural_network/activation_functions.h",
        "include/hello_neural_network/matrix.h",
        "include/hello_neural_network/party.h",
        "src/activation_functions.cpp",
        "src/party.cpp",
        "src/main.cpp",
    ]
    destinationDirectory: File.canonicalFilePath(project.sourceDirectory + "/..") + "/bin/" + qbs.buildVariant
    qbs.installRoot: destinationDirectory
    cpp.cxxLanguageVersion: "c++17"

    cpp.includePaths: [
        "include"
    ]
}
