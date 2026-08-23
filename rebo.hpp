// rebo.hpp
// Created by <NectoYou>, 2026
// License: MIT
#pragma once
#include <fstream>
#include <string>
#include <filesystem>

namespace rebo {
    bool save_txt(const std::string& dir, const std::string& name, const std::string& content) {
        namespace fs = std::filesystem;

        fs::path p = dir;
        p /= (name + ".txt");

        // создаём директорию, если нет
        std::error_code ec;
        fs::create_directories(p.parent_path(), ec);
        if (ec) return false;

        std::ofstream out(p, std::ios::binary);
        if (!out) return false;
        out << content;
        return out.good();
    }

    bool load_txt(const std::string& dir, const std::string& name, std::string& out_content) {
        namespace fs = std::filesystem;

        fs::path p = dir;
        p /= (name + ".txt");

        if (!fs::exists(p)) return false;

        std::ifstream in(p, std::ios::binary | std::ios::ate);
        if (!in) return false;

        auto size = in.tellg();
        in.seekg(0, std::ios::beg);

        out_content.resize(static_cast<std::size_t>(size));
        if (!in.read(out_content.data(), size)) return false;

        return true;
    }

    //json файлик

     bool save_json(const std::string& dir, const std::string& name, const std::string& content) {
        namespace fs = std::filesystem;

        fs::path p = dir;
        p /= (name + ".json");

        // создаём директорию, если нет
        std::error_code ec;
        fs::create_directories(p.parent_path(), ec);
        if (ec) return false;

        std::ofstream out(p); 
        if (!out) return false;

        out << content;
        return out.good();
    }

    bool load_json(const std::string& dir, const std::string& name, std::string& out_content) {
        namespace fs = std::filesystem;

        fs::path p = dir;
        p /= (name + ".json");

        if (!fs::exists(p)) return false;

        std::ifstream in(p); 
        if (!in) return false;

        std::stringstream buffer;
        buffer << in.rdbuf();
        out_content = buffer.str();

        return !in.fail();
    }
}
