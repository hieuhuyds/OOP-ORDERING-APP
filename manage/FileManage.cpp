#include "FileManage.h"

#include <fstream>
#include <sstream>

// DOC NOI DUNG FILE: Mo file va doc toan bo noi dung vao fileContent.
bool FileManage::readFile(const std::string& filePath,
    std::string& fileContent)
{
    std::ifstream input(filePath);

    // Kiem tra file co mo thanh cong hay khong
    if (!input.is_open())
    {
        return false;
    }

    // Doc toan bo noi dung file
    std::stringstream buffer;
    buffer << input.rdbuf();

    fileContent = buffer.str();

    input.close();

    return true;
}

// GHI FILE: Ghi noi dung moi vao file. Neu file da co noi dung thi noi dung cu se bi ghi de.
bool FileManage::writeFile(const std::string& filePath,
    const std::string& fileContent)
{
    std::ofstream output(filePath);

    // Kiem tra file co mo thanh cong hay khong
    if (!output.is_open())
    {
        return false;
    }

    output << fileContent;

    output.close();

    return true;
}

// THEM NOI DUNG VAO CUOI FILE: Them noi dung moi vao cuoi file ma khong xoa noi dung cu.
bool FileManage::appendFile(const std::string& filePath,
    const std::string& newContent)
{
    // Mo file voi che do append de ghi tiep vao cuoi file
    std::ofstream output(filePath, std::ios::app);

    // Kiem tra file co mo thanh cong hay khong
    if (!output.is_open())
    {
        return false;
    }

    output << newContent;

    output.close();

    return true;
}