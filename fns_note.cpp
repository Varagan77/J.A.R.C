#include "fns_note.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

// ─────────────────────────────────────────────
// GIT TIME
// ─────────────────────────────────────────────
static string getCurrentDateTime() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%y %H:%M:%S", ltm);
    return string(buffer);
}

// ─────────────────────────────────────────────
// NOTE ADD
// ─────────────────────────────────────────────
void noteAdd(const string& name) {
    const string basePath = "cmake-building-debug/data/notes/";
    fs::create_directories(basePath);

    string filePath = basePath + name + ".md";
    ofstream file(filePath);

    if (!file.is_open()) {
        cout << "Error: Unable to create note file.\n";
        return;
    }

    cout << "Enter tags (comma separated): ";
    string tags;
    getline(cin, tags);

    cout << "Write your note (type END on a new line to finish):\n";

    string content, line;
    while (true) {
        getline(cin, line);
        if (line == "END")
            break;
        content += line + "\n";
    }

    file << "# " << name << "\n\n";
    file << "**Date:** " << getCurrentDateTime() << "  \n";
    file << "**Tags:** " << tags << "\n\n";
    file << "---\n\n";
    file << content;

    file.close();

    cout << "Note saved: " << filePath << "\n";
}

// ─────────────────────────────────────────────
// NOTE LIST
// ─────────────────────────────────────────────
void noteList() {
    const string basePath = "cmake-building-debug/data/notes/";

    if (!fs::exists(basePath)) {
        cout << "No notes directory found.\n";
        return;
    }

    cout << "Saved Notes:\n";
    int count = 0;

    for (auto& entry : fs::directory_iterator(basePath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".md") {
            cout << " - " << entry.path().filename().string() << "\n";
            count++;
        }
    }

    if(count == 0) cout << "No notes found.\n";
}

// ─────────────────────────────────────────────
// NOTE REMOVE
// ─────────────────────────────────────────────
void noteRemove(const string& name) {
    const string basePath = "cmake-building-debug/data/notes/";
    string filePath = basePath + name + ".md";

    if (!fs::exists(filePath)) {
        cout << "Note not found: " << filePath << "\n";
        return;
    }

    try {
        fs::remove(filePath);
        cout << "Note removed: " << filePath << "\n";
    } catch (const fs::filesystem_error& e) {
        cout << "Error removing note: " << e.what() << "\n";
    }
}
