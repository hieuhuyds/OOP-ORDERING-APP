#pragma once

#include <string>

class FileManage
{
public:
    // Doc toan bo noi dung tu file
    // Tra ve true neu doc thanh cong, false neu mo file that bai
    static bool readFile(const std::string& filePath, std::string& fileContent);

    // Ghi noi dung vao file, noi dung cu se bi ghi de
    // Tra ve true neu ghi thanh cong, false neu mo file that bai
    static bool writeFile(const std::string& filePath, const std::string& fileContent);

    // Them noi dung moi vao cuoi file, khong xoa noi dung cu
    // Tra ve true neu them thanh cong, false neu mo file that bai
    static bool appendFile(const std::string& filePath, const std::string& newContent);
};