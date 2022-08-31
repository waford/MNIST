//
// Created by waford on 8/29/22.
//

#include "MNISTDataset.hpp"

#include <curl/curl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

MNISTDataset::MNISTDataset(std::string name, std::string image_url, std::string label_url) {
    touchDatasetDirectory(name);
}

void MNISTDataset::touchDatasetDirectory(std::string name) {
    // First ensure that the dataests directory exists
    mkdir(kDatasetDirectory.c_str(),  S_IRWXG | S_IRWXU);
    //Then ensure that the specified directory exists
    mkdir((kDatasetDirectory + "/" + name).c_str(), S_IRWXG | S_IRWXU);
}
